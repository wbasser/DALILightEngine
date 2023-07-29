/******************************************************************************
 * @file StatusManager.h
 *
 * @brief Status Manager definitions
 *
 * This file provides all of the definitions for the status manager
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
 * \addtogroup StatusManager
 * @{
 *****************************************************************************/

// ensure only one instantiation
#ifndef _STATUSMANAGER_H
#define _STATUSMANAGER_H

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------

// library includes -----------------------------------------------------------
#include "TaskManager/TaskManager.h"

// Macros and Defines ---------------------------------------------------------
/// define the number of events
#define STATUSMANAGER_NUM_EVENTS                ( 2 )

/// define the execution rate
#define STATUSMANAGER_EXEC_RATE_MSECS           ( 50 )
#define STATUSMANAGER_EXEC_RATE_COUNTS          ( TASK_TIME_MSECS( STATUSMANAGER_EXEC_RATE_MSECS ))

// enumerations ---------------------------------------------------------------
/// enumerate the led actions
typedef enum _STSMNGRLEDACT
{
  STSMNGR_LEDACT_OFF = 0,
  STSMNGR_LEDACT_ON,
  STSMNGR_LEDACT_FLSHSLOW,
  STSMNGR_LEDACT_FLSHFAST,
} STSMNGRLEDACT;

/// enumerate the leds
typedef enum _STSMNGRLEDSEL
{
  STSMNGR_LEDSEL_STS = 0,
  STSMNGR_LEDSEL_CFG,
  STSMNGR_LEDSEL_MAX
} STSMNGRLEDSEL;

// structures -----------------------------------------------------------------

// global parameter declarations -----------------------------------------------

// global function prototypes --------------------------------------------------
extern  BOOL  StatusManager_Initialize( void );
extern  BOOL  StatusManager_ProcessEvent( TASKARG xArg );

/**@} EOF StatusManager.h */

#endif  // _STATUSMANAGER_H
