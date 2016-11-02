
#include "stdafx.h"

#include "CwSerialPort.h"


CwSerialPort::CwSerialPort()
{
}

CwSerialPort::~CwSerialPort()
{
}

//配置串口

bool CwSerialPort::LoadConfig(CString strPath)
{
	char chTmp[256];
	CString path = strPath;
	GetPrivateProfileString(_T("SerialPort"), _T("serialport"), "",chTmp,5,path);
	portName = _T(chTmp);
	rate = GetPrivateProfileInt(_T("SerialPort"), _T("rate"), 115200, path);
	stopbit = GetPrivateProfileInt(_T("SerialPort"), _T("stopbit"),0 ,path);
	fparity = GetPrivateProfileInt(_T("SerialPort"), _T("fparity"),0, path);
	bytesize = GetPrivateProfileInt(_T("SerialPort"), _T("bytesize"),8 ,path);
	return true;
}

//打开串口
bool CwSerialPort::OpenSerialPort(void)
{

	//portname串口的获取
	hComm = CreateFile(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING,
		FILE_FLAG_OVERLAPPED,
		0);
	if (hComm == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	
	m_ov.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	if (!SetUpSerialPort(rate,stopbit,fparity,bytesize))
	{
		printf("setup serialport wrong!\n");
		return true;
	}

	return true;
}

//配置串口
bool CwSerialPort::SetUpSerialPort(int rate,int stopbit,int fparity,int bytesize)
{
	DCB dcb;

	memset(&dcb, 0, sizeof(dcb));
	if (!GetCommState(hComm, &dcb))//获取当前DCB配置
	{
		printf("Get CommState wrong!\n");
		return FALSE;
	}

	dcb.BaudRate = rate;
	//dcb.Parity = NOPARITY;
	dcb.fParity = fparity;
	dcb.StopBits = stopbit;
	dcb.ByteSize = bytesize;
	
	// set DCB
	if (!SetCommState(hComm, &dcb))
	{
		auto A = GetLastError();
		printf("Set CommState wrong!\n");
		return false;
	}
	else
	{
		printf("Set CommState success!\n");
		return true;
	}
		//printf("Set CommState wrong!\n");
		//return true;

}

//关闭串口
bool CwSerialPort::CloseSerialPort(void)
{
	if (CloseHandle(hComm))
		return true;
	else
		return false;
}

//发送数据
bool CwSerialPort::SendData(char *dataBuffer, size_t dataLength) 
{
	BOOL bWrite = TRUE;
	BOOL bResult = TRUE;
	char *writebuffer = dataBuffer;
	DWORD BytesSent = dataLength;
	//HANDLE m_hWriteEvent;
	//ResetEvent(m_hWriteEvent);
	if (bWrite)
	{
		m_ov.Offset = 0;
		m_ov.OffsetHigh = 0;
		// Clear buffer
		bResult = WriteFile(CwSerialPort::hComm,             // Handle to COMM Port
			writebuffer, // Pointer to message buffer in calling finction
			dataLength,                      // Length of message to send
			&BytesSent,         //BytesSent Where to store the number of bytes sent
			&m_ov);                    // Overlapped structure
		if (!bResult)// bResult = wrong
		{
			printf("send data wrong!\n");
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
				//printf("here2\n");
				return false;
			}
			}
		}
	} // end if(bWrite)
	if (!bWrite)
	{
		bWrite = TRUE;
		bResult = GetOverlappedResult(hComm,   // Handle to COMM port
			&m_ov,     // Overlapped structure
			&BytesSent,    // Stores number of bytes sent
			TRUE);         // Wait flag

		// deal with the error code
		if (!bResult)
		{
			//ProcessErrorMessage("GetOverlappedResults() in WriteFile()");
		}
	} // end if (!bWrite)

	// Verify that the data size send equals what we tried to send
	if (BytesSent != dataLength)
	{
		printf("WARNING: WriteFile() error.. Bytes Sent: %d; Message Length: %d\n", BytesSent, strlen((char*)dataBuffer));
	}
	printf("%ld\n", BytesSent);
	return true;

}

//接收数据
bool CwSerialPort::ReceiveData(char *dataBuffer, size_t dataLength)
{
	BOOL bRead = TRUE;
	BOOL bResult = TRUE;
	DWORD dwError = 0;
	DWORD BytesRead = 0;
	char *RXBuff = dataBuffer;
	for (;;)
	{
		Sleep(20);
		bResult = ClearCommError(hComm, &dwError, &comstat);
		if (comstat.cbInQue == 0)
			continue;
		if (bRead)
		{
			bResult = ReadFile(hComm,      // Handle to COMM port
				RXBuff,             // RX Buffer Pointer
				dataLength,                   // Read one byte
				&BytesRead,          // Stores number of bytes read
				&m_ov);      // pointer to the m_ov structure
			WaitForSingleObject(m_ov.hEvent, INFINITE);
			printf("%s", RXBuff);
			if (!bResult)
			{
				switch (dwError = GetLastError())
				{
				case ERROR_IO_PENDING:
				{
					bRead = FALSE;
					break;
				}
				default:
				{
					break;
				}
				}
			}
			else
			{
				bRead = TRUE;
			}
		} // close if (bRead)
		if (!bRead)
		{
			bRead = TRUE;
			bResult = GetOverlappedResult(hComm,  // Handle to COMM port
				&m_ov,      // Overlapped structure
				&BytesRead,    // Stores number of bytes read
				TRUE);          // Wait flag
		}
		return true;
	}
}

