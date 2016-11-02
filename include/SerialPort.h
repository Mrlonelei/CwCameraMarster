
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

#define COM 1				//COM序号

#define IODELAY 200			//IO延时
#define STATIONS 2			//工作站总数

#define STX 0x02			//通信报文协议头
#define ENQ 0x05			//通信报文协议头
#define ACK 0x06			//通信报文协议头

#define STATIONNUM "01"		//工作站号，01指PLC

#define PCNUM "FF"			//上位机默认编号

#define BR "BR"				//按位读寄存器
#define BW "BW"				//按位写寄存器
#define WR "WR"				//按字读寄存器
#define WW "WW"				//按字写寄存器

#define READDELAY "5"		//读寄存器延时
#define WRITEDELAY "0"		//写寄存器延时

#define PLCIOSIZE "01"		//读写默认长度

#define ETX 0x03			//错误码通信报文标记

#define FAL 0x15			//错误码通信报文标记

											
#define STATUS_REG_ADDRESS		"D0000"		//状态寄存器（是否在线、是否异常、明确有几种异常）	位读位写 
											//完成置1，未完成置0
	#define PLCRUNNING			0		//PLC正常运行
	#define DDMOTORWARNING		1		//DD马达报警
	#define CAMMOTORWARNING		2		//相机伺服报警
	#define TAGMOTORWARNING		3		//贴标伺服报警
	#define SAFELIGHTWARNING	4		//安全光幕报警
	#define LOCKWARNING			5		//安全锁报警
	#define FATALERROR			6		//关键故障
	#define LABELWARNING		7		//吸签不成功

	#define PA1LOWWARNING		12		//正压过低报警
	#define PA1HIGHWARNING		13		//正压过高报警
	#define PA2LOWWARNING		14		//负压过低报警
	#define PA2HIGHWARNING		15		//负压过高报警

	#define AOIAWARNING			8		//AOI第1工位报警
	#define AOIBWARNING			9		//AOI第2工位报警
	#define FLICKAWARNING		10		//FLICK第1工位报警
	#define FLICKBWARNING		11		//FLICK第2工位报警

#define SYNC_REG_ADDRESS		"D0001"		//同步信息寄存器（同步信息量）读者不写 写着不读	位读位写 
											//完成置1，未完成置0
	#define AOIINITED			0		//AOI初始化完成
	#define FLICKINITED			1		//色彩分析仪初始化完成
	#define TAGINITED			2		//打印贴标机初始化完成
	#define AOIAFINISHED		3		//AOI第一工位检测完成 
	#define AOIBFINISHED		4		//AOI第二工位检测完成
	#define FLICKFINISHED		5		//色彩分析仪检测完成
	#define FLICKBFINISHED		6		//色彩分析仪检测完成
	#define TAGFINISHED			7		//打印贴标完成
	#define DDFINISHED			8		//DD马达旋转到位
	#define PREPARE				9		//开始准备

#define TAG_REG_ADDRESS			"D0004"		//贴标信息寄存器 位读位写 
	#define FIRSTPASTEONLY      0      //只贴第一块屏
	#define SECONDPASTEONLY     1      //只贴第二片屏
	#define TWOPASTEFIRST       2      //2屏都贴，First打印
	#define TWONOPASTE          3      //两个都不用贴标签
	#define PASTEFINISHED       5      //贴完
	#define RECVPASTEFINISHED   6      //收到贴完
	#define PRINTERERROR		7      //打印机异常
	#define CAMMOVE			    8      //相机焦距调整
	#define CHANGERMODE		    9      //模式切换

#define HB_REG_ADDRESS			"D0003"		//心跳包寄存器 位读位写 
	#define  HEARTBEAT			0      //心跳包
	
#define POS_REG_ADDRESS			"D0006"		//第一工位运动控制寄存器	字读字写
	#define TAGA_REG_ADDRESS	"D0005"		//贴标位置寄存器	字读字写
	#define TAGB_REG_ADDRESS	"D0006"
#define OK_REG_ADDRESS			"D0224"		//OK数寄存器	字读字写
#define NG_REG_ADDRESS			"D0222"		//NG数寄存器	字读字写
#define SUM_REG_ADDRESS			"D0230"		//总数寄存器	字读字写
#define PER_REG_ADDRESS			"D0232"		//良品率寄存器	字读字写
#define TT_REG_ADDRESS			"D0010"		//节拍寄存器	字读字写
#define TEST_REG_ADDRESS		"D0234"		//测试寄存器

#define RESERVE_REG_ADDRESS		"D0012"		//保留，未使用
	#define CAM_POS				1			//调整相机位置
	#define MOTION_OVER			2			//相机位置调整完成

#define SYNC_RECV_POS	8					//同步信号返回报文位置
#define SYNC_RECV_LENGTH 4					//同步信号返回报文字长
#define STATUS_RECV_POS	8					//状态信号返回报文字长
#define RECVTIMEOUT		3000				//一般超时
#define RECVTIMEOUT15	15000				//长超时

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

	//机器人项目私用，回调
	char *m_hOwnerChar;
	ROBOT_POWER_CALLBACK m_pfunc;
	void Robot_SetCallback(ROBOT_POWER_CALLBACK func, char *userPtr);

	//基本功能
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
	//贴标寄存器读写
	void SetPaste(int index,bool bvalue);
	bool SetSyncPaste(CString str );
	int GetSyncPaste(int index);

	///////////////////////////////////////////
	//心跳寄存器读写
	bool SetSyncHb(CString str );
	int GetSyncHb(int index);
	void SetPasteHeartBeat();
	
	//状态寄存器读写
	bool SetStatus(CString str );
	void SetStatus(int index,bool bvalue);
	int GetStatus(int index);
	
	//同步寄存器读写
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

	//设置生产信息
	bool SetTest(CString str );
	bool SetPos(CString str );
	bool SetTag(CString str );
	void SetTag(int index,bool bvalue);
	bool SetOK(CString str );
	bool SetNG(CString str );
	bool SetTT(CString str );
	bool SetSum(CString str );
	bool SetPar(CString str );

	//int转16进制字符串
	CString IntToStr(int rt);

	//
	CString	m_strPLC;			//接收到的读写信息
	CString	m_strComfirm;		//接收到的确认信息
	CString	m_strFALSE;			//接收到的错误信息
	HANDLE	m_hRecvOver;		//接收读写信息完成
	HANDLE	m_hConfirmOver;		//接收确认信息完成
	bool	m_bRecv;			//是否在接收读写信息
	bool	m_bConfirm;			//是否在接收确认信息
	bool	m_bHeartBeat;		//心跳包01状态

	//voyager
	DWORD m_SBput;
	DWORD m_SBget;
	CDataParser* m_pParser;

	CRITICAL_SECTION m_csCharSync;		//临界区

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


