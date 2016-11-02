#pragma once
#include "CwCamerabase.h"
enum{
	CWCAMERATYPE_SVS,
	CWCAMERATYPE_VIEWWORKS
};

#ifdef ALG_CLASS_API

#else 
#define ALG_CLASS_API __declspec(dllimport)
#endif

class ALG_CLASS_API CCwCameraFactory
{
public:
	CCwCameraFactory(void);
	virtual ~CCwCameraFactory(void);
	CCwCamerabase * GetItem(int cameraType);
	bool DestoryItem(CCwCamerabase* & pTarget);
};
