#include "StdAfx.h"
#include "CwBirgerMount.h"




CwBirgerMount::CwBirgerMount(void)
{
	m_nMaxAperture = 0;
	m_nMaxAperture = 0;
}

CwBirgerMount::~CwBirgerMount(void)
{
	this->m_conLensPort.CloseSerialPort();
}

int CwBirgerMount::InitConnect(CWnd* pOwner,CString strComName)
{
	CString strCMD;
	char strRecieve[BIRGERMOUNTCMDLENGTH];
	//int nIsConnected(0);
	int nCountPort = 0;
	CHAR Name[255];
	UCHAR szPortName[255];
	LONG Status;
	DWORD dwIndex = 0;
	DWORD dwName;
	DWORD dwSizeofPortName;
	DWORD Type;
	HKEY hKey;
	CString   strSerialList[256];  // 临时定义 256 个字符串组，因为系统最多也就 256 个 
	LPCTSTR data_Set = "HARDWARE\\DEVICEMAP\\SERIALCOMM\\";
	dwName = sizeof(Name);
	dwSizeofPortName = sizeof(szPortName);

	//long ret0 = (::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey)); 
	long ret0 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey); //打开一个制定的注册表键,成功返回ERROR_SUCCESS即“0”值
	if (ret0 == ERROR_SUCCESS)
	{
		do
		{

			Status = RegEnumValue(hKey, dwIndex++, Name, &dwName, NULL, &Type, szPortName, &dwSizeofPortName);//读取键值 
			if ((Status == ERROR_SUCCESS) || (Status == ERROR_MORE_DATA))
			{
				strSerialList[nCountPort] = CString(szPortName);       // 串口字符串保存 
				TRACE("serial:%s\n", strSerialList[nCountPort]);

				nCountPort++;// 串口计数 
			}
			//每读取一次dwName和dwSizeofPortName都会被修改 
			//注意一定要重置,否则会出现很离奇的错误,本人就试过因没有重置,出现先插入串口号大的（如COM4）,再插入串口号小的（如COM3），此时虽能发现两个串口，但都是同一串口号（COM4）的问题，同时也读不了COM大于10以上的串口 
			dwName = sizeof(Name);
			dwSizeofPortName = sizeof(szPortName);
		} while ((Status == ERROR_SUCCESS) || (Status == ERROR_MORE_DATA));

		RegCloseKey(hKey);
	}

	char chTmp[1024];
	memset(chTmp, 0, 1024 * sizeof(char));
	
	this->m_conLensPort.rate = 115200;
	this->m_conLensPort.fparity = 0;
	this->m_conLensPort.bytesize = 8;
	this->m_conLensPort.stopbit = 0;
	for (int i = 0; i < nCountPort;i++)
	{
		memset(strRecieve, 0, BIRGERMOUNTCMDLENGTH);
		this->m_conLensPort.portName = strSerialList[i];
		if (!this->m_conLensPort.OpenSerialPort())
			continue;
		strCMD.Format("%s", chBirgerCmd[FUNC_CLEAR_ALL_LINK]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		strCMD.Format("%s", chBirgerCmd[FUNC_SET_NEWPROTOCOL]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		this->m_conLensPort.ReceiveData(strRecieve, BIRGERMOUNTCMDLENGTH);
		TRACE(strRecieve);
		/*int res = this->m_conLens.InitPort(pOwner,8,0,115200,'N',8,0);
		if (res)
		{
			this->m_conLens.StartMonitoring();
		}
		strCMD.Format("%s", chBirgerCmd[GET_VERSION]);
		this->m_conLens.Send(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();*/
		
		if (Find_string(strRecieve, chBirgerCmdReceive[BIRGERCMD_OK]) != -1)
		{
			nIsConnected = 1;
			break;
		}
		memset(strRecieve, 0, 256);
	}
	if (nIsConnected)
	{
		this->LearnFocus(0);
		this->DistanceStop();

	}
	

	
	//20161021 Mrl.wy 遍历端口，查找birger mount

	////	for (int i=0;i<nCountPort;i++)
	////	{
	//
	//
	//if (!this->m_conLensPort.InitPort(pOwner, strSerialList[2].GetBuffer(),115200,'N',8,ONESTOPBIT))
	//	return false;
	//this->m_conLensPort.StartMonitoring();
	//
	//Sleep(200);
	///*strCMD.Format(chBirgerCmd[FUNC_CLEAR_ALL_LINK]);

	//this->m_conLensPort.SendData(strCMD,strCMD.GetLength());
	//Sleep(1200);*/
	//strCMD.Format(chBirgerCmd[GET_VERSION]);
	//
	//this->m_conLensPort.SendData(strCMD,strCMD.GetLength());
	//Sleep(1200);
	////this->m_conLensPort.RecvData(strRecieve,256);
	//Sleep(1200);
	///*this->m_conLensPort.StopMonitoring();
	//Sleep(1000);*/
	//nIsConnected = 0;
	//for (int j=0;j<255;j++)
	//{
	//	if((strRecieve[j] == 'O')&&(strRecieve[j] == 'K'))
	//	{
	//		nIsConnected = 1;
	//		break;
	//	}
	//}
	//strSerialList[2].ReleaseBuffer();
	//this->m_conLensPort.ClearReadBuffer();
	///*	if (nIsConnected)
	//		return false;
	//		else
	//		this->m_conLensPort.ClosePort();*/
	////}
	return nIsConnected;
}


int CwBirgerMount::GetFocus(int &nFocus)
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, BIRGERMOUNTCMDLENGTH*sizeof(char));
	if (nIsConnected)
	{
		strCMD.Format("%s", chBirgerCmd[GET_FOCUS_POSITION]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		nFocus = atoi(chReceive);
		return nIsConnected;
	}
	return nIsConnected;
}

int CwBirgerMount::LearnFocus(int nType)
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, BIRGERMOUNTCMDLENGTH*sizeof(char));

	if (nIsConnected)
	{
		strCMD.Format("%s", chBirgerCmd[FUNC_LEARN_FOCUS]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		TRACE(chReceive);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);		
	}
	return nIsConnected;
}

int CwBirgerMount::SetFocus(const int& nFocus)
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, BIRGERMOUNTCMDLENGTH*sizeof(char));

	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[SET_FOCUS_ABOSLUTE_POSITION],nFocus);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		TRACE(chReceive);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;
}

int CwBirgerMount::SetFocusEH(const int& nFocus)
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);

	if (nIsConnected)
	{
		unsigned char checksum = 0;
		unsigned char i;
		unsigned int mask = 0x1000;
		for (i = 0; i < 4; i++)
		{
			checksum ^= (nFocus / mask);
			mask >>= 4;
		}
		checksum &= 0x0F;
		strCMD.Format(chBirgerCmd[SET_FOCUS_EHPOSITION], nFocus,checksum );
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		strCMD.Format(chBirgerCmd[GET_FOCUS_POSITION]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return atoi(chReceive);
	}
	return -20000;
}

int CwBirgerMount::InitAperture()
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);
	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[FUNC_INIT_APERTURE]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strlen(chBirgerCmd[FUNC_INIT_APERTURE]));
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;
}

int CwBirgerMount::FullCloseAperture()
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);
	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[SET_APERTURE_FULLOPEN]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;
}

int CwBirgerMount::FullOpenAperture()
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);
	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[SET_APERTURE_FULLOPEN]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;
}

int CwBirgerMount::GetAperture(int &nAper)
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);
	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[GET_APERTURE_POSITION]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return atoi(chReceive);
	}
	return nIsConnected;
}

int CwBirgerMount::GetApertureRange(int &nMin, int& nMax)
{
	this->FullCloseAperture();
	this->GetAperture(nMax);
	this->FullOpenAperture();
	this->GetAperture(nMin);
	this->m_nMaxAperture = nMax;
	this->m_nMinAperture = nMin;
	return 0;
}

int CwBirgerMount::SetAperture(const int& nAper)
{
	if (nAper<m_nMinAperture||nAper>m_nMaxAperture)
	{
		return -2;
	}
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, sizeof(char)*BIRGERMOUNTCMDLENGTH);
	if (nIsConnected)
	{
		strCMD.Format(chBirgerCmd[SET_FOCUS_ABOSLUTE_POSITION],nAper);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;
}
//20161027 take care use this cmd,overlapped cmd
int CwBirgerMount::DistanceStop()
{
	CString strCMD;
	char chReceive[BIRGERMOUNTCMDLENGTH];
	memset(chReceive, 0, BIRGERMOUNTCMDLENGTH*sizeof(char));

	if (nIsConnected)
	{
		strCMD.Format("%s", chBirgerCmd[FUNC_DISTANCESTOP]);
		this->m_conLensPort.SendData(strCMD.GetBuffer(), strCMD.GetLength());
		strCMD.ReleaseBuffer();
		Sleep(20);
		this->m_conLensPort.ReceiveData(chReceive, BIRGERMOUNTCMDLENGTH);
		TRACE(chReceive);
		return Find_string(chReceive, chBirgerCmdReceive[BIRGERCMD_DONE]);
	}
	return nIsConnected;

}

int CwBirgerMount::CloseConnected()
{
	this->m_conLensPort.CloseSerialPort();
	return 0;
}


int Find_string(const char* str1, const char* str2)
{
	int j = 0;
	if (strlen(str1) < strlen(str2))
		return -1;
	for (int i = 0; i < strlen(str1)-strlen(str2);i++)
	{
		while (j!=strlen(str2))
		{
			if (str1[i+j] != str2[j])
				break;
			++j;
		}
		if (j == strlen(str2))
			return i;
		j = 0;
	}
	return -1;
}