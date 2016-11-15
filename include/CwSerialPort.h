
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
* 函数介绍：构造函数，完成数据的初始化工作。
* 输入参数：-。
* 输出参数：-。
* 返 回 值：-。
*/
	CwSerialPort(void);


/*
* 函数介绍：析构函数，完成数据的释放工作。
* 输入参数：-。
* 输出参数：-。
* 返 回 值：-。
*/
	~CwSerialPort(void);


/*
* 函数介绍：从指定路径读取配置文件，获取到串口，波特率，校验位，数据位，停止位等相关数据。
* 输入参数：strPath：配置文件存储路径。
* 输出参数：-。
* 返 回 值：串口配置是否成功。
*/
	bool LoadConfig(CString strPath);



/*
* 函数介绍：该函数完成打开串口功能。
* 输入参数：-。
* 输出参数：-。
* 返 回 值：串口是否能成功打开。
*/
	bool OpenSerialPort(void);



/*
* 函数介绍：该函数完成关闭串口功能。
* 输入参数：-。
* 输出参数：-。
* 返 回 值：串口是否能成功关闭。
*/
	bool CloseSerialPort(void);



/*
* 函数介绍：该函数完成向指定缓冲区发送指定大小的数据。
* 输入参数：dataBuffer，发送数据的首地址；dataLength发送数据的长度。
* 输出参数：-。
* 返 回 值：数据能否成功发送。
*/
	bool SendData(char *dataBuffer,size_t dataLength); 



/*
* 函数介绍：该函数完成从指定缓冲区发送指定大小的数据。
* 输入参数：dataBuffer，接收数据的目标缓冲区首地址；dataLength发送数据的长度。
* 输出参数：-。
* 返 回 值：数据能否成功接收。
*/
	bool ReceiveData(char *dataBuffer, size_t dataLength,int TimeOut); 

/*
* 函数介绍：该函数完成串口波特率，校验位，数据位，停止位等相关参数的配置。
* 输入参数：rate，波特率；stopbit，停止位；parity，校验位；bytesize，数据位。
* 输出参数：-。
* 返 回 值：串口能否成功配置。
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