
// CwCameraMarster.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCwCameraMarsterApp: 
// �йش����ʵ�֣������ CwCameraMarster.cpp
//

class CCwCameraMarsterApp : public CWinApp
{
public:
	CCwCameraMarsterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	static void GrabCallback(void* pOwner,BYTE* ImgData);
	int InitCamera();

};

extern CCwCameraMarsterApp theApp;