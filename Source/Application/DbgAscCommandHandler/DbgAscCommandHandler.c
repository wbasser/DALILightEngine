/******************************************************************************
 * @file DbgAscCommandHandler.c
 *
 * @brief  Debug Ascii Command Handler
 *
 * This file provides the implementation for the debug ascii commands
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
 * $Log: $
 * 
 *
 * \addtogroup DbgAscCommandHandler
 * @{
 *****************************************************************************/

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "DbgAscCommandHandler/DbgAscCommandHandler.h"

// library includes -----------------------------------------------------------
#include "AscCommonCommands/AscCommonCommands.h"
#include "DALIMessageHandler/DALIMessageHandler.h"
#include "LightControlHandler/LightControlHandler.h"
#include "StatusManager/StatusManager.h"
#include "SystemControlManager/SystemControlManager.h"
#include "UsbGenHandler/UsbGenHandler.h"

// Macros and Defines ---------------------------------------------------------

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations ----------------------------------------------

// local parameter declarations -----------------------------------------------
static  PC8   pcBuffer;
static  U8    anRcvBuffer[ USB_MAX_PACKET_SIZE ];

// local function prototypes --------------------------------------------------
static  void  UsbRcvCallback( U16 wCount );
static  void  UsbXmtCallback( U16 wCount );

// local command handlers
static  ASCCMDSTS CmdForceMsg( U8 nCmdEnum );
static  ASCCMDSTS CmdSetLvl( U8 nCmdEnum );

// constant parameter initializations -----------------------------------------
/// declare the delimiters
const C8 g_szDbgAscCommandHandlerDelims[ ] = 
{ 
  " \t\n\r," 
};

/// command constants
static  const C8  szForceMsg[ ]   = { "FORCEMSG" };
static  const C8  szSetLvl[ ]     = { "SETLVL" };

/// string constants
static  const C8  szRspDaliMsg[ ] = { "RFMSG: %02X\n\r" };

/// initialize the command table
const CODE ASCCMDENTRY g_atDbgAscCommandHandlerTable[ ] =
{
  // add local command using the below listed macro
  // ASCCMD_ENTRY( cmd, len, args, flg, compare, handler ) 
  ASCCMD_ENTRY( szForceMsg, 8, 2, ASCFLAG_COMPARE_NONE,                               0, CmdForceMsg ),
  ASCCMD_ENTRY( szSetLvl,   6, 1, ASCFLAG_COMPARE_GE,   SYSCTRLMNGR_LCLMODE_DIAGNOSTICS, CmdSetLvl   ),

  // external command
  ASCCMD_EXTTBL( g_atAscCommonCommandsTable ),

  // the entry below must be here
  ASCCMD_ENDTBL( )
};

/******************************************************************************
 * @function DbgAscCommandHandler_Initialize
 *
 * @brief debug commands initilization
 *
 * This function will initialize the debug command handler
 *
 * @return  TRUE if errors, FALSE if none
 *
 *****************************************************************************/
BOOL DbgAscCommandHandler_Initialize( void )
{
  // get a pointer to the buffer
  AsciiCommandHandler_GetBuffer( ASCCMD_ENUM_DBGCMD, &pcBuffer );

  // output a prompt
  AsciiCommandHandler_OutputPrompt( ASCCMD_ENUM_DBGCMD );

  // return no errors
  return( FALSE );
}

/******************************************************************************
 * @function DbgAscCommandHandler_Initialize
 *
 * @brief debug commands initilization
 *
 * This function will initialize the debug command handler
 *
 *****************************************************************************/
void DbgAscCommandHandler_StartReceive( void )
{
  // request a receive packet
  UsbGenHandler_Recv( USB_CDCENDPOINT_RCV, anRcvBuffer, USB_MAX_PACKET_SIZE, UsbRcvCallback );
}

/******************************************************************************
 * @function DbgAscCommandHandler_ProcessChar
 *
 * @brief process a character event
 *
 * This function will process a character event
 *
 * @param[in]     xArg    task argument
 *
 * @retunr    TRUE to flush events
 * 
 *****************************************************************************/
BOOL DbgAscCommandHandler_ProcessChar( TASKARG xArg )
{
  // handle local
  AsciiCommandHandler_ProcessChar( ASCCMD_ENUM_DBGCMD, ( U8 )xArg, SystemControlManager_GetMode( ));

  // return true
  return( TRUE );
}

/******************************************************************************
 * @function DbgAscCommandHandler_PutChar
 *
 * @brief output a character
 *
 * This function will output a character
 *
 * @param[in]    nChar     character to send
 *
 *****************************************************************************/
void  DbgAscCommandHandler_PutChar( U8 nChar )
{
  DbgAscCommandHandler_Write( &nChar, 1 );
}

/******************************************************************************
 * @function DbgAscCommandHandler_Write
 *
 * @brief output a block of characters
 *
 * This function will output a block of characters to the approrpiate device
 *
 * @param[in]     pnData     pointer to the data to send
 * @param[in]     nLength    length of the data
 *
 *****************************************************************************/
void DbgAscCommandHandler_Write( PU8 pnData, U16 wLength )
{
  // check for configured
  if ( UsbGenHandler_IsConfigured( ))
  {
    // send the data
    UsbGenHandler_Send( USB_CDCENDPOINT_XMT, pnData, wLength, UsbXmtCallback );
  }
}

/******************************************************************************
 * @function DbgAscCommandHandler_ResetPrompt
 *
 * @brief resets the user prompt
 *
 * This function will reset the prompt back to its normal state
 *
 *****************************************************************************/
void DbgAscCommandHandler_ResetPrompt( void )
{
  // reset the prompt character
  AsciiCommandHandler_SetPromptCharacter( ASCCMD_ENUM_DBGCMD, 0 );
}

/******************************************************************************
 * @function DbgAscCommandHandler_OutputDaliXmt
 *
 * @brief output the transmit DALI message
 *
 * This function outputs the value
 *
 * @param[in]   nValue    value to output
 *
 *****************************************************************************/
void DbgAscCommandHandler_OutputDaliXmt( U8 nValue )
{
  // print the message
  sprintf( pcBuffer, ( PCC8 )szRspDaliMsg, nValue );

  // output the value
  AsciiCommandHandler_OutputBuffer( ASCCMD_ENUM_DBGCMD );
  AsciiCommandHandler_OutputPrompt( ASCCMD_ENUM_DBGCMD );
}

/******************************************************************************
 * @function UsbRcvCallback 
 *
 * @brief receive callback
 *
 * This function process's the receive callback
 *
 * @param[in]   wCount    number of bytes received
 *
 *****************************************************************************/
static void UsbRcvCallback( U16 wCount )
{
  U16 wIdx;

  // clear the index
  wIdx = 0;

  // for each byte recieved 
  while( wIdx < wCount )
  {
    // process the character
    TaskManager_PostEventIrq( TASK_SCHD_ENUM_DBGCHAR, ( TASKARG )anRcvBuffer[ wIdx++ ] );
  }

  // request a receive packet
  UsbGenHandler_Recv( USB_CDCENDPOINT_RCV, anRcvBuffer, USB_MAX_PACKET_SIZE, UsbRcvCallback );
}

/******************************************************************************
 * @function UsbXmtCallback 
 *
 * @brief transmit callback
 *
 * This function process's the trANSmit callback
 *
 * @param[in]   wCount    number of bytes received
 *
 *****************************************************************************/
static void UsbXmtCallback( U16 wCount )
{
}

/******************************************************************************
 * @function CmdForceMsg
 *
 * @brief force message command handler
 *
 * This function will get the arguments and call the force message command handler
 *
 * @param[in]   nCmdEnum    command enumerator
 *
 * @return    appropriate command response
 *
 *****************************************************************************/
static ASCCMDSTS CmdForceMsg( U8 nCmdEnum )
{
  U32UN tArg;
  U8    nAddress;

  // get the first argument( address )
  AsciiCommandHandler_GetValue( nCmdEnum, 0, &tArg.uValue );
  nAddress = tArg.anValue[ LE_U32_LSB_IDX ];

  // get the second argument (data/command)
  AsciiCommandHandler_GetValue( nCmdEnum, 1, &tArg.uValue );

  // now send it
  DALIMessageHandler_ForceMessage( nAddress, tArg.anValue[ LE_U32_LSB_IDX ] );
}

/******************************************************************************
 * @function CmdSetLvl
 *
 * @brief set light level
 *
 * This function will set the light level
 *
 * @param[in]   nCmdEnum    command enumerator
 *
 * @return    appropriate command response
 *
 *****************************************************************************/
static ASCCMDSTS CmdSetLvl( U8 nCmdEnum )
{
  U32UN tArg;

  // get the first argument( address )
  AsciiCommandHandler_GetValue( nCmdEnum, 0, &tArg.uValue );

  // set the light level
  LightControlHandler_SetLightLevel( tArg.awValue[ 0 ]);
}
/**@} EOF DbgAscCommandHandler.c */