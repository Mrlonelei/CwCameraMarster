
#pragma once

#include "afx.h"

#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <conio.h>
#include "string.h"
//#include "CwMFCComFunc.h"
//#include "CwGlobalFunc.h"

class CwSerialPort;

class CwSerialPort
{

public:
/*
* �������ܣ����캯����������ݵĳ�ʼ��������
* ���������-��
* ���������-��
* �� �� ֵ��-��
*/
	CwSerialPort(void);


/*
* �������ܣ�����������������ݵ��ͷŹ�����
* ���������-��
* ���������-��
* �� �� ֵ��-��
*/
	~CwSerialPort(void);


/*
* �������ܣ���ָ��·����ȡ�����ļ�����ȡ�����ڣ������ʣ�У��λ������λ��ֹͣλ��������ݡ�
* ���������strPath�������ļ��洢·����
* ���������-��
* �� �� ֵ�����������Ƿ�ɹ���
*/
	bool LoadConfig(CString strPath);



/*
* �������ܣ��ú�����ɴ򿪴��ڹ��ܡ�
* ���������-��
* ���������-��
* �� �� ֵ�������Ƿ��ܳɹ��򿪡�
*/
	bool OpenSerialPort(void);



/*
* �������ܣ��ú�����ɹرմ��ڹ��ܡ�
* ���������-��
* ���������-��
* �� �� ֵ�������Ƿ��ܳɹ��رա�
*/
	bool CloseSerialPort(void);



/*
* �������ܣ��ú��������ָ������������ָ����С�����ݡ�
* ���������dataBuffer���������ݵ��׵�ַ��dataLength�������ݵĳ��ȡ�
* ���������-��
* �� �� ֵ�������ܷ�ɹ����͡�
*/
	bool SendData(char *dataBuffer,size_t dataLength); 



/*
* �������ܣ��ú�����ɴ�ָ������������ָ����С�����ݡ�
* ���������dataBuffer���������ݵ�Ŀ�껺�����׵�ַ��dataLength�������ݵĳ��ȡ�
* ���������-��
* �� �� ֵ�������ܷ�ɹ����ա�
*/
	bool ReceiveData(char *dataBuffer, size_t dataLength,int TimeOut); 

/*
* �������ܣ��ú�����ɴ��ڲ����ʣ�У��λ������λ��ֹͣλ����ز��������á�
* ���������rate�������ʣ�stopbit��ֹͣλ��parity��У��λ��bytesize������λ��
* ���������-��
* �� �� ֵ�������ܷ�ɹ����á�
*/
	bool SetUpSerialPort(int rate, int stopbit, int parity, int bytesize);


public:

	CString AbsolutePath = _T("E:\\MFC_Project\\Cw_MfcSerialPort\\Cw_MfcSerialPort\\ConfigFile.ini");
	HANDLE hComm;
	OVERLAPPED m_ov;
	COMSTAT comstat;

	//CString AbsolutePath;
	CString portName;
	int rate;
	int stopbit;
	//char* fparity;
	int fparity;
	int bytesize;

	//CString portName = "com3";
	//int rate = 9600;
	//int stopbit = ONESTOPBIT;
	//int fparity = 0;
	//int bytesize = 8;

};