#ifndef CONVCAM40DLLAPI
#define CONVCAM40DLLAPI

enum SVSError : int
{
	CAM_OK = 0,
	ERROR_NO_CAMERA_FOUND = -1,
	ERROR_UNDEFINED_SENSOR_TYPE = -2,
	ERROR_UNDEFINED_SERIALNO = -3,
};

//------------------
//ConvCamControlInterface
//------------------
//-------------Export functions  Start---------------------------------------------
/// <summary>
/// Integer set-function number
/// </summary>
enum SVSFunctionSetInteger : int
{
	/// <summary>
/// MagicWord1
/// </summary>
SVSsetIntMagicWord1 = 4125,

/// <summary>
/// SizeX
/// </summary>
SVSsetIntSizeX = 4127,

/// <summary>
/// AOI_SizeY
/// </summary>
SVSsetIntAOI_SizeY = 4128,

/// <summary>
/// AOI_OffsetY
/// </summary>
SVSsetIntAOI_OffsetY = 4129,

/// <summary>
/// Binning or Decimation HorizontalCount
/// </summary>
SVSsetIntBinningHorizontalCount = 4222,

/// <summary>
/// Binning or Decimation VerticalCount
/// </summary>
SVSsetIntBinningVerticalCount = 4223,

/// <summary>
/// MultiExposureCount
/// </summary>
SVSsetIntMultiExposureCount = 4265,

/// <summary>
/// MultiExposureDistance
/// </summary>
SVSsetIntMultiExposureDistance = 4266,

/// <summary>
/// ExposureAutoMax
/// </summary>
SVSsetIntExposureAutoMax = 4225,

/// <summary>
/// ExposureAutoMin
/// </summary>
SVSsetIntExposureAutoMin = 4226,

/// <summary>
/// BlackLevelRaw
/// </summary>
SVSsetIntBlackLevelRaw = 4172,

/// <summary>
/// BalanceWhite_Red
/// </summary>
SVSsetIntBalanceWhite_Red = 4229,

/// <summary>
/// BalanceWhite_Green
/// </summary>
SVSsetIntBalanceWhite_Green = 4230,

/// <summary>
/// BalanceWhite_Blue
/// </summary>
SVSsetIntBalanceWhite_Blue = 4231,

/// <summary>
/// GainAutoLevel
/// </summary>
SVSsetIntGainAutoLevel = 4233,

/// <summary>
/// H1_PosPhase
/// </summary>
SVSsetIntH1_PosPhase = 4192,

/// <summary>
/// H1_NegPhase
/// </summary>
SVSsetIntH1_NegPhase = 4193,

/// <summary>
/// RG_PosPhase
/// </summary>
SVSsetIntRG_PosPhase = 4194,

/// <summary>
/// RG_NegPhase
/// </summary>
SVSsetIntRG_NegPhase = 4195,

/// <summary>
/// SHP_Phase
/// </summary>
SVSsetIntSHP_Phase = 4196,

/// <summary>
/// SHD_Phase
/// </summary>
SVSsetIntSHD_Phase = 4197,

/// <summary>
/// Dout_Phase
/// </summary>
SVSsetIntDout_Phase = 4198,

/// <summary>
/// Tclk_Phase
/// </summary>
SVSsetIntTclk_Phase = 4199,

/// <summary>
/// Gain0dB_Tap0
/// </summary>
SVSsetIntGain0dB_Tap0 = 4201,

/// <summary>
/// Gain0dB_Tap1
/// </summary>
SVSsetIntGain0dB_Tap1 = 4202,

/// <summary>
/// Gain0dB_Tap2
/// </summary>
SVSsetIntGain0dB_Tap2 = 4203,

/// <summary>
/// Gain0dB_Tap3
/// </summary>
SVSsetIntGain0dB_Tap3 = 4204,

/// <summary>
/// BlackLevel_Tap0
/// </summary>
SVSsetIntBlackLevel_Tap0 = 4205,

/// <summary>
/// BlackLevel_Tap1
/// </summary>
SVSsetIntBlackLevel_Tap1 = 4206,

/// <summary>
/// BlackLevel_Tap2
/// </summary>
SVSsetIntBlackLevel_Tap2 = 4207,

/// <summary>
/// BlackLevel_Tap3
/// </summary>
SVSsetIntBlackLevel_Tap3 = 4208,

/// <summary>
/// SubstratVoltage
/// </summary>
SVSsetIntSubstratVoltage = 4209,

/// <summary>
/// SensorSerialNo
/// </summary>
SVSsetIntSensorSerialNo = 4210,

/// <summary>
/// MagicWord2
/// </summary>
SVSsetIntMagicWord2 = 4211,

/// <summary>
/// DigitalGain
/// </summary>
SVSsetIntDigitalGain = 4237,

/// <summary>
/// DigitalOffset
/// </summary>
SVSsetIntDigitalOffset = 4238,

/// <summary>
/// CrosshairPixelWidth
/// </summary>
SVSsetIntCrosshairPixelWidth = 4239,

/// <summary>
/// CrosshairPositionX
/// </summary>
SVSsetIntCrosshairPositionX = 4240,

/// <summary>
/// CrosshairPositionY
/// </summary>
SVSsetIntCrosshairPositionY = 4241,

/// <summary>
/// LUTIndex
/// </summary>
SVSsetIntLUTIndex = 4244,

/// <summary>
/// LUTValue
/// </summary>
SVSsetIntLUTValue = 4245,

/// <summary>
/// TemperaturSensor
/// </summary>
SVSsetIntTemperaturSensor = 4246,

/// <summary>
/// ADCTestValue
/// </summary>
SVSsetIntADCTestValue = 4248,
/// <summary>
/// DefectPixelOffsetX
/// </summary>
SVSsetIntDefectPixelOffsetX = 4252,

/// <summary>
/// DefectPixelOffsetY
/// </summary>
SVSsetIntDefectPixelOffsetY = 4253,

/// <summary>
/// DefectPixelMapSize
/// </summary>
SVSsetIntDefectPixelMapSize = 4254,

/// <summary>
/// DefectPixelMapIndex
/// </summary>
SVSsetIntDefectPixelMapIndex = 4255,

/// <summary>
/// DefectPixelX
/// </summary>
SVSsetIntDefectPixelX = 4256,

/// <summary>
/// DefectPixelY
/// </summary>
SVSsetIntDefectPixelY = 4257,

/// <summary>
/// DeviceStatus
/// </summary>
SVSsetIntDeviceStatus = 4214,

/// <summary>
/// DeviceCookie
/// </summary>
SVSsetIntDeviceCookie = 4215,

/// <summary>
/// Focus
/// </summary>
SVSsetIntFocus = 4262,

/// <summary>
/// Aperture
/// </summary>
SVSsetIntAperture = 4263,

};
/// <summary>
/// Integer get-function number 
/// </summary>
enum SVSFunctionGetInteger : int
{
/// <summary>
/// MagicWord1
/// </summary>
SVSgetIntMagicWord1 = 8221,

/// <summary>
/// SizeX
/// </summary>
SVSgetIntSizeX = 8223,

/// <summary>
/// AOI_SizeY
/// </summary>
SVSgetIntAOI_SizeY = 8224,

/// <summary>
/// AOI_OffsetY
/// </summary>
SVSgetIntAOI_OffsetY = 8225,

/// <summary>
/// BinningHorizontalCount
/// </summary>
SVSgetIntBinningHorizontalCount = 8318,

/// <summary>
/// BinningVerticalCount
/// </summary>
SVSgetIntBinningVerticalCount = 8319,

/// <summary>
/// MultiExposureCount
/// </summary>
SVSgetIntMultiExposureCount = 8361,

/// <summary>
/// MultiExposureDistance
/// </summary>
SVSgetIntMultiExposureDistance = 8362,

/// <summary>
/// ExposureAutoMax
/// </summary>
SVSgetIntExposureAutoMax = 8321,

/// <summary>
/// ExposureAutoMin
/// </summary>
SVSgetIntExposureAutoMin = 8322,

/// <summary>
/// BlackLevelRaw
/// </summary>
SVSgetIntBlackLevelRaw = 8268,

/// <summary>
/// BalanceWhite_Red
/// </summary>
SVSgetIntBalanceWhite_Red = 8325,

/// <summary>
/// BalanceWhite_Green
/// </summary>
SVSgetIntBalanceWhite_Green = 8326,

/// <summary>
/// BalanceWhite_Blue
/// </summary>
SVSgetIntBalanceWhite_Blue = 8327,

/// <summary>
/// GainAutoLevel
/// </summary>
SVSgetIntGainAutoLevel = 8329,

/// <summary>
/// H1_PosPhase
/// </summary>
SVSgetIntH1_PosPhase = 8288,

/// <summary>
/// H1_NegPhase
/// </summary>
SVSgetIntH1_NegPhase = 8289,

/// <summary>
/// RG_PosPhase
/// </summary>
SVSgetIntRG_PosPhase = 8290,

/// <summary>
/// RG_NegPhase
/// </summary>
SVSgetIntRG_NegPhase = 8291,

/// <summary>
/// SHP_Phase
/// </summary>
SVSgetIntSHP_Phase = 8292,

/// <summary>
/// SHD_Phase
/// </summary>
SVSgetIntSHD_Phase = 8293,

/// <summary>
/// Dout_Phase
/// </summary>
SVSgetIntDout_Phase = 8294,

/// <summary>
/// Tclk_Phase
/// </summary>
SVSgetIntTclk_Phase = 8295,

/// <summary>
/// Gain0dB_Tap0
/// </summary>
SVSgetIntGain0dB_Tap0 = 8297,

/// <summary>
/// Gain0dB_Tap1
/// </summary>
SVSgetIntGain0dB_Tap1 = 8298,

/// <summary>
/// Gain0dB_Tap2
/// </summary>
SVSgetIntGain0dB_Tap2 = 8299,

/// <summary>
/// Gain0dB_Tap3
/// </summary>
SVSgetIntGain0dB_Tap3 = 8300,

/// <summary>
/// BlackLevel_Tap0
/// </summary>
SVSgetIntBlackLevel_Tap0 = 8301,

/// <summary>
/// BlackLevel_Tap1
/// </summary>
SVSgetIntBlackLevel_Tap1 = 8302,

/// <summary>
/// BlackLevel_Tap2
/// </summary>
SVSgetIntBlackLevel_Tap2 = 8303,

/// <summary>
/// BlackLevel_Tap3
/// </summary>
SVSgetIntBlackLevel_Tap3 = 8304,

/// <summary>
/// SubstratVoltage
/// </summary>
SVSgetIntSubstratVoltage = 8305,

/// <summary>
/// SensorSerialNo
/// </summary>
SVSgetIntSensorSerialNo = 8306,

/// <summary>
/// MagicWord2
/// </summary>
SVSgetIntMagicWord2 = 8307,

/// <summary>
/// DigitalGain
/// </summary>
SVSgetIntDigitalGain = 8333,

/// <summary>
/// DigitalOffset
/// </summary>
SVSgetIntDigitalOffset = 8334,

/// <summary>
/// CrosshairPixelWidth
/// </summary>
SVSgetIntCrosshairPixelWidth = 8335,

/// <summary>
/// CrosshairPositionX
/// </summary>
SVSgetIntCrosshairPositionX = 8336,

/// <summary>
/// CrosshairPositionY
/// </summary>
SVSgetIntCrosshairPositionY = 8337,

/// <summary>
/// LUTIndex
/// </summary>
SVSgetIntLUTIndex = 8340,

/// <summary>
/// LUTValue
/// </summary>
SVSgetIntLUTValue = 8341,

/// <summary>
/// TemperaturSensor
/// </summary>
SVSgetIntTemperaturSensor = 8342,

/// <summary>
/// ADCTestValue
/// </summary>
SVSgetIntADCTestValue = 8344,
/// <summary>
/// DefectPixelOffsetX
/// </summary>
SVSgetIntDefectPixelOffsetX = 8348,

/// <summary>
/// DefectPixelOffsetY
/// </summary>
SVSgetIntDefectPixelOffsetY = 8349,

/// <summary>
/// DefectPixelMapSize
/// </summary>
SVSgetIntDefectPixelMapSize = 8350,

/// <summary>
/// DefectPixelMapIndex
/// </summary>
SVSgetIntDefectPixelMapIndex = 8351,

/// <summary>
/// DefectPixelX
/// </summary>
SVSgetIntDefectPixelX = 8352,

/// <summary>
/// DefectPixelY
/// </summary>
SVSgetIntDefectPixelY = 8353,

/// <summary>
/// DeviceStatus
/// </summary>
SVSgetIntDeviceStatus = 8310,

/// <summary>
/// DeviceCookie
/// </summary>
SVSgetIntDeviceCookie = 8311,

/// <summary>
/// Focus
/// </summary>
SVSgetIntFocus = 8358,

/// <summary>
/// Aperture
/// </summary>
SVSgetIntAperture = 8359,

};
/// <summary>
/// String set-function number
/// </summary>
enum SVSFunctionSetString : int
{
	/// <summary>
	/// DeviceModelName, testing purposes only
	/// </summary>
	SVSsetStringDeviceModelName = 4098,

	/// <summary>
	/// DeviceID, testing purposes only
	/// </summary>
	SVSsetStringDeviceID = 4099,

	/// <summary>
	/// DeviceManufacturerInfo, testing purposes only
	/// </summary>
	SVSsetStringDeviceManufacturerInfo = 4100,

	/// <summary>
	/// DeviceVersion, testing purposes only
	/// </summary>
	SVSsetStringDeviceVersion = 4101,

	/// <summary>
	/// ReadLines, testing purposes only
	/// </summary>
	SVSsetStringReadLines = 4190,

	};
	/// <summary>
	/// String get-function number
	/// </summary>
	enum SVSFunctionGetString : int
	{
	/// <summary>
	/// DeviceModelName
	/// </summary>
	SVSgetStringDeviceModelName = 8194,

	/// <summary>
	/// DeviceID
	/// </summary>
	SVSgetStringDeviceID = 8195,

	/// <summary>
	/// DeviceManufacturerInfo
	/// </summary>
	SVSgetStringDeviceManufacturerInfo = 8196,

	/// <summary>
	/// DeviceVersion
	/// </summary>
	SVSgetStringDeviceVersion = 8197,

	/// <summary>
	/// ReadLines, testing purposes only
	/// </summary>
	SVSgetStringReadLines = 8286,

};

/// <summary>
/// Event set-function number
/// </summary>
enum SVSFunctionSetEvent : int
{
	/// <summary>
	/// TriggerSoftware
	/// </summary>
	SVSsetEventTriggerSoftware = 4152,

	/// <summary>
	/// UserSetLoad
	/// </summary>
	SVSsetEventUserSetLoad = 4186,

	/// <summary>
	/// UserSetSave
	/// </summary>
	SVSsetEventUserSetSave = 4187,

	/// <summary>
	/// FactorySetSave, testing purposes only
	/// </summary>
	SVSsetEventFactorySetSave = 4188,

	/// <summary>
	/// SensorDataStore, testing purposes only
	/// </summary>
	SVSsetEventSensorDataStore = 4212,

 /// <summary>
/// DefectPixelDelete
/// </summary>
SVSsetEventDefectPixelDelete = 4258,

/// <summary>
/// DefectMapSave
/// </summary>
SVSsetEventDefectMapSave = 4259,

	/// <summary>
	/// DeviceDisconnect, testing purposes only
	/// </summary>
	SVSsetEventDeviceDisconnect = 4216,

};

/// <summary>
/// Double set-function number
/// </summary>
enum SVSFunctionSetDouble : int
{
	/// <summary>
/// AcquisitionFrameRate
/// </summary>
SVSsetDoubleAcquisitionFrameRate = 4162,

/// <summary>
/// ExposureTime
/// </summary>
SVSsetDoubleExposureTime = 4163,

/// <summary>
/// Gain
/// </summary>
SVSsetDoubleGain = 4171,

/// <summary>
/// GainAutoMax
/// </summary>
SVSsetDoubleGainAutoMax = 4234,

/// <summary>
/// GainAutoMin
/// </summary>
SVSsetDoubleGainAutoMin = 4235,

/// <summary>
/// ExposureDelay
/// </summary>
SVSsetDoubleExposureDelay = 4179,

/// <summary>
/// StrobeDuration
/// </summary>
SVSsetDoubleStrobeDuration = 4183,

/// <summary>
/// StrobeDelay
/// </summary>
SVSsetDoubleStrobeDelay = 4184,
};


/// <summary>
/// Double get-function number
/// </summary>
enum SVSFunctionGetDouble : int
{
	/// <summary>
/// AcquisitionFrameRate
/// </summary>
SVSgetDoubleAcquisitionFrameRate = 8258,

/// <summary>
/// ExposureTime
/// </summary>
SVSgetDoubleExposureTime = 8259,

/// <summary>
/// Gain
/// </summary>
SVSgetDoubleGain = 8267,

/// <summary>
/// GainAutoMax
/// </summary>
SVSgetDoubleGainAutoMax = 8330,

/// <summary>
/// GainAutoMin
/// </summary>
SVSgetDoubleGainAutoMin = 8331,

/// <summary>
/// ExposureDelay
/// </summary>
SVSgetDoubleExposureDelay = 8275,

/// <summary>
/// StrobeDuration
/// </summary>
SVSgetDoubleStrobeDuration = 8279,

/// <summary>
/// StrobeDelay
/// </summary>
SVSgetDoubleStrobeDelay = 8280,


};


/// <summary>
/// Enumeration set-function
/// </summary>
enum SVSFunctionSetEnumeration : int
{
	/// <summary>
/// CameraType
/// </summary>
SVSsetEnumCameraType = 4102,

/// <summary>
/// PixelFrequency
/// </summary>
SVSsetEnumPixelFrequency = 4115,

/// <summary>
/// TapConfiguration
/// </summary>
SVSsetEnumTapConfiguration = 4118,

/// <summary>
/// DeviceScanType
/// </summary>
SVSsetEnumDeviceScanType = 4123,

/// <summary>
/// ResolutionMode
/// </summary>
SVSsetEnumResolutionMode = 4130,

/// <summary>
/// ColorFilter
/// </summary>
SVSsetEnumColorFilter = 4135,

/// <summary>
/// ColorDepth
/// </summary>
SVSsetEnumColorDepth = 4141,

/// <summary>
/// ColorConversion
/// </summary>
SVSsetEnumColorConversion = 4264,

/// <summary>
/// AcquisitionMode
/// </summary>
SVSsetEnumAcquisitionMode = 4146,

/// <summary>
/// TriggerSource
/// </summary>
SVSsetEnumTriggerSource = 4153,

/// <summary>
/// TriggerPolarity
/// </summary>
SVSsetEnumTriggerPolarity = 4159,

/// <summary>
/// ExposureAuto
/// </summary>
SVSsetEnumExposureAuto = 4224,

/// <summary>
/// TapSelector
/// </summary>
SVSsetEnumTapSelector = 4165,

/// <summary>
/// TapBalance
/// </summary>
SVSsetEnumTapBalance = 4173,

/// <summary>
/// WhiteBalanceMode
/// </summary>
SVSsetEnumWhiteBalanceMode = 4227,

/// <summary>
/// BalanceWhiteAuto
/// </summary>
SVSsetEnumBalanceWhiteAuto = 4228,

/// <summary>
/// GainAuto
/// </summary>
SVSsetEnumGainAuto = 4232,

/// <summary>
/// AutoExposureFirst
/// </summary>
SVSsetEnumAutoExposureFirst = 4236,

/// <summary>
/// StrobePolarity
/// </summary>
SVSsetEnumStrobePolarity = 4180,

/// <summary>
/// TestPattern
/// </summary>
SVSsetEnumTestPattern = 4242,

/// <summary>
/// LUTEnable
/// </summary>
SVSsetEnumLUTEnable = 4243,

/// <summary>
/// ADCTestEnable
/// </summary>
SVSsetEnumADCTestEnable = 4247,

/// <summary>
/// DefectPixelCorrectionEnable
/// </summary>
SVSsetEnumDefectPixelCorrectionEnable = 4249,

/// <summary>
/// DefectPixelCorrectionMark
/// </summary>
SVSsetEnumDefectPixelCorrectionMark = 4250,

/// <summary>
/// DefectPixelCorrectionMapSelect
/// </summary>
SVSsetEnumDefectPixelCorrectionMapSelect = 4251,

/// <summary>
/// PIVModeEnable
/// </summary>
SVSsetEnumPIVModeEnable = 4261,

};


/// <summary>
/// Enumeration get-function
/// </summary>
enum SVSFunctionGetEnumeration : int
{
/// <summary>
/// CameraType
/// </summary>
SVSgetEnumCameraType = 8198,

/// <summary>
/// PixelFrequency
/// </summary>
SVSgetEnumPixelFrequency = 8211,

/// <summary>
/// TapConfiguration
/// </summary>
SVSgetEnumTapConfiguration = 8214,

/// <summary>
/// DeviceScanType
/// </summary>
SVSgetEnumDeviceScanType = 8219,

/// <summary>
/// ResolutionMode
/// </summary>
SVSgetEnumResolutionMode = 8226,

/// <summary>
/// ColorConversion
/// </summary>
SVSgetEnumColorConversion = 8360,

/// <summary>
/// ColorFilter
/// </summary>
SVSgetEnumColorFilter = 8231,

/// <summary>
/// ColorDepth
/// </summary>
SVSgetEnumColorDepth = 8237,

/// <summary>
/// AcquisitionMode
/// </summary>
SVSgetEnumAcquisitionMode = 8242,

/// <summary>
/// TriggerSource
/// </summary>
SVSgetEnumTriggerSource = 8249,

/// <summary>
/// TriggerPolarity
/// </summary>
SVSgetEnumTriggerPolarity = 8255,

/// <summary>
/// ExposureAuto
/// </summary>
SVSgetEnumExposureAuto = 8320,

/// <summary>
/// TapSelector
/// </summary>
SVSgetEnumTapSelector = 8261,

/// <summary>
/// TapBalance
/// </summary>
SVSgetEnumTapBalance = 8269,

/// <summary>
/// WhiteBalanceMode
/// </summary>
SVSgetEnumWhiteBalanceMode = 8323,

/// <summary>
/// BalanceWhiteAuto
/// </summary>
SVSgetEnumBalanceWhiteAuto = 8324,

/// <summary>
/// GainAuto
/// </summary>
SVSgetEnumGainAuto = 8328,

/// <summary>
/// AutoExposureFirst
/// </summary>
SVSgetEnumAutoExposureFirst = 8332,

/// <summary>
/// StrobePolarity
/// </summary>
SVSgetEnumStrobePolarity = 8276,

/// <summary>
/// TestPattern
/// </summary>
SVSgetEnumTestPattern = 8338,

/// <summary>
/// LUTEnable
/// </summary>
SVSgetEnumLUTEnable = 8339,

/// <summary>
/// ADCTestEnable
/// </summary>
SVSgetEnumADCTestEnable = 8343,

/// <summary>
/// DefectPixelCorrectionEnable
/// </summary>
SVSgetEnumDefectPixelCorrectionEnable = 8345,

/// <summary>
/// DefectPixelCorrectionMark
/// </summary>
SVSgetEnumDefectPixelCorrectionMark = 8346,

/// <summary>
/// DefectPixelCorrectionMapSelect
/// </summary>
SVSgetEnumDefectPixelCorrectionMapSelect = 8347,

/// <summary>
/// PIVModeEnable
/// </summary>
SVSgetEnumPIVModeEnable = 8357,


};

/// <summary>
/// EnumEntities
/// </summary>
enum SVSEnumEntity : int
{
	/// <summary>
/// EnumEntry_CameraType_evo1050M
/// </summary>
SVSEntityEnumEntry_CameraType_evo1050M = 1,
/// <summary>
/// EnumEntry_CameraType_evo1050C
/// </summary>
SVSEntityEnumEntry_CameraType_evo1050C = 2,
/// <summary>
/// EnumEntry_CameraType_evo2050M
/// </summary>
SVSEntityEnumEntry_CameraType_evo2050M = 3,
/// <summary>
/// EnumEntry_CameraType_evo2050C
/// </summary>
SVSEntityEnumEntry_CameraType_evo2050C = 4,
/// <summary>
/// EnumEntry_CameraType_evo2150M
/// </summary>
SVSEntityEnumEntry_CameraType_evo2150M = 5,
/// <summary>
/// EnumEntry_CameraType_evo2150C
/// </summary>
SVSEntityEnumEntry_CameraType_evo2150C = 6,
/// <summary>
/// EnumEntry_CameraType_evo4050M
/// </summary>
SVSEntityEnumEntry_CameraType_evo4050M = 7,
/// <summary>
/// EnumEntry_CameraType_evo4050C
/// </summary>
SVSEntityEnumEntry_CameraType_evo4050C = 8,
/// <summary>
/// EnumEntry_CameraType_evo8050M
/// </summary>
SVSEntityEnumEntry_CameraType_evo8050M = 9,
/// <summary>
/// EnumEntry_CameraType_evo8050C
/// </summary>
SVSEntityEnumEntry_CameraType_evo8050C = 10,
/// <summary>
/// EnumEntry_CameraType_hr29050M
/// </summary>
SVSEntityEnumEntry_CameraType_hr29050M = 11,
/// <summary>
/// EnumEntry_CameraType_hr29050C
/// </summary>
SVSEntityEnumEntry_CameraType_hr29050C = 12,
/// <summary>
/// EnumEntry_CameraType_hr16000M
/// </summary>
SVSEntityEnumEntry_CameraType_hr16000M = 13,
/// <summary>
/// EnumEntry_CameraType_hr16000C
/// </summary>
SVSEntityEnumEntry_CameraType_hr16000C = 14,
/// <summary>
/// EnumEntry_CameraType_hr16050M
/// </summary>
SVSEntityEnumEntry_CameraType_hr16050M = 15,
/// <summary>
/// EnumEntry_CameraType_hr16050C
/// </summary>
SVSEntityEnumEntry_CameraType_hr16050C = 16,
/// <summary>
/// EnumEntry_CameraType_hr16070M
/// </summary>
SVSEntityEnumEntry_CameraType_hr16070M = 17,
/// <summary>
/// EnumEntry_CameraType_hr16070C
/// </summary>
SVSEntityEnumEntry_CameraType_hr16070C = 18,
/// <summary>
/// EnumEntry_CameraType_evo4070M
/// </summary>
SVSEntityEnumEntry_CameraType_evo4070M = 19,
/// <summary>
/// EnumEntry_CameraType_evo4070C
/// </summary>
SVSEntityEnumEntry_CameraType_evo4070C = 20,
/************************/
/// <summary>
/// EnumEntry_PixelFrequency_FrequencyH64L48MHz
/// </summary>
SVSEntityEnumEntry_PixelFrequency_FrequencyH64L48MHz = 64000000,
/// <summary>
/// EnumEntry_PixelFrequency_Frequency40MHz
/// </summary>
SVSEntityEnumEntry_PixelFrequency_Frequency40MHz = 40000000,
/// <summary>
/// EnumEntry_PixelFrequency_Frequency32MHz
/// </summary>
SVSEntityEnumEntry_PixelFrequency_Frequency32MHz = 32000000,
/************************/
/// <summary>
/// EnumEntry_TapConfiguration_SINGLE
/// </summary>
SVSEntityEnumEntry_TapConfiguration_SINGLE = 1,
/// <summary>
/// EnumEntry_TapConfiguration_DUAL_X
/// </summary>
SVSEntityEnumEntry_TapConfiguration_DUAL_X = 2,
/// <summary>
/// EnumEntry_TapConfiguration_DUAL_Y
/// </summary>
SVSEntityEnumEntry_TapConfiguration_DUAL_Y = 3,
/// <summary>
/// EnumEntry_TapConfiguration_QUAD
/// </summary>
SVSEntityEnumEntry_TapConfiguration_QUAD = 4,
/// <summary>
/// EnumEntry_TapConfiguration_QUAD_TO_DUAL_Y
/// </summary>
SVSEntityEnumEntry_TapConfiguration_QUAD_TO_DUAL_Y = 5,
/// <summary>
/// EnumEntry_TapConfiguration_DUAL_X_TO_SINGLE
/// </summary>
SVSEntityEnumEntry_TapConfiguration_DUAL_X_TO_SINGLE = 6,
/************************/
/// <summary>
/// EnumEntry_DeviceScanType_Areascan
/// </summary>
SVSEntityEnumEntry_DeviceScanType_Areascan = 0,
/************************/
/// <summary>
/// EnumEntry_ResolutionMode_Max_Resolution
/// </summary>
SVSEntityEnumEntry_ResolutionMode_Max_Resolution = 0,
/// <summary>
/// EnumEntry_ResolutionMode_BinningHorizontal
/// </summary>
SVSEntityEnumEntry_ResolutionMode_BinningHorizontal = 1,
/// <summary>
/// EnumEntry_ResolutionMode_BinningVertical
/// </summary>
SVSEntityEnumEntry_ResolutionMode_BinningVertical = 2,
/// <summary>
/// EnumEntry_ResolutionMode_Binning2x2
/// </summary>
SVSEntityEnumEntry_ResolutionMode_Binning2x2 = 3,
/// <summary>
/// EnumEntry_ResolutionMode_DecimationVertical
/// </summary>
SVSEntityEnumEntry_ResolutionMode_DecimationVertical = 6,
/// <summary>
/// EnumEntry_ResolutionMode_DecimationHorizontal
/// </summary>
SVSEntityEnumEntry_ResolutionMode_DecimationHorizontal = 9,
/// <summary>
/// EnumEntry_ResolutionMode_DecimationBoth
/// </summary>
SVSEntityEnumEntry_ResolutionMode_DecimationBoth = 15,
/************************/
/// <summary>
/// EnumEntry_ColorFilter_ColorFilter_none
/// </summary>
SVSEntityEnumEntry_ColorFilter_ColorFilter_none = 0,
/// <summary>
/// EnumEntry_ColorFilter_ColorFilter_RG
/// </summary>
SVSEntityEnumEntry_ColorFilter_ColorFilter_RG = 1,
/// <summary>
/// EnumEntry_ColorFilter_ColorFilter_GR
/// </summary>
SVSEntityEnumEntry_ColorFilter_ColorFilter_GR = 2,
/// <summary>
/// EnumEntry_ColorFilter_ColorFilter_GB
/// </summary>
SVSEntityEnumEntry_ColorFilter_ColorFilter_GB = 3,
/// <summary>
/// EnumEntry_ColorFilter_ColorFilter_BG
/// </summary>
SVSEntityEnumEntry_ColorFilter_ColorFilter_BG = 4,
/************************/
/// <summary>
/// EnumEntry_ColorDepth_ColorDepth_8BPP_high
/// </summary>
SVSEntityEnumEntry_ColorDepth_ColorDepth_8BPP_high = 0,
/// <summary>
/// EnumEntry_ColorDepth_ColorDepth_8BPP_low
/// </summary>
SVSEntityEnumEntry_ColorDepth_ColorDepth_8BPP_low = 1,
/// <summary>
/// EnumEntry_ColorDepth_ColorDepth_12BPP
/// </summary>
SVSEntityEnumEntry_ColorDepth_ColorDepth_12BPP = 2,
/************************/
/// <summary>
/// EnumEntry_AcquisitionMode_NoAquisition
/// </summary>
SVSEntityEnumEntry_AcquisitionMode_NoAquisition = 0,
/// <summary>
/// EnumEntry_AcquisitionMode_Continuous
/// </summary>
SVSEntityEnumEntry_AcquisitionMode_Continuous = 1,
/// <summary>
/// EnumEntry_AcquisitionMode_SoftwareTrigger
/// </summary>
SVSEntityEnumEntry_AcquisitionMode_SoftwareTrigger = 2,
/// <summary>
/// EnumEntry_AcquisitionMode_TriggeredInternalExpoCtrl
/// </summary>
SVSEntityEnumEntry_AcquisitionMode_TriggeredInternalExpoCtrl = 3,
/// <summary>
/// EnumEntry_AcquisitionMode_TriggeredExternalExpoCtrl
/// </summary>
SVSEntityEnumEntry_AcquisitionMode_TriggeredExternalExpoCtrl = 4,
/************************/
/// <summary>
/// EnumEntry_TriggerSource_OFF
/// </summary>
SVSEntityEnumEntry_TriggerSource_OFF = 0,
/// <summary>
/// EnumEntry_TriggerSource_DI1
/// </summary>
SVSEntityEnumEntry_TriggerSource_DI1 = 1,
/// <summary>
/// EnumEntry_TriggerSource_DI2
/// </summary>
SVSEntityEnumEntry_TriggerSource_DI2 = 2,
/// <summary>
/// EnumEntry_TriggerSource_CC1
/// </summary>
SVSEntityEnumEntry_TriggerSource_CC1 = 4,
/// <summary>
/// EnumEntry_TriggerSource_CC2
/// </summary>
SVSEntityEnumEntry_TriggerSource_CC2 = 8,
/************************/
/// <summary>
/// EnumEntry_TriggerPolarity_Positive
/// </summary>
SVSEntityEnumEntry_TriggerPolarity_Positive = 0,
/// <summary>
/// EnumEntry_TriggerPolarity_Negative
/// </summary>
SVSEntityEnumEntry_TriggerPolarity_Negative = 1,
/************************/
/// <summary>
/// EnumEntry_ColorConversion_Off
/// </summary>
SVSEntityEnumEntry_ColorConversion_Off = 0,
/// <summary>
/// EnumEntry_ColorConversion_YUV
/// </summary>
SVSEntityEnumEntry_ColorConversion_YUV = 1,
/************************/
/// <summary>
/// EnumEntry_ExposureAuto_Off
/// </summary>
SVSEntityEnumEntry_ExposureAuto_Off = 0,
/// <summary>
/// EnumEntry_ExposureAuto_Continuous
/// </summary>
SVSEntityEnumEntry_ExposureAuto_Continuous = 1,
/************************/
/// <summary>
/// EnumEntry_TapSelector_TapAll
/// </summary>
SVSEntityEnumEntry_TapSelector_TapAll = 0,
/// <summary>
/// EnumEntry_TapSelector_Tap0
/// </summary>
SVSEntityEnumEntry_TapSelector_Tap0 = 1,
/// <summary>
/// EnumEntry_TapSelector_Tap1
/// </summary>
SVSEntityEnumEntry_TapSelector_Tap1 = 2,
/// <summary>
/// EnumEntry_TapSelector_Tap2
/// </summary>
SVSEntityEnumEntry_TapSelector_Tap2 = 3,
/// <summary>
/// EnumEntry_TapSelector_Tap3
/// </summary>
SVSEntityEnumEntry_TapSelector_Tap3 = 4,
/************************/
/// <summary>
/// EnumEntry_TapBalance_TapBalance_Off
/// </summary>
SVSEntityEnumEntry_TapBalance_TapBalance_Off = 0,
/// <summary>
/// EnumEntry_TapBalance_TapBalance_Once
/// </summary>
SVSEntityEnumEntry_TapBalance_TapBalance_Once = 1,
/// <summary>
/// EnumEntry_TapBalance_TapBalance_Continuous
/// </summary>
SVSEntityEnumEntry_TapBalance_TapBalance_Continuous = 2,
/// <summary>
/// EnumEntry_TapBalance_TapBalance_Reset
/// </summary>
SVSEntityEnumEntry_TapBalance_TapBalance_Reset = 3,
/************************/
/// <summary>
/// EnumEntry_WhiteBalanceMode_Approximative
/// </summary>
SVSEntityEnumEntry_WhiteBalanceMode_Approximative = 0,
/// <summary>
/// EnumEntry_WhiteBalanceMode_Immediate
/// </summary>
SVSEntityEnumEntry_WhiteBalanceMode_Immediate = 1,
/************************/
/// <summary>
/// EnumEntry_BalanceWhiteAuto_Off
/// </summary>
SVSEntityEnumEntry_BalanceWhiteAuto_Off = 0,
/// <summary>
/// EnumEntry_BalanceWhiteAuto_Once
/// </summary>
SVSEntityEnumEntry_BalanceWhiteAuto_Once = 1,
/// <summary>
/// EnumEntry_BalanceWhiteAuto_Continuous
/// </summary>
SVSEntityEnumEntry_BalanceWhiteAuto_Continuous = 2,
/// <summary>
/// EnumEntry_BalanceWhiteAuto_Reset
/// </summary>
SVSEntityEnumEntry_BalanceWhiteAuto_Reset = 3,
/************************/
/// <summary>
/// EnumEntry_GainAuto_Off
/// </summary>
SVSEntityEnumEntry_GainAuto_Off = 0,
/// <summary>
/// EnumEntry_GainAuto_Continuous
/// </summary>
SVSEntityEnumEntry_GainAuto_Continuous = 1,
/************************/
/// <summary>
/// EnumEntry_AutoExposureFirst_Off
/// </summary>
SVSEntityEnumEntry_AutoExposureFirst_Off = 0,
/// <summary>
/// EnumEntry_AutoExposureFirst_On
/// </summary>
SVSEntityEnumEntry_AutoExposureFirst_On = 1,
/************************/
/// <summary>
/// EnumEntry_StrobePolarity_Positive
/// </summary>
SVSEntityEnumEntry_StrobePolarity_Positive = 0,
/// <summary>
/// EnumEntry_StrobePolarity_Negative
/// </summary>
SVSEntityEnumEntry_StrobePolarity_Negative = 1,
/************************/
/// <summary>
/// EnumEntry_TestPattern_Off
/// </summary>
SVSEntityEnumEntry_TestPattern_Off = 0,
/// <summary>
/// EnumEntry_TestPattern_Graukeil
/// </summary>
SVSEntityEnumEntry_TestPattern_Graukeil = 1,
/// <summary>
/// EnumEntry_TestPattern_Grayscale
/// </summary>
SVSEntityEnumEntry_TestPattern_Grayscale = 2,
/// <summary>
/// EnumEntry_TestPattern_Colorscale
/// </summary>
SVSEntityEnumEntry_TestPattern_Colorscale = 3,
/************************/
/// <summary>
/// EnumEntry_LUTEnable_Off
/// </summary>
SVSEntityEnumEntry_LUTEnable_Off = 0,
/// <summary>
/// EnumEntry_LUTEnable_On
/// </summary>
SVSEntityEnumEntry_LUTEnable_On = 3,
/************************/
/// <summary>
/// EnumEntry_ADCTestEnable_Off
/// </summary>
SVSEntityEnumEntry_ADCTestEnable_Off = 0,
/// <summary>
/// EnumEntry_ADCTestEnable_On
/// </summary>
SVSEntityEnumEntry_ADCTestEnable_On = 1,
/************************/
/// <summary>
/// EnumEntry_DefectPixelCorrectionEnable_Off
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionEnable_Off = 0,
/// <summary>
/// EnumEntry_DefectPixelCorrectionEnable_On
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionEnable_On = 1,
/************************/
/// <summary>
/// EnumEntry_DefectPixelCorrectionMark_Off
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionMark_Off = 0,
/// <summary>
/// EnumEntry_DefectPixelCorrectionMark_Mark
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionMark_Mark = 1,
/************************/
/// <summary>
/// EnumEntry_DefectPixelCorrectionMapSelect_factory
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionMapSelect_factory = 0,
/// <summary>
/// EnumEntry_DefectPixelCorrectionMapSelect_SVS
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionMapSelect_SVS = 1,
/// <summary>
/// EnumEntry_DefectPixelCorrectionMapSelect_custom
/// </summary>
SVSEntityEnumEntry_DefectPixelCorrectionMapSelect_custom = 2,
/**********************************************/
/// <summary>
/// EnumEntry_PIVModeEnable_Off
/// </summary>
SVSEntityEnumEntry_PIVModeEnable_Off = 0,
/// <summary>
/// EnumEntry_PIVModeEnable_On
/// </summary>
SVSEntityEnumEntry_PIVModeEnable_On = 1,
/************************/
 SVSEnityEnumEntry_Not_Defined = -1,
};
//------------------

//------------------

/// <summary>
/// Function for sending a command with integer parameter.  
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber"> SVSfunction number</param>
/// <param name="parameter">value to send to camera</param>
/// <returns>error code(below zero)</returns>
int fcallSetInt(int* camHandle, SVSFunctionSetInteger fnumber, int parameter);

/// <summary>
/// Function for reading an integer from camera
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="ivalue">pointer to integer</param>
/// <returns>error code</returns>
int fcallGetInt(int* camHandle, SVSFunctionGetInteger fnumber, int* ivalue);

/// <summary>
/// Function for writing a string value to camera.
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="strValue">string to send to camera</param>
/// <returns>error code</returns>
int fcallSetString(int * camHandle, SVSFunctionSetString fnumber, char* strValue);

/// <summary>
/// Function for reading a string value from camera.
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="strValue">pointer to string with at least 512 characters</param>
/// <returns>error code</returns>
int fcallGetString(int* camHandle, SVSFunctionGetString fnumber, char* strValue);

/// <summary>
/// triggers an event on camera 
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <returns></returns>
int fcallSetEvent(int* camHandle, SVSFunctionSetEvent fnumber);

/// <summary>
/// Function for sending a command with double parameter to camera. 
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="dvalue">parameter[0] : value to send</param>
/// <returns>error code</returns>
int fcallSetDouble(int* camHandle, SVSFunctionSetDouble fnumber, double dvalue);

/// <summary>
/// Function for reading a double value from camera. 
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="dValue">pointer to double</param>
/// <returns>error code</returns>
int fcallGetDouble(int* camHandle, SVSFunctionGetDouble fnumber, double* dValue);

/// <summary>
/// Function for sending a command with EnumEntity parameter.  
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber"> SVSfunction number</param>
/// <param name="parameter">value to send to camera</param>
/// <returns>error code(below zero)</returns>
int fcallSetEnum(int* camHandle, SVSFunctionSetEnumeration fnumber, SVSEnumEntity parameter);

/// <summary>
/// Function for reading an EnumEntity from camera
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="fnumber">SVSfunction number</param>
/// <param name="enVal">pointer to SVSEnumEntity</param>
/// <returns>error code</returns>
int fcallGetEnum(int* camHandle, SVSFunctionGetEnumeration fnumber, SVSEnumEntity* enVal);

/// <summary>
/// Function for getting the amount of available camera link ports
/// </summary>
/// <returns>if(>=0) return value; else error code</returns>
int getClallCount();

/// <summary>
/// Function for getting a string with grabber name and connector number of a specific camera link port
/// call getClallCount before to get the amount of available cameralink ports
/// </summary>
/// <param name="Pnr">port number</param>
/// <returns>grabber name and connector number</returns>
char * getPortID(int Pnr);

/// <summary>
/// funtion initialising communication with camera,
/// call this function first!
/// </summary>
/// <param name="camHandle">Handle for the connected Camera, initialised after return for further function calls</param>
/// <param name="buffer">character buffer with at least 512 chars</param>
/// <param name="portIDstr">name of the grabber port at which camera is connected</param>
/// <returns>error code</returns>
int SVSCamInit(int* camHandle, char* buffer, char* portIDstr);

/// <summary>
/// function for closing the camera link port
/// </summary>
void SVSclosePort(int* camHandle);

/// <summary>
/// function for unloading convcam40dll.dll
/// </summary>
void SVSexit();
//--------------Export functions End-------------------------------------

#endif
