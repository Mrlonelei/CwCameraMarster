
// CwCameraMarsterDlg.h : 头文件
//

#pragma once

#define WM_LIVESHOWIMAGE WM_USER+100
#define WM_LIVESHOWIMAGESTOP WM_USER+101
enum{
	CWCAMERAMASTER_SHOWIMG_LIVE,
	CWCAMERAMASTER_SHOWIMG_LOAD,
	CWCAMERAMASTER_SHOWIMG_NO
};

enum{
	CWCAMERAMASTER_ZOOMSTATUS_IN,
	CWCAMERAMASTER_ZOOMSTATUS_OUT,
	CWCAMERAMASTER_ZOOMSTATUS_OFF
};

#include "CwCamerabase.h"
#include "CwCameraFactory.h"
#include "CwBirgerMount.h"
// CCwCameraMarsterDlg 对话框
class CCwCameraMarsterDlg : public CDialogEx
{
// 构造
public:
	CCwCameraMarsterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CWCAMERAMARSTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	
	CString m_strCameraFile;
	CString m_strOneImageFileName;
	cv::Mat m_matSrcImg;
	cv::Mat m_matInfoImg;
	int m_nFocus;
	int m_nAperture;
	int m_nShutter;
	int m_nIsCameraOnline;

	float m_fXScale;
	float m_fYScale;

	CEdit* m_pedFocus;
	CEdit* m_pedApersture;
	CEdit* m_pedShutter;
	BYTE* m_imgData;
	IplImage* m_srcImg;
	HICON m_hicOnLineIcon;
	HICON m_hicOffLineIcon;
	CvRect m_CornerROI[4];

	int m_nShowImageMode;

	HANDLE m_hLiveThread;
	
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
	void LoadMemImage(uchar *pImgBuf, CImage &DesImg, int nWidth, int nHeight);
	int InfoProcessMain();
	
public:
	afx_msg void OnBnClickedButton2();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);

	static void GrabCallBack(void* pOwner, BYTE* ImgData);
	static void GrabDisplayCallBack(void* pOwner, BYTE* ImgData);

	CCwCameraFactory m_CameraFactory;
	CCwCamerabase* m_Camera;
	CwBirgerMount birCon;
	

	CSemaphore m_semExitLiveThreadFlag;
	int m_nExitLiveThreadFlag;

	int m_nZoomStatus;
	CvRect m_rectZoomROI;
	CvRect m_rectCurrentROI;

	float m_fcurrentXScale;
	float m_fcurrentYScale;

	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonSetFocus();
	afx_msg void OnBnClickedButtonGrab();
	afx_msg void OnBnClickedButtonLoadimage();
	//afx_msg void OnDestroy();
	//afx_msg void OnClose();
	afx_msg void OnCancel();
	afx_msg void OnOK();
	int GetShowImgMode();

	int PaintOnScreen(uchar* pImgBuf,int imgWidth, int imgHeight);
	int PaintOnScreenIDC(uchar* pImgBuf, int imgWidth, int imgHeight, UINT idcNum);
	int PaintOnScreenIDCMat(cv::Mat matSrcImg, UINT idcNum);
	 
	int SetCornerROI(int nX, int nY, int CornerNum);
	void PaintCornerImg(int CornerNum,int IDCNUM);
	

	void SetCameraOnlineAble();
	void SetCameraOfflineEnable();
	
	void SetGrabContinues();
	void SetGrabPerFrame();

	afx_msg void OnBnClickedButtonSetAperture();
	afx_msg void OnBnClickedButtonSetExporsure();
	afx_msg void OnMouseMoveSrcImg(UINT nID, LPARAM lParam);
	afx_msg void OnMouseLBCLKSetCorner(UINT nID, LPARAM lParam);
	afx_msg void OnLiveShowImage(HWND nID, LPARAM lParam);
	afx_msg void OnBnClickedButtonLivemode();
	afx_msg void OnBnClickedButtonCameraload();
	afx_msg void OnBnClickedButtonCameraunload();
	afx_msg void OnBnClickedButtonCamreareload();
	afx_msg void OnBnClickedButtonMainimgzoomin();
	afx_msg void OnBnClickedButtonPortsearch();
	afx_msg void OnHSBProcess(UINT nSBCode, UINT nPos, CScrollBar* pSB);
	afx_msg void OnVSBProcess(UINT nSBCode, UINT nPos, CScrollBar* pSB);
};
