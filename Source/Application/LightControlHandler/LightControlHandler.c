/******************************************************************************
 * @file LightControlHandler.c
 *
 * @brief light control handler implementation
 *
 * This file provides the implementation for the light control handler
 *
 * @copyright Copyright (c) 2012 Cyber Intergration
 * This document contains proprietary data and information of Cyber Integration 
 * LLC. It is the exclusive property of Cyber Integration, LLC and will not be 
 * disclosed in any form to any party without prior written permission of 
 * Cyber Integration, LLC. This document may not be reproduced or further used 
 * without the prior written permission of Cyber Integration, LLC.
 *
 * Version History
 * ======
 * $Rev: $
 * 
 *
 * \addtogroup LightControlHandler
 * @{
 *****************************************************************************/

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "LightControlHandler/LightControlHandler.h"

// library includes -----------------------------------------------------------
#include "DAC/Dac.h"
#include "SystemControlManager/SystemControlManager.h"

// Macros and Defines ---------------------------------------------------------
/// define the period for the light PWM
#define LEVEL_PWM_PERIOD                        ( 10000 )

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations ----------------------------------------------

// local parameter declarations -----------------------------------------------

// local function prototypes --------------------------------------------------

// constant parameter initializations -----------------------------------------

/******************************************************************************
 * @function LightControlHandler_Initialize
 *
 * @brief initialization
 *
 * This function will perform any needed initialization
 *
 * @return  TRUE if errors, FALSE if none
 *
 *****************************************************************************/
BOOL LightControlHandler_Initialize( void )
{
  // set the period for the pwm
  TIMERIOCTLPARAM tTimerParam;

  // set the period
  tTimerParam.uValue = LEVEL_PWM_PERIOD;
  Timers_Ioctl( TIMER_ENUM_LIGHTPWMOUT, TIMER_IOCTL_SETPERIOD, ( PVOID )&tTimerParam );

  // return false for no errors
  return( FALSE );
}
 
/******************************************************************************
 * @function LightControlHandler_SetLightLevel
 *
 * @brief set the light level
 *
 * This function will set the light level
 *
 * @param[in]   wPercent  percent of light (0-1000)
 *
 *****************************************************************************/
void LightControlHandler_SetLightLevel( U16 wPercent )
{
  TIMERIOCTLPARAM tTimerParam;
  SYSCTRLMGRMODE  eMode;

  // outuput it
  Dac_SetPercentOutput( wPercent );

  // now set the pwm
  tTimerParam.eCmpCapChan = LIGHTHANDLER_PWMCHAN_SELECT;
  tTimerParam.uValue = wPercent;
  Timers_Ioctl( TIMER_ENUM_LIGHTPWMOUT, TIMER_IOCTL_SETCOMPAREPCT,  ( PVOID )&tTimerParam );

  // first check to make sure we ar enot in diagnosticmode
  if (( eMode = SystemControlManager_GetMode()) < SYSCTRLMNGR_LCLMODE_DIAGNOSTICS )
  {
    // determine/set the mode
    eMode = ( 0 != wPercent ) ? SYSCTRLMNGR_LCLMODE_RUN : SYSCTRLMNGR_LCLMODE_IDLE;
    SystemControlManager_SetMode( eMode );
  }
}

/******************************************************************************
 * @function 
 *
 * @brief 
 *
 * This function 
 *
 * @param[in]   
 *
 * @return      
 *
 *****************************************************************************/

/**@} EOF LIghtControlHandler.c */
