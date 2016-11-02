#pragma once

#ifdef ALG_CAMERAINTERFACE_API

#else 
#define ALG_CAMERAINTERFACE_API __declspec(dllimport)
#endif

class __declspec(dllexport) CCwCamerabase
{
public:
	CCwCamerabase(void);
	virtual ~CCwCamerabase(void);
	virtual bool SetFilePath(const CString strPath) = 0;
	virtual bool InitCamera(CWnd* pParent,bool IsMilShow,int iIndex) = 0;
	virtual void Destory() = 0;
	virtual void Snap() = 0;
	virtual bool SetShutter(int iShutter) = 0;
	virtual bool SetFocus(int focus) = 0; 
	virtual bool SetAperture(int Aperture) = 0;
	virtual bool GetShutter(int &iShutter) = 0;
	virtual bool GetFocus(int &nFocus) = 0;
	virtual bool GetAperture(int &nAperture) = 0;
	virtual long GetImgWidth() = 0;
	virtual long GetImgHeight() = 0;
	virtual long GetImgPitch() = 0;
	virtual void GetImgBuffer(unsigned char **ImageBuffer) = 0; 
	virtual bool Freeze() = 0;
};


