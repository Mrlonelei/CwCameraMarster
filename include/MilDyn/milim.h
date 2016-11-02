/////////////////////////////////////////////////////////////////
//
// Filename          :  MILIM.H
// Revision          :  9.01.0855
//
// Copyright © 1999 Matrox Electronic Systems Ltd.
// All Rights Reserved
//
/////////////////////////////////////////////////////////////////

#ifndef __MILIM_H__
#define __MILIM_H__

#define M_PROC_CURRENT_VERSION   M_PROC_VERSION_90_PP1

/************************************************************************/
/* MimGetResult()                                                       */
/************************************************************************/
#define M_VALUE                                       0L
#define M_POSITION_X                                  0x00003400L
#define M_POSITION_Y                                  0x00004400L
#define M_NB_EVENT                                    5L

/************************************************************************/
/* MimControl()/MimInquire()                                            */
/************************************************************************/
//To avoid eventual clashes with M_TYPE_XXX, we must use the mask before checking the value itself.
#define M_MASK_MIM_INQUIRE_TYPE                       0x00007FFF
#define M_RESULT_SIZE                                 0L
#define M_RESULT_TYPE                                 1L
#define M_DEINTERLACE_TYPE                            2L
#define M_DISCARD_FIELD                               3L
#define M_FIRST_FIELD                                 4L
#define M_MOTION_DETECT_NUM_FRAMES                    5L
#define M_MOTION_DETECT_THRESHOLD                     6L
#define M_MOTION_DETECT_REFERENCE_FRAME               7L
#define M_MOTION_DETECT_OUTPUT                        8L
#define M_SOURCE_FIRST_IMAGE                          9L
#define M_SOURCE_START_IMAGE                          M_SOURCE_FIRST_IMAGE

#define M_AVERAGE                                     0x00000020L
#define M_DISCARD                                     0x00000021L
#define M_BOB                                         0x00000022L
#define M_ADAPTIVE_AVERAGE                            0x00000023L
#define M_ADAPTIVE_DISCARD                            0x00000024L
#define M_ADAPTIVE_BOB                                0x00000025L
#define M_ADAPTATIVE_AVERAGE                          M_ADAPTIVE_AVERAGE 
#define M_ADAPTATIVE_DISCARD                          M_ADAPTIVE_DISCARD 
#define M_ADAPTATIVE_BOB                              M_ADAPTIVE_BOB     
#define M_ODD_FIELD                                   1L
#define M_EVEN_FIELD                                  2L
#if BW_COMPATIBILITY==0x80
#define M_FIRST_FRAME                                 MIL_MAKE_CONST(0x80000001L, 0x0000000080000001)
#define M_CENTER_FRAME                                MIL_MAKE_CONST(0x80000002L, 0x0000000080000002)
#define M_LAST_FRAME                                  MIL_MAKE_CONST(0x80000003L, 0x0000000080000003)
#else
#define M_FIRST_FRAME                                 0x40000001L
#define M_CENTER_FRAME                                0x40000002L
#define M_LAST_FRAME                                  0x40000003L
#endif

/************************************************************************/
/* MimFindExtreme()                                                     */
/************************************************************************/
#if (BW_COMPATIBILITY == 0x80)
#define M_MAX_VALUE                                   1L
#define M_MIN_VALUE                                   2L
#else
#define M_MAX_VALUE                                   M_MAX
#define M_MIN_VALUE                                   M_MIN
#endif
#define M_MIN_ABS_VALUE                               4L
#define M_MAX_ABS_VALUE                               5L

/************************************************************************/
/* MimStat()                                                            */
/************************************************************************/
#define M_MIN_ABS                                     0x00200000L
#define M_MAX_ABS                                     0x00800000L
#define M_SUM_ABS                                     0x00000008L
#define M_SUM_OF_SQUARES                              0x00000400L
#define M_SUM                                         0x00004000L  //Already defined in milocr.h
#define M_MEAN                                        0x08000000L  //Already defined in milmeas.h
#define M_STANDARD_DEVIATION                          0x10000000L  //Already defined in milmeas.h

/************************************************************************/
/* MimArith()                                                           */
/************************************************************************/
#define M_CONSTANT                                    0x8000L
#define M_FIXED_POINT                                 0x00004000L
#define M_ADD                                         0x0000L
#define M_ADD_CONST                                   (M_ADD | M_CONSTANT)
#define M_SUB                                         0x0001L
#define M_SUB_CONST                                   (M_SUB | M_CONSTANT)
#define M_NEG_SUB                                     0x000AL
#define M_CONST_SUB                                   (M_NEG_SUB | M_CONSTANT)
#define M_SUB_ABS                                     0x0011L
#define M_MIN                                         0x02000000L
#define M_MIN_CONST                                   (M_MIN | M_CONSTANT)
#define M_MAX                                         0x04000000L
#define M_MAX_CONST                                   (M_MAX | M_CONSTANT)
#define M_OR                                          0x0016L
#define M_OR_CONST                                    (M_OR  | M_CONSTANT)
#define M_AND                                         0x0017L
#define M_AND_CONST                                   (M_AND | M_CONSTANT)
#define M_XOR                                         0x0018L
#define M_XOR_CONST                                   (M_XOR | M_CONSTANT)
#define M_NOR                                         0x0019L
#define M_NOR_CONST                                   (M_NOR | M_CONSTANT)
#define M_NAND                                        0x001AL
#define M_NAND_CONST                                  (M_NAND | M_CONSTANT)
#define M_XNOR                                        0x001BL
#define M_XNOR_CONST                                  (M_XNOR | M_CONSTANT)
#define M_NOT                                         0x0014L
#define M_NEG                                         0x0023L
#define M_ABS                                         0x000CL
#define M_PASS                                        0x0002L
#define M_CONST_PASS                                  (M_PASS | M_CONSTANT)
#define M_MULT                                        0x0100L
#define M_MULT_CONST                                  (M_MULT | M_CONSTANT)
#define M_DIV                                         0x0101L
#define M_DIV_CONST                                   (M_DIV | M_CONSTANT)
#define M_INV_DIV                                     0x0102L
#define M_CONST_DIV                                   (M_INV_DIV | M_CONSTANT)

/************************************************************************/
/* MimArithMultiple()                                                   */
/************************************************************************/
#define M_OFFSET_GAIN                                 0x0000L
#define M_WEIGHTED_AVERAGE                            0x0001L
#define M_MULTIPLY_ACCUMULATE_1                       0x0002L
#define M_MULTIPLY_ACCUMULATE_2                       0x0004L

/************************************************************************/
/* MimFlip()                                                            */
/************************************************************************/
#define M_FLIP_VERTICAL                               1L
#define M_FLIP_HORIZONTAL                             2L

/************************************************************************/
/* MimBinarize(), MimClip(), MimLocateEvent(), MimStat()                */
/* Some of these defines are also define in milutil.h                   */
/************************************************************************/
#define M_IN_RANGE                                    1L
#define M_OUT_RANGE                                   2L
#define M_EQUAL                                       3L
#define M_NOT_EQUAL                                   4L
#define M_GREATER                                     5L
#define M_LESS                                        6L
#define M_GREATER_OR_EQUAL                            7L
#define M_LESS_OR_EQUAL                               8L
#define M_MASK                                        0x00001000L

/************************************************************************/
/* MimConvolve()                                                        */
/************************************************************************/
#define M_ID_OFFSET_OF_DEFAULT_KERNEL                 (0x00100000L|M_PSEUDO_ID)
#define M_ID_OFFSET_OF_EDGE_DETECTVAR                 (0x00100100L|M_PSEUDO_ID)
#define M_SMOOTH                                      (M_ID_OFFSET_OF_DEFAULT_KERNEL +  0L)
#define M_LAPLACIAN_EDGE                              (M_ID_OFFSET_OF_DEFAULT_KERNEL +  1L)
#define M_LAPLACIAN_EDGE2                             (M_ID_OFFSET_OF_DEFAULT_KERNEL +  2L)
#define M_SHARPEN                                     (M_ID_OFFSET_OF_DEFAULT_KERNEL +  3L)
#define M_SHARPEN2                                    (M_ID_OFFSET_OF_DEFAULT_KERNEL +  4L)
#define M_HORIZ_EDGE                                  (M_ID_OFFSET_OF_DEFAULT_KERNEL +  5L)
#define M_VERT_EDGE                                   (M_ID_OFFSET_OF_DEFAULT_KERNEL +  6L)
#define M_EDGE_DETECT                                 (M_ID_OFFSET_OF_DEFAULT_KERNEL +  7L)
#define M_EDGE_DETECT2                                (M_ID_OFFSET_OF_DEFAULT_KERNEL +  8L)
#define M_EDGE_DETECT_SQR                             (M_ID_OFFSET_OF_DEFAULT_KERNEL +  9L)
#define M_FIRST_DERIVATIVE_X                          (M_ID_OFFSET_OF_DEFAULT_KERNEL + 10L)
#define M_FIRST_DERIVATIVE_Y                          (M_ID_OFFSET_OF_DEFAULT_KERNEL + 11L)
#define M_SECOND_DERIVATIVE_X                         (M_ID_OFFSET_OF_DEFAULT_KERNEL + 12L)
#define M_SECOND_DERIVATIVE_Y                         (M_ID_OFFSET_OF_DEFAULT_KERNEL + 13L)
#define M_SECOND_DERIVATIVE_XY                        (M_ID_OFFSET_OF_DEFAULT_KERNEL + 14L)
#define M_EDGE_DETECTVAR(Val)                         (M_ID_OFFSET_OF_EDGE_DETECTVAR + Val)

#if (BW_COMPATIBILITY == 0x80)
   #define M_OVERSCAN_DISABLE                         0x40000000L
#else
   #define M_OVERSCAN_DISABLE                         0x00080000L
#endif   // (BW_COMPATIBILITY == 0x80)
#define M_OVERSCAN_FAST                               0x00040000L

#define M_SHEN_PREDEFINED_KERNEL                      (0x10000000L|M_ID_OFFSET_OF_DEFAULT_KERNEL)
#define M_DERICHE_PREDEFINED_KERNEL                   (0x20000000L|M_ID_OFFSET_OF_DEFAULT_KERNEL)
#define M_SHEN_PREDEFINED_KERNEL_INVALID_TYPE         (0x01000000L|M_SHEN_PREDEFINED_KERNEL)
#define M_SHEN_PREDEFINED_KERNEL_INVALID_FACTOR       (0x02000000L|M_SHEN_PREDEFINED_KERNEL)
#define M_DERICHE_PREDEFINED_KERNEL_INVALID_TYPE      (0x01000000L|M_DERICHE_PREDEFINED_KERNEL)
#define M_DERICHE_PREDEFINED_KERNEL_INVALID_FACTOR    (0x02000000L|M_DERICHE_PREDEFINED_KERNEL)

#define M_SHEN_FILTER(FilterOperation, FilterSmoothness)  (((((FilterOperation) & M_ID_OFFSET_OF_DEFAULT_KERNEL) != M_ID_OFFSET_OF_DEFAULT_KERNEL) && (FilterOperation!=M_DEFAULT))   ? M_SHEN_PREDEFINED_KERNEL_INVALID_TYPE :   \
   ((((FilterOperation) & (~(M_ID_OFFSET_OF_DEFAULT_KERNEL | 0xFF))) != 0) && (FilterOperation!=M_DEFAULT))                    ? M_SHEN_PREDEFINED_KERNEL_INVALID_TYPE :   \
   (((((FilterSmoothness) < 0) || ((FilterSmoothness) > 100))) && (FilterSmoothness!=M_DEFAULT))                               ? M_SHEN_PREDEFINED_KERNEL_INVALID_FACTOR : \
   M_SHEN_PREDEFINED_KERNEL | ((FilterOperation==M_DEFAULT) ? 0x80 : FilterOperation) | ((FilterSmoothness==M_DEFAULT)?(0xFF00):(((long) FilterSmoothness) << 8))          )

#define M_DERICHE_FILTER(FilterOperation, FilterSmoothness) (((((FilterOperation) & M_ID_OFFSET_OF_DEFAULT_KERNEL) != M_ID_OFFSET_OF_DEFAULT_KERNEL) && (FilterOperation!=M_DEFAULT)) ? M_DERICHE_PREDEFINED_KERNEL_INVALID_TYPE :   \
   ((((FilterOperation) & (~(M_ID_OFFSET_OF_DEFAULT_KERNEL | 0xFF))) != 0) && (FilterOperation!=M_DEFAULT))                  ? M_DERICHE_PREDEFINED_KERNEL_INVALID_TYPE :   \
   (((((FilterSmoothness) < 0) || ((FilterSmoothness) > 100))) && (FilterSmoothness!=M_DEFAULT))                             ? M_DERICHE_PREDEFINED_KERNEL_INVALID_FACTOR : \
   M_DERICHE_PREDEFINED_KERNEL | ((FilterOperation==M_DEFAULT) ? 0x80 : FilterOperation) | ((FilterSmoothness==M_DEFAULT)?(0xFF00):(((long) FilterSmoothness) << 8))        )

#define M_SHEN                               0x802L
#define M_DERICHE                            M_ID_OFFSET_OF_DEFAULT_KERNEL + 10L

/************************************************************************/
/* MimEdgeDetect()                                                      */
/************************************************************************/
#define M_SOBEL                                       M_EDGE_DETECT
#define M_PREWITT                                     M_EDGE_DETECT2
#define M_NOT_WRITE_ANGLE                             1L
#define M_NOT_WRITE_INT                               2L
#define M_FAST_ANGLE                                  4L
#define M_FAST_GRADIENT                               8L
#define M_FAST_EDGE_DETECT                            (M_FAST_ANGLE + M_FAST_GRADIENT)
#define M_REGULAR_ANGLE                               16L
#define M_REGULAR_GRADIENT                            64L
#define M_REGULAR_EDGE_DETECT                         (M_REGULAR_ANGLE + M_REGULAR_GRADIENT)
#define M_USE_RESERVED_ANGLE_VALUE                    128L

/************************************************************************/
/* MimRank()                                                            */
/************************************************************************/
#define M_MEDIAN                                      0x10000L
#define M_3X3_RECT                                    (M_ID_OFFSET_OF_DEFAULT_KERNEL + 20L)
#define M_3X3_CROSS                                   (M_ID_OFFSET_OF_DEFAULT_KERNEL + 21L)
#define M_5X5_RECT                                    (M_ID_OFFSET_OF_DEFAULT_KERNEL + 30L)

/************************************************************************/
/* MimMorphic(), ...                                                    */
/************************************************************************/
#define M_ERODE                                       1L
#define M_DILATE                                      2L
#define M_THIN                                        3L
#define M_THICK                                       4L
#define M_HIT_OR_MISS                                 5L
#define M_MATCH                                       6L
#define M_AREA_OPEN                                   7L
#define M_AREA_CLOSE                                  8L
#define M_HIT_THRESHOLD                              16L

/************************************************************************/
/* MimThin()                                                            */
/************************************************************************/
#define M_TO_SKELETON                                -1L
#define M_BINARY2                                     1L
#define M_BINARY3                                     2L

/************************************************************************/
/* MimThick()                                                           */
/************************************************************************/
#define M_TO_IDEMPOTENCE                              M_TO_SKELETON

/************************************************************************/
/* MimDistance()                                                        */
/************************************************************************/
#define M_CHAMFER_3_4                                 0x01
#define M_CITY_BLOCK                                  0x02
#define M_CHESSBOARD                                  0x04
#define M_FORWARD                                     0x01
#define M_BACKWARD                                    0x02
#define M_OVERSCAN_TO_DO                              0x04
#define M_BOTH                                        0x07

/************************************************************************/
/* MimWatershed()                                                        */
/************************************************************************/
#define M_WATERSHED                                   0x0001
#define M_BASIN                                       0x0002
#define M_MINIMA_FILL                                 0x0004
#define M_MAXIMA_FILL                                 0x0008

#define M_4_CONNECTED                                 0x00000010L
#define M_8_CONNECTED                                 0x00000020L
#define M_REGULAR                                     0x00020000L
#define M_STRAIGHT_WATERSHED                          0x0080
#define M_SKIP_LAST_LEVEL                             0x0100
#define M_FILL_SOURCE                                 0x0200
#define M_LABELLED_MARKER                             0x0400
#define M_LABELED_MARKER                              M_LABELLED_MARKER

#define M_METHOD_1                                    0x1000
#define M_METHOD_2                                    0x2000

#define M_BASIN_4_CONNECTED                           0x4000
#define M_BASIN_8_CONNECTED                           0x8000

/************************************************************************/
/* MimProject()                                                         */
/************************************************************************/
#define M_0_DEGREE                                      0.0
#define M_90_DEGREE                                    90.0
#define M_180_DEGREE                                  180.0
#define M_270_DEGREE                                  270.0

/************************************************************************/
/* MimResize(), MimTranslate() and MimRotate()                          */
/************************************************************************/
#if (BW_COMPATIBILITY == 0x80)
   #define M_OVERSCAN_DISABLE                         0x40000000L
#else
   #define M_OVERSCAN_DISABLE                         0x00080000L
#endif   // (BW_COMPATIBILITY == 0x80)
#define M_OVERSCAN_ENABLE                             0x00008000L
#define M_OVERSCAN_FAST                               0x00040000L
#define M_INTERPOLATE                                 0x00000004L
#define M_BILINEAR                                    0x00000008L
#define M_BICUBIC                                     0x00000010L
#define M_AVERAGE                                     0x00000020L
#define M_NEAREST_NEIGHBOR                            0x00000040L
#define M_OVERSCAN_CLEAR                              0x00000080L
#define M_FIT_ALL_ANGLE                               0x00000100L
#define M_BINARY                                      0x00001000L
#ifdef  M_MIL_75_COMPATIBLE                               //TBR MIL 8.0
#define M_FAST                                        0x00040000L
#else
#define M_FAST                                        0x00002000L
#endif
#define M_REGULAR                                     0x00020000L

/************************************************************************/
/* MimResize                                                            */
/************************************************************************/
#define M_FILL_DESTINATION                            -1 // DO NOT MODIFY, WITHOUT CODE MODIFICATION

/************************************************************************/
/* MimHistogramEqualize()                                               */
/************************************************************************/
#define M_UNIFORM                                     1
#define M_EXPONENTIAL                                 2
#define M_RAYLEIGH                                    3
#define M_HYPER_CUBE_ROOT                             4
#define M_HYPER_LOG                                   5

/************************************************************************/
/* MimConvert()                                                         */
/************************************************************************/
#define M_REGULAR                                     0x00020000L
#define M_FAST                                        0x00002000L
#define M_MASK                                        0x00001000L

#if (BW_COMPATIBILITY == 0x80)

#define M_RGB_TO_HLS                                  1L
#define M_RGB_TO_L                                    2L
#define M_HLS_TO_RGB                                  3L
#define M_L_TO_RGB                                    4L
#define M_RGB_TO_Y                                    5L
#define M_RGB_TO_H                                    6L

#define M_RGB_TO_YUV16                                101L           // Same as Mil.h
#define M_RGB_TO_YCBCR                                7L
#define M_RGB_TO_YCRCB                                7L  //Obsolete
#define M_RGB_TO_YCLIP                                8L
#define M_YUV16_TO_RGB                                301L           // Same as Mil.h
#define M_YCBCR_TO_RGB                                9L
#define M_YCRCB_TO_RGB                                9L  //Obsolete

#define M_PSEUDO_MATRIX                               0x40000000L
#define M_MATRIX_ID(x)                                ((x) | M_PSEUDO_MATRIX)

#else

#define M_ID_OFFSET_OF_DEFAULT_CONVERT                (0x00200000L|M_PSEUDO_ID)

#define M_RGB_TO_HSL                                  (M_ID_OFFSET_OF_DEFAULT_CONVERT + 1L)     // Same as Mil.h
#define M_RGB_TO_HLS                                  M_RGB_TO_HSL                              // Obsolete
#define M_RGB_TO_L                                    (M_ID_OFFSET_OF_DEFAULT_CONVERT + 2L)     // Same as Mil.h
#define M_HSL_TO_RGB                                  (M_ID_OFFSET_OF_DEFAULT_CONVERT + 3L)     // Same as Mil.h
#define M_HLS_TO_RGB                                  M_HSL_TO_RGB                              // Obsolete
#define M_L_TO_RGB                                    (M_ID_OFFSET_OF_DEFAULT_CONVERT + 4L)     // Same as Mil.h
#define M_RGB_TO_Y                                    (M_ID_OFFSET_OF_DEFAULT_CONVERT + 5L)     // Same as Mil.h
#define M_RGB_TO_H                                    (M_ID_OFFSET_OF_DEFAULT_CONVERT + 6L)     // Same as Mil.h

#define M_RGB_TO_YUV16                                (M_ID_OFFSET_OF_DEFAULT_CONVERT + 101L)   // Same as Mil.h
#define M_RGB_TO_YCBCR                                (M_ID_OFFSET_OF_DEFAULT_CONVERT + 7L)
#define M_RGB_TO_YCRCB                                M_RGB_TO_YCBCR                            // Obsolete
#define M_RGB_TO_YCLIP                                (M_ID_OFFSET_OF_DEFAULT_CONVERT + 8L)
#define M_YUV16_TO_RGB                                (M_ID_OFFSET_OF_DEFAULT_CONVERT + 301L)   // Same as Mil.h
#define M_YCBCR_TO_RGB                                (M_ID_OFFSET_OF_DEFAULT_CONVERT + 9L)
#define M_YCRCB_TO_RGB                                M_YCBCR_TO_RGB                            // Obsolete

#define M_MATRIX_ID(x)                                (x)                                       // Obsolete from MIL 9

#endif

// If the conversion type is set to M_DEFAULT, the conversion will be
//  choosen according to the type of buffers passed to the function.
#define M_DEFAULT                                    0x10000000L

// These can be added to the conversion type to speed-up the
//   process ( M_FAST ) or have a better precision ( M_REGULAR ).
//   Not all conversion are affected by this flag.
#define M_REGULAR                                     0x00020000L
#ifdef  M_MIL_75_COMPATIBLE                               //TBR MIL 8.0
#define M_FAST                                        0x00040000L
#else
#define M_FAST                                        0x00002000L
#endif

/************************************************************************/
/* MimWarp()                                                            */
/************************************************************************/
/* 8 bits reserved for number of fractional bits */
#define M_WARP_MATRIX                                 0x00100000L
#define M_WARP_POLYNOMIAL                             0x00200000L
#define M_WARP_LUT                                    0x00400000L
#define M_OVERSCAN_ENABLE                             0x00008000L
#if (BW_COMPATIBILITY == 0x80)
   #define M_OVERSCAN_DISABLE                         0x40000000L
#else
   #define M_OVERSCAN_DISABLE                         0x00080000L
#endif   // (BW_COMPATIBILITY == 0x80)
#define M_OVERSCAN_FAST                               0x00040000L
#define M_OVERSCAN_CLEAR                              0x00000080L
#define M_FIXED_POINT                                 0x00004000L

/************************************************************************/
/* MimTransform()                                                       */
/************************************************************************/
#define M_FFT                                         1L
#define M_DCT8X8                                      2L
#define M_DCT8x8                                      2L  //Obsolete
#define M_DCT                                         3L
#define M_FFT_OLD                                     4L
#define M_POLAR                                       5L

#define M_FORWARD                                     0x01
#define M_REVERSE                                     4L
#define M_NORMALIZED                                  0x00000002L
#define M_NORMALIZE                                   M_NORMALIZED
#define M_1D_ROWS                                     0x00000010L
#define M_1D_COLUMNS                                  0x00000020L
#define M_REAL                                        0x00000040L
#define M_CENTER                                      0x00000080L
#define M_MAGNITUDE                                   0x00000100L
#define M_PHASE                                       0x00000200L
#define M_LOG_SCALE                                   0x00000400L
#define M_FAST_PHASE                                  0x00000800L
#define M_SQUARE_MAGNITUDE                            0x00001000L
#define M_NORMALIZE_PHASE                             0x00002000L
#define M_NORMALIZE_PHASE_255                         0x00008000L
#define M_CLOCKWISE_PHASE                             0x00010000L
#define M_USE_CORDIC                                  0x00020000L
#define M_INTERNAL_FFT_NEW                            0x00000008L

/************************************************************************/
/* MimPolarTransform()                                                  */
/************************************************************************/
#define M_RECTANGULAR_TO_POLAR                        0x00000001L
#define M_POLAR_TO_RECTANGULAR                        0x00000002L

/************************************************************************/
/* MimDraw()                                                       */
/************************************************************************/
#define M_DRAW_PEAKS                                  0x01000000L
#define M_DOTS                                        0x00000040L
#define M_LINES                                       0x00000080L
// M_1D_COLUMNS and M_1D_ROWS are already defined in MimTransform section


/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __midl // MIDL compiler used by ActiveMIL

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* POINT TO POINT : */

      /* -------------------------------------------------------------- */

#if M_MIL_USE_64BIT
   #define MimArith(Src1, Src2, Dest, Op) MimArithDouble(M_MILID_TO_DOUBLE(Src1), M_MILID_TO_DOUBLE(Src2), Dest, Op)
#else
   #define MimArithDouble MimArith
#endif
MFTYPE32 void MFTYPE    MimArithDouble       (double Src1ImageBufIdOrConstant,
                                              double Src2ImageBufIdOrConstant,
                                              MIL_ID DestImageBufId,
                                              MIL_INT Operation);

#if M_MIL_USE_64BIT
   #define MimArithMultiple(Src1, Src2, Src3, Src4, Src5, Dest, Op, OpFlag) MimArithMultipleDouble(M_MILID_TO_DOUBLE(Src1), M_MILID_TO_DOUBLE(Src2), M_MILID_TO_DOUBLE(Src3), Src4, Src5, Dest, Op, OpFlag)
#else
   #define MimArithMultipleDouble MimArithMultiple
#endif
MFTYPE32 void MFTYPE    MimArithMultipleDouble(double Src1ImageBufId,
                                              double Src2ImageBufIdOrConstant,
                                              double Src3ImageBufIdOrConstant,
                                              double Src4Constant,
                                              double Src5Constant,
                                              MIL_ID DestImageBufId,
                                              MIL_INT Operation,
                                              MIL_INT OperationFlag);

MFTYPE32 void MFTYPE    MimLutMap            (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_ID LutId);

MFTYPE32 void MFTYPE    MimShift             (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbBitsToShift);

MFTYPE32 MIL_INT MFTYPE    MimBinarize          (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT Condition,
                                              double CondLow,
                                              double CondHigh);

MFTYPE32 void MFTYPE    MimClip              (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT Condition,
                                              double CondLow,
                                              double CondHigh,
                                              double WriteLow,
                                              double WriteHigh);



      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* NEIGHBOURHOOD : */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimDeinterlace       (MIL_ID ContextId,
                                              MIL_API_CONST MIL_ID *SrcImageArrayPtr,
                                              MIL_API_CONST MIL_ID *DstImageArrayPtr,
                                              MIL_INT   SrcImageCount,
                                              MIL_INT   DstImageCount,
                                              MIL_INT   ControlFlag);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* GEOMETRICAL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimResize             (MIL_ID SrcImageId,
                                               MIL_ID DestImageId,
                                               double FactorX,
                                               double FactorY,
                                               MIL_INT InterpolationType);

MFTYPE32 void MFTYPE    MimFlip               (MIL_ID SrcImageId,
                                               MIL_ID DestImageId,
                                               MIL_INT Operation,
                                               MIL_INT Mode);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* STATISTICAL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimHistogram         (MIL_ID SrcImageId,
                                              MIL_ID HistogramListId);

MFTYPE32 void MFTYPE    MimHistogramEqualize (MIL_ID src_id,
                                              MIL_ID dst_id,
                                              MIL_INT  EqualizationType,
                                              double Alpha,
                                              double Min,
                                              double Max);

MFTYPE32 void MFTYPE    MimFindExtreme       (MIL_ID SrcImageId,
                                              MIL_ID ResultListId,
                                              MIL_INT ExtremeType);

MFTYPE32 MIL_ID MFTYPE  MimAllocResult       (MIL_ID SystemId,
                                              MIL_INT NumberOfResultElement,
                                              MIL_INT ResultType,
                                              MIL_ID MPTYPE *IdVarPtr);

MFTYPE32 void MFTYPE    MimFree              (MIL_ID ImResultId);

MFTYPE32 MIL_INT MFTYPE    MimInquire           (MIL_ID BufId,
                                              MIL_INT InquireType,
                                              void MPTYPE *TargetVarPtr);

MFTYPE32 void MFTYPE    MimGetResult1d       (MIL_ID ImResultId,
                                              MIL_INT Offresult,
                                              MIL_INT Sizeresult,
                                              MIL_INT ResultType,
                                              void MPTYPE *UserTargetArrayPtr);

MFTYPE32 void MFTYPE    MimGetResult         (MIL_ID ImResultId,
                                              MIL_INT ResultType,
                                              void MPTYPE *UserTargetArrayPtr);

MFTYPE32 MIL_ID MFTYPE  MimAlloc             (MIL_ID SystemId,
                                              MIL_INT ContextType,
                                              MIL_INT ControlFlag,
                                              MIL_ID MPTYPE *IdVarPtr);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs

MFTYPE32 void MFTYPE    MimControlInt64      (MIL_ID ContextId,
                                              MIL_INT ControlType,
                                              MIL_INT64 ControlValue);

MFTYPE32 void MFTYPE    MimControlDouble     (MIL_ID ContextId,
                                              MIL_INT ControlType,
                                              MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs

#define MimControlDouble   MimControl
#define MimControlInt64    MimControl
MFTYPE32 void MFTYPE    MimControl           (MIL_ID ContextId,
                                              MIL_INT   ControlType,
                                              double ControlValue);
#endif


      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* CONVERSION: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimConvert           (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
#if (BW_COMPATIBILITY == 0x80)
                                              MIL_INT ConversionType
#else
                                              MIL_ID ConversionType
#endif
                                              );

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* BUF: */

      /* -------------------------------------------------------------- */
#if M_MIL_USE_UNICODE

MFTYPE32 MIL_ID MFTYPE MimRestoreA           (const char* FileName,
                                              MIL_ID SystemId,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ContextIdPtr);
MFTYPE32 void MFTYPE MimSaveA                (const char* FileName,
                                              MIL_ID ContextId,
                                              MIL_INT ControlFlag);
MFTYPE32 void MFTYPE MimStreamA              (char* MemPtrOrFileName,
                                              MIL_ID SystemId,
                                              MIL_INT Operation,
                                              MIL_INT StreamType,
                                              double Version,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ObjectIdPtr,
                                              MIL_INT *SizeByteVarPtr);

MFTYPE32 MIL_ID MFTYPE MimRestoreW           (MIL_TEXT_PTR FileName,
                                              MIL_ID SystemId,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ContextIdPtr);
MFTYPE32 void MFTYPE MimSaveW                (MIL_TEXT_PTR FileName,
                                              MIL_ID ContextId,
                                              MIL_INT ControlFlag);
MFTYPE32 void MFTYPE MimStreamW              (MIL_TEXT_PTR MemPtrOrFileName,
                                              MIL_ID SystemId,
                                              MIL_INT Operation,
                                              MIL_INT StreamType,
                                              double Version,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ObjectIdPtr,
                                              MIL_INT *SizeByteVarPtr);

#if M_MIL_UNICODE_API
#define MimRestore   MimRestoreW
#define MimSave      MimSaveW
#define MimStream    MimStreamW
#else
#define MimRestore   MimRestoreA
#define MimSave      MimSaveA
#define MimStream    MimStreamA
#endif

#else

MFTYPE32 MIL_ID MFTYPE MimRestore            (MIL_TEXT_PTR FileName,
                                              MIL_ID SystemId,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ContextIdPtr);

MFTYPE32 void MFTYPE MimSave                 (MIL_TEXT_PTR FileName,
                                              MIL_ID ContextId,
                                              MIL_INT ControlFlag);

MFTYPE32 void MFTYPE MimStream               (MIL_TEXT_PTR MemPtrOrFileName,
                                              MIL_ID SystemId,
                                              MIL_INT Operation,
                                              MIL_INT StreamType,
                                              double Version,
                                              MIL_INT ControlFlag,
                                              MIL_ID *ObjectIdPtr,
                                              MIL_INT *SizeByteVarPtr);
#endif   //#if M_MIL_USE_UNICODE

#if (!M_MIL_LITE)

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* NEIGHBOURHOOD : */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimConvolve          (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_ID KernelId);

MFTYPE32 void MFTYPE    MimRank              (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_ID KernelId,
                                              MIL_INT Rank,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimEdgeDetect        (MIL_ID SrcImageId,
                                              MIL_ID DestIntensityImageId,
                                              MIL_ID DestAngleImageId,
                                              MIL_ID KernelId,
                                              MIL_INT ControlFlag,
                                              MIL_INT ThresholdVal);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* MORPHOLOGICAL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimLabel             (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimConnectMap        (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_ID LutBufId);

MFTYPE32 void MFTYPE    MimDilate            (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimErode             (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimClose             (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimOpen              (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimMorphic           (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_ID StructElementId,
                                              MIL_INT Operation,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimThin              (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimThick             (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT NbIteration,
                                              MIL_INT Mode);

MFTYPE32 void MFTYPE    MimDistance          (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT DistanceTranform);


MFTYPE32 void MFTYPE    MimWatershed         (MIL_ID SrcImageId,
                                              MIL_ID MarkerImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT lMinimalVariation,
                                              MIL_INT lControlFlag);


MFTYPE32 void MFTYPE    MimZoneOfInfluence   (MIL_ID SrcImageId,
                                              MIL_ID DestImageId,
                                              MIL_INT OperationFlag);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* GEOMETRICAL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimRotate             (MIL_ID SrcImageId,
                                               MIL_ID DstImageId,
                                               double Angle,
                                               double SrcCenX,
                                               double SrcCenY,
                                               double DstCenX,
                                               double DstCenY,
                                               MIL_INT   InterpolationMode);

MFTYPE32 void MFTYPE    MimTranslate          (MIL_ID SrcImageId,
                                               MIL_ID DestImageId,
                                               double xShift,
                                               double yShift,
                                               MIL_INT InterpolationType);

MFTYPE32 void MFTYPE    MimWarp               (MIL_ID SrcImageId,
                                               MIL_ID DestImageId,
                                               MIL_ID WarpParam1Id,
                                               MIL_ID WarpParam2Id,
                                               MIL_INT   OperationMode,
                                               MIL_INT   InterpolationMode);

MFTYPE32 void MFTYPE    MimPolarTransform (MIL_ID  SrcImageId,
                                           MIL_ID  DestImageId,
                                           double  CenterPosX,
                                           double  CenterPosY,
                                           double  StartRadius,
                                           double  EndRadius,
                                           double  StartAngle,
                                           double  EndAngle,
                                           MIL_INT    OperationMode,
                                           MIL_INT    InterpolationMode,
                                           double *DestinationSizeXPtr,
                                           double *DestinationSizeYPtr);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* STATISTICAL: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE    MimProject           (MIL_ID SrcImageId,
                                              MIL_ID DestArrayId,
                                              double ProjectionAngle);

#if M_MIL_USE_64BIT
   #define MimStat(Src, Result, Type, Condition, CondLow, CondHigh) MimStatDouble(Src, Result, Type, Condition, M_MILID_TO_DOUBLE(CondLow), CondHigh)
#else
   #define MimStatDouble MimStat
#endif
MFTYPE32 void MFTYPE    MimStatDouble        (MIL_ID SrcImageId,
                                              MIL_ID StatResultId,
                                              MIL_INT StatType,
                                              MIL_INT Condition,
                                              double CondLow,
                                              double CondHigh);

MFTYPE32 void MFTYPE    MimLocateEvent       (MIL_ID SrcImageId,
                                              MIL_ID EventResultId,
                                              MIL_INT Condition,
                                              double CondLow,
                                              double CondHigh);

MFTYPE32 void MFTYPE    MimLocatePeak1d      (MIL_ID SrcImageBufId,
                                              MIL_ID DestPositionImageBufId,
                                              MIL_ID DestIntensityImageBufId,
                                              MIL_INT DestY,
                                              MIL_INT PeakWidth,
                                              double MinIntensity,
                                              MIL_INT ControlFlag,
                                              double ControlValue);

MFTYPE32 void MFTYPE    MimCountDifference   (MIL_ID Src1ImageId,
                                              MIL_ID Src2ImageId,
                                              MIL_ID ResId);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* TRANSFORM: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE MimTransform            (MIL_ID SrcImageRId,
                                              MIL_ID SrcImageIId,
                                              MIL_ID DestImageRId,
                                              MIL_ID DestImageIId,
                                              MIL_INT TransformType,
                                              MIL_INT ControlFlag);

      /* -------------------------------------------------------------- */
      /* -------------------------------------------------------------- */

      /* DRAW: */

      /* -------------------------------------------------------------- */

MFTYPE32 void MFTYPE MimDraw                 (MIL_ID GraphContId,
                                              MIL_ID Src1ResultId,
                                              MIL_ID Src2ResultId,
                                              MIL_ID DstImageId,
                                              MIL_INT Operation,
                                              double Param1,
                                              double Param2,
                                              MIL_INT ControlFlag);

#endif // (!MIL_LITE)

#endif /* #ifdef __midl */


#ifdef __cplusplus
} // extern "C"
#endif

#if M_MIL_USE_64BIT
#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// MbufControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void MimControl(MIL_ID ContextId,
                       MIL_INT ControlType,
                       int ControlValue)
   {
   MimControlInt64(ContextId, ControlType, ControlValue);
   };
#endif

inline void MimControl(MIL_ID ContextId,
                       MIL_INT ControlType,
                       MIL_INT32 ControlValue)
   {
   MimControlInt64(ContextId, ControlType, ControlValue);
   };

inline void MimControl(MIL_ID ContextId,
                       MIL_INT ControlType,
                       MIL_INT64 ControlValue)
   {
   MimControlInt64(ContextId, ControlType, ControlValue);
   };

inline void MimControl(MIL_ID ContextId,
                       MIL_INT ControlType,
                       MIL_DOUBLE ControlValue)
   {
   MimControlDouble(ContextId, ControlType, ControlValue);
   };

#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define MimControl  MimControlInt64

#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------
// MimGetResult

inline MFTYPE32 void MFTYPE MimGetResultUnsafe  (MIL_ID MimResultId, MIL_INT ResultType, void          MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, int                   UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, MIL_INT32     MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, MIL_INT64     MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, float         MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, MIL_DOUBLE    MPTYPE *UserResultArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, MIL_UINT32    MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID MimResultId, MIL_INT ResultType, MIL_UINT64    MPTYPE *UserResultArrayPtr);
#endif

//-------------------------------------------------------------------------------------
// MimGetResult1d

inline MFTYPE32 void MFTYPE MimGetResult1dUnsafe  (MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, void          MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, int                   UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_INT32     MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_INT64     MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, float         MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_DOUBLE    MPTYPE *UserResultArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_UINT32    MPTYPE *UserResultArrayPtr);
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID MimResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_UINT64    MPTYPE *UserResultArrayPtr);
#endif

// ----------------------------------------------------------
// MimInquire

inline MFTYPE32 MIL_INT MFTYPE MimInquireUnsafe  (MIL_ID CodeId, MIL_INT ParamToInquire, void       MPTYPE * ValuePtr);
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, int                 ValuePtr);
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, MIL_INT32  MPTYPE * ValuePtr);
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, MIL_INT64  MPTYPE * ValuePtr);
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, MIL_DOUBLE MPTYPE * ValuePtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, MIL_UINT32 MPTYPE * ValuePtr);
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID CodeId, MIL_INT ParamToInquire, MIL_UINT64 MPTYPE * ValuePtr);
#endif

// -------------------------------------------------------------------------
// MimGetResult

inline MIL_INT MimGetResultRequiredType(MIL_ID ImResultId, MIL_INT ResultType)
   {
   switch (ResultType)
      {
      case M_NB_EVENT:
      case M_POSITION_X:
      case M_POSITION_Y:
         // For these results, the doc specifies that MIL_INT is returned
         // except when allocated with 32+M_FLOAT, where a float is returned.
         if (MbufInquire(ImResultId, M_TYPE, M_NULL) == 32+M_FLOAT)
            return M_TYPE_FLOAT;
         else
            return M_TYPE_MIL_INT;
         break;

      case M_VALUE:
         {
         // For M_VALUE, the doc specifies that MIL_INT is returned
         // except for M_PROJ_LIST, M_EXTREME_LIST, M_EVENT_LIST
         // allocated with 32+M_FLOAT, where a float is returned.
         MIL_INT IdResultType = MimInquire(ImResultId, M_RESULT_TYPE, NULL);
         switch (IdResultType)
            {
            case M_PROJ_LIST:
            case M_EXTREME_LIST:
            case M_EVENT_LIST:
               if (MbufInquire(ImResultId, M_TYPE, M_NULL) == 32+M_FLOAT)
                  return M_TYPE_FLOAT;
               else
                  return M_TYPE_MIL_INT;
               break;
            default:
               return M_TYPE_MIL_INT;
               break;
            }
         }
         break;

      default:
         return M_TYPE_DOUBLE;
         break;
      }
   }

inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, int                UserResultArrayPtr)
   {
   if (UserResultArrayPtr)
      SafeTypeError(MT("MimGetResult"));

   MimGetResult(ImResultId, ResultType, NULL);
   }

inline void MimGetResultSafeTypeExecute (MIL_ID ImResultId, MIL_INT ResultType, void          MPTYPE *UserResultArrayPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = (ResultType & (M_TYPE_DOUBLE | M_TYPE_MIL_INT32 | 
#if (BW_COMPATIBILITY != 0x80)
      M_TYPE_MIL_INT64 | 
#endif
      M_TYPE_FLOAT ));
   if (RequiredType == 0)
      RequiredType = MimGetResultRequiredType(ImResultId, ResultType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MimGetResult"));

   MimGetResult(ImResultId, ResultType, UserResultArrayPtr);
   }


inline MFTYPE32 void MFTYPE MimGetResultUnsafe  (MIL_ID ImResultId, MIL_INT ResultType, void       MPTYPE *UserResultArrayPtr) {MimGetResult               (ImResultId, ResultType, UserResultArrayPtr);}
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, MIL_INT32  MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, MIL_INT64  MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, float      MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_FLOAT);}
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, MIL_DOUBLE MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_DOUBLE);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, MIL_UINT32 MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 void MFTYPE MimGetResultSafeType(MIL_ID ImResultId, MIL_INT ResultType, MIL_UINT64 MPTYPE *UserResultArrayPtr) {MimGetResultSafeTypeExecute(ImResultId, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// -------------------------------------------------------------------------
// MimGetResult1d

inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, int                UserResultArrayPtr)
   {
   if (UserResultArrayPtr)
      SafeTypeError(MT("MimGetResult1d"));

   MimGetResult1d(ImResultId, OffEntry, NbEntries, ResultType, NULL);
   }

inline void MimGetResult1dSafeTypeExecute (MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, void          MPTYPE *UserResultArrayPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = (ResultType & (M_TYPE_DOUBLE | M_TYPE_MIL_INT32 | 
#if (BW_COMPATIBILITY != 0x80)
      M_TYPE_MIL_INT64 | 
#endif
      M_TYPE_FLOAT ));
   if (RequiredType == 0)
      RequiredType = MimGetResultRequiredType(ImResultId, ResultType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MimGetResult1d"));

   MimGetResult1d(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr);
   }

inline MFTYPE32 void MFTYPE MimGetResult1dUnsafe  (MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, void          MPTYPE *UserResultArrayPtr) {MimGetResult1d               (ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr);}
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_INT32  MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_INT64  MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, float      MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_FLOAT);}
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_DOUBLE MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_DOUBLE);}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_UINT32 MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 void MFTYPE MimGetResult1dSafeType(MIL_ID ImResultId, MIL_INT OffEntry, MIL_INT NbEntries, MIL_INT ResultType, MIL_UINT64 MPTYPE *UserResultArrayPtr){MimGetResult1dSafeTypeExecute(ImResultId, OffEntry, NbEntries, ResultType, UserResultArrayPtr, M_TYPE_MIL_INT64);}
#endif

// ----------------------------------------------------------
// MimInquire

inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MT("MimInquire"));

   return MimInquire(ContextOrResultId,InquireType, NULL);
   }

inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeTypeExecute (MIL_ID ContextOrResultId, MIL_INT InquireType, void MPTYPE *UserVarPtr, MIL_INT GivenType)
   {
   MIL_INT RequiredType = (InquireType & (M_TYPE_MIL_INT32 | 
#if (BW_COMPATIBILITY != 0x80)
      M_TYPE_MIL_INT64 | 
#endif
      M_TYPE_DOUBLE | M_TYPE_MIL_ID));
   if (RequiredType == 0)
      RequiredType = M_TYPE_MIL_INT;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MT("MimInquire"));

   return MimInquire(ContextOrResultId, InquireType, UserVarPtr);
   }

inline MFTYPE32 MIL_INT MFTYPE MimInquireUnsafe  (MIL_ID ContextOrResultId, MIL_INT InquireType, void       MPTYPE *UserVarPtr) {return MimInquire               (ContextOrResultId, InquireType, UserVarPtr                  );}
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, MIL_INT32  MPTYPE *UserVarPtr) {return MimInquireSafeTypeExecute(ContextOrResultId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, MIL_INT64  MPTYPE *UserVarPtr) {return MimInquireSafeTypeExecute(ContextOrResultId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, MIL_DOUBLE MPTYPE *UserVarPtr) {return MimInquireSafeTypeExecute(ContextOrResultId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, MIL_UINT32 MPTYPE *UserVarPtr) {return MimInquireSafeTypeExecute(ContextOrResultId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MFTYPE32 MIL_INT MFTYPE MimInquireSafeType(MIL_ID ContextOrResultId, MIL_INT InquireType, MIL_UINT64 MPTYPE *UserVarPtr) {return MimInquireSafeTypeExecute(ContextOrResultId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#define MimGetResult         MimGetResultSafeType
#define MimGetResult1d       MimGetResult1dSafeType
#define MimInquire           MimInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define MimGetResultUnsafe         MimGetResult
#define MimGetResult1dUnsafe       MimGetResult1d
#define MimInquireUnsafe           MimInquire

#endif // #if M_MIL_USE_SAFE_TYPE


#endif //__MILIM_H__
