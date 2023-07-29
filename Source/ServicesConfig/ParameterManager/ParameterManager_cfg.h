/******************************************************************************
 * @file ParameterManager_cfg.h
 *
 * @brief parameter manager configuration declarations
 *
 * This file provides the declarations for the parameter manager
 *
 * @copyright Copyright (c) 2012 CyberIntegration
 * This document contains proprietary data and information of CyberIntegration
 * LLC. It is the exclusive property of CyberIntegration, LLC and will not be
 * disclosed in any form to any party without prior written permission of 
 * CyberIntegration, LLC. This document may not be reproduced or further used
 * without the prior written permission of CyberIntegration, LLC.
 *
 * Version History
 * ======
 * $Rev: $
 * 
 *
 * \addtogroup ParameterManager_cfg
 * @{
 *****************************************************************************/
 
// ensure only one instantiation
#ifndef _PARAMETERMANAGER_CFG_H
#define _PARAMETERMANAGER_CFG_H

// local includes -------------------------------------------------------------
#include "ParameterManager/ParameterManager_def.h"

// macros/defines-------------------------------------------------------------

// enumerations ---------------------------------------------------------------
/// enumerate each parameter
typedef enum _PARAMSELENUM
{
  /// enumerate parameters below
  PARAMSEL_ENUM_MB0_LASTADDR = 0,       ///< 0 
  PARAMSEL_ENUM_MB0_CHECKSUM,           ///< 1
  PARAMSEL_ENUM_MB0_NUMMBANKS,          ///< 2
  PARAMSEL_ENUM_MB0_GTIN0,              ///< 3
  PARAMSEL_ENUM_MB0_GTIN1,              ///< 4
  PARAMSEL_ENUM_MB0_GTIN2,              ///< 5
  PARAMSEL_ENUM_MB0_GTIN3,              ///< 6
  PARAMSEL_ENUM_MB0_GTIN4,              ///< 7
  PARAMSEL_ENUM_MB0_GTIN5,              ///< 8
  PARAMSEL_ENUM_MB0_FWMAJ,              ///< 9
  PARAMSEL_ENUM_MB0_FWMIN,              ///< 10
  PARAMSEL_ENUM_MB0_SERNUM0,            ///< 11
  PARAMSEL_ENUM_MB0_SERNUM1,            ///< 12
  PARAMSEL_ENUM_MB0_SERNUM2,            ///< 13
  PARAMSEL_ENUM_MB0_SERNUM3,            ///< 14
  PARAMSEL_ENUM_MB0_SERNUM4,            ///< 15
  PARAMSEL_ENUM_MB0_SERNUM5,            ///< 16
  PARAMSEL_ENUM_MB0_SERNUM6,            ///< 17
  PARAMSEL_ENUM_MB0_SERNUM7,            ///< 18
  PARAMSEL_ENUM_MB0_SERNUM8,            ///< 19
  PARAMSEL_ENUM_MB0_SERNUM9,            ///< 20
  PARAMSEL_ENUM_MB0_SERNUM10,           ///< 21
  PARAMSEL_ENUM_MB0_SERNUM11,           ///< 22
  PARAMSEL_ENUM_MB0_SERNUM12,           ///< 23
  PARAMSEL_ENUM_MB0_SERNUM13,           ///< 24
  PARAMSEL_ENUM_MB0_SERNUM14,           ///< 25
  PARAMSEL_ENUM_MB0_SERNUM15,           ///< 26
  PARAMSEL_ENUM_MB0_MINFFTIME,          ///< 27
  PARAMSEL_ENUM_MB0_GEARTYPE,           ///< 28
  PARAMSEL_ENUM_MB0_POPTYPES,           ///< 29
  PARAMSEL_ENUM_MB0_FEATURES,           ///< 30
  PARAMSEL_ENUM_MB0_EXTVERNUM,          ///< 31
  PARAMSEL_ENUM_MB0_DEVTYPE,            ///< 32
  PARAMSEL_ENUM_MB0_PHYMNLVL,           ///< 33
  PARAMSEL_ENUM_MB1_LASTADDR,           ///< 34
  PARAMSEL_ENUM_MB1_CHECKSUM,           ///< 35
  PARAMSEL_ENUM_MB1_LOCKBYTE,           ///< 37
  PARAMSEL_ENUM_MB1_OEMGIN0,            ///< 38
  PARAMSEL_ENUM_MB1_OEMGIN1,            ///< 39
  PARAMSEL_ENUM_MB1_OEMGIN2,            ///< 40
  PARAMSEL_ENUM_MB1_OEMGIN3,            ///< 41
  PARAMSEL_ENUM_MB1_OEMGIN4,            ///< 42
  PARAMSEL_ENUM_MB1_OEMGIN5,            ///< 43
  PARAMSEL_ENUM_MB1_OEMSNM1,            ///< 44
  PARAMSEL_ENUM_MB1_OEMSNM2,            ///< 45
  PARAMSEL_ENUM_MB1_OEMSNM3,            ///< 46
  PARAMSEL_ENUM_MB1_OEMSNM4,            ///< 47
  PARAMSEL_ENUM_MB1_SUBSYSM,            ///< 48
  PARAMSEL_ENUM_MB1_LMPTYPEL,           ///< 49
  PARAMSEL_ENUM_MB1_LMPTYPEU,           ///< 50
  PARAMSEL_ENUM_OPS_SHRTADRR,           ///< 51
  PARAMSEL_ENUM_OPS_PWRONLVL,           ///< 52
  PARAMSEL_ENUM_OPS_SYSFLVL,            ///< 53
  PARAMSEL_ENUM_OPS_MINLVL,             ///< 54
  PARAMSEL_ENUM_OPS_MAXLVL,             ///< 55
  PARAMSEL_ENUM_OPS_LREQVAL,            ///< 56
  PARAMSEL_ENUM_OPS_FADERATE,           ///< 57
  PARAMSEL_ENUM_OPS_FADETIME,           ///< 58
  PARAMSEL_ENUM_OPS_RANADRH,            ///< 59
  PARAMSEL_ENUM_OPS_RANADRM,            ///< 60
  PARAMSEL_ENUM_OPS_RANADRL,            ///< 61
  PARAMSEL_ENUM_OPS_GRP0007,            ///< 62
  PARAMSEL_ENUM_OPS_GRP0815,            ///< 63
  PARAMSEL_ENUM_OPS_SCENE00,            ///< 64
  PARAMSEL_ENUM_OPS_SCENE01,            ///< 65
  PARAMSEL_ENUM_OPS_SCENE02,            ///< 66
  PARAMSEL_ENUM_OPS_SCENE03,            ///< 67
  PARAMSEL_ENUM_OPS_SCENE04,            ///< 68
  PARAMSEL_ENUM_OPS_SCENE05,            ///< 69
  PARAMSEL_ENUM_OPS_SCENE06,            ///< 70
  PARAMSEL_ENUM_OPS_SCENE07,            ///< 71
  PARAMSEL_ENUM_OPS_SCENE08,            ///< 72
  PARAMSEL_ENUM_OPS_SCENE09,            ///< 73
  PARAMSEL_ENUM_OPS_SCENE10,            ///< 74
  PARAMSEL_ENUM_OPS_SCENE11,            ///< 75
  PARAMSEL_ENUM_OPS_SCENE12,            ///< 76
  PARAMSEL_ENUM_OPS_SCENE13,            ///< 77
  PARAMSEL_ENUM_OPS_SCENE14,            ///< 78
  PARAMSEL_ENUM_OPS_SCENE15,            ///< 79
  PARAMSEL_ENUM_OPS_FAILSTS,            ///< 80
  PARAMSEL_ENUM_OPS_OPMODE,             ///< 81
  PARAMSEL_ENUM_OPS_FFADETIM,           ///< 82
  
  // do not remove these lines below
  PARAMSEL_MAX_NUM,
  PARAMSEL_ILLEGAL
} PARAMSELENUM;

// global parameter declarations -----------------------------------------------
extern  const PARAMDFLTS  atParamDefaults[ ];

// global function prototypes --------------------------------------------------
extern  U8    ParameterManager_GetVerMajor( void );
extern  U8    ParameterManager_GetVerMinor( void );
extern  BOOL  ParameterManager_RdByte( U16 wAddress, PU8 pnData );
extern  BOOL  ParameterManager_RdWord( U16 wAddress, PU16 pwData );
extern  BOOL  ParameterManager_RdLong( U16 wAddress, PU32 puData );
extern  BOOL  ParameterManager_RdBlock( U16 wAddress, U16 wLength, PU8 pnData );
extern  BOOL  ParameterManager_WrByte( U16 wAddress, U8 nData );
extern  BOOL  ParameterManager_WrWord( U16 wAddress, U16 wData );
extern  BOOL  ParameterManager_WrLong( U16 wAddress, U32 uData );
extern  BOOL  ParameterManager_WrBlock( U16 wAddress, U16 wLength, PU8 pnData );
#if ( PARAM_ENABLE_NOTIFICATIONS == ON )
  extern  void  Parametermanager_PostDone( BOOL bErrDet );
#endif // PARAM_ENABLE_NOTIFICATION

/**@} EOF ParameterManager_cfg.h */

#endif  // _PARAMETERMANAGER_CFG_H
