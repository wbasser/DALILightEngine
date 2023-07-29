/******************************************************************************
 * @file StatusManager
 *
 * @brief status manager implementation
 *
 * This file implements the status manager.  This file is responsible for flashing the status
 * LED at a rate of 500 MSEC.
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

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "StatusManager/StatusManager.h"

// library includes -----------------------------------------------------------
#include "DALIMessageHandler/DALIMessageHandler.h"
#include "GPIO/Gpio.h"

// Macros and Defines ---------------------------------------------------------
/// define the slow/fast time milleseconds
#define SLOW_TIME_MSECS                         ( 500 )
#define FAST_TIME_MSECS                         ( 250 )

/// define the off/on/slow-fast flash
#define OFF_COUNTS                              ( 0 )
#define ON_COUNTS                               ( 0xFF )
#define SLOW_COUNTS                             ( SLOW_TIME_MSECS / STATUSMANAGER_EXEC_RATE_MSECS )
#define FAST_COUNTS                             ( FAST_TIME_MSECS / STATUSMANAGER_EXEC_RATE_MSECS )

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------
typedef struct  _LEDCTL
{
  U8            nCount;
  BOOL          bState;
  STSMNGRLEDACT eAction;
  GPIOPINENUM   eGpioPin;
} LEDCTL, *PLEDCTL;
#define LEDCTL_SIZE                             sizeof( LEDCTL )

// global parameter declarations ----------------------------------------------

// local parameter declarations -----------------------------------------------
static  LEDCTL  atLedCtl[ STSMNGR_LEDSEL_MAX ];

// local function prototypes --------------------------------------------------
static  void  ProcessLed( PLEDCTL ptLedCtl );

// constant parameter initializations -----------------------------------------

/******************************************************************************
 * @function StatusManager_Initialize
 *
 * @brief initialization
 *
 * This function initialized the status manager
 *
 * @return  TRUE if errors, FALSE if none
 *
 *****************************************************************************/
BOOL StatusManager_Initialize( void )
{
  // set the status LED to flash slow
  atLedCtl[ STSMNGR_LEDSEL_STS ].eAction= STSMNGR_LEDACT_FLSHSLOW;
  atLedCtl[ STSMNGR_LEDSEL_STS ].nCount = 1;
  atLedCtl[ STSMNGR_LEDSEL_STS ].bState = OFF;
  atLedCtl[ STSMNGR_LEDSEL_STS ].eGpioPin = GPIO_PIN_ENUM_STSLED;
  Gpio_Set( GPIO_PIN_ENUM_STSLED, OFF );

  // set the DALI led to off
  atLedCtl[ STSMNGR_LEDSEL_CFG ].eAction= STSMNGR_LEDACT_OFF;
  atLedCtl[ STSMNGR_LEDSEL_CFG ].nCount = 1;
  atLedCtl[ STSMNGR_LEDSEL_CFG ].bState = OFF;
  atLedCtl[ STSMNGR_LEDSEL_CFG ].eGpioPin = GPIO_PIN_ENUM_CFGLED;
  Gpio_Set( GPIO_PIN_ENUM_CFGLED, OFF );

  // rturn no errors
  return ( FALSE );
}

/******************************************************************************
 * @function StatusManager_ProcessEvent
 *
 * @brief process the event
 *
 * This function process the event by toggling the status LED
 *
 * @param[in]   xArg    event argument
 *
 * @return      TRUE to flush the event from the event queue
 *
 *****************************************************************************/
BOOL StatusManager_ProcessEvent( TASKARG xArg )
{
  STSMNGRLEDSEL     eLedSel;
  DALIMSGHANDCFGSTS eCfgSts;

  // determine the argument
  switch( xArg )
  {
    case TASK_TIMEOUT_EVENT :
      // update the configuration led
      eCfgSts = DALIMessageHandler_GetConfigStatus( );

      // now set the configuration LED
      switch( eCfgSts )
      {
        case DALIMSGHAND_CFGSTS_INPROGRESS :
          atLedCtl[ STSMNGR_LEDSEL_CFG ].eAction= STSMNGR_LEDACT_FLSHFAST;
          break;

        case DALIMSGHAND_CFGSTS_CONFIGURED :
          atLedCtl[ STSMNGR_LEDSEL_CFG ].eAction= STSMNGR_LEDACT_ON;
          break;

        case DALIMSGHAND_CFGSTS_NOTCFGD :
        default  :
          atLedCtl[ STSMNGR_LEDSEL_CFG ].eAction= STSMNGR_LEDACT_OFF;
          break;
      }

      // process the leds
      for ( eLedSel = STSMNGR_LEDSEL_STS; eLedSel < STSMNGR_LEDSEL_MAX; eLedSel++ )
      {
        // process the led
        ProcessLed( &atLedCtl[ eLedSel ] );
      }
      break;

    default :
      break;
  }

  // return true to flush event
  return( TRUE );
}

/******************************************************************************
 * @function ProcessLed
 *
 * @brief process the led
 *
 * This function process the current LED
 *
 * @param[in]   ptLEdCtl    pointer to the led control
 *
 * @return      TRUE to flush the event from the event queue
 *
 *****************************************************************************/
static void ProcessLed( PLEDCTL ptLedCtl )
{
  BOOL bNewState;

  // decrement the count
  if ( --ptLedCtl->nCount == 0 )
  {
    // update the times
    switch( ptLedCtl->eAction )
    {
      case STSMNGR_LEDACT_ON :
        // reset the count
        ptLedCtl->nCount = 1;
        bNewState = ON;
        break;

      case STSMNGR_LEDACT_FLSHSLOW :
        // toggle state
        ptLedCtl->nCount = SLOW_COUNTS;
        bNewState = ptLedCtl->bState ^ 1;
        break;

      case STSMNGR_LEDACT_FLSHFAST :
        // toggle state
        ptLedCtl->nCount = FAST_COUNTS;
        bNewState = ptLedCtl->bState ^ 1;
        break;

      case STSMNGR_LEDACT_OFF :
      default :
        // reset the count
        ptLedCtl->nCount = 1;
        bNewState = OFF;
        break;
    }

    // now update the GPIO if there is a change
    if ( bNewState ^ ptLedCtl->bState )
    {
      // copy the new state
      ptLedCtl->bState = bNewState;

      // set the GPIO
      Gpio_Set( ptLedCtl->eGpioPin, bNewState );
    }
  }
}

/**@} EOF StatusManager.c */


