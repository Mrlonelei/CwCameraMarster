
// CwCameraMarsterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CwCameraMarster.h"
#include "CwCameraMarsterDlg.h"
#include "afxdialogex.h"
#include <util.h>
#include <CwError.h>
#include <CwTFTBase.h>
#include "CwCameraFactory.h"
#include "CwSerialPort.h"
#include "CwBirgerMount.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CAMERA_TEST 1

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
const int CORNERROIWIDTH = 100;
const int CORNERROIHEIGHT = 100;
const int BLOCKCOLS = 3;
const int BLOCKROWS = 3;



DWORD WINAPI LiveShowThread(LPVOID pParam)
{

	CCwCameraMarsterDlg *pOwner = (CCwCameraMarsterDlg *)pParam;
	//CWnd* srcpic = pOwner->GetDlgItem(IDC_STATIC_SRCIMG);
	int imgHeight = 4384;
	int imgWidth = 6592;
	uchar* imgBuffer = new uchar[imgHeight*imgWidth];
	while (true)
	{
		while (CWCAMERAMASTER_SHOWIMG_LIVE == pOwner->GetShowImgMode())
		{
#if CAMERA_TEST
			pOwner->m_Camera->Snap();

			pOwner->m_Camera->GetImgBuffer(&imgBuffer);

			pOwner->PaintOnScreen(imgBuffer, imgWidth, imgHeight);

			pOwner->InfoProcessMain();
#endif
			//AfxMessageBox("live");
						
			Sleep(100);
			pOwner->m_semExitLiveThreadFlag.Lock();			//20160907 Mrl.wy 线程退出标志
			if (pOwner->m_nExitLiveThreadFlag)
			{
				pOwner->m_semExitLiveThreadFlag.Unlock();
				break;
			}
			pOwner->m_semExitLiveThreadFlag.Unlock();
		}

		pOwner->m_semExitLiveThreadFlag.Lock();
		if (pOwner->m_nExitLiveThreadFlag)
		{
			pOwner->m_semExitLiveThreadFlag.Unlock();
			break;
		}
		pOwner->m_semExitLiveThreadFlag.Unlock();

		Sleep(100);

	}
	
	delete[]imgBuffer;
	imgBuffer = NULL;
	return 0;
}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCwCameraMarsterDlg 对话框



CCwCameraMarsterDlg::CCwCameraMarsterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCwCameraMarsterDlg::IDD, pParent), m_nFocus(0), m_nAperture(0), m_nShutter(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CCwCameraMarsterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CCwCameraMarsterDlg::GrabDisplayCallBack(void* pOwner, BYTE* ImgData)
{
	CCwCameraMarsterDlg* pThisDlg = (CCwCameraMarsterDlg*)pOwner;
}



BEGIN_MESSAGE_MAP(CCwCameraMarsterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SET_FOCUS, &CCwCameraMarsterDlg::OnBnClickedButtonSetFocus)
	ON_BN_CLICKED(IDC_BUTTON_GRAB, &CCwCameraMarsterDlg::OnBnClickedButtonGrab)
	ON_BN_CLICKED(IDC_BUTTON_LOADIMAGE, &CCwCameraMarsterDlg::OnBnClickedButtonLoadimage)
	ON_BN_CLICKED(IDC_BUTTON_SET_APERTURE, &CCwCameraMarsterDlg::OnBnClickedButtonSetAperture)
	ON_BN_CLICKED(IDC_BUTTON_SET_EXPORSURE, &CCwCameraMarsterDlg::OnBnClickedButtonSetExporsure)

	ON_BN_CLICKED(IDC_BUTTON_LIVEMODE, &CCwCameraMarsterDlg::OnBnClickedButtonLivemode)
	ON_BN_CLICKED(IDC_BUTTON_CAMERALOAD, &CCwCameraMarsterDlg::OnBnClickedButtonCameraload)
	ON_BN_CLICKED(IDC_BUTTON_CAMERAUNLOAD, &CCwCameraMarsterDlg::OnBnClickedButtonCameraunload)
	ON_BN_CLICKED(IDC_BUTTON_CAMREARELOAD, &CCwCameraMarsterDlg::OnBnClickedButtonCamreareload)
	ON_BN_CLICKED(IDC_BUTTON_MAINIMGZOOMIN, &CCwCameraMarsterDlg::OnBnClickedButtonMainimgzoomin)
	ON_BN_CLICKED(IDC_BUTTON_PORTSEARCH, &CCwCameraMarsterDlg::OnBnClickedButtonPortsearch)
END_MESSAGE_MAP()


// CCwCameraMarsterDlg 消息处理程序

BOOL CCwCameraMarsterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	
	m_pedFocus = (CEdit*)GetDlgItem(IDC_EDITFOCUS);
	m_pedApersture = (CEdit*)GetDlgItem(IDC_EDITAPERTURE);
	m_pedShutter = (CEdit*)GetDlgItem(IDC_EDITEXPORSURE);

	
	this->m_Camera = this->m_CameraFactory.GetItem(CWCAMERATYPE_SVS);
	//m_Camera.SetOwner(this, GrabCallBack);
	this->m_Camera->SetFilePath("Camera.dcf");
	this->m_nIsCameraOnline = 0;
#if CAMERA_TEST
	//this->m_nIsCameraOnline = m_Camera->InitCamera(this, 0, 0);
#endif
	
	m_hicOnLineIcon = AfxGetApp()->LoadIcon(IDI_ICON_ONLINE);
	m_hicOffLineIcon = AfxGetApp()->LoadIcon(IDI_ICON_OFFLINE);
	SetCameraOnlineAble();
	if (this->m_nIsCameraOnline)
	{
		int nGetVal(0);
		this->m_Camera->GetFocus(nGetVal);
		this->m_nFocus = nGetVal;
		this->m_Camera->GetAperture(nGetVal);
		this->m_nAperture = nGetVal;
		this->m_Camera->GetShutter(nGetVal);
		this->m_nShutter = nGetVal;
		SetCameraOnlineAble();
	}
	else
	{
		//AfxMessageBox("Camera off line");
#if CAMERA_TEST

		//this->m_Camera->Destory();
		SetCameraOfflineEnable();
#endif
	}
	SetGrabPerFrame();
	CString str;
	str.Format("%d", this->m_nFocus);
	m_pedFocus->SetWindowText(str);
	str.Format("%d", this->m_nAperture);
	m_pedApersture->SetWindowText(str);
	str.Format("%d", this->m_nShutter);
	m_pedShutter->SetWindowText(str);
	
	this->m_fXScale = 1.0;
	this->m_fYScale = 1.0;
	

	this->m_CornerROI[CWTFT_CORNER_LEFTUP].x = 0;
	this->m_CornerROI[CWTFT_CORNER_LEFTUP].y = 0;
	this->m_CornerROI[CWTFT_CORNER_LEFTUP].width = CORNERROIWIDTH;
	this->m_CornerROI[CWTFT_CORNER_LEFTUP].height = CORNERROIHEIGHT;

	this->m_CornerROI[CWTFT_CORNER_LEFTDOWN].x = 0;
	this->m_CornerROI[CWTFT_CORNER_LEFTDOWN].y = 0;
	this->m_CornerROI[CWTFT_CORNER_LEFTDOWN].width = CORNERROIWIDTH;
	this->m_CornerROI[CWTFT_CORNER_LEFTDOWN].height = CORNERROIHEIGHT;

	this->m_CornerROI[CWTFT_CORNER_RIGHTUP].x = 0;
	this->m_CornerROI[CWTFT_CORNER_RIGHTUP].y = 0;
	this->m_CornerROI[CWTFT_CORNER_RIGHTUP].width = CORNERROIWIDTH;
	this->m_CornerROI[CWTFT_CORNER_RIGHTUP].height = CORNERROIHEIGHT;

	this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].x = 0;
	this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].y = 0;
	this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].width = CORNERROIWIDTH;
	this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].height = CORNERROIHEIGHT;
	
	SetCornerROI(0, 0, CWTFT_CORNER_LEFTUP);
	SetCornerROI(0, this->m_matSrcImg.rows - CORNERROIHEIGHT - 1, CWTFT_CORNER_LEFTDOWN);
	SetCornerROI(this->m_matSrcImg.cols - CORNERROIWIDTH - 1, 0, CWTFT_CORNER_RIGHTUP);
	SetCornerROI(this->m_matSrcImg.cols - CORNERROIWIDTH - 1, this->m_matSrcImg.rows - CORNERROIHEIGHT - 1, CWTFT_CORNER_RIGHTDOWN);

	this->m_nShowImageMode = CWCAMERAMASTER_SHOWIMG_NO;

	CRect cRect;
	GetDlgItem(IDC_STATIC_IMGINFO)->GetClientRect(&cRect);

	this->m_matInfoImg.create(cvSize(cRect.Width(), cRect.Height()), CV_8UC3);
	this->m_matInfoImg = cvScalar(10, 10, 10);
	
	this->m_semExitLiveThreadFlag.Lock();
	this->m_nExitLiveThreadFlag = 0;
	this->m_semExitLiveThreadFlag.Unlock();
	
	this->m_nZoomStatus = CWCAMERAMASTER_ZOOMSTATUS_OFF;

	this->m_hLiveThread = CreateThread(NULL, 0, LiveShowThread, this,0,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCwCameraMarsterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCwCameraMarsterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);

		
	}
	else
	{

		/*if (this->m_matSrcImg.data != NULL)
		{
		CRect rect;
		GetDlgItem(IDC_STATIC_SRCIMG)->GetClientRect(&rect);
		cv::Mat resizeMat;
		cv::resize(this->m_matSrcImg, resizeMat, cvSize(rect.Width(), rect.Height()));
		CDC * pDC = GetDlgItem(IDC_STATIC_SRCIMG)->GetDC();
		HDC pHDC = pDC->GetSafeHdc();

		CImage dstcimg;
		LoadMemImage(resizeMat.data, dstcimg, resizeMat.cols, resizeMat.rows);
		dstcimg.Draw(pHDC, 0, 0);


		SetCornerROI(0, 0, CWTFT_CORNER_LEFTUP);
		SetCornerROI(0, this->m_matSrcImg.rows - CORNERROIHEIGHT - 1, CWTFT_CORNER_LEFTDOWN);
		SetCornerROI(this->m_matSrcImg.cols - CORNERROIWIDTH - 1, 0, CWTFT_CORNER_RIGHTUP);
		SetCornerROI(this->m_matSrcImg.cols - CORNERROIWIDTH - 1, this->m_matSrcImg.rows - CORNERROIHEIGHT - 1, CWTFT_CORNER_RIGHTDOWN);

		PaintCornerImg(CWTFT_CORNER_LEFTUP, IDC_STATIC_LEFTUP);
		PaintCornerImg(CWTFT_CORNER_LEFTDOWN, IDC_STATIC_LEFTDOWN);
		PaintCornerImg(CWTFT_CORNER_RIGHTUP, IDC_STATIC_RIGHTUP);
		PaintCornerImg(CWTFT_CORNER_RIGHTDOWN, IDC_STATIC_RIGHTDOWN);
		}*/
		CDialogEx::OnPaint();
	

	}
}
void CCwCameraMarsterDlg::OnCancel()
{
	
	this->m_Camera->Freeze();
	this->m_Camera->Destory();

	this->m_semExitLiveThreadFlag.Lock();
	this->m_nExitLiveThreadFlag = 1;
	this->m_semExitLiveThreadFlag.Unlock();
	
	this->DestroyWindow();
}
//void CCwCameraMarsterDlg::OnDestroy()
//{
//	this->m_Camera->Freeze();
//	this->m_Camera->Destory();
//	
//	this->m_semExitLiveThreadFlag.Lock();
//	this->m_nExitLiveThreadFlag = 1;
//	this->m_semExitLiveThreadFlag.Unlock();
//
//	
//	CDialogEx::OnDestroy();
//}
//void CCwCameraMarsterDlg::OnClose()
//{
//	this->m_Camera->Freeze();
//	this->m_Camera->Destory();
//
//	this->m_semExitLiveThreadFlag.Lock();
//	this->m_nExitLiveThreadFlag = 1;
//	this->m_semExitLiveThreadFlag.Unlock();
//
//	CDialogEx::OnClose();
//}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCwCameraMarsterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCwCameraMarsterDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
}

//20151210 Mrl.wy set focus
void CCwCameraMarsterDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码

}




void CCwCameraMarsterDlg::OnBnClickedButtonGrab()
{
	// TODO:  在此添加控件通知处理程序代码
	uchar* imgBuff = NULL;
	this->m_Camera->Snap();
	this->m_Camera->GetImgBuffer(&imgBuff);
	int nWidth =6592;
	int nHeight = 4384;
	if (imgBuff != NULL)
	{
		if (this->m_matSrcImg.data == NULL)
		{
			this->m_matSrcImg.create(cvSize(nWidth, nHeight), CV_8U);
		}
		else
		{
			if (this->m_matSrcImg.cols != nWidth || this->m_matSrcImg.rows != nHeight)
			{
				this->m_matSrcImg.release();
				this->m_matSrcImg.create(cvSize(nWidth, nHeight), CV_8U);
			}
		}
		memcpy(this->m_matSrcImg.data, imgBuff, nWidth*nHeight*sizeof(uchar));
		cv::imwrite("srcImgGrab.bmp", this->m_matSrcImg);
	}
	PaintOnScreen(this->m_matSrcImg.data,nWidth,nHeight);
	InfoProcessMain();
}

void CCwCameraMarsterDlg::GrabCallBack(void* pOwner, BYTE* ImgData)
{
	CCwCameraMarsterDlg* pOwn = (CCwCameraMarsterDlg*)pOwner;

	return;
}

int CCwCameraMarsterDlg::PaintOnScreenIDC(uchar* pImgBuf, int imgWidth, int imgHeight, UINT idcNum)
{
	CRect rect;
	GetDlgItem(idcNum)->GetClientRect(&rect);
	cv::Mat srcbuff(cvSize(imgWidth,imgHeight),CV_8U);
	cv::Mat resizeMat;
	memcpy(srcbuff.data, pImgBuf, imgWidth*imgHeight*sizeof(uchar));
	if (pImgBuf == NULL)
		return 0;
	if (rect.Width() != imgWidth || rect.Height() != imgHeight)
	{
		cv::resize(srcbuff, resizeMat, cvSize(rect.Width(), rect.Height()));
	}
	else
	{
		resizeMat = srcbuff;
	}

	CDC * pDC = GetDlgItem(idcNum)->GetDC();
	HDC pHDC = pDC->GetSafeHdc();

	cv::imwrite("resizeMat.bmp", resizeMat);
	CImage dstcimg;
	LoadMemImage(resizeMat.data, dstcimg, rect.Width(), rect.Height());
	dstcimg.Draw(pHDC, 0, 0);
	ReleaseDC(pDC);
	dstcimg.Destroy();

	OnPaint();
	return RC_SUCCESS;
}

int CCwCameraMarsterDlg::PaintOnScreenIDCMat(cv::Mat matSrcImg, UINT idcNum)
{
	CRect rect;
	GetDlgItem(idcNum)->GetClientRect(&rect);
	
	cv::Mat resizeMat;
	
	if (0 == matSrcImg.cols || 0 == matSrcImg.rows)
	{
		return -1;
	}
	if (rect.Width() != m_matSrcImg.cols || rect.Height() != matSrcImg.rows)
	{
		cv::resize(matSrcImg, resizeMat, cvSize(rect.Width(), rect.Height()));
	}
	else
	{
		resizeMat = matSrcImg;
	}



	CDC * pDC = GetDlgItem(idcNum)->GetDC();
	HDC pHDC = pDC->GetSafeHdc();

	cv::imwrite("resizeMat.bmp", resizeMat);
	CImage dstcimg;
	LoadMemImage(resizeMat.data, dstcimg, rect.Width(), rect.Height());
	dstcimg.Draw(pHDC, 0, 0);
	ReleaseDC(pDC);
	dstcimg.Destroy();
	//CloseHandle(pHDC);
	OnPaint();
	return RC_SUCCESS;
}

int CCwCameraMarsterDlg::PaintOnScreen(uchar* pImgBuf,int imgWidth,int imgHeight)
{


	if (this->m_matSrcImg.cols != imgWidth||this->m_matSrcImg.rows != imgHeight)
	{
		this->m_matSrcImg.release();
		this->m_matSrcImg.create(imgHeight, imgWidth, CV_8U);
	}
	memcpy(this->m_matSrcImg.data, pImgBuf, imgHeight*imgWidth*sizeof(uchar));

	CRect rect;
	GetDlgItem(IDC_STATIC_SRCIMG)->GetClientRect(&rect);

	cv::Mat resizeMat;
	cv::resize(this->m_matSrcImg, resizeMat, cvSize(rect.Width(), rect.Height()));
	CDC * pDC = GetDlgItem(IDC_STATIC_SRCIMG)->GetDC();
	HDC pHDC = pDC->GetSafeHdc();
	this->m_fXScale = (this->m_matSrcImg.cols) / (float)(resizeMat.cols);
	this->m_fYScale = (this->m_matSrcImg.rows) / (float)(resizeMat.rows);

	CImage dstcimg;
	LoadMemImage(resizeMat.data, dstcimg, resizeMat.cols, resizeMat.rows);
	dstcimg.Draw(pHDC, 0, 0);

	dstcimg.Destroy();
	
	ReleaseDC(pDC);

	PaintCornerImg(CWTFT_CORNER_LEFTUP, IDC_STATIC_LEFTUP);
	PaintCornerImg(CWTFT_CORNER_LEFTDOWN, IDC_STATIC_LEFTDOWN);
	PaintCornerImg(CWTFT_CORNER_RIGHTUP, IDC_STATIC_RIGHTUP);
	PaintCornerImg(CWTFT_CORNER_RIGHTDOWN, IDC_STATIC_RIGHTDOWN);
	
	OnPaint();

	return RC_SUCCESS;
}

void CCwCameraMarsterDlg::OnBnClickedButtonLoadimage()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("BMP Files (*.bmp)|*.bmp|All Files (*.*)|*.*||"),
		NULL);
	if (dlg.DoModal() == IDOK)
	{
		this->m_strOneImageFileName = dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}
	if (this->m_matSrcImg.data == NULL)
	{
		this->m_matSrcImg = cv::imread(this->m_strOneImageFileName.GetBuffer(), 0);
		this->m_strOneImageFileName.ReleaseBuffer();
	}
	else
	{
		this->m_matSrcImg.release();
		this->m_matSrcImg = cv::imread(this->m_strOneImageFileName.GetBuffer(), 0);
		this->m_strOneImageFileName.ReleaseBuffer();
	}

	if (this->m_matSrcImg.data == NULL)
		AfxMessageBox("LOAD IMAGE FAIL");
	this->PaintOnScreen(this->m_matSrcImg.data, this->m_matSrcImg.cols, this->m_matSrcImg.rows);
	CRect cRect;
	GetDlgItem(IDC_STATIC_IMGINFO)->GetClientRect(&cRect);
	//PaintOnScreenIDC(this->m_matInfoImg.data, cRect.Width(), cRect.Height(), IDC_STATIC_IMGINFO);
	this->InfoProcessMain();



}

void CCwCameraMarsterDlg::LoadMemImage(uchar *pImgBuf, CImage &DesImg, int nWidth, int nHeight)
{
	if (!DesImg.IsNull())
	{
		DesImg.ReleaseGDIPlus();
		DesImg.Destroy();
	}

	//DesImg.Create(nWidth,nHeight,8);

	while (DesImg.IsNull())
	{
		DesImg.Create(nWidth, nHeight, 8);
		Sleep(20);
	}

	RGBQUAD* ColorTable;
	int MaxColors = 256;
	//这里可以通过Img.GetMaxColorTableEntries()得到大小(如果你是Img.Load读入图像的话)
	ColorTable = new RGBQUAD[MaxColors];
	DesImg.GetColorTable(0, MaxColors, ColorTable);//这里是取得指针
	for (int i = 0; i < MaxColors; i++)
	{
		ColorTable[i].rgbBlue = (BYTE)i;
		ColorTable[i].rgbGreen = (BYTE)i;
		ColorTable[i].rgbRed = (BYTE)i;
	}
	DesImg.SetColorTable(0, MaxColors, ColorTable);
	delete[]ColorTable;
	ColorTable = NULL;

	BYTE* q;
	for (int y = 0; y < nHeight; y++)
	{
		q = (byte*)DesImg.GetPixelAddress(0, y);
		memcpy(q, &pImgBuf[nWidth*y], nWidth);
	}
}


int CCwCameraMarsterDlg::SetCornerROI(int nX, int nY, int CornerNum)
{
	if (nX >0)
		this->m_CornerROI[CornerNum].x = nX;
	if (nY>0)
		this->m_CornerROI[CornerNum].y = nY;

	return RC_SUCCESS;
}

void CCwCameraMarsterDlg::PaintCornerImg(int CornerNum, int IDCNUM)
{
	if (this->m_matSrcImg.data != NULL)
	{
		CRect cornerRect;
		GetDlgItem(IDCNUM)->GetClientRect(&cornerRect);
		CDC * pDC = GetDlgItem(IDCNUM)->GetDC();
		HDC pHDC = pDC->GetSafeHdc();

		CImage CornerDst;
		cv::Mat cornerROIImg = this->m_matSrcImg(this->m_CornerROI[CornerNum]);
		cv::Mat resizeCornerROIImg;

		cv::resize(cornerROIImg, resizeCornerROIImg, cvSize(cornerRect.Width(), cornerRect.Height()));
		LoadMemImage(resizeCornerROIImg.data, CornerDst, resizeCornerROIImg.cols, resizeCornerROIImg.rows);
		/*pDC = GetDlgItem(IDCNUM)->GetDC();
		pHDC = pDC->GetSafeHdc();*/
		CornerDst.Draw(pHDC, 0, 0);
		ReleaseDC(pDC);
		CornerDst.Destroy();
	}
}

void CCwCameraMarsterDlg::OnBnClickedButtonSetFocus()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strFocus;
	this->m_pedFocus->GetWindowTextA(strFocus);
	this->m_nFocus = atoi(strFocus);
	if (this->m_nIsCameraOnline)
	{
		this->m_Camera->SetFocus(this->m_nFocus);
	}
	else
	{
		AfxMessageBox("No Camera");
	}

}

void CCwCameraMarsterDlg::OnBnClickedButtonSetAperture()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strAperture;
	this->m_pedApersture->GetWindowTextA(strAperture);
	this->m_nAperture = atoi(strAperture);
	if (this->m_nIsCameraOnline)
	{
		this->m_Camera->SetAperture(this->m_nAperture);
	}
	else
	{
		AfxMessageBox("No Camera");
	}
}


void CCwCameraMarsterDlg::OnBnClickedButtonSetExporsure()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strShutter;
	this->m_pedShutter->GetWindowTextA(strShutter);
	this->m_nShutter = atoi(strShutter);
	if (this->m_nIsCameraOnline)
	{	
		this->m_Camera->SetShutter(this->m_nShutter);
	}
	else
	{
		AfxMessageBox("No Camera");
	}
}

BOOL CCwCameraMarsterDlg::PreTranslateMessage(MSG* pMsg)
{
	CString strOut;
	CRect picRect;
	CPoint MovePoint = pMsg->pt;

	GetDlgItem(IDC_STATIC_SRCIMG)->GetWindowRect(picRect);
	switch (pMsg->message)
	{
	case WM_MOUSEMOVE:
		if (picRect.PtInRect(MovePoint))
		{
			OnMouseMoveSrcImg(MK_MBUTTON, (LPARAM)&pMsg->pt);
			return TRUE;
		}
		break;
	case WM_LBUTTONDBLCLK:
		if (picRect.PtInRect(MovePoint))
		{
			OnMouseLBCLKSetCorner(MK_MBUTTON, (LPARAM)&pMsg->pt);
			return TRUE;
		}
		break;
	case WM_LBUTTONDOWN://20160926 Mrl.wy 
		if (picRect.PtInRect(MovePoint));
		{
			if (CWCAMERAMASTER_ZOOMSTATUS_IN == this->m_nZoomStatus || CWCAMERAMASTER_ZOOMSTATUS_OUT == this->m_nZoomStatus)
			{
				this->m_rectZoomROI.x = (MovePoint.x - picRect.left)*this->m_fXScale;
			}
		}
		break;
	case WM_LIVESHOWIMAGE:
		OnLiveShowImage(pMsg->hwnd,pMsg->lParam);
		break;

	default:
		break;
	}
	

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CCwCameraMarsterDlg::OnMouseMoveSrcImg(UINT nID, LPARAM lParam)
{
	//AfxMessageBox("opoos!");
	CPoint* ptr_pt = (CPoint*)lParam;
	CString strInfo;
	CRect cRect;
	GetDlgItem(IDC_STATIC_SRCIMG)->GetWindowRect(cRect);
	CvPoint imgPos((int)((ptr_pt->x - cRect.left)*this->m_fXScale), (int)((ptr_pt->y - cRect.top)*this->m_fYScale));
	uchar rGray(0), bGray(0), gGray(0);
	if (this->m_matSrcImg.data != NULL)
	{
		rGray = this->m_matSrcImg.at<uchar>(imgPos);
		bGray = this->m_matSrcImg.at<uchar>(imgPos);
		gGray = this->m_matSrcImg.at<uchar>(imgPos);
	}
	
	strInfo.Format("X:%d  Y:%d  R:  %d   G:%d   B:%d", imgPos.x, imgPos.y,rGray , bGray, gGray);

	GetDlgItem(IDC_EDIT_SRCIMGINFO)->SetWindowText(strInfo);
}

void CCwCameraMarsterDlg::OnMouseLBCLKSetCorner(UINT nID, LPARAM lParam)
{
	CPoint* ptr_pt = (CPoint*)lParam;
	CString  strInfo;
	CRect cRect;
	GetDlgItem(IDC_STATIC_SRCIMG)->GetWindowRect(cRect);
	cv::Point imgPoint;
	imgPoint.x = (int)((ptr_pt->x - cRect.left)*this->m_fXScale);
	imgPoint.y = (int)((ptr_pt->y - cRect.top)*this->m_fYScale);
	
	if (imgPoint.x - CORNERROIWIDTH / 2 < 0)
		imgPoint.x = 0;
	else
		imgPoint.x -= CORNERROIWIDTH / 2;
	
	
	if (imgPoint.y - CORNERROIHEIGHT / 2 < 0)
		imgPoint.y = 0;
	else
		imgPoint.y -= CORNERROIHEIGHT / 2;
	
	
	if (imgPoint.x > 0 && (imgPoint.x+CORNERROIWIDTH) < (this->m_matSrcImg.cols / 2) && imgPoint.y>0 && ((imgPoint.y+CORNERROIHEIGHT) < (this->m_matSrcImg.rows / 2)))
	{
		SetCornerROI(imgPoint.x, imgPoint.y, CWTFT_CORNER_LEFTUP);
		SetCornerROI(imgPoint.x, -1, CWTFT_CORNER_LEFTDOWN);
		SetCornerROI(-1, imgPoint.y, CWTFT_CORNER_RIGHTUP);
		SetCornerROI(-1, -1, CWTFT_CORNER_RIGHTDOWN);
	}
	else
	{
		if ((imgPoint.x >= (this->m_matSrcImg.cols / 2)) && ((imgPoint.x+CORNERROIWIDTH)<this->m_matSrcImg.cols) && (imgPoint.y>(this->m_matSrcImg.rows / 2)) && (imgPoint.y+CORNERROIHEIGHT < this->m_matSrcImg.rows))
		{
			SetCornerROI(-1, -1, CWTFT_CORNER_LEFTUP);
			SetCornerROI(-1, imgPoint.y, CWTFT_CORNER_LEFTDOWN);
			SetCornerROI(imgPoint.x, -1, CWTFT_CORNER_RIGHTUP);
			SetCornerROI(imgPoint.x, imgPoint.y, CWTFT_CORNER_RIGHTDOWN);
		}
	}
	PaintCornerImg(CWTFT_CORNER_LEFTUP, IDC_STATIC_LEFTUP);
	PaintCornerImg(CWTFT_CORNER_LEFTDOWN, IDC_STATIC_LEFTDOWN);
	PaintCornerImg(CWTFT_CORNER_RIGHTUP, IDC_STATIC_RIGHTUP);
	PaintCornerImg(CWTFT_CORNER_RIGHTDOWN, IDC_STATIC_RIGHTDOWN);
	OnPaint();
}

void CCwCameraMarsterDlg::OnBnClickedButtonLivemode()
{
	// TODO:  在此添加控件通知处理程序代码
	switch (this->m_nShowImageMode)
	{
	case CWCAMERAMASTER_SHOWIMG_LOAD:
		this->m_nShowImageMode = CWCAMERAMASTER_SHOWIMG_LOAD;
		SetGrabPerFrame();
		SuspendThread(m_hLiveThread);
		//::PostMessage(this->GetSafeHwnd(), WM_LIVESHOWIMAGE, 0, 0);
		break;
	case CWCAMERAMASTER_SHOWIMG_LIVE:
		this->m_nShowImageMode = CWCAMERAMASTER_SHOWIMG_NO;
		SetGrabPerFrame();
		SuspendThread(m_hLiveThread);
		//::PostMessage(this->GetSafeHwnd(), WM_LIVESHOWIMAGESTOP, 0, 0);
		break;
	case CWCAMERAMASTER_SHOWIMG_NO:
		this->m_nShowImageMode = CWCAMERAMASTER_SHOWIMG_LIVE;
		SetGrabContinues();
		ResumeThread(m_hLiveThread);
		//::PostMessage(this->GetSafeHwnd(), WM_LIVESHOWIMAGE, 0, 0);
		break;
	default:
		break;
	}
}

void CCwCameraMarsterDlg::OnLiveShowImage(HWND nID, LPARAM lParam)
{
	
	
}

int CCwCameraMarsterDlg::GetShowImgMode()
{
	return this->m_nShowImageMode;
}

int CCwCameraMarsterDlg::InfoProcessMain()
{
	cv::Rect ProcessROI(
		this->m_CornerROI[CWTFT_CORNER_LEFTUP].x,
		this->m_CornerROI[CWTFT_CORNER_LEFTUP].y,
		this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].x - this->m_CornerROI[CWTFT_CORNER_LEFTUP].x,
		this->m_CornerROI[CWTFT_CORNER_RIGHTDOWN].y - this->m_CornerROI[CWTFT_CORNER_LEFTUP].y);

	cv::Mat processSrc = this->m_matSrcImg(ProcessROI);
	cv::Rect block[BLOCKCOLS*BLOCKROWS];
	float blockArea[BLOCKCOLS*BLOCKROWS];
	int blockWidth = processSrc.cols / BLOCKCOLS;
	int blockHeight = processSrc.rows / BLOCKROWS;
	long blockAreaEach = blockWidth*blockHeight;
	for (int i = 0; i < BLOCKCOLS*BLOCKROWS;i++)
	{
		block[i].x = blockWidth*(i%BLOCKCOLS);
		block[i].y = blockHeight*(i / BLOCKROWS);
		block[i].width = blockWidth;
		block[i].height = blockHeight;
	}
	std::stringstream sstrAvg;
	
	for (int i = 0; i < BLOCKCOLS*BLOCKROWS;i++)
	{
		blockArea[i] = cv::sum(processSrc(block[i]))[0] / (float)blockAreaEach;
		cv::Mat sobelX, sobelY;
		/*sobelX.create(block[i].height, block[i].width, CV_32FC1);
		sobelY.create(block[i].height, block[i].width, CV_32FC1);
*/
		cv::Sobel(processSrc(block[i]), sobelX, CV_32F, 2, 0, 3);
		cv::Sobel(processSrc(block[i]), sobelY, CV_32F, 0, 2, 3);
		double fDefX(0.0), fDefY(0.0);
		for (int j = 0; j < block[i].height; j++)
		{
			const float* ptrX = sobelX.ptr<float>(j);
			const float* ptrY = sobelY.ptr<float>(j);
			for (int o = 0; o < block[i].width; o++)
			{
				fDefX += fabs(*(ptrX + o));
				fDefY += fabs(*(ptrY + o));
			}
		}
		//sobelX.release();
		//sobelY.release();

		sstrAvg.setf(std::ios_base::fixed);
		sstrAvg << blockArea[i];
		cv::putText(processSrc(block[i]), sstrAvg.str(), cvPoint(blockWidth / 10.0, blockHeight / 3.0), CV_FONT_NORMAL, 8, cvScalar(255, 255, 255),10,8);
		sstrAvg.str("");
		sstrAvg << (fDefX/(float)(sobelX.cols*sobelX.rows)) / blockArea[i];
		cv::putText(processSrc(block[i]), sstrAvg.str(), cvPoint(blockWidth / 10.0, 2*(blockHeight / 3.0)), CV_FONT_NORMAL, 8, cvScalar(255, 255, 255), 10, 8);
		sstrAvg.str("");
		sstrAvg << (fDefY  /(float)(sobelY.cols*sobelY.rows)) / blockArea[i];
		cv::putText(processSrc(block[i]), sstrAvg.str(), cvPoint(blockWidth / 10.0, 3 * (blockHeight / 3.0)), CV_FONT_NORMAL, 8, cvScalar(255, 255, 255), 10, 8);

		sstrAvg.str("");
		sstrAvg.clear();

		fDefX = 0.0;
		fDefY = 0.0;
	}
	cv::imwrite("info.bmp", processSrc);
	PaintOnScreenIDCMat(processSrc, IDC_STATIC_IMGINFO);
	return RC_SUCCESS;
}

void CCwCameraMarsterDlg::OnBnClickedButtonCameraload()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("DCF Files (*.dcf)|*.dcf|All Files (*.*)|*.*||"),
		NULL);

	if (dlg.DoModal() == IDOK)
	{
		this->m_strCameraFile = dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}

	if (this->m_nIsCameraOnline)
	{
		this->m_Camera->Freeze();
		this->m_Camera->Destory();
	}
	this->m_Camera->SetFilePath(this->m_strCameraFile);
	this->m_nIsCameraOnline = this->m_Camera->InitCamera(this, 0, 0);
	if (this->m_nIsCameraOnline)
	{
		SetCameraOnlineAble();
	}
	else
	{
		AfxMessageBox("Camera is Off Line");
		this->m_Camera->Destory();
		SetCameraOfflineEnable();
	}
	
}


void CCwCameraMarsterDlg::SetCameraOfflineEnable()
{
	CStatic* camerastate = (CStatic*)GetDlgItem(IDC_STATIC_CAMERASTATE);
	camerastate->SetIcon(this->m_hicOffLineIcon);
	CButton* cbEnable;
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_LIVEMODE);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_GRAB);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERAUNLOAD);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_APERTURE);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_FOCUS);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_EXPORSURE);
	cbEnable->EnableWindow(FALSE);

}

void CCwCameraMarsterDlg::SetCameraOnlineAble()
{
	CStatic* camerastate = (CStatic*)GetDlgItem(IDC_STATIC_CAMERASTATE);
	camerastate->SetIcon(this->m_hicOnLineIcon);
	CButton* cbEnable;
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_LIVEMODE);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_GRAB);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERAUNLOAD);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_APERTURE);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_FOCUS);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_SET_EXPORSURE);
	cbEnable->EnableWindow(TRUE);
}

void CCwCameraMarsterDlg::SetGrabContinues()
{
	CStatic* GrabMode = (CStatic*)GetDlgItem(IDC_STATIC_MODESHOWER);
	GrabMode->SetIcon(this->m_hicOnLineIcon);
	CButton* cbEnable;
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_LOADIMAGE);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_GRAB);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERALOAD);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERAUNLOAD);
	cbEnable->EnableWindow(FALSE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMREARELOAD);
	cbEnable->EnableWindow(FALSE);
}

void CCwCameraMarsterDlg::SetGrabPerFrame()
{
	CStatic* GrabMode = (CStatic*)GetDlgItem(IDC_STATIC_MODESHOWER);
	GrabMode->SetIcon(this->m_hicOffLineIcon);
	CButton* cbEnable;
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_LOADIMAGE);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_GRAB);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERALOAD);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMERAUNLOAD);
	cbEnable->EnableWindow(TRUE);
	cbEnable = (CButton*)GetDlgItem(IDC_BUTTON_CAMREARELOAD);
	cbEnable->EnableWindow(TRUE);
}

void CCwCameraMarsterDlg::OnBnClickedButtonCameraunload()
{
	// TODO:  在此添加控件通知处理程序代码
	if (this->m_nIsCameraOnline)
	{
		this->m_Camera->Freeze();
		this->m_Camera->Destory();
		this->m_nIsCameraOnline = false;

		SetCameraOfflineEnable();
	}
}



void CCwCameraMarsterDlg::OnBnClickedButtonCamreareload()
{
	// TODO:  在此添加控件通知处理程序代码
	if (this->m_nIsCameraOnline)
	{
		this->m_Camera->Freeze();
		this->m_Camera->Destory();
		SetCameraOfflineEnable();
	}
	this->m_nIsCameraOnline = this->m_Camera->InitCamera(this,0,0);
	if (this->m_nIsCameraOnline)
	{
		SetCameraOnlineAble();
	}
	else
	{
		AfxMessageBox("Camera is Off Line");
		this->m_Camera->Destory();
		SetCameraOfflineEnable();
	}
}


void CCwCameraMarsterDlg::OnBnClickedButtonMainimgzoomin()
{
	// TODO:  在此添加控件通知处理程序代码
	this->m_nZoomStatus = CWCAMERAMASTER_ZOOMSTATUS_IN;
}


void CCwCameraMarsterDlg::OnBnClickedButtonPortsearch()
{
	// TODO:  在此添加控件通知处理程序代码
	//int i = 0;
	//CHAR Name[255];
	//UCHAR szPortName[255];
	//LONG Status;
	//DWORD dwIndex = 0;
	//DWORD dwName;
	//DWORD dwSizeofPortName;
	//DWORD Type;
	//HKEY hKey;
	//CString   strSerialList[256];  // 临时定义 256 个字符串组，因为系统最多也就 256 个 
	//LPCTSTR data_Set = "HARDWARE\\DEVICEMAP\\SERIALCOMM\\";
	//dwName = sizeof(Name);
	//dwSizeofPortName = sizeof(szPortName);
	////long ret0 = (::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey)); 
	//long ret0 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey); //打开一个制定的注册表键,成功返回ERROR_SUCCESS即“0”值
	//if (ret0 == ERROR_SUCCESS)
	//{
	//	do
	//	{

	//		Status = RegEnumValue(hKey, dwIndex++, Name, &dwName, NULL, &Type, szPortName, &dwSizeofPortName);//读取键值 
	//		if ((Status == ERROR_SUCCESS) || (Status == ERROR_MORE_DATA))
	//		{
	//			strSerialList[i] = CString(szPortName);       // 串口字符串保存 
	//			TRACE("serial:%s\n", strSerialList[i]);
	//			i++;// 串口计数 
	//		}
	//		//每读取一次dwName和dwSizeofPortName都会被修改 
	//		//注意一定要重置,否则会出现很离奇的错误,本人就试过因没有重置,出现先插入串口号大的（如COM4）,再插入串口号小的（如COM3），此时虽能发现两个串口，但都是同一串口号（COM4）的问题，同时也读不了COM大于10以上的串口 
	//		dwName = sizeof(Name);
	//		dwSizeofPortName = sizeof(szPortName);
	//	} while ((Status == ERROR_SUCCESS) || (Status == ERROR_MORE_DATA));

	//	RegCloseKey(hKey);
	//}

	
	if (this->birCon.InitConnect(this, ""))
	{
		TRACE("birger mount ok");
		int nFo(0);
		this->birCon.GetFocus(nFo);

	}
	else
		TRACE("birger mount ng");




}
