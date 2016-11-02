#include "stdafx.h"
#include "SerialPort.h"
#include <assert.h>

//
// Constructor
//
CSerialPort::CSerialPort()
{
	m_hComm = NULL;
	// initialize overlapped structure members to zero
	m_ov.Offset = 0;
	m_ov.OffsetHigh = 0;

	// create events
	m_ov.hEvent = NULL;
	m_hWriteEvent = NULL;
	m_hShutdownEvent = NULL;

	m_szWriteBuffer = NULL;
	m_nWriteSize=1;

	m_bThreadAlive = FALSE;

//	m_pCmd = NULL;
	m_SBget = 30;
	m_SBput = 0;
	m_pParser = NULL;
	m_hOwnerChar = NULL;

	m_bRecv = FALSE;
	m_bConfirm = FALSE;
	m_bHeartBeat = FALSE;
	m_nPortIndex = 0;
	m_hRecvOver = CreateEvent(NULL,true,false,"");
	m_hConfirmOver = CreateEvent(NULL,true,false,"");
	InitializeCriticalSection(&m_csCharSync);
}

//
// Delete dynamic memory
//
CSerialPort::~CSerialPort()
{
	do
	{
		SetEvent(m_hShutdownEvent);
	} while (m_bThreadAlive);

	
	// if the port is still opened: close it 
	if (m_hComm != NULL)
	{
		CloseHandle(m_hComm);
		m_hComm = NULL;
	}
	// Close Handles  
	if(m_hShutdownEvent!=NULL)
		CloseHandle( m_hShutdownEvent); 
	if(m_ov.hEvent!=NULL)
		CloseHandle( m_ov.hEvent ); 
	if(m_hWriteEvent!=NULL)
		CloseHandle( m_hWriteEvent ); 

	TRACE("Thread ended\n");
	delete [] m_szWriteBuffer;
}

void CSerialPort::Robot_SetCallback(ROBOT_POWER_CALLBACK func, char *userPtr)
{
	m_hOwnerChar = userPtr;
	m_pfunc = func;
}

//
// Initialize the port. This can be port 1 to 4.
//
BOOL CSerialPort::InitPort(CWnd* pPortOwner,	// the owner (CWnd) of the port (receives message)
						   UINT  portnr,		// portnumber (1..9)
						   UINT  portindex,
						   UINT  baud,			// baudrate
						   char  parity,		// parity 
						   UINT  databits,		// databits 
						   UINT  stopbits,		// stopbits 
						   DWORD dwCommEvents,	// EV_RXCHAR, EV_CTS etc
						   UINT  writebuffersize)	// size to the writebuffer
{
	assert(portnr > 0 && portnr < 30);
	//assert(pPortOwner != NULL);

	// if the thread is alive: Kill
	if (m_bThreadAlive)
	{
		do
		{
			SetEvent(m_hShutdownEvent);
		} while (m_bThreadAlive);
		TRACE("Thread ended\n");
	}

	// create events
	if (m_ov.hEvent != NULL)
		ResetEvent(m_ov.hEvent);
	else
		m_ov.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	if (m_hWriteEvent != NULL)
		ResetEvent(m_hWriteEvent);
	else
		m_hWriteEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	
	if (m_hShutdownEvent != NULL)
		ResetEvent(m_hShutdownEvent);
	else
		m_hShutdownEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	// initialize the event objects
	m_hEventArray[0] = m_hShutdownEvent;	// highest priority
	m_hEventArray[1] = m_ov.hEvent;
	m_hEventArray[2] = m_hWriteEvent;

	// initialize critical section
	InitializeCriticalSection(&m_csCommunicationSync);
	
	// set buffersize for writing and save the owner
	m_pOwner = pPortOwner;

	if (m_szWriteBuffer != NULL)
		delete [] m_szWriteBuffer;
	m_szWriteBuffer = new char[writebuffersize];

	m_nPortNr = portnr;

	m_nWriteBufferSize = writebuffersize;
	m_dwCommEvents = dwCommEvents;

	BOOL bResult = FALSE;
	char *szPort = new char[50];
	char *szBaud = new char[50];

	// now it critical!
	EnterCriticalSection(&m_csCommunicationSync);

	// if the port is already opened: close it
	if (m_hComm != NULL)
	{
		CloseHandle(m_hComm);
		m_hComm = NULL;
	}

	// prepare port strings
	sprintf(szPort, "COM%d", portnr);
	sprintf(szBaud, "baud=%d parity=%c data=%d stop=%d", baud, parity, databits, stopbits);
	m_nPortIndex = portindex;

	// get a handle to the port
	m_hComm = CreateFile(szPort,						// communication port string (COMX)
					     GENERIC_READ | GENERIC_WRITE,	// read/write types
					     0,								// comm devices must be opened with exclusive access
					     NULL,							// no security attributes
					     OPEN_EXISTING,					// comm devices must use OPEN_EXISTING
					     FILE_FLAG_OVERLAPPED,			// Async I/O
					     0);							// template must be 0 for comm devices

	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		// port not found
		delete [] szPort;
		delete [] szBaud;

		return FALSE;
	}

	// set the timeout values
	m_CommTimeouts.ReadIntervalTimeout = 1000;
	m_CommTimeouts.ReadTotalTimeoutMultiplier = 1000;
	m_CommTimeouts.ReadTotalTimeoutConstant = 1000;
	m_CommTimeouts.WriteTotalTimeoutMultiplier = 1000;
	m_CommTimeouts.WriteTotalTimeoutConstant = 1000;

	// configure
	if (SetCommTimeouts(m_hComm, &m_CommTimeouts))
	{						   
		if (SetCommMask(m_hComm, dwCommEvents))
		{
			if (GetCommState(m_hComm, &m_dcb))
			{
				m_dcb.EvtChar = 'q';
				m_dcb.fRtsControl = RTS_CONTROL_ENABLE;		// set RTS bit high!
				if (BuildCommDCB(szBaud, &m_dcb))
				{
					if (SetCommState(m_hComm, &m_dcb))
						; // normal operation... continue
					else
						ProcessErrorMessage("SetCommState()");
				}
				else
					ProcessErrorMessage("BuildCommDCB()");
			}
			else
				ProcessErrorMessage("GetCommState()");
		}
		else
			ProcessErrorMessage("SetCommMask()");
	}
	else
		ProcessErrorMessage("SetCommTimeouts()");

	delete [] szPort;
	delete [] szBaud;

	// flush the port
	PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	// release critical section
	LeaveCriticalSection(&m_csCommunicationSync);

	TRACE("Initialisation for communicationport %d completed.\nUse Startmonitor to communicate.\n", portnr);

	return TRUE;
}

//
//  The CommThread Function.
//
UINT CSerialPort::CommThread(LPVOID pParam)
{
	// Cast the void pointer passed to the thread back to
	// a pointer of CSerialPort class
	CSerialPort *port = (CSerialPort*)pParam;
	
	// Set the status variable in the dialog class to
	// TRUE to indicate the thread is running.
	port->m_bThreadAlive = TRUE;	
		
	// Misc. variables
	DWORD BytesTransfered = 0; 
	DWORD Event = 0;
	DWORD CommEvent = 0;
	DWORD dwError = 0;
	COMSTAT comstat;
	memset(&comstat,0,sizeof(comstat));
	BOOL  bResult = TRUE;
		
	// Clear comm buffers at startup
	if (port->m_hComm)		// check if the port is opened
		PurgeComm(port->m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	// begin forever loop.  This loop will run as long as the thread is alive.
	for (;;) 
	{ 

		// Make a call to WaitCommEvent().  This call will return immediatly
		// because our port was created as an async port (FILE_FLAG_OVERLAPPED
		// and an m_OverlappedStructerlapped structure specified).  This call will cause the 
		// m_OverlappedStructerlapped element m_OverlappedStruct.hEvent, which is part of the m_hEventArray to 
		// be placed in a non-signeled state if there are no bytes available to be read,
		// or to a signeled state if there are bytes available.  If this event handle 
		// is set to the non-signeled state, it will be set to signeled when a 
		// character arrives at the port.

		// we do this for each port!

		bResult = WaitCommEvent(port->m_hComm, &Event, &port->m_ov);
		if (!bResult)  
		{ 
			// If WaitCommEvent() returns FALSE, process the last error to determin
			// the reason..
			switch (dwError = GetLastError()) 
			{ 
			case ERROR_IO_PENDING: 	
				{ 
					// This is a normal return value if there are no bytes
					// to read at the port.
					// Do nothing and continue
					break;
				}
			case 87:
				{
					// Under Windows NT, this value is returned for some reason.
					// I have not investigated why, but it is also a valid reply
					// Also do nothing and continue.
					break;
				}
			default:
				{
					// All other error codes indicate a serious error has
					// occured.  Process this error.
					port->ProcessErrorMessage("WaitCommEvent()");
					break;
				}
			}
		}
		else
		{
			// If WaitCommEvent() returns TRUE, check to be sure there are
			// actually bytes in the buffer to read.  
			//
			// If you are reading more than one byte at a time from the buffer 
			// (which this program does not do) you will have the situation occur 
			// where the first byte to arrive will cause the WaitForMultipleObjects() 
			// function to stop waiting.  The WaitForMultipleObjects() function 
			// resets the event handle in m_OverlappedStruct.hEvent to the non-signelead state
			// as it returns.  
			//
			// If in the time between the reset of this event and the call to 
			// ReadFile() more bytes arrive, the m_OverlappedStruct.hEvent handle will be set again
			// to the signeled state. When the call to ReadFile() occurs, it will 
			// read all of the bytes from the buffer, and the program will
			// loop back around to WaitCommEvent().
			// 
			// At this point you will be in the situation where m_OverlappedStruct.hEvent is set,
			// but there are no bytes available to read.  If you proceed and call
			// ReadFile(), it will return immediatly due to the async port setup, but
			// GetOverlappedResults() will not return until the next character arrives.
			//
			// It is not desirable for the GetOverlappedResults() function to be in 
			// this state.  The thread shutdown event (event 0) and the WriteFile()
			// event (Event2) will not work if the thread is blocked by GetOverlappedResults().
			//
			// The solution to this is to check the buffer with a call to ClearCommError().
			// This call will reset the event handle, and if there are no bytes to read
			// we can loop back through WaitCommEvent() again, then proceed.
			// If there are really bytes to read, do nothing and proceed.
		
			bResult = ClearCommError(port->m_hComm, &dwError, &comstat);

			if (comstat.cbInQue == 0)
				continue;
		}	// end if bResult

		// Main wait function.  This function will normally block the thread
		// until one of nine events occur that require action.
		Event = WaitForMultipleObjects(2, port->m_hEventArray, FALSE, INFINITE);
		

		switch (Event)
		{
		case 0:
			{
				// Shutdown event.  This is event zero so it will be
				// the higest priority and be serviced first.
				CloseHandle(port->m_hComm);
				port->m_hComm=NULL;
				port->m_bThreadAlive = FALSE;
				
				// Kill this thread.  break is not needed, but makes me feel better.
				AfxEndThread(100);

				break;
			}
		case 1:	// read event
			{
				GetCommMask(port->m_hComm, &CommEvent);
				if (CommEvent & EV_RXCHAR)
					// Receive character event from port.
				{
					ReceiveChar(port, comstat);
				}
				if (port->m_pOwner != NULL)
				{	
					
					if (CommEvent & EV_CTS)
						::SendMessage(port->m_pOwner->m_hWnd, WM_COMM_CTS_DETECTED, (WPARAM) 0, (LPARAM) port->m_nPortNr);
					if (CommEvent & EV_BREAK)
						::SendMessage(port->m_pOwner->m_hWnd, WM_COMM_BREAK_DETECTED, (WPARAM) 0, (LPARAM) port->m_nPortNr);
					if (CommEvent & EV_ERR)
						::SendMessage(port->m_pOwner->m_hWnd, WM_COMM_ERR_DETECTED, (WPARAM) 0, (LPARAM) port->m_nPortNr);
					if (CommEvent & EV_RING)
						::SendMessage(port->m_pOwner->m_hWnd, WM_COMM_RING_DETECTED, (WPARAM) 0, (LPARAM) port->m_nPortNr);

					if (CommEvent & EV_RXFLAG)
						::SendMessage(port->m_pOwner->m_hWnd, WM_COMM_RXFLAG_DETECTED, (WPARAM) 0, (LPARAM) port->m_nPortNr);
				}
					
				break;
			}  

		} // end switch

		Sleep(30);

	} // close forever loop

	return 0;
}

UINT CSerialPort::CommThread1(LPVOID pParam)
{
	// Cast the void pointer passed to the thread back to
	// a pointer of CSerialPort class
	CSerialPort *port = (CSerialPort*)pParam;

	// Set the status variable in the dialog class to
	// TRUE to indicate the thread is running.
	port->m_bThreadAlive = TRUE;	

	// Misc. variables
	DWORD BytesTransfered = 0; 
	DWORD Event = 0;
	DWORD CommEvent = 0;
	DWORD dwError = 0;
	COMSTAT comstat;
	memset(&comstat,0,sizeof(comstat));
	BOOL  bResult = TRUE;

	// Clear comm buffers at startup
	if (port->m_hComm)		// check if the port is opened
		PurgeComm(port->m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

	// begin forever loop.  This loop will run as long as the thread is alive.
	for (;;) 
	{ 

		// Make a call to WaitCommEvent().  This call will return immediatly
		// because our port was created as an async port (FILE_FLAG_OVERLAPPED
		// and an m_OverlappedStructerlapped structure specified).  This call will cause the 
		// m_OverlappedStructerlapped element m_OverlappedStruct.hEvent, which is part of the m_hEventArray to 
		// be placed in a non-signeled state if there are no bytes available to be read,
		// or to a signeled state if there are bytes available.  If this event handle 
		// is set to the non-signeled state, it will be set to signeled when a 
		// character arrives at the port.

		// we do this for each port!

		bResult = WaitCommEvent(port->m_hComm, &Event, &port->m_ov);
		if (!bResult)  
		{ 
			// If WaitCommEvent() returns FALSE, process the last error to determin
			// the reason..
			switch (dwError = GetLastError()) 
			{ 
			case ERROR_IO_PENDING: 	
				{ 
					// This is a normal return value if there are no bytes
					// to read at the port.
					// Do nothing and continue
					break;
				}
			case 87:
				{
					// Under Windows NT, this value is returned for some reason.
					// I have not investigated why, but it is also a valid reply
					// Also do nothing and continue.
					break;
				}
			default:
				{
					// All other error codes indicate a serious error has
					// occured.  Process this error.
					port->ProcessErrorMessage("WaitCommEvent()");
					break;
				}
			}
		}
		else
		{
			// If WaitCommEvent() returns TRUE, check to be sure there are
			// actually bytes in the buffer to read.  
			//
			// If you are reading more than one byte at a time from the buffer 
			// (which this program does not do) you will have the situation occur 
			// where the first byte to arrive will cause the WaitForMultipleObjects() 
			// function to stop waiting.  The WaitForMultipleObjects() function 
			// resets the event handle in m_OverlappedStruct.hEvent to the non-signelead state
			// as it returns.  
			//
			// If in the time between the reset of this event and the call to 
			// ReadFile() more bytes arrive, the m_OverlappedStruct.hEvent handle will be set again
			// to the signeled state. When the call to ReadFile() occurs, it will 
			// read all of the bytes from the buffer, and the program will
			// loop back around to WaitCommEvent().
			// 
			// At this point you will be in the situation where m_OverlappedStruct.hEvent is set,
			// but there are no bytes available to read.  If you proceed and call
			// ReadFile(), it will return immediatly due to the async port setup, but
			// GetOverlappedResults() will not return until the next character arrives.
			//
			// It is not desirable for the GetOverlappedResults() function to be in 
			// this state.  The thread shutdown event (event 0) and the WriteFile()
			// event (Event2) will not work if the thread is blocked by GetOverlappedResults().
			//
			// The solution to this is to check the buffer with a call to ClearCommError().
			// This call will reset the event handle, and if there are no bytes to read
			// we can loop back through WaitCommEvent() again, then proceed.
			// If there are really bytes to read, do nothing and proceed.

			bResult = ClearCommError(port->m_hComm, &dwError, &comstat);

			if (comstat.cbInQue == 0)
				continue;
		}	// end if bResult

		// Main wait function.  This function will normally block the thread
		// until one of nine events occur that require action.
		Event = WaitForMultipleObjects(1, &(port->m_hEventArray[2]), FALSE, INFINITE);


		switch (Event)
		{
 
		case 0: // write event
			{
				// Write character event from port
				WriteChar(port);
				break;
			}

		} // end switch

		Sleep(30);

	} // close forever loop

	return 0;
}
//
// start comm watching
//
BOOL CSerialPort::StartMonitoring()
{
	if (!(m_Thread = AfxBeginThread(CommThread, this)))
		return FALSE;
	TRACE("Thread started\n");

	if (!(m_Thread1 = AfxBeginThread(CommThread1, this)))
		return FALSE;
	TRACE("Thread started\n");

	return TRUE;	
}

//
// Restart the comm thread
//
BOOL CSerialPort::RestartMonitoring()
{
	TRACE("Thread resumed\n");
	m_Thread->ResumeThread();
	m_Thread1->ResumeThread();
	return TRUE;	
}


//
// Suspend the comm thread
//
BOOL CSerialPort::StopMonitoring()
{
	TRACE("Thread suspended\n");
	m_Thread->SuspendThread(); 
	m_Thread1->SuspendThread();
	return TRUE;	
}


//
// If there is a error, give the right message
//
void CSerialPort::ProcessErrorMessage(char* ErrorText)
{
	char *Temp = new char[200];
	
	LPVOID lpMsgBuf;

	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
	);

	sprintf(Temp, "WARNING:  %s Failed with the following error: \n%s\nPort: %d\n", (char*)ErrorText, lpMsgBuf, m_nPortNr); 
	//MessageBox(NULL, Temp, "Application Error", MB_ICONSTOP);

	LocalFree(lpMsgBuf);
	delete [] Temp;
}

//
// Write a character.
//
void CSerialPort::WriteChar(CSerialPort* port)
{
	BOOL bWrite = TRUE;
	BOOL bResult = TRUE;
	BOOL bEnd = FALSE;

	DWORD BytesSent = 0;
	CString strOut;

	ResetEvent(port->m_hWriteEvent);

	// Gain ownership of the critical section
	EnterCriticalSection(&port->m_csCommunicationSync);

	if (bWrite)
	{
		// Initailize variables
		port->m_ov.Offset = 0;
		port->m_ov.OffsetHigh = 0;

		// Clear buffer
		PurgeComm(port->m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);

		/*/////////////////////////////////////////////////////////////////////////
		bResult = WriteFile(port->m_hComm,							// Handle to COMM Port
							port->m_szWriteBuffer,					// Pointer to message buffer in calling finction
//							strlen((char*)port->m_szWriteBuffer),	// Length of message to send
							port->m_nWriteSize,	// Length of message to send
							&BytesSent,								// Where to store the number of bytes sent
							&port->m_ov);							// Overlapped structure
		/////////////////////////////////////////////////////////////////////////*/
		//1、先发sigcmd
// 		static UCHAR sigbuf[1024];
// 		static int siglen;
// 		siglen = 0;
// 		if (port->m_pCmd != NULL)
// 		{
// 			for (int i=0;i<CMD_NUM;i++)
// 			{
// 				if (port->m_pCmd->m_arSigCmd[i].bToBeSend == true)
// 				{
// 					if (siglen + port->m_pCmd->m_arSigCmd[i].Length > 1024)
// 					{
// 						break;
// 					}
// 					memcpy(sigbuf+siglen,port->m_pCmd->m_arSigCmd[i].buf,port->m_pCmd->m_arSigCmd[i].Length);
// 					siglen += port->m_pCmd->m_arSigCmd[i].Length;
// 					port->m_pCmd->m_arSigCmd[i].bToBeSend = false;
// 				}
// 			}
// 			bResult = WriteFile(port->m_hComm,				// Handle to COMM Port
// 								sigbuf,						// Pointer to message buffer in calling finction
// 								siglen,						// Length of message to send
// 								&BytesSent,					// Where to store the number of bytes sent
// 								&port->m_ov);				// Overlapped structure
// 		}

		//2发送环形缓冲的数据
		while(!bEnd)
		{
			if (port->m_SBput ==  port->m_SBget)
			{
				bEnd = TRUE;
				break;
			}

			if (port->m_SBput < port->m_SBget)
			{
				bResult = WriteFile(port->m_hComm,				// Handle to COMM Port
									port->m_szWriteBuffer/*+port->m_SBget*/,	// Pointer to message buffer in calling finction
									port->m_SBput/* - port->m_SBget*/,	// Length of message to send
									&BytesSent,					// Where to store the number of bytes sent
									&port->m_ov);
				
				//CString str;
				//str.Format("%s",port->m_szWriteBuffer);
				//LOG("D://testsend.txt",str);
				//if (!bResult)
				//{
				//	CString str;
				//	char tmp[100] = {0};
				//	memcpy((char *)tmp,(char *)(port->m_szWriteBuffer),port->m_SBput);
				//	str.Format("%s,m_SBput：%d",tmp,port->m_SBput);
				//	LOG("d://testsend.txt",str);
				//}
				//else
				//{
				//	CString str;
				//	char tmp[100] = {0};
				//	memcpy((char *)tmp,(char *)(port->m_szWriteBuffer),port->m_SBput);
				//	str.Format("%s,m_SBput：%d",tmp,port->m_SBput);
				//	LOG("d://testsend.txt",str);
				//}

				port->m_SBget = 30;

				if (!bResult)
				{
					break;
				}
				else
				{
					bEnd = TRUE;
				}

			} 
			else
			{
				//将缓冲尾部发送完，但是不给bEnd赋值，造成第二次发

				bResult = WriteFile(port->m_hComm,				// Handle to COMM Port
									port->m_szWriteBuffer+port->m_SBget,	// Pointer to message buffer in calling finction
									port->m_nWriteBufferSize - port->m_SBget,	// Length of message to send
									&BytesSent,					// Where to store the number of bytes sent
									&port->m_ov);
							port->m_SBget = 0;

							//CString str;
							//str.Format("%s",port->m_szWriteBuffer);
							//LOG("D://testsend.txt",str);

				if (!bResult)
				{
					break;
				}
			}//end if (port->m_SBput > port->m_SBget)

		}//end while(bEnd)


		// deal with any error codes
		if (!bResult)  
		{
			DWORD dwError = GetLastError();
			switch (dwError)
			{
				case ERROR_IO_PENDING:
					{
						// continue to GetOverlappedResults()
						BytesSent = 0;
						bWrite = FALSE;
						break;
					}
				default:
					{
						// all other error codes
						port->ProcessErrorMessage("WriteFile()");
					}
			}
		} 
		else
		{
			LeaveCriticalSection(&port->m_csCommunicationSync);
		}
	} // end if(bWrite)
	if (!bWrite)
	{
		bWrite = TRUE;
	
		bResult = GetOverlappedResult(port->m_hComm,	// Handle to COMM port 
									  &port->m_ov,		// Overlapped structure
									  &BytesSent,		// Stores number of bytes sent
									  TRUE); 			// Wait flag

		LeaveCriticalSection(&port->m_csCommunicationSync);

		// deal with the error code 
//		if (!bResult)  
//		{
//			port->ProcessErrorMessage("GetOverlappedResults() in WriteFile()");
//		}	
	} // end if (!bWrite)

	//Verify that the data size send equals what we tried to send
	if (BytesSent != (DWORD)(port->m_nWriteSize))	// Length of message to send)
	{
		TRACE("WARNING: WriteFile() error.. Bytes Sent: %d; Message Length: %d\n", BytesSent, strlen((char*)port->m_szWriteBuffer));
		//LOG("WriteFile.txt",port->m_szWriteBuffer);
	}
	strOut.Format("wirte buffer : %s write size: %d", port->m_szWriteBuffer,BytesSent);
	TRACE(strOut);

//	::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_TXEMPTY_DETECTED, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
//	::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_TXEMPTY_DETECTED,0,(LPARAM) port->m_nPortNr);
}

//
// Character received. Inform the owner
//

void CSerialPort::ReceiveChar(CSerialPort* port, COMSTAT comstat)
{
	BOOL  bRead = TRUE; 
	BOOL  bResult = TRUE;
	DWORD dwError = 0;
	DWORD BytesRead = 0;
	unsigned char RXBuff;

	ResetEvent(port->m_ov.hEvent);

	for (;;) 
	{ 
		// Gain ownership of the comm port critical section.
		// This process guarantees no other part of this program 
		// is using the port object. 

		EnterCriticalSection(&port->m_csCommunicationSync);

		// ClearCommError() will update the COMSTAT structure and
		// clear any other errors.

		bResult = ClearCommError(port->m_hComm, &dwError, &comstat);

		LeaveCriticalSection(&port->m_csCommunicationSync);

		// start forever loop.  I use this type of loop because I
		// do not know at runtime how many loops this will have to
		// run. My solution is to start a forever loop and to
		// break out of it when I have processed all of the
		// data available.  Be careful with this approach and
		// be sure your loop will exit.
		// My reasons for this are not as clear in this sample 
		// as it is in my production code, but I have found this 
		// solutiion to be the most efficient way to do this.

		if (comstat.cbInQue == 0)
		{
			// break out when all bytes have been read
			break;
		}

		EnterCriticalSection(&port->m_csCommunicationSync);

		if (bRead)
		{
			bResult = ReadFile(port->m_hComm,		// Handle to COMM port 
				&RXBuff,				// RX Buffer Pointer
				1,					// Read one byte
				&BytesRead,			// Stores number of bytes read
				&port->m_ov);		// pointer to the m_ov structure
			// deal with the error code 
			if (!bResult)  
			{ 
				switch (dwError = GetLastError()) 
				{ 
				case ERROR_IO_PENDING: 	
					{ 
						// asynchronous i/o is still in progress 
						// Proceed on to GetOverlappedResults();
						bRead = FALSE;
						break;
					}
				default:
					{
						// Another error has occured.  Process this error.
						port->ProcessErrorMessage("ReadFile()");
						break;
					} 
				}
			}
			else
			{
				// ReadFile() returned complete. It is not necessary to call GetOverlappedResults()
				bRead = TRUE;
			}
		}  // close if (bRead)

		if (!bRead)
		{
			bRead = TRUE;
			bResult = GetOverlappedResult(port->m_hComm,	// Handle to COMM port 
				&port->m_ov,		// Overlapped structure
				&BytesRead,		// Stores number of bytes read
				TRUE); 			// Wait flag

			// deal with the error code 
			if (!bResult)  
			{
				port->ProcessErrorMessage("GetOverlappedResults() in ReadFile()");
			}	
		}  // close if (!bRead)

		LeaveCriticalSection(&port->m_csCommunicationSync);

		// notify parent that a byte was received
		if (port->m_pOwner != NULL)
		{
			switch(port->m_nPortIndex)
			{
			case 1:
				//::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_RXCHAR_FROMPLC, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
				//{
					//CString str;
					//str.Format("%c",RXBuff);
					//LOG("d://test.txt",str);
				//}
				
				if (RXBuff == STX)
				{
					port->m_bRecv = TRUE;		
					port->m_strPLC.Format("%c",RXBuff);

				//	LOG("d://testrx.txt",port->m_strPLC);
				}
				else if (port->m_bRecv == TRUE)
				{
					port->m_strPLC += RXBuff;
				//	LOG("d://testrx.txt",port->m_strPLC);
				}

				if (RXBuff == ETX)
				{

					
					port->m_bRecv = FALSE;
					//LOG("testrx.txt",port->m_strPLC);
					SetEvent(port->m_hRecvOver);
				//	EnterCriticalSection(&port->m_csCharSync);
					
				//	LeaveCriticalSection(&port->m_csCharSync);

				}

				if (RXBuff == ACK)
				{
					port->m_bConfirm = TRUE;		
					port->m_strComfirm.Format("%c",RXBuff);
				}	
				else if (port->m_bConfirm == TRUE)
				{
					port->m_strComfirm += RXBuff;
				}

				{
					CString strcon;
					strcon = STATIONNUM;
					strcon += PCNUM;
				
					if (port->m_strComfirm.Right(4) == strcon)
					{
						port->m_bConfirm = FALSE;	
						SetEvent(port->m_hConfirmOver);	
						//LOG("testrecv.txt",port->m_strComfirm);
						port->m_strComfirm.ReleaseBuffer();
						port->m_strComfirm = "";
						
						
					}	
					else if(port->m_strComfirm != "")
					{
						//LOG("testrecv.txt",port->m_strComfirm);
					}

				}
				
				break;
			case 2:
				::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_RXCHAR_FROMFLICKA, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
				break;
			case 3:
				::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_RXCHAR_FROMFLICKB, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
				break;
			case 4:
				::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_RXCHAR_FROMTAG, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
				break;
			default:
				break;
			}
			//::SendMessage((port->m_pOwner)->m_hWnd, WM_COMM_RXCHAR, (WPARAM) RXBuff, (LPARAM) port->m_nPortNr);
			//if (RXBuff > 48 && RXBuff < 58)
			//{
			//	strcpy(port->m_hOwnerChar,(const char *)&RXBuff);
			//}

		}
		TRACE("RECEIVE CHAR :%c", RXBuff);
		if (port->m_pParser != NULL)
		{
			port->m_pParser->RecvData(RXBuff);
		}
		Sleep(20);
	} // end forever loop

}

//
// Write a string to the port
//
void CSerialPort::WriteToPort(char* string)
{		
	assert(m_hComm != 0);
	
	memset(m_szWriteBuffer, 0, sizeof(m_szWriteBuffer));
	strcpy(m_szWriteBuffer, string);
	m_nWriteSize=strlen(string);

	// set event for write
	SetEvent(m_hWriteEvent);
}


void CSerialPort::WriteToPort(char* string,int n)
{		
	if(m_hComm == 0)
	{
		return;
	}

	////////////////////////////////////////////////////////////////////////
	
	Sleep(40);
	m_nWriteSize=n;
	//////////////////////////////////////////////////////////////////////////
	memset(m_szWriteBuffer, 0, sizeof(m_szWriteBuffer));
	
	if (m_nWriteBufferSize-m_SBput > (DWORD)n )
	{
		//剩余空间足够存储数据
		m_SBput = 0;

		memcpy(m_szWriteBuffer+m_SBput,string,n);
		m_SBput += n;

		m_SBput = n;
	}
	else
	{
		//剩余空间不足以存储数据时
		int bufleft = m_nWriteBufferSize-m_SBput;	//存在缓冲尾部的字节个数
		int cmdleft = n - bufleft;		//溢出，需要存到缓冲头部的字节个数
		memcpy(m_szWriteBuffer+m_SBput,string,bufleft);
		memcpy(m_szWriteBuffer,(BYTE*)string+bufleft,cmdleft);
		m_SBput = cmdleft;
	}
	SetEvent(m_hWriteEvent);
}

void CSerialPort::WriteToPort(LPCTSTR string)
{		
	assert(m_hComm != 0);

	memset(m_szWriteBuffer, 0, sizeof(m_szWriteBuffer));
	strcpy(m_szWriteBuffer, string);
	m_nWriteSize=strlen(string);

	// set event for write
	SetEvent(m_hWriteEvent);
}

void CSerialPort::WriteToPort(LPCTSTR string,int n)
{		
	assert(m_hComm != 0);

	memset(m_szWriteBuffer, 0, sizeof(m_szWriteBuffer));
//	strncpy(m_szWriteBuffer, string, n);
	memcpy(m_szWriteBuffer, string, n);
	m_nWriteSize=n;
	// set event for write
	SetEvent(m_hWriteEvent);
}

//
// Return the device control block
//
DCB CSerialPort::GetDCB()
{
	return m_dcb;
}

//
// Return the communication event masks
//
DWORD CSerialPort::GetCommEvents()
{
	return m_dwCommEvents;
}

//
// Return the output buffer size
//
DWORD CSerialPort::GetWriteBufferSize()
{
	return m_nWriteBufferSize;
}


void CSerialPort::ClosePort()
{
		SetEvent(m_hShutdownEvent);
}

/*
void CSerialPort::ClosePort()
{
	do
	{
		SetEvent(m_hShutdownEvent);
	} while (m_bThreadAlive);

	
	// if the port is still opened: close it 
	if (m_hComm != NULL)
	{
		CloseHandle(m_hComm);
		m_hComm = NULL;
	}
	// Close Handles  
	if(m_hShutdownEvent!=NULL)
		CloseHandle( m_hShutdownEvent); 
	if(m_ov.hEvent!=NULL)
		CloseHandle( m_ov.hEvent ); 
	if(m_hWriteEvent!=NULL)
		CloseHandle( m_hWriteEvent ); 

	TRACE("Thread ended\n");
	delete [] m_szWriteBuffer;
}

*/

//DEL void CSerialPort::SetCmd(CVoyCmd *pCmd)
//DEL {
//DEL 	m_pCmd = pCmd;
//DEL 	m_pCmd->m_pPhy = this;
//DEL }	


CString CSerialPort::IntToStr(int rt)
{
	int remain,div,rtbit;
	CString tmp = "";
	CString str = "";

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{
		rtbit = rt >> (4 * i);
		div = rtbit / 16;
		remain = rtbit % 16;

		if (div > 0 && remain == 0)
		{
			tmp = "0";
		} 
		else
		{
			if (remain >= 0 && remain <= 9)
			{
				tmp.Format("%c",remain + '0');
			} 
			else if(remain >= 10 && remain <= 15)
			{
				tmp.Format("%c",remain - 10 + 'A');
			}
		}

		str = tmp + str;
	}

	return str;
}

void CSerialPort::Send(const void *pBuffer, const int iLength)
{
	WriteToPort((char*)pBuffer,iLength);
}

int CSerialPort::GetSync(int index)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return -1;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt = 0;
	char ch = 0;
	CString data;
	CString outString;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WR;
	data = data + READDELAY;
	data = data + SYNC_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	WaitForSingleObject(m_hRecvOver,RECVTIMEOUT);
	//EnterCriticalSection(&m_csCharSync);
	
	if (m_strPLC == "")
	{
		return -1;
	}

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{

       if( (SYNC_RECV_POS - i) > m_strPLC.GetLength() ) 
	   {
		   outString.Format("m_strPLC Length %d",m_strPLC.GetLength());
		   //AfxMessageBox(outString);
		   //AfxMessageBox(m_strPLC);
		   m_strPLC.ReleaseBuffer();
		   m_strPLC = "";
		   return -1;
	   }
		ch = m_strPLC.GetAt(SYNC_RECV_POS - i);
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - 48;
		} 
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}
		
		switch (i)
		{
		case 0:
			rt += ch;
			break;
		case 1:
			rt += ch * 16;
			break;
		case 2:
			rt += ch * 16 * 16;
			break;
		case 3:
			rt += ch * 16 * 16 * 16;
			break;
		}
		
	}
	// LeaveCriticalSection(&m_csCharSync);
//	m_strPLC.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";

	data = (char)ACK;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data.ReleaseBuffer();
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	ResetEvent(m_hRecvOver);
	LeaveCriticalSection(&m_csCharSync);

	return rt;
}

bool CSerialPort::SetSync(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + SYNC_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0)
	{
		//LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		return false;
	}
		
}


int CSerialPort::GetSyncReserve(int index)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return -1;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt = 0;
	char ch = 0;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WR;
	data = data + READDELAY;
	data = data + RESERVE_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	WaitForSingleObject(m_hRecvOver,RECVTIMEOUT);

	if (m_strPLC == "")
	{
		return -1;
	}

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{
		ch = m_strPLC.GetAt(SYNC_RECV_POS - i);
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - 48;
		} 
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}

		switch (i)
		{
		case 0:
			rt += ch;
			break;
		case 1:
			rt += ch * 16;
			break;
		case 2:
			rt += ch * 16 * 16;
			break;
		case 3:
			rt += ch * 16 * 16 * 16;
			break;
		}

	}

	m_strPLC.ReleaseBuffer();
	m_strPLC = "";

	data = (char)ACK;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data.ReleaseBuffer();
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	ResetEvent(m_hRecvOver);
	LeaveCriticalSection(&m_csCharSync);

	return rt;
}

bool CSerialPort::SetSyncReserve(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + RESERVE_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		//LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		return false;
	}

}


void CSerialPort::SetAOISync(int index,bool bvalue)
{

	CString str;
	int rt;
	CString strGetSync;
	int GetStr;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetAOISyncGetSync");
		}
	}
	while(rt == -1);

	if (index == 0)
	{
		if (bvalue)
		{
			rt|=(bvalue<<AOIAFINISHED);
		} 
		else
		{
			rt&= ~((!bvalue)<<AOIAFINISHED);
		}
	}
	else if(index == 1)
	{
		if (bvalue)
		{
			rt|=(bvalue<<AOIBFINISHED);
		} 
		else
		{
			rt&= ~((!bvalue)<<AOIBFINISHED);
		}
	}

	str = IntToStr(rt);
	int rtSetSync = 0;
	do 
	{
	  rtSetSync = SetSync(str);
	  if (rtSetSync == 0)
	  {
		  //LOG("SerialError.txt","SetAOISyncSetSync");
	  }
	} while (!rtSetSync);

}
void CSerialPort::SetPrepareSync(bool bvalue)
{
	CString str;
	int rt;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetPrepareSyncGetSync");
		}
	}
	while(rt == -1);

	if (bvalue)
	{
		rt|=(bvalue<<PREPARE);
	} 
	else
	{
		rt&= ~((!bvalue)<<PREPARE);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSync(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetPrepareSyncSetSync");
		}
	} while (!rtSetSync);
}

void CSerialPort::SetFlickSync(int index,bool bvalue)
{
	CString str;
	int rt;

	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetFlickSyncGetSync");
		}
	}
	while(rt == -1);
	
	if (index == 0)
	{
		if (bvalue)
		{
			rt|=(bvalue<<FLICKFINISHED);
		} 
		else
		{
			rt&= ~((!bvalue)<<FLICKFINISHED);
		}
	}
	else if(index == 1)
	{
		if (bvalue)
		{
			rt|=(bvalue<<FLICKBFINISHED);
		} 
		else
		{
			rt&= ~((!bvalue)<<FLICKBFINISHED);
		}
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
	  rtSetSync = SetSync(str);
	  if (rtSetSync == 0)
	  {
		  //LOG("SerialError.txt","SetFlickSyncSetSync");
	  }
	} while (!rtSetSync);

}

void CSerialPort::SetTagSync(bool bvalue)
{
	CString str;
	int rt;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetTagSyncGetSync");
		}
	}
	while(rt == -1);
	
	if (bvalue)
	{
		rt|=(bvalue<<TAGFINISHED);
	} 
	else
	{
		rt&= ~((!bvalue)<<TAGFINISHED);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSync(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetTagSyncSetSync");
		}

	} while (!rtSetSync);

}



void CSerialPort::SetAOIInitSync(int index,bool bvalue)
{
	CString str;
	int rt;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetAOIInitSyncGetSync");
		}
	}
	while(rt == -1);
	
	if (bvalue)
	{
		rt|=(bvalue<<AOIINITED);
	} 
	else
	{
		rt&= ~((!bvalue)<<AOIINITED);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSync(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetAOIInitSyncSetSync");
		}
	} while (!rtSetSync);
}

void CSerialPort::SetCamPosSync(int index,bool bvalue)
{
	CString str;
	int rt = 0;
	do
	{
		rt = GetSyncReserve(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetCamPosSyncGetSync");
		}		
	}
	while(rt == -1);

	if (bvalue)
	{
		rt|=(bvalue<<CAM_POS);
	} 
	else
	{
		rt&= ~((!bvalue)<<CAM_POS);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSyncReserve(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetCamPosSyncSetSyncReserve");
		}
	} while (!rtSetSync);
}

void CSerialPort::SetFlickInitSync(bool bvalue)
{
	CString str;
	int rt;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetFlickInitSyncGetSync");
		}	
	}
	while(rt == -1);
	
	if (bvalue)
	{
		rt|=(bvalue<<FLICKINITED);
	} 
	else
	{
		rt&= ~((!bvalue)<<FLICKINITED);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSync(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetFlickInitSyncSetSync");
		}
	} while (!rtSetSync);

}

void CSerialPort::SetTagInitSync(bool bvalue)
{
	CString str;
	int rt;
	do
	{
		rt = GetSync(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetTagInitSyncGetSync");
		}
	}
	while(rt == -1);
	
	if (bvalue)
	{
		rt|=(bvalue<<TAGINITED);
	} 
	else
	{
		rt&= ~((!bvalue)<<TAGINITED);
	}

	str = IntToStr(rt);

	int rtSetSync = 0;
	do 
	{
	  rtSetSync = SetSync(str);
	  if (rtSetSync == 0)
	  {
		  //LOG("SerialError.txt","SetTagInitSyncSetSync");
	  }
	} while (!rtSetSync);

}

void CSerialPort::SetTag(int index,bool bvalue)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return;
	}

	EnterCriticalSection(&m_csCharSync);
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + BW;
	data = data + WRITEDELAY;
	if (index == 0)
	{
		data = data + TAGA_REG_ADDRESS;
	} 
	else
	{
		data = data + TAGB_REG_ADDRESS;
	}
	data = data + PLCIOSIZE;
	if (bvalue == true)
	{
		data = data + "1";
	} 
	else
	{
		data = data + "0";
	}
	data.ReleaseBuffer();

	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	LeaveCriticalSection(&m_csCharSync);

}
bool CSerialPort::SetPos(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + POS_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";//LOG
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0 /*&& m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetPos");
		return false;
	}

}

bool CSerialPort::SetTag(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + TAG_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetTag");
		return false;
	}

}

bool CSerialPort::SetOK(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + OK_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();
	
	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0 /*&& m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetOK");
		return false;
	}


}

bool CSerialPort::SetNG(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + NG_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0 /*&& m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetNG");
		return false;
	}


}

bool CSerialPort::SetSum(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + SUM_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0 /*&& m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetSum");
		return false;
	}

}

bool CSerialPort::SetPar(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + PER_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0 /*&& m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetPar");
		return false;
	}

}

bool CSerialPort::SetTT(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + TT_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetTT");
		return false;
	}
}

bool CSerialPort::SetTest(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + TEST_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT15);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		//LOG("SerialError.txt","SetTest");
		return false;
	}
}

//BOOL CSerialPort::Create(CWnd* pPortOwner,int inCom,int portindex)
//{
//	BOOL res = InitPort(pPortOwner,inCom,portindex);
//	if (res == TRUE)
//	{
//		StartMonitoring();
//	}
//	return res;
//}

void CSerialPort::SigWrite()
{
	SetEvent(m_hWriteEvent);
}


void CSerialPort::SetParser(CDataParser *inParser)
{
	m_pParser = inParser;
}

BOOL CSerialPort::Create(CWnd* pPortOwner, int inCom,int portindex, int BaudRate)
{
	BOOL res = InitPort(pPortOwner,inCom,portindex,BaudRate);
	if (res == TRUE)
	{
		StartMonitoring();
	}
	return res;
}

void CSerialPort::SetPasteHeartBeat()
{
	CString str;
	int rt;
	CString strGetSync;
	int GetStr;
	int count = 0;
	do
	{
		count++;
		rt = GetSyncHb(0);

		if (rt == -1)
		{
			//LOG("SerialError.txt","HEARTBEATGetSyncPaste");
		}

		if (count > 1)
		{
			ClosePort();
			Sleep(100);
			if(InitPort(m_pOwner,COM,1))	
			{
				StartMonitoring();
			}
			//LOG("SerialError.txt","HEARTBEATStartMonitoring");
			return;

		}

	}while(rt == -1);

	if (m_bHeartBeat)
	{
		rt|=(m_bHeartBeat<<HEARTBEAT);
	} 
	else
	{
		rt&= ~((!m_bHeartBeat)<<HEARTBEAT);
	}

	str = IntToStr(rt);

	count = 0;
	int rtSetSync = 0;
	do 
	{
		count++;
		rtSetSync = SetSyncHb(str);

		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","HEARTBEATSetSyncPaste");
		}

		if (count > 1)
		{
			ClosePort();
			Sleep(100);
			if(InitPort(m_pOwner,COM,1))	
			{
				StartMonitoring();
			}
			//LOG("SerialError.txt","HEARTBEATStartMonitoring");
			return;
		}

	} while (!rtSetSync);

	m_bHeartBeat = !m_bHeartBeat;
}


void CSerialPort::SetPaste(int index,bool bvalue)
{
	CString str;
	int rt;
	CString strGetSync;
	int GetStr;
	do
	{
		rt = GetSyncPaste(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetPasteGetSyncPaste");
		}
	}
	while(rt == -1);

	if (index == FIRSTPASTEONLY ||index == SECONDPASTEONLY ||
		index == TWOPASTEFIRST ||index == TWONOPASTE )
	{
		if (bvalue)
		{

			rt&= ~(bvalue<<FIRSTPASTEONLY);
			rt&= ~(bvalue<<SECONDPASTEONLY);
			rt&= ~(bvalue<<TWOPASTEFIRST);
			rt&= ~(bvalue<<TWONOPASTE);
			rt|=(bvalue<<index);

			CString str;
			str.Format("%d",bvalue<<index);
			//LOG("PASTE.txt",str);
		} 
	}
	else
	{
		if (bvalue)
		{
			rt|=(bvalue<<index);
		} 
		else
		{
			rt&= ~((!bvalue)<<index);
		}
	}

	str = IntToStr(rt);
	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetSyncPaste(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetPasteSetSyncPaste");
		}
	} while (!rtSetSync);

}

bool CSerialPort::SetSyncHb(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + HB_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		return false;
	}

}
int CSerialPort::GetSyncHb(int index)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return -1;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt = 0;
	char ch = 0;
	CString data;
	CString outString;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WR;
	data = data + READDELAY;
	data = data + HB_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	WaitForSingleObject(m_hRecvOver,RECVTIMEOUT);

	if (m_strPLC == "")
	{
		return -1;
	}

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{
		if( (SYNC_RECV_POS - i) > m_strPLC.GetLength() ) 
		{
			outString.Format("m_strPLC Length %d",m_strPLC.GetLength());
			//AfxMessageBox(outString);
			//AfxMessageBox(m_strPLC);
			m_strPLC.ReleaseBuffer();
			m_strPLC = "";
			return -1;
		}
		ch = m_strPLC.GetAt(SYNC_RECV_POS - i);
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - 48;
		} 
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}

		switch (i)
		{
		case 0:
			rt += ch;
			break;
		case 1:
			rt += ch * 16;
			break;
		case 2:
			rt += ch * 16 * 16;
			break;
		case 3:
			rt += ch * 16 * 16 * 16;
			break;
		}

	}
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";

	//m_strPLC.ReleaseBuffer();
	data = (char)ACK;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data.ReleaseBuffer();
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	ResetEvent(m_hRecvOver);
	LeaveCriticalSection(&m_csCharSync);

	return rt;
}


bool CSerialPort::SetSyncPaste(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + TAG_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		return false;
	}

}
int CSerialPort::GetSyncPaste(int index)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return -1;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt = 0;
	char ch = 0;
	CString data;
	CString outString;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WR;
	data = data + READDELAY;
	data = data + TAG_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	WaitForSingleObject(m_hRecvOver,RECVTIMEOUT);

	if (m_strPLC == "")
	{
		return -1;
	}

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{
		if( (SYNC_RECV_POS - i) > m_strPLC.GetLength() ) 
		{
			outString.Format("m_strPLC Length %d",m_strPLC.GetLength());
			//AfxMessageBox(outString);
			//AfxMessageBox(m_strPLC);
			m_strPLC.ReleaseBuffer();
			m_strPLC = "";
			return -1;
		}
		ch = m_strPLC.GetAt(SYNC_RECV_POS - i);
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - 48;
		} 
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}

		switch (i)
		{
		case 0:
			rt += ch;
			break;
		case 1:
			rt += ch * 16;
			break;
		case 2:
			rt += ch * 16 * 16;
			break;
		case 3:
			rt += ch * 16 * 16 * 16;
			break;
		}

	}
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";

	//m_strPLC.ReleaseBuffer();
	data = (char)ACK;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data.ReleaseBuffer();
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	ResetEvent(m_hRecvOver);
	LeaveCriticalSection(&m_csCharSync);

	return rt;
}

void CSerialPort::SetStatus(int index,bool bvalue)
{

	CString str;
	int rt;
	CString strGetSync;
	int GetStr;
	do
	{
		rt = GetStatus(0);
		if (rt == -1)
		{
			//LOG("SerialError.txt","SetStatusGetStatus");
		}
	}
	while(rt == -1);

	if (bvalue)
	{
		rt|=(bvalue<<index);
	} 
	else
	{
		rt&= ~((!bvalue)<<index);
	}

	str = IntToStr(rt);
	int rtSetSync = 0;
	do 
	{
		rtSetSync = SetStatus(str);
		if (rtSetSync == 0)
		{
			//LOG("SerialError.txt","SetStatusSetStatus");
		}
	} while (!rtSetSync);

}

bool CSerialPort::SetStatus(CString str )
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return 0;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt;
	CString data;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WW;
	data = data + READDELAY;
	data = data + STATUS_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data = data + str;
	data.ReleaseBuffer();

	m_strComfirm.ReleaseBuffer();
	m_strComfirm = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	rt = WaitForSingleObject(m_hConfirmOver,RECVTIMEOUT);
	ResetEvent(m_hConfirmOver);
	LeaveCriticalSection(&m_csCharSync);

	if (rt == WAIT_OBJECT_0/* && m_strComfirm != ""*/)
	{
		////LOG("D:\\Get.txt",m_strComfirm);
		return true;
	} 
	else
	{
		return false;
	}

}
int CSerialPort::GetStatus(int index)
{
	if (m_hComm == INVALID_HANDLE_VALUE || m_hComm == NULL)
	{
		return -1;
	}

	EnterCriticalSection(&m_csCharSync);
	int rt = 0;
	char ch = 0;
	CString data;
	CString outString;
	data = (char)ENQ;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data = data + WR;
	data = data + READDELAY;
	data = data + STATUS_REG_ADDRESS;
	data = data + PLCIOSIZE;
	data.ReleaseBuffer();
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	WaitForSingleObject(m_hRecvOver,RECVTIMEOUT);

	if (m_strPLC == "")
	{
		return -1;
	}

	for (int i = 0; i < SYNC_RECV_LENGTH; i ++)
	{
		if( (SYNC_RECV_POS - i) > m_strPLC.GetLength() ) 
		{
			outString.Format("m_strPLC Length %d",m_strPLC.GetLength());
			//AfxMessageBox(outString);
			//AfxMessageBox(m_strPLC);
			m_strPLC.ReleaseBuffer();
			m_strPLC = "";
			return -1;
		}
		ch = m_strPLC.GetAt(SYNC_RECV_POS - i);
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - 48;
		} 
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}

		switch (i)
		{
		case 0:
			rt += ch;
			break;
		case 1:
			rt += ch * 16;
			break;
		case 2:
			rt += ch * 16 * 16;
			break;
		case 3:
			rt += ch * 16 * 16 * 16;
			break;
		}

	}
	m_strPLC.ReleaseBuffer();
	m_strPLC = "";

	//m_strPLC.ReleaseBuffer();
	data = (char)ACK;
	data = data + STATIONNUM;
	data = data + PCNUM;
	data.ReleaseBuffer();
	WriteToPort((char*)data.GetBuffer(),data.GetLength());
	ResetEvent(m_hRecvOver);
	LeaveCriticalSection(&m_csCharSync);

	return rt;
}
