#pragma once
#include "CwSerialPort.h"
#include "SerialPort.h"
#define MAXFOCUSCOUNT 16384
#define MINFOCUSCOUNT 0
#define BIRGERMOUNTCMDLENGTH 256

enum{
	GET_VERSION,
	GET_FOCUS_POSITION,
	GET_APERTURE_POSITION,

	SET_FOCUS_ZERO,
	SET_FOCUS_INFINITY,
	SET_FOCUS_ABOSLUTE_POSITION,
	SET_FOCUS_EHPOSITION,
	SET_APERTURE_FULLCLOSE,
	SET_APERTURE_FULLOPEN,
	SET_APERTURE_ABSOLUTE_POSITION,

	FUNC_LEARN_FOCUS,
	FUNC_INIT_APERTURE,
	FUNC_SET_NEWPROTOCOL,
	FUNC_CLEAR_ALL_LINK,
	FUNC_DISTANCESTOP,

	
	BIRGERMOUNTCMDNUM

};

enum{
	BIRGERCMD_DONE,
	BIRGERCMD_OK,
	BIRGERCMD_ERR,
	BIRGERMOUNTCMDRECEIVENUM
};

const char chBirgerCmd[BIRGERMOUNTCMDNUM][BIRGERMOUNTCMDLENGTH] = {
	{ "lv\r\n" },	//GET_VERSION
	{ "pf\r\n" },	//GET_FOCUS_POSITION
	{ "pa\r\n" },	//GET_APERTURE_POSITION
	{ "mz\r\n" },	//SET_FOCUS_ZERO
	{ "mi\r\n" },	//SET_FOCUS_INFINITY
	{ "fa%d\r\n" },	//SET_FOCUS_ABOSLUTE_POSITION  
	{ "eh%04x,%x\r\n"}, //SET_FOCUS_EHPOSITION
	{ "mc\r\n" },	//SET_APERTURE_FULLCLOSE
	{ "mo\r\n" },	//SET_APERTURE_FULLOPEN
	{ "ma%d\r\n" },	//SET_APERTURE_ABSOLUTE_POSITION
	{ "la\r\n" },	//FUNC_LEARN_FOCUS
	{ "in\r\n" },	//FUNC_INIT_APERTURE
	{ "rm0,1\r\n" },	//FUNC_SET_NEWPROTOCOL
	{ "routeesc,0\r\n" },	//FUNC_CLEAR_ALL_LINK
	{ "ds\r\n" }			//FUNC_DISTANCESTOP
};

const char chBirgerCmdReceive[BIRGERMOUNTCMDRECEIVENUM][BIRGERMOUNTCMDLENGTH] = {
	{ "DONE" },		//BIRGERCMD_DONE
	{ "OK" },			//BIRGERCMD_OK
	{ "ERR" }		//BIRGERCMD_ERR
};

class CwBirgerMount
{
private:
	//CwSerialPortCamera m_conLensPort;
	CwSerialPort m_conLensPort;
	//CSerialPort m_conLens;
	int nIsConnected;
	HANDLE hReceiveThread;
	int m_nMinAperture;
	int m_nMaxAperture;
public:
	CwBirgerMount(void);
	virtual ~CwBirgerMount(void);
	int InitConnect(CWnd* pOwner,CString strComName);

	int InitAperture();
	int LearnFocus(int type = 0);
	int FullOpenAperture();
	int FullCloseAperture();

	int GetFocus(int &nFocus);
	int GetAperture(int &nAper);
	int GetFocusRange(int &nMin,int&nMax);
	int GetApertureRange(int &nMin,int& nMax);


	int DistanceStop();
	int SetFocus(const int& nFocus);
	int SetFocusEH(const int& nFocus);
	int SetAperture(const int& nAper);
	int GetIsConnected();

	int CloseConnected();
};
int Find_string(const char* str1, const char* str2);