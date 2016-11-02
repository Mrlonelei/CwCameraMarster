/************************************************************************/
/* Copyright (c) 2012,   ������ά
/* All rights reserved.													
/*																		
/* �ļ����ƣ� CwCamera.h												
/* ժҪ������SOLIOS�忨����SVS����ɼ�ͼ��̬��.
/* ���ߣ���ΰ��
/* V1.0
/* 
/*���ӣ�SetFocus(int)(���ý���)��SetAperture(int)(���ù�Ȧλ��)��������
/*���ߣ����ٻ�
/*ʱ�䣺2014��3��27��
/*�汾��: V2.0
/*ʹ�÷���:1��������������ļ�·����SetFilePath(CString),����Ϊ��������ļ�·��
/*         2����ʼ�������InitCamera(CWnd* pParent=NULL,bool IsMilShow=false,int iIndex=0)
/*            ��һ������ָ��ʹ�������Ĵ��ڵĸ�����ָ�룬�ڶ�������ָ���Ƿ���ʾͼ�񣬵���������ָ���忨������
/*         3��SetOwner(void* MainFrm,ImageGrabbedCallback MainDisplayCallback)
/*            ��һ������ָ��ʹ��������������ָ�룬�ڶ��������ǻص��������
/*         4�����ù��ܺ���������SetFocus(int)��
/*ʹ�÷���: m_CwCamera.SetFilePath("C://hr29050MFLCPC_8bit4taps_SoliosXCL_con.dcf");   
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
   bool SetFilePath(const CString strPath); //�������ϵͳdcf�ļ�·��
   bool InitCamera(CWnd* pParent=NULL,bool IsMilShow=false,int iIndex=0); //����������ʼ�������iIndexΪ�忨������
   void SetdispPan(double dXOffSet,double dYOffSet); //����ͼ��ƫ�ƣ�Mil��ʾʱ���� 
   void SetOwner(void* MainFrm,ImageGrabbedCallback MainDisplayCallback);
   void Grab(); //�����ɼ�ͼ��,Mil��ʾʱ����
   void Stop(); //ֹͣ�����ɼ�,�����ɼ�ʱ��
   bool GrabImage(); //�����̲߳ɼ�ͼ��
   bool Freeze(); //ֹͣ�̲߳ɼ�
   void Snap(); //��֡�ɼ�ͼ��  
   bool SetShutter(int iShutter); //�����ع�ʱ��,��λΪus,��СֵΪ10�����ֵΪ7000000
   bool SetFocus(int focus); //���ý���λ�ã���СֵΪ0,���ֵΪ16383
   bool SetAperture(int Aperture); //���ù�Ȧλ�ã���СֵΪ0,���ֵΪ63

   bool GetShutter(int& iShutter);// 20160705 Mrl.wy  ��ȡ�ع�ֵ
   bool GetFocus(int& nFocus);//20160705 Mrl.wy ��ȡ����ֵ		
   bool GetAperture(int& nAperture);//20160705 Mrl.wy ��ȡ��Ȧֵ

   bool SetGainLeft(int iGain); //���������棬��λΪdB����СֵΪ0�����ֵΪ899
   long GetImgWidth(){return m_lWidth;} //��ȡͼ����
   long GetImgHeight(){return m_lHeight;} //��ȡͼ��߶�
   long GetImgPitch(){return m_lPitch;}   //��ȡͼ���Pitch
   long GetChannalBit(){return m_Sizebit;} //��ȡͼ��ͨ����λ��
   void GetImgBuffer(unsigned char **ImageBuffer); //��֡�ɼ�ʱ����ȡͼ���buffer
   void Zoom(double dXFactor,double dYFactor); //Mil��ʾʱ����
   void SaveImage(CString strPath); //�洢ͼ�񣬽�ͼ��洢��ָ��·��
   void Destory(); //�ͷ����
private:
    //------------------Mil Function---------------------//
    bool MilCreate(int iIndex);
    bool MilDestroy();
	bool InitSvsCamera(); //��ʼ��SVS������ɹ�����true��ʧ�ܷ���false
	void DestorySvsCamera(); //�ͷ�SVS���
    CString SendCLCommand(char * TestString , bool feedback,int iIndex=0);//���ʹ�������
private:
   long m_lWidth; //ͼ��Ŀ��
   long m_lHeight; //ͼ��ĸ߶�
   long m_lPitch; //ͼ���Pitch
   long m_Sizebit; //ÿͨ��������λ��
   long m_lBand;
   long	m_ReadSize ;
   char	*m_ReadBuffer;

   CString	m_strResult;
   CString m_strFilePath; //��������ļ�·��

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

   void*  m_MainFrm;  // ������ָ��
   HANDLE m_hThread; // �ɼ��߳̾��  
   ImageGrabbedCallback m_MainDisplayCallback;  //
   BYTE *m_lBufferAddress;
   bool m_bStartGrab; 
};
#endif  //CWCAMERA_DLL_H