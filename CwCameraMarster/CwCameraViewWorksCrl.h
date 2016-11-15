#pragma once
#include "CwSerialPort.h"
#define MAXEXPCOUNT 1000
#define MINEXPCOUNT 0
#define VIEWWORKSCMDLENGTH 256

enum{
	SET_DATA_BIT,
	SET_EXPOSURE_TIME,
	GET_EXPOSURE_TIME,
	GET_MODEL_NAME,
	VIEWWORKSCMDNUM

};

enum{
	VIEWWORKSCMD_DONE,
	VIEWWORKSCMD_OK,
	VIEWWORKSCMD_ERR,
	VIEWWORKSCMDRECEIVENUM
};

const char chViewWorksCmd[VIEWWORKSCMDNUM][VIEWWORKSCMDLENGTH] = {
	{ "sdb %d\r\n" },	//GET_VERSION
	{ "set %d\r\n" },	//GET_FOCUS_POSITION
	{ "get\r\n" },	//GET_APERTURE_POSITION
	{"gmn\r\n"}		//GET_MODEL_NAME
	
};

const char chViewWorksCmdReceive[VIEWWORKSCMDRECEIVENUM][VIEWWORKSCMDLENGTH] = {
	{ "DONE" },		//BIRGERCMD_DONE
	{ "OK" },			//BIRGERCMD_OK
	{ "ERR" }		//BIRGERCMD_ERR
};
class CCwCameraViewWorksCrl
{
private:
	CwSerialPort m_ConCameraPort;
public:
	CCwCameraViewWorksCrl(void);
	virtual ~CCwCameraViewWorksCrl(void);
	bool initCameraViewWorksCrl(CWnd* powner,CString portName);
	bool GetShutter(int& iShutter);// 20161020 Mrl.wy  读取曝光值
	bool SetShutter(const int nShutter); //20161020 Mrl.wy 设置曝光值
	int Find_string(const char* str1, const char* str2);
	bool ClosePort();
};
