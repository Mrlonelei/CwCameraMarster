/************************************************************************/
/* Copyright (c) 2012,   北京兆维
/* All rights reserved.													
/*																		
/* 文件名称： CwCamera.h												
/* 摘要：利用SOLIOS板卡控制SVS相机采集图像动态库.
/* 作者：邹伟金
/* V1.0
/* 
/*增加：SetFocus(int)(设置焦距)、SetAperture(int)(设置光圈位置)两个函数
/*作者：彭荣华
/*时间：2014年3月27日
/*版本号: V2.0
/*使用方法:1、设置相机配置文件路径：SetFilePath(CString),参数为相机配置文件路径
/*         2、初始化相机：InitCamera(CWnd* pParent=NULL,bool IsMilShow=false,int iIndex=0)
/*            第一个参数指定使用相机类的窗口的父窗口指针，第二个参数指定是否显示图像，第三个参数指定板卡的索引
/*         3、SetOwner(void* MainFrm,ImageGrabbedCallback MainDisplayCallback)
/*            第一个参数指定使用相机类的主程序指针，第二个参数是回调函数入口
/*         4、调用功能函数，比如SetFocus(int)等
/*使用范例: m_CwCamera.SetFilePath("C://hr29050MFLCPC_8bit4taps_SoliosXCL_con.dcf");   
/*			m_CwCamera.InitCamera(NULL,0);
/*			m_CwCamera.SetOwner(this,GrabDisplayCallBack);
/*			m_CwCamera.SetFocus(600);
/*
/************************************************************************/
#ifndef CWCAMERA_DLL_H
#define CWCAMERA_DLL_H
#include "mil.h"
#include "ConvCam40DllApi.h"
//#ifdef CW_CAMERA_CPP
//#define CW_CAMERA_API __declspec(dllexport)
//#else 
//#define CW_CAMERA_API __declspec(dllimport)
//#endif
#define PICNUM				1
#define CAMLINKALL			6


typedef void (*ImageGrabbedCallback)(void* pOwner, BYTE* pImgData);
class __declspec(dllexport) CwCamera
{
public:
   CwCamera();
   ~CwCamera(); 
   bool SetFilePath(const CString strPath); //设置相机系统dcf文件路径
   bool InitCamera(CWnd* pParent=NULL,bool IsMilShow=false,int iIndex=0); //根据索引初始化相机，iIndex为板卡的索引
   void SetdispPan(double dXOffSet,double dYOffSet); //设置图像偏移，Mil显示时可用 
   void SetOwner(void* MainFrm,ImageGrabbedCallback MainDisplayCallback);
   void Grab(); //连续采集图像,Mil显示时可用
   void Stop(); //停止连续采集,连续采集时用
   bool GrabImage(); //开辟线程采集图像
   bool Freeze(); //停止线程采集
   void Snap(); //单帧采集图像  
   bool SetShutter(int iShutter); //设置曝光时间,单位为us,最小值为10，最大值为7000000
   bool SetFocus(int focus); //设置焦距位置，最小值为0,最大值为16383
   bool SetAperture(int Aperture); //设置光圈位置，最小值为0,最大值为63

   bool GetShutter(int& iShutter);// 20160705 Mrl.wy  读取曝光值
   bool GetFocus(int& nFocus);//20160705 Mrl.wy 读取焦距值		
   bool GetAperture(int& nAperture);//20160705 Mrl.wy 读取光圈值

   bool SetGainLeft(int iGain); //设置左增益，单位为dB，最小值为0，最大值为899
   long GetImgWidth(){return m_lWidth;} //获取图像宽度
   long GetImgHeight(){return m_lHeight;} //获取图像高度
   long GetImgPitch(){return m_lPitch;}   //获取图像的Pitch
   long GetChannalBit(){return m_Sizebit;} //获取图像单通道的位数
   void GetImgBuffer(unsigned char **ImageBuffer); //单帧采集时，获取图像的buffer
   void Zoom(double dXFactor,double dYFactor); //Mil显示时可用
   void SaveImage(CString strPath); //存储图像，将图像存储到指定路径
   void Destory(); //释放相机
private:
    //------------------Mil Function---------------------//
    bool MilCreate(int iIndex);
    bool MilDestroy();
	bool InitSvsCamera(); //初始化SVS相机，成功返回true，失败返回false
	void DestorySvsCamera(); //释放SVS相机
    CString SendCLCommand(char * TestString , bool feedback,int iIndex=0);//发送串口命令
private:
   long m_lWidth; //图像的宽度
   long m_lHeight; //图像的高度
   long m_lPitch; //图像的Pitch
   long m_Sizebit; //每通道的数据位数
   long m_lBand;
   long	m_ReadSize ;
   char	*m_ReadBuffer;

   CString	m_strResult;
   CString m_strFilePath; //相机配置文件路径

   DWORD m_SizeImage;
   BITMAPINFO* m_LPBitMapInfo;

//----------------SVS---------------------------//
   int camHandle;
   int ErrorNr;
   char * portIDstr; 
   bool m_bMilShow;
   
//----------------About Mil---------------------------//
public:
   MIL_ID MilApplication;
   MIL_ID MilSystem;
   MIL_ID MilDigitizer;
   MIL_ID MilDisplay;
   MIL_ID MilImageDisp;
   MIL_ID MilImages[PICNUM];
   MIL_ID MilImagePro;
   MIL_ID MilImageProChild;

   void*  m_MainFrm;  // 主窗口指针
   HANDLE m_hThread; // 采集线程句柄  
   ImageGrabbedCallback m_MainDisplayCallback;  //
   BYTE *m_lBufferAddress;
   bool m_bStartGrab; 
};
#endif  //CWCAMERA_DLL_H