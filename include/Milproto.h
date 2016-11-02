/***************************************************************************/
/*

    Filename:  MILPROTO.H
    Owner   :  Matrox Imaging dept.
    Revision:  9.00.1950
    Content :  This file contains the prototypes for the Matrox
               Imaging Library (MIL) C user's functions.

    COPYRIGHT (c) 1993  Matrox Electronic Systems Ltd.
    All Rights Reserved

*/
/***************************************************************************/

#ifndef __MILPROTO_H
#define __MILPROTO_H

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************/
/* GRAPHIC MODULE:                                                         */
/***************************************************************************/

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CONTROL: */

      /* -------------------------------------------------------------- */

MFTYPE32 MIL_ID MFTYPE  MgraAlloc            (MIL_ID SystemId,
                                              MIL_ID MPTYPE *GraphContextIdVarPtr);

MFTYPE32 void MFTYPE    MgraFree             (MIL_ID GraphContextId);

MFTYPE32 void MFTYPE    MgraColor            (MIL_ID GraphContextId,
                                              MIL_DOUBLE ForegroundColor);

MFTYPE32 void MFTYPE    MgraBackColor        (MIL_ID GraphContextId,
                                              MIL_DOUBLE BackgroundColor);

MFTYPE32 void MFTYPE    MgraFont             (MIL_ID GraphContextId,
                                              MIL_INT Font);

MFTYPE32 void MPTYPE * MFTYPE MgraFontGetLarge(void);
MFTYPE32 void MPTYPE * MFTYPE MgraFontGetSmall(void);
MFTYPE32 void MPTYPE * MFTYPE MgraFontGetMedium(void);

MFTYPE32 void MFTYPE    MgraFontScale        (MIL_ID GraphContextId,
                                              MIL_DOUBLE xFontScale,
                                              MIL_DOUBLE yFontScale);

MFTYPE32 MIL_INT    MFTYPE    MgraInquire    (MIL_ID GraphContextId,
                                              MIL_INT InquireType,
                                              void MPTYPE *result_ptr);
MFTYPE32 void MFTYPE    MgraControl          (MIL_ID GraphContextId,
                                              MIL_INT   ControlType,
                                              MIL_DOUBLE ControlValue);


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

       /* DRAWING : */

      /* -------------------------------------------------------------- */

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraDot              (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XPos,
                                                 MIL_INT YPos);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraDotDouble        (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XPos,
                                                    MIL_DOUBLE YPos);
      MFTYPE32 void MFTYPE    MgraDotInt64         (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XPos,
                                                    MIL_INT64 YPos);
   #else
      MFTYPE32 void MFTYPE    MgraDot              (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XPos,
                                                    MIL_DOUBLE YPos);
      #define MgraDotDouble MgraDot
      #define MgraDotInt64  MgraDot
   #endif
#endif


/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraDots             (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT  NumberOfDots,
                                                 MIL_API_CONST MIL_INT *XPos,
                                                 MIL_API_CONST MIL_INT *YPos,
                                                 MIL_INT ControlFlag);
#else
   MFTYPE32 void MFTYPE    MgraDotsDouble       (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT  NumberOfDots,
                                                 MIL_API_CONST MIL_DOUBLE *XPos,
                                                 MIL_API_CONST MIL_DOUBLE *YPos,
                                                 MIL_INT ControlFlag);
   MFTYPE32 void MFTYPE    MgraDotsInt64        (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT  NumberOfDots,
                                                 MIL_API_CONST MIL_INT64 *XPos,
                                                 MIL_API_CONST MIL_INT64 *YPos,
                                                 MIL_INT ControlFlag);
   MFTYPE32 void MFTYPE    MgraDotsInt32        (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT  NumberOfDots,
                                                 MIL_API_CONST MIL_INT32 *XPos,
                                                 MIL_API_CONST MIL_INT32 *YPos,
                                                 MIL_INT ControlFlag);
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraLine             (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XStart,
                                                 MIL_INT YStart,
                                                 MIL_INT XEnd,
                                                 MIL_INT YEnd);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraLineDouble       (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      MFTYPE32 void MFTYPE    MgraLineInt64        (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XStart,
                                                    MIL_INT64 YStart,
                                                    MIL_INT64 XEnd,
                                                    MIL_INT64 YEnd);
   #else
      MFTYPE32 void MFTYPE    MgraLine             (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      #define MgraLineDouble MgraLine
      #define MgraLineInt64  MgraLine
   #endif
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraLines            (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT NumberOfLines,
                                                 MIL_API_CONST MIL_INT *XStart,
                                                 MIL_API_CONST MIL_INT *YStart,
                                                 MIL_API_CONST MIL_INT *XEnd,
                                                 MIL_API_CONST MIL_INT *YEnd,
                                                 MIL_INT ControlFlag);
#else
   MFTYPE32 void MFTYPE    MgraLinesDouble      (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT NumberOfLines,
                                                 MIL_API_CONST MIL_DOUBLE *XStart,
                                                 MIL_API_CONST MIL_DOUBLE *YStart,
                                                 MIL_API_CONST MIL_DOUBLE *XEnd,
                                                 MIL_API_CONST MIL_DOUBLE *YEnd,
                                                 MIL_INT ControlFlag);
   MFTYPE32 void MFTYPE    MgraLinesInt64       (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT NumberOfLines,
                                                 MIL_API_CONST MIL_INT64 *XStart,
                                                 MIL_API_CONST MIL_INT64 *YStart,
                                                 MIL_API_CONST MIL_INT64 *XEnd,
                                                 MIL_API_CONST MIL_INT64 *YEnd,
                                                 MIL_INT ControlFlag);
   MFTYPE32 void MFTYPE    MgraLinesInt32       (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT NumberOfLines,
                                                 MIL_API_CONST MIL_INT32 *XStart,
                                                 MIL_API_CONST MIL_INT32 *YStart,
                                                 MIL_API_CONST MIL_INT32 *XEnd,
                                                 MIL_API_CONST MIL_INT32 *YEnd,
                                                 MIL_INT ControlFlag);
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraArc              (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XCenter,
                                                 MIL_INT YCenter,
                                                 MIL_INT XRad,
                                                 MIL_INT YRad,
                                                 MIL_DOUBLE StartAngle,
                                                 MIL_DOUBLE EndAngle);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraArcDouble        (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XCenter,
                                                    MIL_DOUBLE YCenter,
                                                    MIL_DOUBLE XRad,
                                                    MIL_DOUBLE YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
      MFTYPE32 void MFTYPE    MgraArcInt64         (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XCenter,
                                                    MIL_INT64 YCenter,
                                                    MIL_INT64 XRad,
                                                    MIL_INT YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
   #else
      MFTYPE32 void MFTYPE    MgraArc              (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XCenter,
                                                    MIL_DOUBLE YCenter,
                                                    MIL_DOUBLE XRad,
                                                    MIL_DOUBLE YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
      #define MgraArcDouble MgraArc
      #define MgraArcInt64  MgraArc
   #endif
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraArcFill          (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XCenter,
                                                 MIL_INT YCenter,
                                                 MIL_INT XRad,
                                                 MIL_INT YRad,
                                                 MIL_DOUBLE StartAngle,
                                                 MIL_DOUBLE EndAngle);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraArcFillDouble    (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XCenter,
                                                    MIL_DOUBLE YCenter,
                                                    MIL_DOUBLE XRad,
                                                    MIL_DOUBLE YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
      MFTYPE32 void MFTYPE    MgraArcFillInt64     (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XCenter,
                                                    MIL_INT64 YCenter,
                                                    MIL_INT64 XRad,
                                                    MIL_INT64 YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
   #else
      MFTYPE32 void MFTYPE    MgraArcFill          (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XCenter,
                                                    MIL_DOUBLE YCenter,
                                                    MIL_DOUBLE XRad,
                                                    MIL_DOUBLE YRad,
                                                    MIL_DOUBLE StartAngle,
                                                    MIL_DOUBLE EndAngle);
      #define MgraArcFillDouble MgraArcFill
      #define MgraArcFillInt64  MgraArcFill
   #endif
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
      MFTYPE32 void MFTYPE    MgraRect             (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT XStart,
                                                    MIL_INT YStart,
                                                    MIL_INT XEnd,
                                                    MIL_INT YEnd);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraRectDouble       (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      MFTYPE32 void MFTYPE    MgraRectInt64        (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XStart,
                                                    MIL_INT64 YStart,
                                                    MIL_INT64 XEnd,
                                                    MIL_INT64 YEnd);
   #else
      MFTYPE32 void MFTYPE    MgraRect             (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      #define MgraRectDouble MgraRect
      #define MgraRectInt64  MgraRect
   #endif
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraRectFill         (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XStart,
                                                 MIL_INT YStart,
                                                 MIL_INT XEnd,
                                                 MIL_INT YEnd);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraRectFillDouble   (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      MFTYPE32 void MFTYPE    MgraRectFillInt64    (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XStart,
                                                    MIL_INT64 YStart,
                                                    MIL_INT64 XEnd,
                                                    MIL_INT64 YEnd);
   #else
      MFTYPE32 void MFTYPE    MgraRectFill         (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart,
                                                    MIL_DOUBLE XEnd,
                                                    MIL_DOUBLE YEnd);
      #define MgraRectFillDouble MgraRectFill
      #define MgraRectFillInt64  MgraRectFill
   #endif
#endif

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraFill             (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XStart,
                                                 MIL_INT YStart);
#else
   #if M_MIL_USE_64BIT
      MFTYPE32 void MFTYPE    MgraFillDouble       (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart);
      MFTYPE32 void MFTYPE    MgraFillInt64        (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_INT64 XStart,
                                                    MIL_INT64 YStart);
   #else
      MFTYPE32 void MFTYPE    MgraFill             (MIL_ID GraphContextId,
                                                    MIL_ID ImageId,
                                                    MIL_DOUBLE XStart,
                                                    MIL_DOUBLE YStart);
      #define MgraFillDouble MgraFill
      #define MgraFillInt64  MgraFill
   #endif
#endif

/* -------------------------------------------------------------- */
MFTYPE32 void MFTYPE    MgraClear            (MIL_ID GraphContextId,
                                              MIL_ID ImageId);

/* -------------------------------------------------------------- */
#if (BW_COMPATIBILITY==0x80)
   MFTYPE32 void MFTYPE    MgraText             (MIL_ID GraphContextId,
                                                 MIL_ID ImageId,
                                                 MIL_INT XStart,
                                                 MIL_INT YStart,
                                                 MIL_API_CONST_TEXT_PTR String);
#if !M_MIL_USE_CE
   #define MgraTextA MgraText
#endif

#else // (BW_COMPATIBILITY==0x80)

   #if M_MIL_USE_64BIT

      #if M_MIL_USE_UNICODE|| M_MIL_USE_CE
         MFTYPE32 void MFTYPE    MgraTextADouble      (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST char* String);
         MFTYPE32 void MFTYPE    MgraTextAInt64       (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_INT64 XStart,
                                                       MIL_INT64 YStart,
                                                       MIL_API_CONST char* String);
      #endif // #if M_MIL_USE_UNICODE|| M_MIL_USE_CE

      #if M_MIL_USE_UNICODE 
         MFTYPE32 void MFTYPE    MgraTextWDouble      (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST_TEXT_PTR String);
         MFTYPE32 void MFTYPE    MgraTextWInt64       (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_INT64 XStart,
                                                       MIL_INT64 YStart,
                                                       MIL_API_CONST_TEXT_PTR String);

         // MgraTextW and MgraTextA themselves will be defined at the end of the
         // file in C++ function (or #define in C) mapping to on of the 4 flavors
         // of MgraText.
         #if M_MIL_UNICODE_API
            #define MgraText MgraTextW
         #else
            #define MgraText MgraTextA
         #endif

      #else // #if M_MIL_USE_UNICODE
         MFTYPE32 void MFTYPE    MgraTextDouble       (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST_TEXT_PTR String);
         MFTYPE32 void MFTYPE    MgraTextInt64        (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_INT64 XStart,
                                                       MIL_INT64 YStart,
                                                       MIL_API_CONST_TEXT_PTR String);
         #if !M_MIL_USE_CE
            #define MgraTextA MgraText
         #endif
      #endif // #if M_MIL_USE_UNICODE #else

   #else // #if M_MIL_USE_64BIT

      #if M_MIL_USE_UNICODE|| M_MIL_USE_CE
         MFTYPE32 void MFTYPE    MgraTextA            (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST char* String);
      #endif // #if M_MIL_USE_UNICODE|| M_MIL_USE_CE

      #if M_MIL_USE_UNICODE 
         MFTYPE32 void MFTYPE    MgraTextW            (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST_TEXT_PTR String);

         #if M_MIL_UNICODE_API
            #define MgraText MgraTextW
         #else
            #define MgraText MgraTextA
         #endif

      #else // #if M_MIL_USE_UNICODE
         MFTYPE32 void MFTYPE    MgraText             (MIL_ID GraphContextId,
                                                       MIL_ID ImageId,
                                                       MIL_DOUBLE XStart,
                                                       MIL_DOUBLE YStart,
                                                       MIL_API_CONST_TEXT_PTR String);
         #if !M_MIL_USE_CE
            #define MgraTextA MgraText
         #endif
      #endif // #if M_MIL_USE_UNICODE #else

   #endif // #if M_MIL_USE_64BIT #else

#endif // #if (BW_COMPATIBILITY==0x80) #else

/* -------------------------------------------------------------- */



      /* -------------------------------------------------------------- */

/***************************************************************************/
/* DATA GENERATION MODULE:                                                 */
/***************************************************************************/

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* DATA BUFFERS: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MgenLutRamp          (MIL_ID LutBufId,
                                              MIL_INT StartPoint,
                                              MIL_DOUBLE StartValue,
                                              MIL_INT EndPoint,
                                              MIL_DOUBLE EndValue);

MFTYPE32 void MFTYPE    MgenLutFunction      (MIL_ID lut_id,
                                              MIL_INT func,
                                              MIL_DOUBLE a,
                                              MIL_DOUBLE b,
                                              MIL_DOUBLE c,
                                              MIL_INT start_index,
                                              MIL_DOUBLE StartXValue,
                                              MIL_INT end_index);

MFTYPE32 void MFTYPE    MgenWarpParameter    (MIL_ID  InWarpParameter,
                                              MIL_ID  OutXLutorCoef,
                                              MIL_ID  OutYLut,
                                              MIL_INT    OperationMode,
                                              MIL_INT    Transform,
                                              MIL_DOUBLE  Val1,
                                              MIL_DOUBLE  Val2);

      /* -------------------------------------------------------------- */

/***************************************************************************/
/* HOOK HANDLER PROTOTYPE                                           */
/***************************************************************************/
typedef MFTYPE32 MIL_INT (MFTYPE MPTYPE *MIL_HOOK_FUNCTION_PTR)(MIL_INT HookType,
                                                                MIL_ID EventId,
                                                                void MPTYPE * UserData);


      /* -------------------------------------------------------------- */

/***************************************************************************/
/* DATA BUFFERS MODULE:                                                    */
/***************************************************************************/

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CREATION: */

      /* -------------------------------------------------------------- */

MFTYPE32 MIL_ID MFTYPE  MbufAlloc1d          (MIL_ID SystemId,
                                              MIL_INT SizeX,
                                              MIL_INT Type,
                                              BUFATTRTYPE Attribute,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufAlloc2d          (MIL_ID SystemId,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_INT Type,
                                              BUFATTRTYPE Attribute,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufAllocColor       (MIL_ID SystemId,
                                              MIL_INT SizeBand,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_INT Type,
                                              BUFATTRTYPE Attribute,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufChild1d          (MIL_ID ParentImageId,
                                              MIL_INT OffX,
                                              MIL_INT SizeX,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufChild2d          (MIL_ID ParentMilBufId,
                                              MIL_INT OffX,
                                              MIL_INT OffY,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufChildColor       (MIL_ID ParentMilBufId,
                                              MIL_INT Band,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 MIL_ID MFTYPE  MbufChildColor2d     (MIL_ID ParentMilBufId,
                                              MIL_INT Band,
                                              MIL_INT OffX,
                                              MIL_INT OffY,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 void  MFTYPE  MbufChildMove         (MIL_ID MilBufId,
                                              MIL_INT OffsetX,
                                              MIL_INT OffsetY,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_INT ControlFlag);

MFTYPE32 MIL_ID MFTYPE  MbufCreateColor       (MIL_ID SystemId,
                                               MIL_INT SizeBand,
                                               MIL_INT SizeX,
                                               MIL_INT SizeY,
                                               MIL_INT Type,
                                               BUFATTRTYPE Attribute,
#if (BW_COMPATIBILITY==0x80)
                                               MIL_INT ControlFlag,
#else
                                               MIL_INT64 ControlFlag,
#endif
                                               MIL_INT Pitch,
                                               void MPTYPE **ArrayOfDataPtr,
                                               MIL_ID MPTYPE *IdVarPtr);
#if !M_MIL_USE_PPC
#ifdef M_USE_MBUFBLIT
/*MFTYPE32 void MFTYPE  MbufBlit                (MIL_ID  SrcBufId,
                                              MIL_ID  DstBufId,
                                              LPMBLTDESC pBltDesc);*/
#define MbufBlit(srcID,dstID,pBltDesc)        MbufTransfer(srcID,                \
                                                           dstID,                \
                                                           0,                    \
                                                           0,                    \
                                                           M_DEFAULT,            \
                                                           M_DEFAULT,            \
                                                           M_DEFAULT,            \
                                                           0,                    \
                                                           0,                    \
                                                           M_DEFAULT,            \
                                                           M_DEFAULT,            \
                                                           M_DEFAULT,            \
                                                           M_DEFAULT,            \
                                                           M_MTX0_METHOD,        \
                                                           M_DEFAULT,            \
                                                           pBltDesc)
#endif
#endif


MFTYPE32 MIL_ID MFTYPE  MbufCreate2dFunc      (MIL_ID SystemId,
                                               MIL_INT SizeX,
                                               MIL_INT SizeY,
                                               MIL_INT Type,
                                               BUFATTRTYPE Attribute,
#if (BW_COMPATIBILITY==0x80)
                                               MIL_INT ControlFlag,
#else
                                               MIL_INT64 ControlFlag,
#endif
                                               MIL_INT Pitch,
                                               MIL_DATA_PTR DataPtr,
                                               MIL_ID MPTYPE *IdVarPtr);   
  
#if M_MIL_USE_64BIT
#define CAST_TO_64BIT_WITHOUT_SIGN_EXTENSION(X) (X)
#else
#define CAST_TO_64BIT_WITHOUT_SIGN_EXTENSION(X) ((sizeof(X) == sizeof(MIL_DATA_PTR))? ((MIL_DATA_PTR)(X)):((MIL_DATA_PTR)((unsigned long)(X)))) 
#endif

#define MbufCreate2d(SystemId, SizeX, SizeY, Type, Attribute, ControlFlag, Pitch, DataPtr, IdVarPtr) \
        MbufCreate2dFunc(SystemId, SizeX, SizeY, Type, Attribute, ControlFlag, Pitch, CAST_TO_64BIT_WITHOUT_SIGN_EXTENSION(DataPtr), IdVarPtr)

MFTYPE32 void MFTYPE    MbufFree             (MIL_ID BufId);


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* ACCESS: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MbufClear            (MIL_ID BufId,
                                              MIL_DOUBLE Value);

MFTYPE32 void MFTYPE    MbufCopy             (MIL_ID SrcBufId,
                                              MIL_ID DestBufId);

MFTYPE32 void MFTYPE    MbufCopyColor        (MIL_ID SrcBufId,
                                              MIL_ID DestBufId,
                                              MIL_INT Band);

MFTYPE32 void MFTYPE    MbufCopyColor2d      (MIL_ID SrcBufId,
                                              MIL_ID DestBufId,
                                              MIL_INT SrcBand,
                                              MIL_INT SrcOffX,
                                              MIL_INT SrcOffY,
                                              MIL_INT DstBand,
                                              MIL_INT DstOffX,
                                              MIL_INT DstOffY,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY);

MFTYPE32 void MFTYPE    MbufCopyClip         (MIL_ID SrcBufId,
                                              MIL_ID DestBufId,
                                              MIL_INT DestOffsetX,
                                              MIL_INT DestOffsetY);

MFTYPE32 void MFTYPE    MbufCopyMask         (MIL_ID SrcBufId,
                                              MIL_ID DestBufId,
                                              MIL_INT MaskValue);

MFTYPE32 void MFTYPE    MbufCopyCond         (MIL_ID SrcBufId,
                                              MIL_ID DestBufId,
                                              MIL_ID CondBufId,
                                              MIL_INT Cond,
                                              MIL_DOUBLE CondVal);

MFTYPE32 void MFTYPE    MbufGetLine          (MIL_ID SrcImageId,
                                              MIL_INT   XStart,
                                              MIL_INT   YStart,
                                              MIL_INT   XEnd,
                                              MIL_INT   YEnd,
                                              MIL_INT   Mode,
                                              MIL_INT   MPTYPE *NbPixelsValPtr,
                                              void   MPTYPE *BufferType);

MFTYPE32 void MFTYPE    MbufPut1d            (MIL_ID DestBufId,
                                              MIL_INT Offx,
                                              MIL_INT Sizex,
                                              MIL_API_CONST void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufPut2d            (MIL_ID DestBufId,
                                              MIL_INT Offx,
                                              MIL_INT Offy,
                                              MIL_INT Sizex,
                                              MIL_INT Sizey,
                                              MIL_API_CONST void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufPutColor         (MIL_ID DestBufId,
                                              MIL_INT Format,
                                              MIL_INT Band,
                                              MIL_API_CONST void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufPutColor2d       (MIL_ID DestBufId,
                                              MIL_INT Format,
                                              MIL_INT Band,
                                              MIL_INT Offx,
                                              MIL_INT Offy,
                                              MIL_INT Sizex,
                                              MIL_INT Sizey,
                                              MIL_API_CONST void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufPutLine          (MIL_ID SrcImageId,
                                              MIL_INT   XStart,
                                              MIL_INT   YStart,
                                              MIL_INT   XEnd,
                                              MIL_INT   YEnd,
                                              MIL_INT   Mode,
                                              MIL_INT   MPTYPE *NbPixelsValPtr,
                                              MIL_API_CONST void   MPTYPE *BufferType);

MFTYPE32 void MFTYPE    MbufPut              (MIL_ID DestBufId,
                                              MIL_API_CONST void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufGet1d            (MIL_ID SourceBufId,
                                              MIL_INT Offx,
                                              MIL_INT Sizex,
                                              void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufGet2d            (MIL_ID SourceBufId,
                                              MIL_INT Offx,
                                              MIL_INT Offy,
                                              MIL_INT Sizex,
                                              MIL_INT Sizey,
                                              void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufGetColor         (MIL_ID SourceBufId,
                                              MIL_INT Format,
                                              MIL_INT Band,
                                              void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufGet              (MIL_ID SourceBufId,
                                              void MPTYPE *BufferPtr);

MFTYPE32 void MFTYPE    MbufGetColor2d       (MIL_ID SourceBufId,
                                              MIL_INT Format,
                                              MIL_INT Band,
                                              MIL_INT Offx,
                                              MIL_INT Offy,
                                              MIL_INT Sizex,
                                              MIL_INT Sizey,
                                              void MPTYPE *BufferPtr);
MFTYPE32 MIL_INT MFTYPE MbufGetArc              (MIL_ID ImageId,
                                               MIL_INT  XCenter,
                                               MIL_INT  YCenter,
                                               MIL_INT  XRad,
                                               MIL_INT  YRad,
                                               MIL_DOUBLE StartAngle,
                                               MIL_DOUBLE EndAngle,
                                               void* ArrayPtr,
                                               MIL_INT* SizeByte
                                              );

MFTYPE32 MIL_INT MFTYPE MbufInquire           (MIL_ID BufId,
                                               MIL_INT InquireType,
                                               void MPTYPE *ResultPtr);

#if M_MIL_USE_UNICODE
MFTYPE32 MIL_INT MFTYPE MbufDiskInquireA     (MIL_API_CONST char* FileName,
                                              MIL_INT InquireType,
                                              void MPTYPE *ResultPtr);
MFTYPE32 void MFTYPE    MbufSaveA            (MIL_API_CONST char* FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufRestoreA         (MIL_API_CONST char* FileName,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufLoadA            (MIL_API_CONST char* FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufImportA          (MIL_API_CONST char* FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufExportA          (MIL_API_CONST char* FileName,
                                              MIL_INT FileFormat,
                                              MIL_ID srcBufId);
MFTYPE32 void MFTYPE    MbufExportSequenceA  (MIL_API_CONST char* FileName,
                                              MIL_INT FileFormat,
                                              MIL_API_CONST MIL_ID *BufArrayPtr,
                                              MIL_INT NumberOfFrames,
                                              MIL_DOUBLE FrameRate,
                                              MIL_INT ControlFlag);
MFTYPE32 void MFTYPE    MbufImportSequenceA  (MIL_API_CONST char* FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID *BufArrayPtr,
                                              MIL_INT StartImage,
                                              MIL_INT NumberOfFrames,
                                              MIL_INT ControlFlag);

MFTYPE32 MIL_INT MFTYPE MbufDiskInquireW     (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT InquireType,
                                              void MPTYPE *ResultPtr);

MFTYPE32 void MFTYPE    MbufSaveW            (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufRestoreW         (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufLoadW            (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufImportW          (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufExportW          (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_ID srcBufId);
MFTYPE32 void MFTYPE    MbufExportSequenceW  (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_API_CONST MIL_ID *BufArrayPtr,
                                              MIL_INT NumberOfFrames,
                                              MIL_DOUBLE FrameRate,
                                              MIL_INT ControlFlag);
MFTYPE32 void MFTYPE    MbufImportSequenceW  (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID *BufArrayPtr,
                                              MIL_INT StartImage,
                                              MIL_INT NumberOfFrames,
                                              MIL_INT ControlFlag);
#if M_MIL_UNICODE_API
#define MbufExportSequence MbufExportSequenceW
#define MbufImportSequence MbufImportSequenceW
#define MbufDiskInquire    MbufDiskInquireW
#define MbufSave           MbufSaveW
#define MbufRestore        MbufRestoreW
#define MbufLoad           MbufLoadW
#define MbufImport         MbufImportW
#define MbufExport         MbufExportW
#else
#define MbufExportSequence MbufExportSequenceA
#define MbufImportSequence MbufImportSequenceA
#define MbufDiskInquire    MbufDiskInquireA
#define MbufSave           MbufSaveA
#define MbufRestore        MbufRestoreA
#define MbufLoad           MbufLoadA
#define MbufImport         MbufImportA
#define MbufExport         MbufExportA
#endif
#else

MFTYPE32 MIL_INT     MFTYPE    MbufDiskInquire(MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT InquireType,
                                              void MPTYPE *ResultPtr);

MFTYPE32 void MFTYPE    MbufSave             (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufRestore          (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufLoad             (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_ID BufId);
MFTYPE32 MIL_ID MFTYPE  MbufImport           (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 void MFTYPE    MbufExport           (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_ID srcBufId);
MFTYPE32 void MFTYPE    MbufExportSequence   (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_API_CONST MIL_ID *BufArrayPtr,
                                              MIL_INT NumberOfFrames,
                                              MIL_DOUBLE FrameRate,
                                              MIL_INT ControlFlag);
MFTYPE32 void MFTYPE    MbufImportSequence   (MIL_API_CONST_TEXT_PTR FileName,
                                              MIL_INT FileFormat,
                                              MIL_INT Operation,
                                              MIL_ID SystemId,
                                              MIL_ID *BufArrayPtr,
                                              MIL_INT StartImage,
                                              MIL_INT NumberOfFrames,
                                              MIL_INT ControlFlag);

#endif

MFTYPE32 void MFTYPE    MbufControlRegion    (MIL_ID BufferId,
                                              MIL_INT OffsetX,
                                              MIL_INT OffsetY,
                                              MIL_INT SizeX,
                                              MIL_INT SizeY,
                                              MIL_INT Band,
                                              MIL_INT ControlFlag,
                                              MIL_DOUBLE ControlValue);
#define MbufModified2d(BufferId, OffsetX, OffsetY, SizeX, SizeY) \
        MbufControlRegion(BufferId, OffsetX, OffsetY, SizeX, SizeY, M_ALL_BAND, M_MODIFIED, M_DEFAULT)


MFTYPE32 void MFTYPE    MbufCompression      (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT ControlValue,
                                              MIL_INT OperationFlag);

MFTYPE32 void MFTYPE    MbufBayer            (MIL_ID SrcImageBufId,
                                              MIL_ID DestImageBufId,
                                              MIL_ID CoefOrExpId,
                                              MIL_INT ControlFlag);

MFTYPE32 void MFTYPE    MbufTransfer         (MIL_ID     SourceBufferID,
                                              MIL_ID     DestinationBufferID,
                                              MIL_INT       SourceOffsetX,
                                              MIL_INT       SourceOffsetY,
                                              MIL_INT       SourceSizeX,
                                              MIL_INT       SourceSizeY,
                                              MIL_INT       SourceBand,
                                              MIL_INT       DestinationOffsetX,
                                              MIL_INT       DestinationOffsetY,
                                              MIL_INT       DestinationSizeX,
                                              MIL_INT       DestinationSizeY,
                                              MIL_INT       DestinationBand,
                                              MIL_INT       TransferFunction,
                                              MIL_INT       TransferType,
                                              MIL_INT       OperationFlag,
                                              void      *ForExtension);


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CONTROL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MbufControlNeighborhood (MIL_ID BufId,
                                                 MIL_INT OperationFlags,
                                                 MIL_INT OperationValue);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs

MFTYPE32 void MFTYPE    MbufControlInt64        (MIL_ID BufId,
                                                 MIL_INT OperationFlags,
                                                 MIL_INT64 OperationValue);

MFTYPE32 void MFTYPE    MbufControlDouble       (MIL_ID BufId,
                                                 MIL_INT OperationFlags,
                                                 MIL_DOUBLE OperationValue);
#else
// Prototypes for 32 bits OSs

#define MbufControlDouble MbufControl
#define MbufControlInt64  MbufControl
MFTYPE32 void MFTYPE    MbufControl             (MIL_ID BufId,
                                                 MIL_INT OperationFlags,
                                                 MIL_DOUBLE OperationValue);
#endif


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* HOOK: */

      /* -------------------------------------------------------------- */

typedef MIL_HOOK_FUNCTION_PTR MBUFHOOKFCTPTR;
typedef MIL_HOOK_FUNCTION_PTR MIL_BUF_HOOK_FUNCTION_PTR;

MFTYPE32 void MFTYPE    MbufHookFunction        (MIL_ID BufferId,
                                                 MIL_INT HookType,
                                                 MIL_BUF_HOOK_FUNCTION_PTR HookHandlerPtr,
                                                 void MPTYPE * UserDataPtr);

MFTYPE32 MIL_INT MFTYPE    MbufGetHookInfo         (MIL_ID Id,
                                                    MIL_INT InfoType,
                                                    void MPTYPE *UserPtr);


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

/***************************************************************************/
/* I/O DEVICES:                                                            */
/***************************************************************************/

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CREATION: */

      /* -------------------------------------------------------------- */

typedef MIL_HOOK_FUNCTION_PTR MDIGHOOKFCTPTR;
typedef MIL_HOOK_FUNCTION_PTR MIL_DIG_HOOK_FUNCTION_PTR;

MFTYPE32 void MFTYPE    MdigHookFunction     (MIL_ID DigitizerId,
                                              MIL_INT HookType,
                                              MIL_DIG_HOOK_FUNCTION_PTR HookHandlerPtr,
                                              void MPTYPE * UserDataPtr);
#if M_MIL_USE_UNICODE
MFTYPE32 MIL_ID MFTYPE  MdigAllocA           (MIL_ID SystemId,
                                              MIL_INT DeviceNum,
                                              MIL_API_CONST char* DataFormat,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 MIL_ID MFTYPE  MdigAllocW           (MIL_ID SystemId,
                                              MIL_INT DeviceNum,
                                              MIL_API_CONST_TEXT_PTR DataFormat,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *IdVarPtr);
#if M_MIL_UNICODE_API
#define MdigAlloc MdigAllocW
#else
#define MdigAlloc MdigAllocA
#endif
#else
MFTYPE32 MIL_ID MFTYPE  MdigAlloc            (MIL_ID SystemId,
                                              MIL_INT DeviceNum,
                                              MIL_API_CONST_TEXT_PTR DataFormat,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *IdVarPtr);
#endif

MFTYPE32 void MFTYPE    MdigFree             (MIL_ID DevId);


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CONTROL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MdigChannel          (MIL_ID DevId,
                                              DIG_CONTROL_TYPE Channel);

MFTYPE32 void MFTYPE    MdigReference        (MIL_ID  DevId,
                                              DIG_CONTROL_TYPE    ReferenceType,
                                              MIL_DOUBLE  ReferenceLevel);

MFTYPE32 void MFTYPE    MdigLut              (MIL_ID DevId,
                                              MIL_ID LutBufId);

MFTYPE32 void MFTYPE    MdigHalt             (MIL_ID DevId);

MFTYPE32 MIL_INT MFTYPE MdigInquire          (MIL_ID DevId,
                                              DIG_CONTROL_TYPE InquireType,
                                              void MPTYPE *ResultPtr);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs

MFTYPE32 void MFTYPE    MdigControlInt64     (MIL_ID DigitizerId,
                                              DIG_CONTROL_TYPE ControlType,
                                              MIL_INT64 ControlValue);

MFTYPE32 void MFTYPE    MdigControlDouble    (MIL_ID DigitizerId,
                                              DIG_CONTROL_TYPE ControlType,
                                              MIL_DOUBLE ControlValue);

#else
// Prototypes for 32 bits OSs

#define MdigControlDouble MdigControl
#define MdigControlInt64  MdigControl
MFTYPE32 void MFTYPE    MdigControl          (MIL_ID DigitizerId,
                                              DIG_CONTROL_TYPE OperationFlags,
                                              MIL_DOUBLE OperationValue);
#endif

MFTYPE32 void MFTYPE    MdigGrabWait         (MIL_ID DevId,
                                              MIL_INT Flag);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

       /* ACCESS: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MdigGrab             (MIL_ID SrcDevId,
                                              MIL_ID DestImageId);

MFTYPE32 void MFTYPE    MdigGrabContinuous   (MIL_ID SrcDevId,
                                              MIL_ID DestImageId);

MFTYPE32 void MFTYPE    MdigProcess          (MIL_ID         Digitizer,
                                              MIL_API_CONST MIL_ID         *DestImageIdList,
                                              MIL_INT           DestImageListSize,
                                              MIL_INT           Operation,
                                              MIL_INT           OperationFlag,
                                              MIL_BUF_HOOK_FUNCTION_PTR UserProcessingFunctionPtr,
                                              void MPTYPE    *UserDataPtr);

MFTYPE32 MIL_INT MFTYPE    MdigGetHookInfo(  MIL_ID Id,
                                             MIL_INT InfoType,
                                             void MPTYPE *UserPtr);

MFTYPE32 void MFTYPE    MdigAverage          (MIL_ID Digitizer,
                                              MIL_ID DestImageId,
                                              MIL_INT WeightFactor,
                                              MIL_INT AverageType,
                                              MIL_INT NbIteration);

typedef MFTYPE32 MIL_INT (MFTYPE MPTYPE *MIL_FOCUS_HOOK_FUNCTION_PTR)(MIL_INT HookType,
                                                                      MIL_INT position,
                                                                      void MPTYPE *UserDataPtr);
typedef MIL_FOCUS_HOOK_FUNCTION_PTR MFOCUSHOOKFCTPTR;

MFTYPE32 void MFTYPE    MdigFocus           (MIL_ID DigId,
                                             MIL_ID DestImageId,
                                             MIL_ID FocusImageRegionId,
                                             MIL_FOCUS_HOOK_FUNCTION_PTR FocusHookPtr,
                                             void MPTYPE *UserDataPtr,
                                             MIL_INT MinPosition,
                                             MIL_INT StartPosition,
                                             MIL_INT MaxPosition,
                                             MIL_INT MaxPositionVariation,
                                             MIL_INT ProcMode,
                                             MIL_INT *ResultPtr);

#if M_MIL_USE_UNICODE
MFTYPE32 void MFTYPE MdigControlFeatureW    (MIL_ID DigitizerId, 
                                            MIL_INT ControlFlag, 
                                            MIL_API_CONST_TEXT_PTR FeatureName, 
                                            MIL_INT FeatureType, 
                                            MIL_API_CONST void* FeatureValuePtr);   

MFTYPE32 void MFTYPE MdigInquireFeatureW    (MIL_ID DigitizerId, 
                                            MIL_INT ControlFlag, 
                                            MIL_API_CONST_TEXT_PTR FeatureName, 
                                            MIL_INT FeatureType, 
                                            void* FeatureValuePtr);   

MFTYPE32 void MFTYPE MdigControlFeatureA    (MIL_ID DigitizerId, 
                                             MIL_INT ControlFlag, 
                                             MIL_API_CONST char* FeatureName, 
                                             MIL_INT FeatureType, 
                                             MIL_API_CONST void* FeatureValuePtr);   

MFTYPE32 void MFTYPE MdigInquireFeatureA    (MIL_ID DigitizerId, 
                                             MIL_INT ControlFlag, 
                                             MIL_API_CONST char* FeatureName, 
                                             MIL_INT FeatureType, 
                                             void* FeatureValuePtr);   

   #if M_MIL_UNICODE_API
   #define MdigControlFeature MdigControlFeatureW
   #define MdigInquireFeature MdigInquireFeatureW
   #else
   #define MdigControlFeature MdigControlFeatureA
   #define MdigInquireFeature MdigInquireFeatureA
   #endif

#else

MFTYPE32 void MFTYPE MdigControlFeature    (MIL_ID DigitizerId, 
                                            MIL_INT ControlFlag, 
                                            MIL_API_CONST_TEXT_PTR FeatureName, 
                                            MIL_INT FeatureType, 
                                            MIL_API_CONST void* FeatureValuePtr);   

MFTYPE32 void MFTYPE MdigInquireFeature    (MIL_ID DigitizerId, 
                                            MIL_INT ControlFlag, 
                                            MIL_API_CONST_TEXT_PTR FeatureName, 
                                            MIL_INT FeatureType, 
                                            void* FeatureValuePtr);   
#endif



      /* -------------------------------------------------------------- */

/***************************************************************************/
/* SYSTEM MODULE:                                                          */
/***************************************************************************/

      /* -------------------------------------------------------------- */
     /* -------------------------------------------------------------- */

     /* CONTROL: */

     /* -------------------------------------------------------------- */

#if (BW_COMPATIBILITY==0x80)
#ifdef __cplusplus
extern "C"
   {
#endif

typedef MIL_HOOK_FUNCTION_PTR MDISPHOOKFCTPTR;
typedef MIL_HOOK_FUNCTION_PTR MIL_DISP_HOOK_FUNCTION_PTR;

MFTYPE32 void MFTYPE    MdispHookFunction    (MIL_ID DisplayId,
                                              MIL_INT HookType,
                                              MIL_DISP_HOOK_FUNCTION_PTR HookHandlerPtr,
                                              void MPTYPE * UserDataPtr);




MFTYPE32 MIL_ID MFTYPE  MdispAlloc           (MIL_ID SystemId,
                                              MIL_INT DispNum,
                                              MIL_API_CONST_TEXT_PTR DispFormat,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 void MFTYPE    MdispFree            (MIL_ID DisplayId);

MFTYPE32 void MFTYPE    MdispSelect          (MIL_ID DisplayId,
                                              MIL_ID ImageId);

#define MdispDeselect(DisplayId, ImageId) MdispSelect(DisplayId, M_NULL)

MFTYPE32 MIL_INT MFTYPE MdispInquire         (MIL_ID DisplayId,
                                              MIL_INT inquire_type,
                                              void MPTYPE *result_ptr);

MFTYPE32 void MFTYPE    MdispPan             (MIL_ID DisplayId,
                                              MIL_DOUBLE XOffset,
                                              MIL_DOUBLE YOffset);
MFTYPE32 void MFTYPE    MdispZoom            (MIL_ID DisplayId,
                                              MIL_DOUBLE XFactor,
                                              MIL_DOUBLE YFactor);

MFTYPE32 void MFTYPE    MdispLut             (MIL_ID DisplayId,
                                              MIL_ID LutBufId);

MFTYPE32 void MFTYPE    MdispOverlayKey      (MIL_ID DisplayId,
                                              MIL_INT Mode,
                                              MIL_INT Cond,
                                              MIL_INT Mask,
                                              MIL_INT Color);
// Prototypes for 32 bits OSs

#define MdispControlDouble MdispControl
#define MdispControlInt64  MdispControl
MFTYPE32 void MFTYPE       MdispControl         (MIL_ID DisplayId,
                                                 MIL_INT ControlType,
                                                 MIL_DOUBLE ControlValue);


MFTYPE32 void MFTYPE    MdispUpdate         (MIL_ID DisplayId,
                                             MIL_INT OffsetX,
                                             MIL_INT OffsetY,
                                             MIL_INT SizeX,
                                             MIL_INT SizeY,
                                             MIL_INT ControlFlag
                                             );

MFTYPE32 MIL_INT MFTYPE    MdispGetHookInfo    (MIL_ID EventId,
                                             MIL_INT InfoType,
                                             void MPTYPE *UserPtr);

MFTYPE32 void MFTYPE    MdispSelectWindow    (MIL_ID DisplayId,
                                              MIL_ID ImageId,
                                              MIL_WINDOW_HANDLE ClientWindowHandle);


/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#endif

typedef MIL_HOOK_FUNCTION_PTR MSYSHOOKFCTPTR;
typedef MIL_HOOK_FUNCTION_PTR MIL_SYS_HOOK_FUNCTION_PTR;

MFTYPE32 void MFTYPE MsysHookFunction        (MIL_ID SystemId,
                                              MIL_INT HookType,
                                              MIL_SYS_HOOK_FUNCTION_PTR HookHandlerPtr,
                                              void MPTYPE * UserDataPtr);

MFTYPE32 MIL_INT MFTYPE  MsysGetHookInfo        (MIL_ID SystemId,
                                              MIL_ID Id,
                                              MIL_INT InfoType,
                                              void MPTYPE *UserPtr);


#if M_MIL_USE_UNICODE 
MFTYPE32 MIL_ID MFTYPE MsysAllocW            (MIL_CONST_TEXT_PTR SystemTypePtr,
                                              MIL_INT SystemNum,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *SystemIdVarPtr);
MFTYPE32 MIL_ID MFTYPE MsysAllocA            (const char* SystemTypePtr,
                                              MIL_INT SystemNum,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *SystemIdVarPtr);
   #if M_MIL_UNICODE_API
   #define MsysAlloc MsysAllocW
   #else
   #define MsysAlloc MsysAllocA
   #endif
#else
MFTYPE32 MIL_ID MFTYPE MsysAlloc            (MIL_CONST_TEXT_PTR SystemTypePtr,
                                              MIL_INT SystemNum,
                                              MIL_INT InitFlag,
                                              MIL_ID MPTYPE *SystemIdVarPtr);
#endif


MFTYPE32 void MFTYPE  MsysFree               (MIL_ID SystemId);

MFTYPE32 MIL_INT MFTYPE  MsysInquire         (MIL_ID SystemId,
                                              MIL_INT   InquireType,
                                              void MPTYPE *ResultPtr);

MFTYPE32 void MFTYPE  MsysControl            (MIL_ID SystemId,
                                              MIL_INT ControlType,
                                              MIL_INT ControlValue);

MFTYPE32 void MFTYPE MsysConfigAccess        (MIL_ID       SystemId,
                                              MIL_INT         VendorId,
                                              MIL_INT         DeviceId,
                                              MIL_INT         DeviceNum,
                                              MIL_INT         OperationFlag,
                                              MIL_INT         OperationType,
                                              MIL_INT         Offset,
                                              MIL_INT         Size,
                                              void MPTYPE *UserArrayPtr);


      /* -------------------------------------------------------------- */

/***************************************************************************/
/* APPLICATION MODULE:                                                     */
/***************************************************************************/

      /* -------------------------------------------------------------- */
     /* -------------------------------------------------------------- */

     /* CONTROL: */

     /* -------------------------------------------------------------- */


typedef MIL_HOOK_FUNCTION_PTR MAPPHOOKFCTPTR;
typedef MIL_HOOK_FUNCTION_PTR MIL_APP_HOOK_FUNCTION_PTR;

MFTYPE32 void   MFTYPE MappHookFunction(MIL_INT HookType,
                                        MIL_APP_HOOK_FUNCTION_PTR HookErrorCurrentPtr,
                                        void MPTYPE *ExpansionFlagPtr);
#if M_MIL_USE_UNICODE 
MFTYPE32 MIL_ID MFTYPE  MappAllocA         (MIL_INT InitFlag,
                                           MIL_ID MPTYPE *IdVarPtr);
MFTYPE32 MIL_ID MFTYPE  MappAllocW         (MIL_INT InitFlag,
                                           MIL_ID MPTYPE *IdVarPtr);
#if !M_COMPILING_MILDLL
   #if M_MIL_UNICODE_API
   #define MappAlloc MappAllocW
   #else
   #define MappAlloc MappAllocA
   #endif
#endif
#else
MFTYPE32 MIL_ID MFTYPE  MappAlloc         (MIL_INT InitFlag,
                                           MIL_ID MPTYPE *IdVarPtr);
#endif


MFTYPE32 void MFTYPE    MappFree          (MIL_ID ApplicationId);

MFTYPE32 void MFTYPE    MappControl       (MIL_INT ControlType,
                                           MIL_INT ControlFlag);

MFTYPE32 MIL_ID MFTYPE    MappControlThread (MIL_ID ThreadOrEventId,
                                           MIL_INT Operation,
                                           MIL_INT OperationValue,
                                           MIL_ID *IdVarPtr);

MFTYPE32 MIL_INT MFTYPE    MappGetError      (MIL_INT ErrorType,
                                           void MPTYPE *ErrorVarPtr);

MFTYPE32 MIL_INT MFTYPE    MappGetHookInfo   (MIL_ID Id,
                                           MIL_INT InfoType,
                                           void MPTYPE *UserPtr);

MFTYPE32 MIL_INT MFTYPE MappInquire       (MIL_INT InquireType,
                                           void MPTYPE *UserVarPtr);

MFTYPE32 void MFTYPE    MappModify        (MIL_ID FirstId,
                                           MIL_ID SecondId,
                                           MIL_INT ModificationType,
                                           MIL_INT ModificationFlag);

MFTYPE32 MIL_DOUBLE MFTYPE  MappTimer         (MIL_INT Mode,
                                           MIL_DOUBLE *Time);
MFTYPE32 void  MFTYPE  MappTimerVoid      (MIL_INT Mode,
                                           MIL_DOUBLE *Time);

/* -------------------------------------------------------------- */

/***************************************************************************/
/* THREAD FUNCTIONS:                                                       */
/***************************************************************************/
typedef MFTYPE32 MIL_UINT32 (MFTYPE MPTYPE *MIL_THREAD_FUNCTION_PTR)(void* UserDataPtr);
typedef MIL_THREAD_FUNCTION_PTR MTHREADFCTPTR;

MFTYPE32 MIL_ID MFTYPE  MthrAlloc         (MIL_ID SystemID,
                                           MIL_INT ObjectType,
                                           MIL_INT ControlFlag,
                                           MIL_THREAD_FUNCTION_PTR ThreadFctPtr,
                                           void *UserPtr,
                                           MIL_ID *ThreadOrEventId);
#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs

MFTYPE32 void MFTYPE    MthrControlInt64  (MIL_ID ThreadOrEventId,
                                           MIL_INT ControlType,
                                           MIL_INT64 ControlValue);

MFTYPE32 void MFTYPE    MthrControlDouble (MIL_ID ThreadOrEventId,
                                           MIL_INT ControlType,
                                           MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs

#define MthrControlDouble MthrControl
#define MthrControlInt64  MthrControl
MFTYPE32 void MFTYPE    MthrControl       (MIL_ID ThreadOrEventId,
                                           MIL_INT ControlType,
                                           MIL_DOUBLE ControlValue);
#endif

MFTYPE32 void MFTYPE    MthrFree          (MIL_ID ThreadOrEventId);

MFTYPE32 MIL_INT MFTYPE MthrInquire       (MIL_ID ThreadOrEventId,
                                           MIL_INT InquireType,
                                           void *InquireVal);

MFTYPE32 MIL_INT MFTYPE    MthrWait       (MIL_ID ThreadOrEventId,
                                           MIL_INT WaitOption,
                                           MIL_INT *State);

MFTYPE32 MIL_INT MFTYPE    MthrWaitMultiple  (MIL_API_CONST MIL_ID *ThreadOrEventIdArray, 
                                              MIL_INT ThreadOrEventArraySize, 
                                              MIL_INT WaitOption, 
                                              MIL_INT *State);


/***************************************************************************/
/* OS MODULE:                                                              */
/***************************************************************************/
// Main declaration
#if M_MIL_UNICODE_API && !M_MIL_USE_LINUX
#define MosMain wmain
#define MosWinMain wWinMain
#else
#define MosMain main
#define MosWinMain WinMain
#endif


MFTYPE32 MIL_INT MFTYPE MosGetch();
MFTYPE32 MIL_INT MFTYPE MosKbhit();
MFTYPE32 MIL_INT MFTYPE MosGetchar();
MFTYPE32 MIL_INT MFTYPE MosAbs(MIL_INT val);
MFTYPE32 void MFTYPE MosSleep(MIL_INT ms);

// String manipulation
#if M_MIL_USE_UNICODE || M_MIL_USE_CE
   MFTYPE32 MIL_INT MFTYPE MosStrlenA(const char* str);
   MFTYPE32 char* MFTYPE MosStruprA(char* str);   
   MFTYPE32 char* MFTYPE MosStrlwrA(char* str);
   MFTYPE32 MIL_INT MFTYPE MosStrcmpA(const char* string1, const char* string2);
   MFTYPE32 char* MFTYPE MosStrcatA(char* dest, MIL_INT destsize, const char* source);
   MIL_INT MosPrintfA(const char* format, ...);
   MIL_INT MosSprintfA(char* buf, MIL_INT bufsize, const char* format, ...);
   MFTYPE32 char* MFTYPE MosStrcpyA(char* dest, MIL_INT destsize, const char* source);
#endif

#if M_MIL_USE_UNICODE
   MFTYPE32 MIL_INT MFTYPE MosStrlenW(const wchar_t* str);
   MFTYPE32 wchar_t* MFTYPE MosStruprW(wchar_t* str);   
   MFTYPE32 wchar_t* MFTYPE MosStrlwrW(wchar_t* str);
   MFTYPE32 MIL_INT MFTYPE MosStrcmpW(const wchar_t* string1, const wchar_t* string2);
   MFTYPE32 wchar_t* MFTYPE MosStrcatW(wchar_t* dest, MIL_INT destsize, const wchar_t* source);
   MIL_INT MosPrintfW(const wchar_t* format, ...);
   MIL_INT MosSprintfW(wchar_t* buf, MIL_INT bufsize, const wchar_t* format, ...);
   MFTYPE32 wchar_t* MFTYPE MosStrcpyW(wchar_t* dest, MIL_INT destsize, const wchar_t* source);

   #if M_MIL_UNICODE_API
      #define MosStrlen MosStrlenW
      #define MosStrupr MosStruprW 
      #define MosStrlwr MosStrlwrW
      #define MosStrcmp MosStrcmpW
      #define MosStrcat MosStrcatW
      #define MosPrintf MosPrintfW
      #define MosSprintf MosSprintfW
      #define MosStrcpy MosStrcpyW
   #else
      #define MosStrlen MosStrlenA
      #define MosStrupr MosStruprA
      #define MosStrlwr MosStrlwrA
      #define MosStrcmp MosStrcmpA
      #define MosStrcat MosStrcatA
      #define MosPrintf MosPrintfA
      #define MosSprintf MosSprintfA
      #define MosStrcpy MosStrcpyA
   #endif
#else
   MFTYPE32 MIL_INT MFTYPE MosStrlen(MIL_CONST_TEXT_PTR str);
   MFTYPE32 MIL_TEXT_PTR MFTYPE MosStrupr(MIL_TEXT_PTR str);
   MFTYPE32 MIL_TEXT_PTR MFTYPE MosStrlwr(MIL_TEXT_PTR str);
   MFTYPE32 MIL_INT MFTYPE MosStrcmp(MIL_CONST_TEXT_PTR string1, MIL_CONST_TEXT_PTR string2);
   MFTYPE32 MIL_TEXT_PTR MFTYPE MosStrcat(MIL_TEXT_PTR dest, MIL_INT destsize, MIL_CONST_TEXT_PTR source);   
   MFTYPE32 MIL_TEXT_PTR MFTYPE MosStrcpy(MIL_TEXT_PTR dest, MIL_INT destsize, MIL_CONST_TEXT_PTR source);
   MIL_INT MosSprintf(MIL_TEXT_PTR buf, MIL_INT bufsize, MIL_CONST_TEXT_PTR format, ...);
   MIL_INT MosPrintf(MIL_CONST_TEXT_PTR format, ...);   
#endif

/* -------------------------------------------------------------- */

/***************************************************************************/
/* MISC FUNCTIONS:                                                         */
/***************************************************************************/
MFTYPE32 MIL_UINT MFTYPE  MPtrToInt           (void *pvPtr);

/* -------------------------------------------------------------- */

/***************************************************************************/
/* TOOLKIT FOR PSEUDO MIL FUNCTIONS DEVELOPMENT                            */
/***************************************************************************/
#include <milfunc.h>

/**************************************************************************/
/* VGA WINDOWS SPECIFIC FUNCTION SET                                      */
/**************************************************************************/

#if (!defined(__MWINEXT__)) && (BW_COMPATIBILITY == 0x80)

   #define __MWINEXT__

   #if (defined(_INC_WINDOWS) || defined(_WINDOWS_) || defined(__WINDOWS_H) || defined(__WINDOWS__))


    /* Structure for hook to modification to bitmap */
    typedef struct
    {
    LPBITMAPINFO DIBHeaderPtr;          /* pointer to the DIB header          */
    UINT         DIBColorUse;           /* color usage of DIB header          */
    LPSTR        DIBDataPtr;            /* pointer to the DIB data            */
    LPLOGPALETTE DIBPalettePtr;         /* pointer to the DIB palette         */
    HPALETTE     DIBPaletteHdl;         /* handle to the DIB palette          */
    HBITMAP      DIBBitmapHdl;          /* handle to DIB bitmap               */
    LPBITMAPINFO DIBDisplayHeaderPtr;   /* pointer to the display DIB header  */
    UINT         DIBDisplayColorUse;    /* color usage of display DIB header  */
    LPSTR        DIBDisplayDataPtr;     /* pointer to the display DIB data    */
    LPLOGPALETTE DIBDisplayPalettePtr;  /* pointer to the display DIB palette */
    HPALETTE     DIBDisplayPaletteHdl;  /* handle to the display DIB palette  */
    HBITMAP      DIBDisplayBitmapHdl;   /* handle to the display DIB bitmap   */
    MIL_ID       MilVgaBufferId;        /* MIL ID of the MIL VGA buffer       */
    MIL_ID       MilVgaDisplayId;       /* MIL ID of the MIL VGA display      */
    long         VgaDriverBufferId;     /* Reserved                           */
    long         VgaDriverDisplayId;    /* Reserved                           */
    long         VgaDriverSystemId;     /* Reserved                           */
    long         ModificationHookType;  /* Type of hook on modification       */
    long         ModificationType;      /* Type of modification to buffer     */
    long         ModificationOffsetX;   /* Offset x of modification in buffer */
    long         ModificationOffsetY;   /* Offset y of modification in buffer */
    long         ModificationSizeX;     /* Size x of modification in buffer   */
    long         ModificationSizeY;     /* Size y of modification in buffer   */
    long         ModificationZoomX;     /* Zoom x of modification in buffer   */
    long         ModificationZoomY;     /* Zoom y of modification in buffer   */
    long         ModificationPanX;      /* Pan x of modification in buffer    */
    long         ModificationPanY;      /* Pan y of modification in buffer    */
    LPVOID       ExpansionPtr;          /* Reserved                           */
    } M_DIB_INFO;

    /* Structure for hook to modification to window */
    typedef struct
    {
    HWND         WindowHandle;          /* Window hdl associated to display   */
    LPBITMAPINFO DIBHeaderPtr;          /* pointer to the DIB header          */
    UINT         DIBColorUse;           /* color usage of DIB header          */
    LPSTR        DIBDataPtr;            /* pointer to the DIB data            */
    LPLOGPALETTE DIBPalettePtr;         /* pointer to the DIB palette         */
    HPALETTE     DIBPaletteHdl;         /* handle to the DIB palette          */
    HBITMAP      DIBBitmapHdl;          /* handle to DIB bitmap               */
    LPBITMAPINFO DIBDisplayHeaderPtr;   /* pointer to the display DIB header  */
    UINT         DIBDisplayColorUse;    /* color usage of display DIB header  */
    LPSTR        DIBDisplayDataPtr;     /* pointer to the display DIB data    */
    LPLOGPALETTE DIBDisplayPalettePtr;  /* pointer to the display DIB palette */
    HPALETTE     DIBDisplayPaletteHdl;  /* handle to the display DIB palette  */
    HBITMAP      DIBDisplayBitmapHdl;   /* handle to the display DIB bitmap   */
    MIL_ID       MilVgaBufferId;        /* MIL ID of the MIL VGA buffer       */
    MIL_ID       MilVgaDisplayId;       /* MIL ID of the MIL VGA display      */
    long         VgaDriverBufferId;     /* Reserved                           */
    long         VgaDriverDisplayId;    /* Reserved                           */
    long         VgaDriverSystemId;     /* Reserved                           */
    long         ModificationHookType;  /* Type of hook on modification       */
    long         ModificationType;      /* Type of modification to buffer     */
    long         ModificationOffsetX;   /* Offset x of modified window        */
    long         ModificationOffsetY;   /* Offset y of modified window        */
    long         ModificationSizeX;     /* Size x of modified window          */
    long         ModificationSizeY;     /* Size y of modified window          */
    long         ModificationZoomX;     /* Zoom x of modified window          */
    long         ModificationZoomY;     /* Zoom y of modified window          */
    long         ModificationPanX;      /* Pan x of modified window           */
    long         ModificationPanY;      /* Pan x of modified window           */
    long         ModificationMenu;      /* Menu that is used by user          */
    long         ModificationValue;     /* Optional value for modification    */
    long         VisibleOffsetX;        /* Offset x of visible rect. of wnd   */
    long         VisibleOffsetY;        /* Offset y of visible rect. of wnd   */
    long         VisibleSizeX;          /* Size x of visible rect. of wnd     */
    long         VisibleSizeY;          /* Size y of visible rect. of wnd     */
    LPVOID       ExpansionPtr;          /* Reserved                           */
    long         ExpansionFlag;         /* Reserved                           */
    long         ReservedValue1;        /* Reserved                           */
    long         ReservedValue2;        /* Reserved                           */
    long         ReservedValue3;        /* Reserved                           */
    long         ReservedValue4;        /* Reserved                           */
    } M_WINDOW_INFO;

    /* Structure for hook to modification messages */
    typedef struct
    {
    HWND         WindowHandle;          /* Window hdl associated to display   */
    UINT         message;               /* Window message                     */
    WPARAM       wParam;                /* Window message wParam              */
    LPARAM       lParam;                /* Window message lParam              */
    MIL_ID       MilVgaBufferId;        /* MIL ID of the MIL VGA buffer       */
    MIL_ID       MilVgaDisplayId;       /* MIL ID of the MIL VGA display      */
    long         VgaDriverBufferId;     /* Reserved                           */
    long         VgaDriverDisplayId;    /* Reserved                           */
    long         VgaDriverSystemId;     /* Reserved                           */
    long         ModificationHookType;  /* Type of hook on modification       */
    } M_WINDOW_MSG_INFO;

    typedef struct
    {
        long Style;
        long SizeX;
        long SizeY;
        HWND ParentWnd;
    } M_CREATE_CAPTURE_WINDOW;

    typedef MFTYPE32 long (MFTYPE MPTYPE *MVGADIBHOOKFCTPTR)
                                 (M_DIB_INFO MPTYPE *ModifiedVgaBufferInfoPtr,
                                 void MPTYPE *ExtraUserInfoPtr);

    typedef MFTYPE32 long (MFTYPE MPTYPE *MVGAWINHOOKFCTPTR)
                                 (M_WINDOW_INFO MPTYPE *ModifiedVgaWindowInfoPtr,
                                 void MPTYPE *ExtraUserInfoPtr);

    typedef MFTYPE32 long (MFTYPE MPTYPE *MVGAWINMSGHOOKFCTPTR)
                                 (M_WINDOW_MSG_INFO MPTYPE *ModifiedVgaWindowMsgInfoPtr,
                                 void MPTYPE *ExtraUserInfoPtr);

    typedef void MPTYPE *MVGAHOOKFCTPTR;

    /* To get a DIB info structure to display a VGA windows buffer */
    MFTYPE32 M_DIB_INFO MPTYPE * MFTYPE MvgaDispAllocDIBInfo(
                                    MIL_ID MilVgaDisplayId,
                                    MIL_ID MilVgaBufferId);


    /* To free a DIB info structure from a display a VGA windows buffer */
    MFTYPE32 void MFTYPE MvgaDispFreeDIBInfo(
                                    MIL_ID MilVgaDisplayId,
                                    MIL_ID MilVgaBufferId);


    /* To hook a user function that will handle display refresh */
    MFTYPE32 MVGAHOOKFCTPTR MFTYPE MvgaHookModifiedDIB(
                                    MIL_ID MilVgaDisplayId,
                                    MVGAHOOKFCTPTR FctPtr,
                                    void MPTYPE *ExtraUserInfoPtr);

    /* To hook a user function for modification of MIL VGA object */
    MFTYPE32 MVGAHOOKFCTPTR MFTYPE MvgaHookModified(
                                    MIL_ID MilVgaDisplayId,
                                    long HookTypeFlag,
                                    MVGAHOOKFCTPTR FctPtr,
                                    void MPTYPE *ExtraUserInfoPtr);

    /* To display a buffer in a display window creates by the user */
    MFTYPE32 void MFTYPE MvgaDispSelectClientArea(
                                    MIL_ID MilVgaDisplayId,
                                    MIL_ID MilVgaBufferId,
                                    HWND ClientWindowHandle);


    /* To undisplay a buffer from a display window created by user */
    MFTYPE32 void MFTYPE MvgaDispDeselectClientArea(
                                    MIL_ID MilVgaDisplayId,
                                    MIL_ID MilVgaBufferId,
                                    HWND ClientWindowHandle);

    MFTYPE32 void MFTYPE MvgaDispControl(
                                    MIL_ID MilVgaDisplayId,
                                    long ControlType,
                                    long ControlState);

    MFTYPE32 long MFTYPE MvgaDispInquire(
                                    MIL_ID MilVgaDisplayId,
                                    long InquireType,
                                    long MPTYPE *TargetVarPtr);

    MFTYPE32 void MFTYPE MvgaDispCapture(
                                    MIL_ID MilVgaDisplayId,
                                    long OffsetX,
                                    long OffsetY,
                                    long SizeX,
                                    long SizeY,
                                    long DestOffsetX,
                                    long DestOffsetY);

    MFTYPE32 void MFTYPE MvgaDispProtectArea(
                                    MIL_ID MilVgaDisplayId,
                                    long OffsetX,
                                    long OffsetY,
                                    long SizeX,
                                    long SizeY);

    MFTYPE32 void MFTYPE MvgaDispSetTitleName(
                                    MIL_ID MilVgaDisplayId,
                                    MIL_API_CONST char *TitleName);

   #endif
#endif

#if !M_MIL_USE_64BIT
typedef struct _MILBUFFERINFO { 
    long   StructSize;      // Size of the structure, in bytes. This member must be initialized before the structure is used. 
    long   SizeX;
    long   SizeY;
    long   SizeBand;
    long   SizeBit;
    long   Type;
    long   Attribute;
    long   Format;
    long   OffsetX;
    long   OffsetY;
    long   OffsetBand;
    long   AncestorOffsetX;
    long   AncestorOffsetY;
    long   AncestorOffsetBand;
    long   AncestorOffsetBit;
    long   Pitch;
    long   PitchByte;
    void*  HostPtr;
    void*  BandHostPtr[3];
    void*  PhysPtr;
    MIL_ID Id;           
    MIL_ID ParentId;         
    MIL_ID AncestorId;           
    long   NativeId;
} MILBUFFERINFOOLD,* LPMILBUFFERINFOOLD; 
#endif


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* WINDOWS CE  */

      /* -------------------------------------------------------------- */

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#if M_MIL_USE_64BIT
#ifdef __cplusplus

struct MCppParameter
   {
#if !M_MIL_USE_LINUX
   MCppParameter(int          Param) { m_Param = (double)Param; }
   MCppParameter(unsigned int Param) { m_Param = (double)Param; }
#endif
   MCppParameter(MIL_INT8     Param) { m_Param = (double)Param; }
   MCppParameter(MIL_UINT8    Param) { m_Param = (double)Param; }
   MCppParameter(MIL_INT16    Param) { m_Param = (double)Param; }
   MCppParameter(MIL_UINT16   Param) { m_Param = (double)Param; }
   MCppParameter(MIL_INT32    Param) { m_Param = (double)Param; }
   MCppParameter(MIL_UINT32   Param) { m_Param = (double)Param; }
   MCppParameter(MIL_INT64    Param) { m_Param = (double)Param; }
   MCppParameter(MIL_UINT64   Param) { m_Param = (double)Param; }
   MCppParameter(float        Param) { m_Param = (double)Param; }
   MCppParameter(MIL_DOUBLE   Param) { m_Param = (double)Param; }

   double m_Param;
   };

//////////////////////////////////////////////////////////////
// MgraDot function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraDot(MIL_ID GraphContextId,
                    MIL_ID ImageId,
                    const MCppParameter& XPos,
                    const MCppParameter& YPos)
   {
   MgraDotDouble(GraphContextId, ImageId, XPos.m_Param, YPos.m_Param);
   }

//////////////////////////////////////////////////////////////
// MgraLine function definition when compiling c++ files
//////////////////////////////////////////////////////////////

inline void MgraLine(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     const MCppParameter& XStart,
                     const MCppParameter& YStart,
                     const MCppParameter& XEnd,
                     const MCppParameter& YEnd)
   {
   MgraLineDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, XEnd.m_Param, YEnd.m_Param);
   }

//////////////////////////////////////////////////////////////
// MgraArc function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraArc(MIL_ID GraphContextId,
                    MIL_ID ImageId,
                    const MCppParameter& XCenter,
                    const MCppParameter& YCenter,
                    const MCppParameter& XRad,
                    const MCppParameter& YRad,
                    MIL_DOUBLE StartAngle,
                    MIL_DOUBLE EndAngle)
   {
   MgraArcDouble(GraphContextId, ImageId, XCenter.m_Param, YCenter.m_Param, XRad.m_Param, YRad.m_Param, StartAngle, EndAngle);
   }

//////////////////////////////////////////////////////////////
// MgraArcFill function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraArcFill(MIL_ID GraphContextId,
                        MIL_ID ImageId,
                        const MCppParameter& XCenter,
                        const MCppParameter& YCenter,
                        const MCppParameter& XRad,
                        const MCppParameter& YRad,
                        MIL_DOUBLE StartAngle,
                        MIL_DOUBLE EndAngle)
   {
   MgraArcFillDouble(GraphContextId, ImageId, XCenter.m_Param, YCenter.m_Param, XRad.m_Param, YRad.m_Param, StartAngle, EndAngle);
   }

//////////////////////////////////////////////////////////////
// MgraRect function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraRect(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     const MCppParameter& XStart,
                     const MCppParameter& YStart,
                     const MCppParameter& XEnd,
                     const MCppParameter& YEnd)
   {
   MgraRectDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, XEnd.m_Param, YEnd.m_Param);
   }

//////////////////////////////////////////////////////////////
// MgraRectFill function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraRectFill(MIL_ID GraphContextId,
                         MIL_ID ImageId,
                         const MCppParameter& XStart,
                         const MCppParameter& YStart,
                         const MCppParameter& XEnd,
                         const MCppParameter& YEnd)
   {
   MgraRectFillDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, XEnd.m_Param, YEnd.m_Param);
   }

//////////////////////////////////////////////////////////////
// MgraFill function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraFill(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     const MCppParameter& XStart,
                     const MCppParameter& YStart)
   {
   MgraFillDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param);
   }

//////////////////////////////////////////////////////////////
// MgraTextW function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if M_MIL_USE_UNICODE|| M_MIL_USE_CE

   inline void MgraTextA(MIL_ID GraphContextId,
                         MIL_ID ImageId,
                         const MCppParameter& XStart,
                         const MCppParameter& YStart,
                         MIL_API_CONST char* String)
      {
      MgraTextADouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, String);
      }

#endif // #if M_MIL_USE_UNICODE|| M_MIL_USE_CE

#if M_MIL_USE_UNICODE 

   inline void MgraTextW(MIL_ID GraphContextId,
                         MIL_ID ImageId,
                         const MCppParameter& XStart,
                         const MCppParameter& YStart,
                         MIL_API_CONST_TEXT_PTR String)
      {
      MgraTextWDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, String);
      }

#else // #if M_MIL_USE_UNICODE

   inline void MgraText(MIL_ID GraphContextId,
                        MIL_ID ImageId,
                        const MCppParameter& XStart,
                        const MCppParameter& YStart,
                        MIL_API_CONST_TEXT_PTR String)
      {
      MgraTextDouble(GraphContextId, ImageId, XStart.m_Param, YStart.m_Param, String);
      }

#endif // #if M_MIL_USE_UNICODE #else




//////////////////////////////////////////////////////////////
// MbufControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void MbufControl(MIL_ID BufId,
                        MIL_INT OperationFlags,
                        int OperationValue)
   {
   MbufControlInt64(BufId, OperationFlags, OperationValue);
   };
#endif

inline void MbufControl(MIL_ID BufId,
                        MIL_INT OperationFlags,
                        MIL_INT32 OperationValue)
   {
   MbufControlInt64(BufId, OperationFlags, OperationValue);
   };

inline void MbufControl(MIL_ID BufId,
                        MIL_INT OperationFlags,
                        MIL_INT64 OperationValue)
   {
   MbufControlInt64(BufId, OperationFlags, OperationValue);
   };

inline void MbufControl(MIL_ID BufId,
                        MIL_INT OperationFlags,
                        MIL_DOUBLE OperationValue)
   {
   MbufControlDouble(BufId, OperationFlags, OperationValue);
   };

//////////////////////////////////////////////////////////////
// MdigControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void MdigControl(MIL_ID DigitizerId,
                        DIG_CONTROL_TYPE ControlType,
                        int ControlValue)
   {
   MdigControlInt64(DigitizerId, ControlType, ControlValue);
   };
#endif

inline void MdigControl(MIL_ID DigitizerId,
                        DIG_CONTROL_TYPE ControlType,
                        MIL_INT32 ControlValue)
   {
   MdigControlInt64(DigitizerId, ControlType, ControlValue);
   };

inline void MdigControl(MIL_ID DigitizerId,
                        DIG_CONTROL_TYPE ControlType,
                        MIL_INT64 ControlValue)
   {
   MdigControlInt64(DigitizerId, ControlType, ControlValue);
   };

inline void MdigControl(MIL_ID DigitizerId,
                        DIG_CONTROL_TYPE ControlType,
                        MIL_DOUBLE ControlValue)
   {
   MdigControlDouble(DigitizerId, ControlType, ControlValue);
   };

//////////////////////////////////////////////////////////////
// MthrControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void MthrControl(MIL_ID ThreadOrEventId,
                        MIL_INT ControlType,
                        int ControlValue)
   {
   MthrControlInt64(ThreadOrEventId, ControlType, ControlValue);
   };
#endif

inline void MthrControl(MIL_ID ThreadOrEventId,
                        MIL_INT ControlType,
                        MIL_INT32 ControlValue)
   {
   MthrControlInt64(ThreadOrEventId, ControlType, ControlValue);
   };

inline void MthrControl(MIL_ID ThreadOrEventId,
                        MIL_INT ControlType,
                        MIL_INT64 ControlValue)
   {
   MthrControlInt64(ThreadOrEventId, ControlType, ControlValue);
   };

/*inline void MthrControl(MIL_ID ThreadOrEventId,
                        MIL_INT ControlType,
                        MIL_DOUBLE ControlValue)
   {
   MthrControlDouble(ThreadOrEventId, ControlType, ControlValue);
   };*/

#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define MgraDot      MgraDotInt64
#define MgraLine     MgraLineInt64
#define MgraArc      MgraArcInt64
#define MgraArcFill  MgraArcFillInt64
#define MgraRect     MgraRectInt64
#define MgraRectFill MgraRectFillInt64
#if M_MIL_USE_UNICODE 
#define MgraTextW    MgraTextWInt64
#define MgraTextA    MgraTextAInt64
#else
#define MgraText     MgraTextInt64
#endif
#define MbufControl  MbufControlInt64
#define MdigControl  MdigControlInt64
#define MthrControl  MthrControlInt64

#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if BW_COMPATIBILITY != 0x80

// These functions have 3 versions of Mgra API even en 32 bits.

#if ((defined __cplusplus) && (!defined WINDOWS_NT_DRIVER_COMPILATION) && (!defined WINDOWS_CE_DRIVER_COMPILATION))
extern "C++" { // In case this file was included while extern "C".

//////////////////////////////////////////////////////////////
// MgraDots function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraDots(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     MIL_INT  NumberOfDots,
                     MIL_API_CONST MIL_INT32 *XPos,
                     MIL_API_CONST MIL_INT32 *YPos,
                     MIL_INT ControlFlag)
   {
   MgraDotsInt32(GraphContextId, ImageId, NumberOfDots, XPos, YPos, ControlFlag);
   }

inline void MgraDots(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     MIL_INT  NumberOfDots,
                     MIL_API_CONST MIL_INT64 *XPos,
                     MIL_API_CONST MIL_INT64 *YPos,
                     MIL_INT ControlFlag)
   {
   MgraDotsInt64(GraphContextId, ImageId, NumberOfDots, XPos, YPos, ControlFlag);
   }

inline void MgraDots(MIL_ID GraphContextId,
                     MIL_ID ImageId,
                     MIL_INT  NumberOfDots,
                     MIL_API_CONST MIL_DOUBLE *XPos,
                     MIL_API_CONST MIL_DOUBLE *YPos,
                     MIL_INT ControlFlag)
   {
   MgraDotsDouble(GraphContextId, ImageId, NumberOfDots, XPos, YPos, ControlFlag);
   }

//////////////////////////////////////////////////////////////
// MgraLines function definition when compiling c++ files
//////////////////////////////////////////////////////////////
inline void MgraLines(MIL_ID GraphContextId,
                      MIL_ID ImageId,
                      MIL_INT NumberOfLines,
                      MIL_API_CONST MIL_INT32 *XStart,
                      MIL_API_CONST MIL_INT32 *YStart,
                      MIL_API_CONST MIL_INT32 *XEnd,
                      MIL_API_CONST MIL_INT32 *YEnd,
                      MIL_INT ControlFlag)
   {
   MgraLinesInt32(GraphContextId, ImageId, NumberOfLines, XStart, YStart, XEnd, YEnd, ControlFlag);
   }

inline void MgraLines(MIL_ID GraphContextId,
                      MIL_ID ImageId,
                      MIL_INT NumberOfLines,
                      MIL_API_CONST MIL_INT64 *XStart,
                      MIL_API_CONST MIL_INT64 *YStart,
                      MIL_API_CONST MIL_INT64 *XEnd,
                      MIL_API_CONST MIL_INT64 *YEnd,
                      MIL_INT ControlFlag)
   {
   MgraLinesInt64(GraphContextId, ImageId, NumberOfLines, XStart, YStart, XEnd, YEnd, ControlFlag);
   }

inline void MgraLines(MIL_ID GraphContextId,
                      MIL_ID ImageId,
                      MIL_INT NumberOfLines,
                      MIL_API_CONST MIL_DOUBLE *XStart,
                      MIL_API_CONST MIL_DOUBLE *YStart,
                      MIL_API_CONST MIL_DOUBLE *XEnd,
                      MIL_API_CONST MIL_DOUBLE *YEnd,
                      MIL_INT ControlFlag)
   {
   MgraLinesDouble(GraphContextId, ImageId, NumberOfLines, XStart, YStart, XEnd, YEnd, ControlFlag);
   }

} // extern "C++"
#else // #ifdef __cplusplus

//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. MIL_INT one
//////////////////////////////////////////////////////////////
#if M_MIL_USE_64BIT
   #define MgraDots     MgraDotsInt64
   #define MgraLines    MgraLinesInt64
#else
   #define MgraDots     MgraDotsInt32
   #define MgraLines    MgraLinesInt32
#endif

#endif // #ifdef __cplusplus #else
#endif // #if BW_COMPATIBILITY != 0x80


//////////////////////////////////////////////////////////////
// SafeType functions.
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// M_MIL_USE_SAFE_TYPE defined in milos.h.
#if M_MIL_USE_SAFE_TYPE

inline void SafeTypeError(MIL_API_CONST_TEXT_PTR FunctionName);

// Definition of the error function called at each error of bad type
// of data passed to a void* argument.
//
// Application can define their own SafeTypeError function and
// disable this one by adding #define M_MIL_SAFE_TYPE_ERROR_DEFINED 1
// before including mil.h.

#if !M_MIL_SAFE_TYPE_ERROR_DEFINED
#define M_MIL_SAFE_TYPE_ERROR_DEFINED 1

#ifndef M_MIL_USE_SAFE_TYPE_COMPILE_ERROR_ONLY
inline void SafeTypeError(MIL_API_CONST_TEXT_PTR FunctionName)
   {
   MfuncPrintMessage(
      M_RESP_OK,
      MT("SafeType error in "), 
      FunctionName,
      MT(".\nPointer type is wrong.\n"),
      MT("\n"), MT("\n"));
   }
#else
inline void SafeTypeError(MIL_API_CONST_TEXT_PTR FunctionName)
   {
   }
#endif

#endif

inline void ReplaceTypeMilIdByTypeMilIntXX(MIL_INT *DataType)
   {
#if M_MIL_USE_INT64_ID
   if (*DataType == M_TYPE_MIL_ID)
      *DataType = M_TYPE_MIL_INT64;
#else
   if (*DataType == M_TYPE_MIL_ID)
      *DataType = M_TYPE_MIL_INT32;
#endif
   }

// ----------------------------------------------------------
// MappGetError

inline MFTYPE32 MIL_INT MFTYPE MappGetErrorUnsafe  (MIL_INT ErrorType, void          MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, int                   UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_TEXT_CHAR MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_INT       MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_UINT      MPTYPE *UserVarPtr);
#endif

//---------------------------------------------------------------------------------
// MappGetHookInfo

inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoUnsafe  (MIL_ID EventId, MIL_INT InfoType, void             MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, int                       ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT8         MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT16        MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT32        MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT64        MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_DOUBLE       MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, void             MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, const void       MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_ID           MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, const MIL_ID     MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_TEXT_PTR     MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_CONST_TEXT_PTR MPTYPE  *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT8        MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT16       MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT32       MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT64       MPTYPE  *ResultPtr);
#endif
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, wchar_t          MPTYPE  *ResultPtr);
#endif

//---------------------------------------------------------------
// MappInquire

inline MFTYPE32 MIL_INT MFTYPE MappInquireUnsafe  (MIL_INT InquireType, void          MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, int                   UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_TEXT_CHAR MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_INT       MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_DOUBLE    MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_UINT       MPTYPE *UserVarPtr);
#endif

// ----------------------------------------------------------
// MbufDiskInquire

#if M_MIL_USE_UNICODE
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafeA  (MIL_API_CONST char*    FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, int                ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafeW  (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, int                ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr);
#endif
#else
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafe   (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, int                ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr);
#endif
#endif

// ----------------------------------------------------------
// MbufGetHookInfo

inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoUnsafe  (MIL_ID EventId, MIL_INT InfoType, void          MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, int                    ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT       MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_DOUBLE    MPTYPE  *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT      MPTYPE  *ResultPtr);
#endif

// ----------------------------------------------------------
// MbufInquire

inline MFTYPE32 MIL_INT MFTYPE MbufInquireUnsafe  (MIL_ID BufId, MIL_INT InquireType,       void          MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       int                    ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT32     MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT64     MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_DOUBLE    MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_TEXT_CHAR MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       char          MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const char          MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       signed char   MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const signed char   MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       unsigned char MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const unsigned char MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT16     MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_INT16     MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT16    MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_UINT16    MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT32     MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_INT32     MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT32    MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_UINT32    MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       float         MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const float         MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       void          MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const void          MPTYPE **ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT32    MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT64    MPTYPE  *ResultPtr);
#endif

#if M_MIL_USE_WINDOWS
struct IDirectDrawSurface;
struct tagBITMAPINFO;
typedef tagBITMAPINFO BITMAPINFO;
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, IDirectDrawSurface  MPTYPE **ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, BITMAPINFO          MPTYPE **ResultPtr);
#endif

// ----------------------------------------------------------
// MdigGetHookInfo

inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoUnsafe  (MIL_ID DevId, MIL_INT InfoType, void          MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, int                   ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_INT       MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_DOUBLE    MPTYPE *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_UINT      MPTYPE *ResultPtr);
#endif

// ----------------------------------------------------------

// MdigInquire

inline MFTYPE32 MIL_INT MFTYPE MdigInquireUnsafe  (MIL_ID DevId, DIG_CONTROL_TYPE InquireType, void          MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, int                   ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_TEXT_CHAR MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_INT32     MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_INT64     MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_DOUBLE    MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_ID        MPTYPE *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_UINT32    MPTYPE *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_UINT64    MPTYPE *ResultPtr);
#endif

// ----------------------------------------------------------
// MfpgaGetHookInfo

inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoUnsafe  (MIL_ID  EventId, MIL_INT InfoType, void            MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, int                     UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_INT32       MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_INT64       MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_DOUBLE      MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_UINT32      MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_UINT64      MPTYPE *UserVarPtr);
#endif

// ----------------------------------------------------------
// MfpgaInquire

inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireUnsafe  (MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, void            MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, int                     UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_INT32       MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_INT64       MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_TEXT_CHAR   MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_UINT32      MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_UINT64      MPTYPE *UserVarPtr);
#endif

// ----------------------------------------------------------
// MfuncInquire

inline MFTYPE32 MIL_INT MFTYPE MfuncInquireUnsafe  (MIL_ID ObjectId, MIL_INT InquireType, void        MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, int                 UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_INT32   MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_INT64   MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_UINT64  MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
#endif

// ----------------------------------------------------------
// MgraInquire

inline MFTYPE32 MIL_INT MFTYPE MgraInquireUnsafe  (MIL_ID GraphContId, MIL_INT InquireType, void        MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, int                 UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_INT     MPTYPE *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_DOUBLE  MPTYPE *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_UINT    MPTYPE *UserVarPtr);
#endif

// ----------------------------------------------------------
// MsysGetHookInfo

inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoUnsafe  (MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, void          MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, int                    ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, MIL_INT       MPTYPE  *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, MIL_UINT      MPTYPE  *ResultPtr);
#endif

// ----------------------------------------------------------
// MsysInquire

inline MFTYPE32 MIL_INT MFTYPE MsysInquireUnsafe  (MIL_ID SystemId, MIL_INT InquireType, void          MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, int                    ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_INT32     MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_INT64     MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_TEXT_CHAR MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_DOUBLE    MPTYPE  *ResultPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_UINT32    MPTYPE  *ResultPtr);
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_UINT64    MPTYPE  *ResultPtr);
#endif

//--------------------------------------------------------------------
// MthrInquire

inline MFTYPE32 MIL_INT MFTYPE MthrInquireUnsafe  (MIL_ID ThreadOrEventId, MIL_INT InquireType, void      *UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, int        UserVarPtr);
inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, MIL_INT   *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, MIL_UINT  *UserVarPtr);
#endif

// -------------------------------------------------------------------------
// MappGetError

inline MIL_INT MappGetErrorRequiredType(MIL_INT ErrorType)
   {
   if ((ErrorType & M_MESSAGE) == M_MESSAGE)
      return M_TYPE_TEXT_CHAR;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, int UserVarPtr)
   {
   if (UserVarPtr || ((ErrorType & M_MESSAGE) == M_MESSAGE))
      SafeTypeError(MT("MappGetError"));

   return MappGetError(ErrorType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeTypeExecute (MIL_INT ErrorType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MappGetErrorRequiredType(ErrorType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MappGetError"));

   return MappGetError(ErrorType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetErrorUnsafe  (MIL_INT ErrorType, void          MPTYPE *UserVarPtr) {return MappGetError               (ErrorType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_TEXT_CHAR MPTYPE *UserVarPtr) {return MappGetErrorSafeTypeExecute(ErrorType, UserVarPtr, M_TYPE_TEXT_CHAR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_INT       MPTYPE *UserVarPtr) {return MappGetErrorSafeTypeExecute(ErrorType, UserVarPtr, M_TYPE_MIL_INT  );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappGetErrorSafeType(MIL_INT ErrorType, MIL_UINT      MPTYPE *UserVarPtr) {return MappGetErrorSafeTypeExecute(ErrorType, UserVarPtr, M_TYPE_MIL_INT);}
#endif

// ----------------------------------------------------------
// MappGetHookInfo


inline MIL_INT MappGetHookInfoRequiredType(MIL_ID EventId, MIL_INT InfoType)
   {
   if ((InfoType & M_MESSAGE) == M_MESSAGE)
      return M_TYPE_TEXT_CHAR;

   if (
      (InfoType & M_PARAM_VALUE) == M_PARAM_VALUE
      )
      {
      MIL_INT InquireParamType = ((InfoType & ~M_PARAM_VALUE) + M_PARAM_TYPE);
      MIL_INT ParamType;
      MappGetHookInfo(EventId, InquireParamType, &ParamType);
      if (ParamType == M_TYPE_ARRAY_ID_PTR || ParamType == M_TYPE_PTR || ParamType == M_TYPE_FILENAME || ParamType == M_TYPE_STRING || ParamType == M_TYPE_ID_PTR)
         ParamType = M_SAFE_TYPE_CHECK_PTR;
      return ParamType;
      }
   
   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeTypeExecute (MIL_ID EventId, MIL_INT InfoType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MappGetHookInfoRequiredType(EventId, InfoType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MappGetHookInfo"));

   return MappGetHookInfo(EventId, InfoType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MappGetHookInfo"));

   return MappGetHookInfo(EventId, InfoType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoUnsafe  (MIL_ID EventId, MIL_INT InfoType, void          MPTYPE  *ResultPtr) {return MappGetHookInfo               (EventId, InfoType, ResultPtr)                    ;}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT8      MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_CHAR       );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT16     MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_SHORT      );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT32     MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT32  );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT64     MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT64  );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_DOUBLE    MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_DOUBLE     );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, void          MPTYPE **ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, const void    MPTYPE **ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_ID        MPTYPE **ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, const MIL_ID  MPTYPE **ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_TEXT_PTR  MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_CONST_TEXT_PTR MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT8     MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_CHAR       );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT16    MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_SHORT      );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT32    MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT32  );}
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT64    MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT64  );}
#endif
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T
inline MFTYPE32 MIL_INT MFTYPE MappGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, wchar_t       MPTYPE  *ResultPtr) {return MappGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_SHORT      );}
#endif

//-----------------------------------------------------------------------------
// MappInquire

#define MAX_INSTALLED_SYSTEM 16

inline MIL_INT MappInquireRequiredType(MIL_INT InquireType)
   {
   if (
      (InquireType >= M_INSTALLED_SYSTEM_DESCRIPTOR && InquireType < M_INSTALLED_SYSTEM_DESCRIPTOR + MAX_INSTALLED_SYSTEM) ||
      (InquireType >= M_INSTALLED_SYSTEM_PRINT_NAME && InquireType < M_INSTALLED_SYSTEM_PRINT_NAME + MAX_INSTALLED_SYSTEM) ||
      (InquireType >= M_INSTALLED_SYSTEM_REG_KEY_NAME && InquireType < M_INSTALLED_SYSTEM_REG_KEY_NAME + MAX_INSTALLED_SYSTEM) ||
      (InquireType >= M_APP_INQUIRE_STRING_REG_DEF_START && InquireType < M_APP_INQUIRE_STRING_REG_DEF_END)                ||
      (InquireType >= M_APP_INQUIRE_STRING_DIRECT_ACCESS_START && InquireType < M_APP_INQUIRE_STRING_DIRECT_ACCESS_END)    ||
      (InquireType >= M_APP_INQUIRE_STRING_REG_DEF_START+M_CLIENT_ASCII_MODE && InquireType < M_APP_INQUIRE_STRING_REG_DEF_END+M_CLIENT_ASCII_MODE)
      )
      return M_TYPE_TEXT_CHAR;

   if (
      (InquireType == M_VERSION)
      )
      return M_TYPE_DOUBLE;

   if (
      (InquireType == M_CURRENT_APPLICATION)
      )
      return M_TYPE_MIL_ID;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MT("MappInquire"));

   return MappInquire(InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeTypeExecute (MIL_INT InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MappInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MappInquire"));

   return MappInquire(InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MappInquireUnsafe  (MIL_INT InquireType, void          MPTYPE *UserVarPtr) {return MappInquire       (InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_TEXT_CHAR MPTYPE *UserVarPtr) {return MappInquireSafeTypeExecute(InquireType, UserVarPtr, M_TYPE_TEXT_CHAR);}
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_INT       MPTYPE *UserVarPtr) {return MappInquireSafeTypeExecute(InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_DOUBLE    MPTYPE *UserVarPtr) {return MappInquireSafeTypeExecute(InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MappInquireSafeType(MIL_INT InquireType, MIL_UINT      MPTYPE *UserVarPtr) {return MappInquireSafeTypeExecute(InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
#endif


// ----------------------------------------------------------
// MbufDiskInquire

inline MIL_INT MbufDiskInquireRequiredType(MIL_INT InquireType)
   {
   if (
      InquireType == M_ASPECT_RATIO ||
      InquireType == M_FRAME_RATE
      )
      return M_TYPE_DOUBLE;

   return M_TYPE_MIL_INT;
   }

#if M_MIL_USE_UNICODE

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*        FileName, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MbufDiskInquireA"));

   return MbufDiskInquireA(FileName, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MbufDiskInquireW"));

   return MbufDiskInquireW(FileName, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeAExecute(MIL_API_CONST char*        FileName, MIL_INT InquireType, void    MPTYPE *ResultPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MbufDiskInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MbufDiskInquireSafeTypeA"));

   return MbufDiskInquireA(FileName, InquireType, ResultPtr);;
   }

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeWExecute(MIL_API_CONST_TEXT_PTR     FileName, MIL_INT InquireType, void    MPTYPE *ResultPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MbufDiskInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MbufDiskInquireSafeTypeW"));

   return MbufDiskInquireW(FileName, InquireType, ResultPtr);;
   }

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafeA  (MIL_API_CONST char*    FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr) {return MbufDiskInquireA(FileName, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeAExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeAExecute(FileName, InquireType, ResultPtr, M_TYPE_DOUBLE );}

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafeW  (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr) {return MbufDiskInquireW(FileName, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeWExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeWExecute(FileName, InquireType, ResultPtr, M_TYPE_DOUBLE );}

#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeA(MIL_API_CONST char*    FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeAExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeW(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeWExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
#endif

#if M_MIL_UNICODE_API
#define MbufDiskInquireUnsafe      MbufDiskInquireUnsafeW
#else
#define MbufDiskInquireUnsafe      MbufDiskInquireUnsafeA
#endif

#else

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr != NULL)
      SafeTypeError(MT("MbufDiskInquire"));

   return MbufDiskInquire(FileName, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeTypeExecute(MIL_API_CONST_TEXT_PTR     FileName, MIL_INT InquireType, void    MPTYPE *ResultPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MbufDiskInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MbufDiskInquireSafeType"));

   return MbufDiskInquire(FileName, InquireType, ResultPtr);;
   }
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireUnsafe  (MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, void       MPTYPE *ResultPtr) {return MbufDiskInquire(FileName, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_INT    MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_DOUBLE MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeExecute(FileName, InquireType, ResultPtr, M_TYPE_DOUBLE );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufDiskInquireSafeType(MIL_API_CONST_TEXT_PTR FileName, MIL_INT InquireType, MIL_UINT   MPTYPE *ResultPtr) {return MbufDiskInquireSafeTypeExecute(FileName, InquireType, ResultPtr, M_TYPE_MIL_INT);}
#endif

#endif
// ----------------------------------------------------------
// MbufGetHookInfo


inline MIL_INT MbufGetHookInfoRequiredType(MIL_INT InfoType)
   {
   switch (InfoType)
      {
      case M_MODIFIED_BUFFER+M_BUFFER_ID:
         return M_TYPE_MIL_ID;
         break;

      case M_MODIFIED_BUFFER+M_GRAB_TIME_STAMP:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER1:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER2:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER3:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER4:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER5:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER6:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER7:
      case M_MODIFIED_BUFFER+M_GRAB_EXPOSURE_MEASURED+M_TIMER8:

        return M_TYPE_DOUBLE;
        break;
      }

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeTypeExecute (MIL_ID EventId, MIL_INT InfoType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MbufGetHookInfoRequiredType(InfoType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MbufGetHookInfo"));

   return MbufGetHookInfo(EventId, InfoType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MbufGetHookInfo"));

   return MbufGetHookInfo(EventId, InfoType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoUnsafe  (MIL_ID EventId, MIL_INT InfoType, void          MPTYPE  *ResultPtr) {return MbufGetHookInfo               (EventId, InfoType, ResultPtr)                  ;}
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_INT       MPTYPE  *ResultPtr) {return MbufGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT  );}
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_DOUBLE    MPTYPE  *ResultPtr) {return MbufGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufGetHookInfoSafeType(MIL_ID EventId, MIL_INT InfoType, MIL_UINT      MPTYPE  *ResultPtr) {return MbufGetHookInfoSafeTypeExecute(EventId, InfoType, ResultPtr, M_TYPE_MIL_INT  );}
#endif

// ----------------------------------------------------------
// MbufInquire


inline MIL_INT MbufInquireRequiredType(MIL_INT InquireType)
   {
   MIL_INT InquireTypeNoBand = InquireType &~ (M_RED|M_GREEN|M_BLUE|M_Y|M_U|M_V);
   switch (InquireTypeNoBand)
      {
      case M_HOST_ADDRESS           :
      case M_HOST_ADDRESS_REMOTE    :
      case M_PHYSICAL_ADDRESS       :
      case M_PHYSICAL_ADDRESS_REMOTE:
         return M_SAFE_TYPE_CHECK_PTR;
         break;
      }

   if (M_IN_BUF_INQUIRE_MIL_ID_RANGE(InquireType))
      return M_TYPE_MIL_ID;

   if (M_IN_BUF_INQUIRE_DOUBLE_RANGE(InquireType))
      return M_TYPE_DOUBLE;

   if (M_IN_BUF_INQUIRE_MIL_INT64_RANGE(InquireType))
      return M_TYPE_MIL_INT64;

   // In Windows headers, HANDLE is declared as a void*.
   if (InquireType == M_DC_HANDLE || InquireType == M_DIB_HANDLE)
      return M_SAFE_TYPE_CHECK_PTR;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr || M_BUF_INQUIRE_MUST_HAVE_USER_PTR(InquireType))  
      SafeTypeError(MT("MbufInquire"));

   return MbufInquire(BufId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeTypeExecute (MIL_ID BufId, MIL_INT InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MbufInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MbufInquire"));

   return MbufInquire(BufId, InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufInquireUnsafe  (MIL_ID BufId, MIL_INT InquireType,       void          MPTYPE  *ResultPtr) {return MbufInquire               (BufId, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT32     MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT64     MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_DOUBLE    MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_DOUBLE   );}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_TEXT_CHAR MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_TEXT_CHAR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       char          MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const char          MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       signed char   MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const signed char   MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       unsigned char MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const unsigned char MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT16     MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_INT16     MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT16    MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_UINT16    MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_INT32     MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_INT32     MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT32    MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MIL_UINT32    MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       float         MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const float         MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       void          MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const void          MPTYPE **ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_SAFE_TYPE_CHECK_PTR);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT32    MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MIL_UINT64    MPTYPE  *ResultPtr) {return MbufInquireSafeTypeExecute(BufId, InquireType, ResultPtr, M_TYPE_MIL_INT64);}
#endif

#ifdef __MILBUFFERINFO_H__
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType,       MilBufferInfo **ResultPtr)
   {
   if (InquireType != M_BUFFER_INFO)
      SafeTypeError(MT("MbufInquire"));

   return MbufInquireUnsafe(BufId, InquireType, ResultPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, const MilBufferInfo **ResultPtr)
   {
   if (InquireType != M_BUFFER_INFO)
      SafeTypeError(MT("MbufInquire"));

   return MbufInquireUnsafe(BufId, InquireType, ResultPtr);
   }
#endif

#if M_MIL_USE_WINDOWS
inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, IDirectDrawSurface  MPTYPE **ResultPtr)
   {
   if (InquireType != M_DDRAW_SURFACE)
      SafeTypeError(MT("MbufInquire"));

   return MbufInquireUnsafe(BufId, InquireType, ResultPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MbufInquireSafeType(MIL_ID BufId, MIL_INT InquireType, BITMAPINFO          MPTYPE **ResultPtr)
   {
   if (InquireType != M_BITMAPINFO)
      SafeTypeError(MT("MbufInquire"));

   return MbufInquireUnsafe(BufId, InquireType, ResultPtr);
   }
#endif


// ----------------------------------------------------------
// MdigGetHookInfo

inline MIL_INT MdigGetHookInfoRequiredType(MIL_INT InfoType)
   {
   switch (InfoType & ~M_MODIFIED_BUFFER)
      {
      case M_BUFFER_ID:
      case 0:
         return M_TYPE_MIL_ID;
         break;

      case M_GRAB_TIME_STAMP:
      case M_GRAB_EXPOSURE_MEASURED:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER1:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER2:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER3:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER4:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER5:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER6:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER7:
      case M_GRAB_EXPOSURE_MEASURED+M_TIMER8:
      case M_GC_CAMERA_TIME_STAMP:
         return M_TYPE_DOUBLE;
         break;

      default:
         return M_TYPE_MIL_INT;
         break;
      }
   }

inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeTypeExecute (MIL_ID DevId, MIL_INT InfoType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MdigGetHookInfoRequiredType(InfoType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MdigGetHookInfo"));

   return MdigGetHookInfo(DevId, InfoType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MdigGetHookInfo"));

   return MdigGetHookInfo(DevId, InfoType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoUnsafe  (MIL_ID DevId, MIL_INT InfoType, void          MPTYPE *ResultPtr) {return MdigGetHookInfo               (DevId, InfoType, ResultPtr)                  ;}
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_INT       MPTYPE *ResultPtr) {return MdigGetHookInfoSafeTypeExecute(DevId, InfoType, ResultPtr, M_TYPE_MIL_INT  );}
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_DOUBLE    MPTYPE *ResultPtr) {return MdigGetHookInfoSafeTypeExecute(DevId, InfoType, ResultPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MdigGetHookInfoSafeType(MIL_ID DevId, MIL_INT InfoType, MIL_UINT      MPTYPE *ResultPtr) {return MdigGetHookInfoSafeTypeExecute(DevId, InfoType, ResultPtr, M_TYPE_MIL_INT  );}
#endif

// ----------------------------------------------------------
// MdigInquire

inline MIL_INT MdigInquireRequiredType(DIG_CONTROL_TYPE InquireType)
   {
   if ( M_IN_DIG_INQUIRE_STRING_RANGE(InquireType) )
      return M_TYPE_TEXT_CHAR;

   if ( M_IN_DIG_INQUIRE_DOUBLE_RANGE(InquireType) )
      return M_TYPE_DOUBLE;

   if ( M_IN_DIG_INQUIRE_MIL_INT64_RANGE(InquireType) )
      return M_TYPE_MIL_INT64;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MT("MdigInquire"));

   return MdigInquire(DevId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MdigInquireExecute (MIL_ID DevId, DIG_CONTROL_TYPE InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MdigInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MdigInquire"));

   return MdigInquire(DevId, InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MdigInquireUnsafe  (MIL_ID DevId, DIG_CONTROL_TYPE InquireType, void          MPTYPE *UserVarPtr) {return MdigInquire       (DevId, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_TEXT_CHAR MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_TEXT_CHAR);}
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_INT32     MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_INT64     MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_DOUBLE    MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_UINT32    MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MdigInquireSafeType(MIL_ID DevId, DIG_CONTROL_TYPE InquireType, MIL_UINT64    MPTYPE *UserVarPtr) {return MdigInquireExecute(DevId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#ifdef __MILFPGA_H__
// ----------------------------------------------------------
// MfpgaGetHookInfo

inline MIL_INT MfpgaGetHookInfoRequiredType(MIL_INT InfoType)
   {
   switch (InfoType)
      {
      case M_TIME_STAMP:
         return M_TYPE_DOUBLE;
         break;
      }

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, int UserVarPtr)
   {
   if (UserVarPtr != NULL)
      SafeTypeError(MT("MfpgaGetHookInfo"));

   return MfpgaGetHookInfo(EventId, InfoType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeTypeExecute (MIL_ID  EventId, MIL_INT InfoType, void       MPTYPE *UserVarPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MfpgaGetHookInfoRequiredType(InfoType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MfpgaGetHookInfo"));

   return MfpgaGetHookInfo(EventId, InfoType, UserVarPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoUnsafe  (MIL_ID  EventId, MIL_INT InfoType, void        MPTYPE *UserVarPtr) {return MfpgaGetHookInfo               (EventId, InfoType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_INT32   MPTYPE *UserVarPtr) {return MfpgaGetHookInfoSafeTypeExecute(EventId, InfoType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_INT64   MPTYPE *UserVarPtr) {return MfpgaGetHookInfoSafeTypeExecute(EventId, InfoType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_DOUBLE  MPTYPE *UserVarPtr) {return MfpgaGetHookInfoSafeTypeExecute(EventId, InfoType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_UINT32  MPTYPE *UserVarPtr) {return MfpgaGetHookInfoSafeTypeExecute(EventId, InfoType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaGetHookInfoSafeType(MIL_ID  EventId, MIL_INT InfoType, MIL_UINT64  MPTYPE *UserVarPtr) {return MfpgaGetHookInfoSafeTypeExecute(EventId, InfoType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MfpgaInquire

inline MIL_INT MfpgaInquireRequiredType(MIL_INT InquireType)
   {
   switch (InquireType)
      {
      case M_FPGA_PACKAGE_NAME:
         return M_TYPE_TEXT_CHAR;
         break;
      }
   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr != NULL)
      SafeTypeError(MT("MfpgaInquire"));

   return MfpgaInquire(MilSystemId, FpgaDeviceNum, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeTypeExecute (MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, void       MPTYPE *UserVarPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MfpgaInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MfpgaInquire"));

   return MfpgaInquire(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireUnsafe  (MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, void           MPTYPE *UserVarPtr) {return MfpgaInquire               (MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_INT32      MPTYPE *UserVarPtr) {return MfpgaInquireSafeTypeExecute(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_INT64      MPTYPE *UserVarPtr) {return MfpgaInquireSafeTypeExecute(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_TEXT_CHAR  MPTYPE *UserVarPtr) {return MfpgaInquireSafeTypeExecute(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr, M_TYPE_TEXT_CHAR);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_UINT32     MPTYPE *UserVarPtr) {return MfpgaInquireSafeTypeExecute(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfpgaInquireSafeType(MIL_ID  MilSystemId, MIL_INT FpgaDeviceNum, MIL_INT InquireType, MIL_UINT64     MPTYPE *UserVarPtr) {return MfpgaInquireSafeTypeExecute(MilSystemId, FpgaDeviceNum, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#endif // #ifdef __MILFPGA_H__

// ----------------------------------------------------------
// MfuncInquire

inline MIL_INT MfuncInquireRequiredType(MIL_INT InquireType)
   {
   if (InquireType == M_OBJECT_TYPE_EXTENDED)
      return M_TYPE_MIL_INT64;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeTypeExecute (MIL_ID ObjectId, MIL_INT InquireType, void       MPTYPE *UserVarPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MfuncInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MfuncInquire"));

   return MfuncInquire(ObjectId, InquireType, UserVarPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MT("MfuncInquire"));

   return MfuncInquire(ObjectId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MfuncInquireUnsafe  (MIL_ID ObjectId, MIL_INT InquireType, void       MPTYPE *UserVarPtr) {return MfuncInquire               (ObjectId, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_INT32  MPTYPE *UserVarPtr) {return MfuncInquireSafeTypeExecute(ObjectId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_INT64  MPTYPE *UserVarPtr) {return MfuncInquireSafeTypeExecute(ObjectId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_UINT32 MPTYPE *UserVarPtr) {return MfuncInquireSafeTypeExecute(ObjectId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MfuncInquireSafeType(MIL_ID ObjectId, MIL_INT InquireType, MIL_UINT64 MPTYPE *UserVarPtr) {return MfuncInquireSafeTypeExecute(ObjectId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MgraInquire

inline MIL_INT MgraInquireRequiredType(MIL_INT InquireType)
   {
   switch (InquireType)
      {
      case M_BACKGROUND_MODE:
      case M_FONT:
      case M_OWNER_SYSTEM_TYPE:
      case M_RGB_COLOR_MODE:
         return M_TYPE_MIL_INT;
         break;

      case M_OWNER_SYSTEM:
         return M_TYPE_MIL_ID;
         break;
      }

   return M_TYPE_DOUBLE;
   }

inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MT("MgraInquire"));

   return MgraInquire(GraphContId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeTypeExecute (MIL_ID GraphContId, MIL_INT InquireType, void       MPTYPE *UserVarPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MgraInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MgraInquire"));

   return MgraInquire(GraphContId, InquireType, UserVarPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MgraInquireUnsafe  (MIL_ID GraphContId, MIL_INT InquireType, void       MPTYPE *UserVarPtr) {return MgraInquire               (GraphContId, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_INT    MPTYPE *UserVarPtr) {return MgraInquireSafeTypeExecute(GraphContId, InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_DOUBLE MPTYPE *UserVarPtr) {return MgraInquireSafeTypeExecute(GraphContId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MgraInquireSafeType(MIL_ID GraphContId, MIL_INT InquireType, MIL_UINT   MPTYPE *UserVarPtr) {return MgraInquireSafeTypeExecute(GraphContId, InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
#endif

// ----------------------------------------------------------
// MsysGetHookInfo

inline MIL_INT MsysGetHookInfoRequiredType(MIL_INT )
   {
   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr)
      SafeTypeError(MT("MsysGetHookInfo"));

   return MsysGetHookInfo(SystemId,EventId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeTypeExecute (MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MsysGetHookInfoRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MsysGetHookInfo"));

   return MsysGetHookInfo(SystemId, EventId, InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoUnsafe  (MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, void          MPTYPE  *ResultPtr) {return MsysGetHookInfo               (SystemId, EventId, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, MIL_INT       MPTYPE  *ResultPtr) {return MsysGetHookInfoSafeTypeExecute(SystemId, EventId, InquireType, ResultPtr, M_TYPE_MIL_INT  );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MsysGetHookInfoSafeType(MIL_ID SystemId, MIL_ID EventId, MIL_INT InquireType, MIL_UINT      MPTYPE  *ResultPtr) {return MsysGetHookInfoSafeTypeExecute(SystemId, EventId, InquireType, ResultPtr, M_TYPE_MIL_INT  );}
#endif

// ----------------------------------------------------------
// MsysInquire


inline MIL_INT MsysInquireRequiredType(MIL_INT InquireType)
   {
   if (M_IN_SYS_INQUIRE_MIL_ID_RANGE(InquireType))
      return M_TYPE_MIL_ID;

   if (M_IN_SYS_INQUIRE_STRING_RANGE(InquireType))
      return M_TYPE_TEXT_CHAR;

   if (M_IN_SYS_INQUIRE_MIL_INT64_RANGE(InquireType))
      return M_TYPE_MIL_INT64;

   if (M_IN_SYS_INQUIRE_DOUBLE_RANGE(InquireType))
      return M_TYPE_MIL_DOUBLE;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, int ResultPtr)
   {
   if (ResultPtr || M_SYS_INQUIRE_MUST_HAVE_USER_PTR(InquireType))
      SafeTypeError(MT("MsysInquire"));

   return MsysInquire(SystemId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeTypeExecute (MIL_ID SystemId, MIL_INT InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MsysInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MsysInquire"));

   return MsysInquire(SystemId, InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MsysInquireUnsafe  (MIL_ID SystemId, MIL_INT InquireType, void          MPTYPE  *ResultPtr) {return MsysInquire               (SystemId, InquireType, ResultPtr);}
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_INT32     MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_INT64     MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_TEXT_CHAR MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_TEXT_CHAR);}
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_DOUBLE    MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_MIL_DOUBLE);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_UINT32    MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MsysInquireSafeType(MIL_ID SystemId, MIL_INT InquireType, MIL_UINT64    MPTYPE  *ResultPtr) {return MsysInquireSafeTypeExecute(SystemId, InquireType, ResultPtr, M_TYPE_MIL_INT64);}
#endif

//-------------------------------------------------------------------------------
// MthrInquire

inline MIL_INT MthrInquireRequiredType(MIL_INT InquireType)
   {
   if (
      InquireType == M_NATIVE_ID 
      )
      return M_TYPE_MIL_ID;

   return M_TYPE_MIL_INT;
   }

inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr != 0)
      SafeTypeError(MT("MthrInquire"));

   return MthrInquire(ThreadOrEventId, InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MthrInquireExecute (MIL_ID ThreadOrEventId, MIL_INT InquireType, void       MPTYPE *ValuePtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = MthrInquireRequiredType(InquireType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MthrInquire"));

   return MthrInquire(ThreadOrEventId, InquireType, ValuePtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MthrInquireUnsafe  (MIL_ID ThreadOrEventId, MIL_INT InquireType, void          MPTYPE *UserVarPtr) {return MthrInquire     (ThreadOrEventId, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, MIL_INT     MPTYPE *UserVarPtr) {return MthrInquireExecute(ThreadOrEventId, InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MthrInquireSafeType(MIL_ID ThreadOrEventId, MIL_INT InquireType, MIL_UINT    MPTYPE *UserVarPtr) {return MthrInquireExecute(ThreadOrEventId, InquireType, UserVarPtr, M_TYPE_MIL_INT  );}
#endif

#define MappGetError         MappGetErrorSafeType
#define MappGetHookInfo      MappGetHookInfoSafeType
#define MappInquire          MappInquireSafeType

#if M_MIL_USE_UNICODE
#define MbufDiskInquireW     MbufDiskInquireSafeTypeW
#define MbufDiskInquireA     MbufDiskInquireSafeTypeA
#else
#define MbufDiskInquire      MbufDiskInquireSafeType
#endif
#define MbufGetHookInfo      MbufGetHookInfoSafeType
#define MbufInquire          MbufInquireSafeType

#define MdigGetHookInfo      MdigGetHookInfoSafeType
#define MdigInquire          MdigInquireSafeType

//#define MfpgaGetHookInfo     MfpgaGetHookInfoSafeType
//#define MfpgaInquire         MfpgaInquireSafeType

// MfuncInquireSafeType is not activated because too many undocumented InquireTypes with various pointer types.
//#define MfuncInquire         MfuncInquireSafeType

#define MgraInquire          MgraInquireSafeType

#define MsysGetHookInfo      MsysGetHookInfoSafeType
#define MsysInquire          MsysInquireSafeType

#define MthrInquire          MthrInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

// Definitions of Unsafe functions are available even if M_MIL_USE_SAFE_TYPE
// is deactivated in order to allow applications that have been transformed
// to use it to compile properly.

#define MappGetErrorUnsafe         MappGetError
#define MappGetHookInfoUnsafe      MappGetHookInfo
#define MappInquireUnsafe          MappInquire

#define MbufCreate2dUnsafe         MbufCreate2d
#define MbufCreateColorUnsafe      MbufCreateColor
#if M_MIL_USE_UNICODE
#define MbufDiskInquireUnsafeW     MbufDiskInquireW
#define MbufDiskInquireUnsafeA     MbufDiskInquireA
#if M_MIL_UNICODE_API
#define MbufDiskInquireUnsafe      MbufDiskInquireW
#else
#define MbufDiskInquireUnsafe      MbufDiskInquireA
#endif
#else
#define MbufDiskInquireUnsafe      MbufDiskInquire
#endif
#define MbufGet1dUnsafe            MbufGet1d
#define MbufGet2dUnsafe            MbufGet2d
#define MbufGetUnsafe              MbufGet
#define MbufGetArcUnsafe           MbufGetArc
#define MbufGetColor2dUnsafe       MbufGetColor2d
#define MbufGetColorUnsafe         MbufGetColor
#define MbufGetHookInfoUnsafe      MbufGetHookInfo
#define MbufGetLineUnsafe          MbufGetLine
#define MbufInquireUnsafe          MbufInquire
#define MbufPut1dUnsafe            MbufPut1d
#define MbufPut2dUnsafe            MbufPut2d
#define MbufPutUnsafe              MbufPut
#define MbufPutColor2dUnsafe       MbufPutColor2d
#define MbufPutColorUnsafe         MbufPutColor
#define MbufPutLineUnsafe          MbufPutLine

#define MdigGetHookInfoUnsafe      MdigGetHookInfo
#define MdigInquireUnsafe          MdigInquire

#define MfpgaGetHookInfoUnsafe     MfpgaGetHookInfo
#define MfpgaInquireUnsafe         MfpgaInquire

#define MfuncInquireUnsafe         MfuncInquire

#define MgraInquireUnsafe          MgraInquire

#define MsysGetHookInfoUnsafe      MsysGetHookInfo
#define MsysInquireUnsafe          MsysInquire

#define MthrInquireUnsafe          MthrInquire

#endif // #if M_MIL_USE_SAFE_TYPE #else


#endif
