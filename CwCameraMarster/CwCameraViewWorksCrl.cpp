#include "StdAfx.h"
#include "CwCameraViewWorksCrl.h"
#include "EnumSerial.h"


int CCwCameraViewWorksCrl::Find_string(const char* str1, const char* str2)
{
	int j = 0;
	if (strlen(str1) < strlen(str2))
		return -1;
	for (int i = 0; i < strlen(str1) - strlen(str2); i++)
	{
		while (j != strlen(str2))
		{
			if (str1[i + j] != str2[j])
				break;
			++j;
		}
		if (j == strlen(str2))
			return i;
		j = 0;
	}
	return -1;
}

CCwCameraViewWorksCrl::CCwCameraViewWorksCrl(void)
{
}

CCwCameraViewWorksCrl::~CCwCameraViewWorksCrl(void)
{
}

bool CCwCameraViewWorksCrl::initCameraViewWorksCrl(CWnd* powner,CString portName)
{
	char chFriendlyName[256];
	memset(chFriendlyName, 0, 256 * sizeof(char));
	GetPrivateProfileString(
		"SerialPort",
		"strFriendlyName",
		"Matrox Solios Camera Link Com Port 0",
		chFriendlyName,
		sizeof(chFriendlyName),
		"CameraConfig.ini");

	int nSerialPortNum(0);
	CString strSerialList[256];
	CArray<SSerInfo, SSerInfo&> asi;
	EnumSerialPorts(asi, false);
	nSerialPortNum = asi.GetSize();
	char chReceive[VIEWWORKSCMDLENGTH];
	int iFirst, iCount;
	for (int i = 0; i < asi.GetSize(); i++)
	{
		CString str = asi[i].strFriendlyName;
		if (str.Find(chFriendlyName) != -1)
		{
			TRACE(str);
			iFirst = asi[i].strFriendlyName.Find("(")+1;
			iCount = asi[i].strFriendlyName.Find(")") - iFirst;
			this->m_ConCameraPort.portName = asi[i].strFriendlyName.Mid(iFirst,iCount);
			TRACE(m_ConCameraPort.portName);
			this->m_ConCameraPort.rate = 19200;
			this->m_ConCameraPort.fparity = 0;
			this->m_ConCameraPort.bytesize = 8;
			this->m_ConCameraPort.stopbit = 0;
			if (this->m_ConCameraPort.OpenSerialPort())
				return false;
			CString strCMD;
			strCMD.Format(chViewWorksCmd[GET_MODEL_NAME]);
			TRACE(strCMD);
			this->m_ConCameraPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
			strCMD.ReleaseBuffer();
			memset(chReceive, 0, sizeof(char)*VIEWWORKSCMDLENGTH);
			this->m_ConCameraPort.ReceiveData(chReceive, VIEWWORKSCMDLENGTH,500);
			TRACE(chReceive);
			/*if (Find_string(chReceive, chViewWorksCmdReceive[VIEWWORKSCMD_OK]) == -1)
				return false;*/
			return true;
		}

	}

	// 获得可用的端口数目(serial RS232 )
	AfxMessageBox("Camera port Matrox Solios Camera Link Com Port 0");
	return false;
}

bool CCwCameraViewWorksCrl::ClosePort()
{
	return this->m_ConCameraPort.CloseSerialPort();
}