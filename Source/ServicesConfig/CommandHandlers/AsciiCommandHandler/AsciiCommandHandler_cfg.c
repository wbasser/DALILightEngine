/******************************************************************************
 * @file AsciiCommandHandler_cfg.c
 *
 * @brief 
 *
 * This file 
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
 * \addtogroup AsciiCommandHandler
 * @{
 *****************************************************************************/

// local includes -------------------------------------------------------------
#include "AsciiCommandHandler/AsciiCommandHandler.h"

// library includes ----------------------------------------------------------
#include "DbgAscCommandHandler/DbgAscCommandHandler.h"

// local parameter declarations -----------------------------------------------
/// declare the buffers here using the below macro
// ASCCMD_BUFFER( name, bufsize, numargs )
ASCCMD_BUFFER( DbgCmd, DBGASCCOMMANDHANDLER_NUM_EVENTS, DBGASCCOMMANDHANDLER_NUM_ARGS );

// local constant parameter initializations -----------------------------------------

// global constant parameter initializations -----------------------------------------
const CODE  ASCCMDDEF   g_atAscCmdDefs[ ASCCMD_ENUM_MAX ] =
{
  // add entries to this table using the below macro
  // ASCCMD_DEF( bufsize, numargs, name, enbecho, prompt, eolchar, writefunc, delims, cmdtbl )
  ASCCMD_DEF( DBGASCCOMMANDHANDLER_NUM_EVENTS, DBGASCCOMMANDHANDLER_NUM_ARGS, DbgCmd, ON, DBGASCCOMMANDHANDLER_PROMPT_CHAR, DBGASCCOMMANDHANDLER_EOL_CHAR, DbgAscCommandHandler_Write, g_szDbgAscCommandHandlerDelims, g_atDbgAscCommandHandlerTable ),
};

/**@} EOF AsciiCommandHandler_cfg.c */