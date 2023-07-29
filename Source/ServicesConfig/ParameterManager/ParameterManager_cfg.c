/******************************************************************************
 * @file ParameterManager_cfg.c
 *
 * @brief parameter manager configuration implementation
 *
 * This file provides the implementation for the configuraitn of the paramete
 * manager
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
 * \addtogroup 
 * @{
 *****************************************************************************/

// local includes -------------------------------------------------------------
#include "ParameterManager\ParameterManager_cfg.h"
#include "ParameterManager\ParameterManager.h"
#if ( PARAM_ENABLE_CONFIGVER == OFF )
  #include "ManufInfo/ManufInfo.h"
#endif // PARAM_ENABLE_CONFIGVER

// library includes -----------------------------------------------------------


// Macros and Defines ---------------------------------------------------------

/// define the memory block write enable code

// constant parameter initializations -----------------------------------------
const CODE  PARAMDFLTS  atParamDefaults[ PARAMSEL_MAX_NUM ] =
{
  // populate the table with one of the below macros
  // PARAM_ENTRY( defval, minval, maxval, lock )
  // PARAM_ENTRYNAM( defval, minval, maxval, lock, name )
  PARAM_ENTRY(  33,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_LASTADDR,    ///< 0 
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_CHECKSUM,    ///< 1
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_NUMMBANKS,   ///< 2
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN0,       ///< 3
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN1,       ///< 4
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN2,       ///< 5
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN3,       ///< 6
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN4,       ///< 7
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GTIN5,       ///< 8
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_FWMAJ,       ///< 9
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_FWMIN,       ///< 10
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM0,     ///< 11
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM1,     ///< 12
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM2,     ///< 13
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM3,     ///< 14
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM4,     ///< 15
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM5,     ///< 16
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM6,     ///< 17
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM7,     ///< 18
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM8,     ///< 19
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM9,     ///< 20
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM10,    ///< 21
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM11,    ///< 22
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM12,    ///< 23
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM13,    ///< 24
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM14,    ///< 25
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_SERNUM15,    ///< 26
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_MINFFTIME,   ///< 27
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_GEARTYPE,    ///< 28
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_POPTYPES,    ///< 29
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_FEATURES,    ///< 30
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_EXTVERNUM,   ///< 31
  PARAM_ENTRY(   1,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_DEVTYPE,     ///< 32
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB0_PHYMNLVL,    ///< 33
  PARAM_ENTRY(  15,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_LASTADDR,    ///< 34
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_CHECKSUM,    ///< 35
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_LOCKBYTE,    ///< 37
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN0,     ///< 38
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN1,     ///< 39
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN2,     ///< 40
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN3,     ///< 41
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN4,     ///< 42
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMGIN5,     ///< 43
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMSNM1,     ///< 44
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMSNM2,     ///< 45
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMSNM3,     ///< 46
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_OEMSNM4,     ///< 47
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_SUBSYSM,     ///< 48
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_LMPTYPEL,    ///< 49
  PARAM_ENTRY(   0,   0, 255, ON  ),   // PARAMSEL_ENUM_MB1_LMPTYPEU,    ///< 50
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SHRTADRR,    ///< 51
  PARAM_ENTRY( 254,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_PWRONLVL,    ///< 52
  PARAM_ENTRY( 254,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SYSFLVL,     ///< 53
  PARAM_ENTRY(   0,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_MINLVL,      ///< 54
  PARAM_ENTRY( 254,   0, 254, OFF ),   // PARAMSEL_ENUM_OPS_MAXLVL,      ///< 55
  PARAM_ENTRY(   0,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_LREQVAL,     ///< 56
  PARAM_ENTRY(   7,   1,  15, OFF ),   // PARAMSEL_ENUM_OPS_FADERATE,    ///< 57
  PARAM_ENTRY(   0,   0,  15, OFF ),   // PARAMSEL_ENUM_OPS_FADETIME,    ///< 58
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_RANADRH,     ///< 59
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_RANADRM,     ///< 60
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_RANADRL,     ///< 61
  PARAM_ENTRY(   0,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_GRP0007,     ///< 62
  PARAM_ENTRY(   0,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_GRP0815,     ///< 63
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE00,     ///< 64
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE01,     ///< 65
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE02,     ///< 66
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE03,     ///< 67
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE04,     ///< 68
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE05,     ///< 69
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE06,     ///< 70
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE07,     ///< 71
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE08,     ///< 72
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE09,     ///< 73
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE10,     ///< 74
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE11,     ///< 75
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE12,     ///< 76
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE13,     ///< 77
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE14,     ///< 78
  PARAM_ENTRY( 255,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_SCENE15,     ///< 79
  PARAM_ENTRY( 128,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_FAILSTS,     ///< 80
  PARAM_ENTRY(   1,   0, 255, OFF ),   // PARAMSEL_ENUM_OPS_OPMODE,      ///< 81
  PARAM_ENTRY(   7,   1,  15, OFF ),   // PARAMSEL_ENUM_OPS_FFADETIM,    ///< 82
};

/******************************************************************************
 * @function ParameterManager_GetVerMajor
 *
 * @brief get the software version major
 *
 * This function will return the software version major
 *
 * @return        version major
 *
 *****************************************************************************/
U8 ParameterManager_GetVerMajor( void )
{
  U8  nValue = 0;
  
  #if ( SYSTEMDEFINE_OS_SELECTION != SYSTEMDEFINE_OS_MINIMAL )
    #if ( PARAM_ENABLE_CONFIGVER == ON )
      nValue = PARAM_CONFIG_VERMAJ;
    #else
      nValue = ManufInfo_GetSfwMajor( );
    #endif //PARAM_ENABLE_CONFIGVER
  #endif // SYSTEMDEFINE_OS_SELECTION
  
  // return the software major
  return( nValue );
}

/******************************************************************************
 * @function ParameterManager_GetVerMajor
 *
 * @brief get the software version major
 *
 * This function will return the software version major
 *
 * @return        version major
 *
 *****************************************************************************/
U8  ParameterManager_GetVerMinor( void )
{
  U8  nValue = 0;
  
  #if ( SYSTEMDEFINE_OS_SELECTION != SYSTEMDEFINE_OS_MINIMAL )
    #if ( PARAM_ENABLE_CONFIGVER == ON )
      nValue = PARAM_CONFIG_VERMIN;
    #else
      nValue = ManufInfo_GetSfwMinor( );
    #endif //PARAM_ENABLE_CONFIGVER
  #endif // SYSTEMDEFINE_OS_SELECTION
  
  // return the software major
  return( nValue );
}

/******************************************************************************
 * @function ParameterManager_RdByte
 *
 * @brief read a byte from the eeprom
 *
 * This function will read a byte from the EEPROM
 *
 * @param[in]   wAddress    address to read from
 * @param[in]   pnData      data to read to
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_RdByte( U16 wAddress, PU8 pnData )
{
  BOOL  bStatus = TRUE;

  // read and set status
  bStatus = ( EepromHandler_RdByte( wAddress, pnData ) != EEPROM_ERR_NONE );
  
  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_RdWord
 *
 * @brief read a word from the EEPROM
 *
 * This function will read a word from the EEPROM
 *
 * @param[in]   wAddress    address to read from
 * @param[in]   pwData      data to read to
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_RdWord( U16 wAddress, PU16 pwData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_RdWord( wAddress, pwData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_RdLong
 *
 * @brief read a long from the EEPROM
 *
 * This function will read a long from the EEPROM
 *
 * @param[in]   wAddress    address to read from
 * @param[in]   puData      data to read to
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_RdLong( U16 wAddress, PU32 puData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_RdLong( wAddress, puData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_RdBlock
 *
 * @brief read a block of data from the eeprom
 *
 * This function will read a block of data from the eeprom
 *
 * @param[in]   wAddress    address to read from
 * @param[in]   wLength     length to read
 * @param[i0]   pnData      pointer to the data storage
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_RdBlock( U16 wAddress, U16 wLength, PU8 pnData )
{
  BOOL  bStatus = TRUE;

    // read and set status
  bStatus = ( EepromHandler_RdBlock( wAddress, wLength, pnData ) != EEPROM_ERR_NONE );
  
  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_WrByte
 *
 * @brief write a byte to the eeprom
 *
 * This function will write a byte to the eeprom
 *
 * @param[in]   wAddress    address to write to
 * @param[in]   nData       data to write
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_WrByte( U16 wAddress, U8 nData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_WrByte( wAddress, nData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_WrWord
 *
 * @brief write a word to the EEPROM
 *
 * This function will write a word to the EEPROM
 *
 * @param[in]   wAddress    address to write to
 * @param[in]   wData       data to write
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_WrWord( U16 wAddress, U16 wData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_WrWord( wAddress, wData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_WrLong
 *
 * @brief write a long to the EEPROM
 *
 * This function will write a long value to the EEPROM
 *
 * @param[in]   wAddress    address to write to
 * @param[in]   uData       data to write
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_WrLong( U16 wAddress, U32 uData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_WrLong( wAddress, uData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

/******************************************************************************
 * @function ParamaterManager_WrBlock
 *
 * @brief write a block to the EEPROM
 *
 * This function will write a block of data to the EEPROM
 *
 * @param[in]   wAddress    address to write to
 * @param[in]   wLength     length of the data to write
 * @param[in]   uData       data to write
 *
 * @return        TRUE if errors detected, FALSE otherwise
 *
 *****************************************************************************/
BOOL ParameterManager_WrBlock( U16 wAddress, U16 wLength, PU8 pnData )
{
  BOOL  bStatus = TRUE;
  
  // read and set status
  bStatus = ( EepromHandler_WrBlock( wAddress, wLength, pnData ) != EEPROM_ERR_NONE );

  // return status
  return( bStatus );
}

#if ( PARAM_ENABLE_NOTIFICATIONS == ON )
  /******************************************************************************
   * @function ParamaterManager_PostDone
   *
   * @brief post done
   *
   * This function will post a done or call the callback
   *
   * @param[in]   bErrDet     True if errors found
   *
   *****************************************************************************/
  void Parametermanager_PostDone( BOOL bErrDet )
  {
   // check for type
   #if ( PARAM_ENABLE_CALLBACKS == ON )
   {
    PARAM_DONE_CALLBACK( bErrDet );
   }
   #else
    // post the event 
    TaskManager_PostEvent( PARAM_NOTIFICATION_TASK, ( bErrDet ) ? PARAM_ERROR_EVENT : PARAM_DONE_EVENT );
   #endif
  }
#endif	// PARAM_ENABLE_NOTIFICATIONS

/**@} EOF ParamaterManager_cfg.c */
