
#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__
// #include "IPhy.h"
 //#include "LOG.h"
//#include "log.h"
class CDataParser
{
public:
	CDataParser(){};
	virtual ~CDataParser(){};
	virtual void RecvData(unsigned char inData){};
};

#define COM 1				//COM���

#define IODELAY 200			//IO��ʱ
#define STATIONS 2			//����վ����

#define STX 0x02			//ͨ�ű���Э��ͷ
#define ENQ 0x05			//ͨ�ű���Э��ͷ
#define ACK 0x06			//ͨ�ű���Э��ͷ

#define STATIONNUM "01"		//����վ�ţ�01ָPLC

#define PCNUM "FF"			//��λ��Ĭ�ϱ��

#define BR "BR"				//��λ���Ĵ���
#define BW "BW"				//��λд�Ĵ���
#define WR "WR"				//���ֶ��Ĵ���
#define WW "WW"				//����д�Ĵ���

#define READDELAY "5"		//���Ĵ�����ʱ
#define WRITEDELAY "0"		//д�Ĵ�����ʱ

#define PLCIOSIZE "01"		//��дĬ�ϳ���

#define ETX 0x03			//������ͨ�ű��ı��

#define FAL 0x15			//������ͨ�ű��ı��

											
#define STATUS_REG_ADDRESS		"D0000"		//״̬�Ĵ������Ƿ����ߡ��Ƿ��쳣����ȷ�м����쳣��	λ��λд 
											//�����1��δ�����0
	#define PLCRUNNING			0		//PLC��������
	#define DDMOTORWARNING		1		//DD��ﱨ��
	#define CAMMOTORWARNING		2		//����ŷ�����
	#define TAGMOTORWARNING		3		//�����ŷ�����
	#define SAFELIGHTWARNING	4		//��ȫ��Ļ����
	#define LOCKWARNING			5		//��ȫ������
	#define FATALERROR			6		//�ؼ�����
	#define LABELWARNING		7		//��ǩ���ɹ�

	#define PA1LOWWARNING		12		//��ѹ���ͱ���
	#define PA1HIGHWARNING		13		//��ѹ���߱���
	#define PA2LOWWARNING		14		//��ѹ���ͱ���
	#define PA2HIGHWARNING		15		//��ѹ���߱���

	#define AOIAWARNING			8		//AOI��1��λ����
	#define AOIBWARNING			9		//AOI��2��λ����
	#define FLICKAWARNING		10		//FLICK��1��λ����
	#define FLICKBWARNING		11		//FLICK��2��λ����

#define SYNC_REG_ADDRESS		"D0001"		//ͬ����Ϣ�Ĵ�����ͬ����Ϣ�������߲�д д�Ų���	λ��λд 
											//�����1��δ�����0
	#define AOIINITED			0		//AOI��ʼ�����
	#define FLICKINITED			1		//ɫ�ʷ����ǳ�ʼ�����
	#define TAGINITED			2		//��ӡ�������ʼ�����
	#define AOIAFINISHED		3		//AOI��һ��λ������ 
	#define AOIBFINISHED		4		//AOI�ڶ���λ������
	#define FLICKFINISHED		5		//ɫ�ʷ����Ǽ�����
	#define FLICKBFINISHED		6		//ɫ�ʷ����Ǽ�����
	#define TAGFINISHED			7		//��ӡ�������
	#define DDFINISHED			8		//DD�����ת��λ
	#define PREPARE				9		//��ʼ׼��

#define TAG_REG_ADDRESS			"D0004"		//������Ϣ�Ĵ��� λ��λд 
	#define FIRSTPASTEONLY      0      //ֻ����һ����
	#define SECONDPASTEONLY     1      //ֻ���ڶ�Ƭ��
	#define TWOPASTEFIRST       2      //2��������First��ӡ
	#define TWONOPASTE          3      //��������������ǩ
	#define PASTEFINISHED       5      //����
	#define RECVPASTEFINISHED   6      //�յ�����
	#define PRINTERERROR		7      //��ӡ���쳣
	#define CAMMOVE			    8      //����������
	#define CHANGERMODE		    9      //ģʽ�л�

#define HB_REG_ADDRESS			"D0003"		//�������Ĵ��� λ��λд 
	#define  HEARTBEAT			0      //������
	
#define POS_REG_ADDRESS			"D0006"		//��һ��λ�˶����ƼĴ���	�ֶ���д
	#define TAGA_REG_ADDRESS	"D0005"		//����λ�üĴ���	�ֶ���д
	#define TAGB_REG_ADDRESS	"D0006"
#define OK_REG_ADDRESS			"D0224"		//OK���Ĵ���	�ֶ���д
#define NG_REG_ADDRESS			"D0222"		//NG���Ĵ���	�ֶ���д
#define SUM_REG_ADDRESS			"D0230"		//�����Ĵ���	�ֶ���д
#define PER_REG_ADDRESS			"D0232"		//��Ʒ�ʼĴ���	�ֶ���д
#define TT_REG_ADDRESS			"D0010"		//���ļĴ���	�ֶ���д
#define TEST_REG_ADDRESS		"D0234"		//���ԼĴ���

#define RESERVE_REG_ADDRESS		"D0012"		//������δʹ��
	#define CAM_POS				1			//�������λ��
	#define MOTION_OVER			2			//���λ�õ������

#define SYNC_RECV_POS	8					//ͬ���źŷ��ر���λ��
#define SYNC_RECV_LENGTH 4					//ͬ���źŷ��ر����ֳ�
#define STATUS_RECV_POS	8					//״̬�źŷ��ر����ֳ�
#define RECVTIMEOUT		3000				//һ�㳬ʱ
#define RECVTIMEOUT15	15000				//����ʱ

#define WM_COMM_BREAK_DETECTED		WM_USER+1	// A break was detected on input.
#define WM_COMM_CTS_DETECTED		WM_USER+2	// The CTS (clear-to-send) signal changed state. 
#define WM_COMM_DSR_DETECTED		WM_USER+3	// The DSR (data-set-ready) signal changed state. 
#define WM_COMM_ERR_DETECTED		WM_USER+4	// A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. 
#define WM_COMM_RING_DETECTED		WM_USER+5	// A ring indicator was detected. 
#define WM_COMM_RLSD_DETECTED		WM_USER+6	// The RLSD (receive-line-signal-detect) signal changed state. 
#define WM_COMM_RXCHAR				WM_USER+7	// A character was received and placed in the input buffer.  
#define WM_COMM_RXFLAG_DETECTED		WM_USER+8	// The event character was received and placed in the input buffer.  
#define WM_COMM_TXEMPTY_DETECTED	WM_USER+9	// The last character in the output buffer was sent.  

#define WM_COMM_RXCHAR_FROMPLC		WM_USER+10	// A character was received and placed in the input buffer. 
#define WM_COMM_RXCHAR_FROMFLICKA	WM_USER+11	// A character was received and placed in the input buffer.
#define WM_COMM_RXCHAR_FROMFLICKB	WM_USER+12	// A character was received and placed in the input buffer.
#define WM_COMM_RXCHAR_FROMTAG		WM_USER+13	// A character was received and placed in the input buffer.

typedef char (__stdcall *ROBOT_POWER_CALLBACK)(char *power);


class CSerialPort /*: public IPhy*/
{														 
public:

	//��������Ŀ˽�ã��ص�
	char *m_hOwnerChar;
	ROBOT_POWER_CALLBACK m_pfunc;
	void Robot_SetCallback(ROBOT_POWER_CALLBACK func, char *userPtr);

	//��������
	BOOL Create(CWnd* pPortOwner,int inCom,int portindex,int BaudRate);
	void SetParser(CDataParser* inParser);
	void SigWrite();
	BOOL Create(CWnd* pPortOwner,int inCom);
	void Send(const void *pBuffer, const int iLength);
	void ClosePort();
	int m_nWriteSize; 

	// contruction and destruction
	CSerialPort();
	virtual		~CSerialPort();

	// port initialisation											
	BOOL		InitPort(CWnd* pPortOwner, UINT portnr, UINT  portindex,UINT baud = 9600, char parity = 'N', UINT databits = 8, UINT stopbits = 1, DWORD dwCommEvents = EV_RXCHAR, UINT writebuffersize = 128);
	HANDLE				m_hComm;
	UINT				m_nPortIndex;

	// start/stop comm watching
	BOOL		StartMonitoring();
	BOOL		RestartMonitoring();
	BOOL		StopMonitoring();

	DWORD		GetWriteBufferSize();
	DWORD		GetCommEvents();
	DCB			GetDCB();

	void		WriteToPort(char* string);
	void		WriteToPort(char* string,int n);
	void		WriteToPort(LPCTSTR string);
	void		WriteToPort(LPCTSTR string,int n);

	///////////////////////////////////////////
	//����Ĵ�����д
	void SetPaste(int index,bool bvalue);
	bool SetSyncPaste(CString str );
	int GetSyncPaste(int index);

	///////////////////////////////////////////
	//�����Ĵ�����д
	bool SetSyncHb(CString str );
	int GetSyncHb(int index);
	void SetPasteHeartBeat();
	
	//״̬�Ĵ�����д
	bool SetStatus(CString str );
	void SetStatus(int index,bool bvalue);
	int GetStatus(int index);
	
	//ͬ���Ĵ�����д
	int GetSync(int index);
	int GetSyncReserve(int index);
	bool SetSync(CString str );
	bool SetSyncReserve(CString str );

	void SetCamPosSync(int index,bool bvalue);
	void SetAOISync(int index,bool bvalue);
	void SetFlickSync(int index,bool bvalue);
	void SetTagSync(bool bvalue);
	void SetAOIInitSync(int index,bool bvalue);
	void SetFlickInitSync(bool bvalue);
	void SetTagInitSync(bool bvalue);
	void SetPrepareSync(bool bvalue);

	//����������Ϣ
	bool SetTest(CString str );
	bool SetPos(CString str );
	bool SetTag(CString str );
	void SetTag(int index,bool bvalue);
	bool SetOK(CString str );
	bool SetNG(CString str );
	bool SetTT(CString str );
	bool SetSum(CString str );
	bool SetPar(CString str );

	//intת16�����ַ���
	CString IntToStr(int rt);

	//
	CString	m_strPLC;			//���յ��Ķ�д��Ϣ
	CString	m_strComfirm;		//���յ���ȷ����Ϣ
	CString	m_strFALSE;			//���յ��Ĵ�����Ϣ
	HANDLE	m_hRecvOver;		//���ն�д��Ϣ���
	HANDLE	m_hConfirmOver;		//����ȷ����Ϣ���
	bool	m_bRecv;			//�Ƿ��ڽ��ն�д��Ϣ
	bool	m_bConfirm;			//�Ƿ��ڽ���ȷ����Ϣ
	bool	m_bHeartBeat;		//������01״̬

	//voyager
	DWORD m_SBput;
	DWORD m_SBget;
	CDataParser* m_pParser;

	CRITICAL_SECTION m_csCharSync;		//�ٽ���

protected:
	// protected memberfunctions
	void		ProcessErrorMessage(char* ErrorText);
	static UINT	CommThread(LPVOID pParam);
	static UINT	CommThread1(LPVOID pParam);
	static void	ReceiveChar(CSerialPort* port, COMSTAT comstat);
	static void	WriteChar(CSerialPort* port);

	// thread
	CWinThread*			m_Thread;
	CWinThread*			m_Thread1;

	// synchronisation objects
	CRITICAL_SECTION	m_csCommunicationSync;
	BOOL				m_bThreadAlive;

	// handles
	HANDLE				m_hWriteEvent;
	HANDLE				m_hShutdownEvent;

	
	// Event array. 
	// One element is used for each event. There are two event handles for each port.
	// A Write event and a receive character event which is located in the overlapped structure (m_ov.hEvent).
	// There is a general shutdown when the port is closed. 
	HANDLE				m_hEventArray[3];

	// structures
	OVERLAPPED			m_ov;
	COMMTIMEOUTS		m_CommTimeouts;
	DCB					m_dcb;

	// owner window
	CWnd*				m_pOwner;

	// misc
	UINT				m_nPortNr;
	char*				m_szWriteBuffer;
	DWORD				m_dwCommEvents;
	DWORD				m_nWriteBufferSize;
	 
};

#endif __SERIALPORT_H__


