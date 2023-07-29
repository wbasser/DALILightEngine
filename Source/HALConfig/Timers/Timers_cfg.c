/******************************************************************************
 * @file Timers_cfg.c
 *
 * @brief timers configuration implementation
 *
 * This file provides the configuration table for the timers
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
 * \addtogroup Timers
 * @{
 *****************************************************************************/

// library includes -----------------------------------------------------------

// local includes -------------------------------------------------------------
#include "Timers/Timers_cfg.h"

// library includes -----------------------------------------------------------
#include "LightControlHandler/LightControlHandler.h"
#include "ManchesterCodec/ManchesterCodec.h"

// Macros and Defines ---------------------------------------------------------
// constant parameter initializations -----------------------------------------
const TIMERDEF  g_atTimerDefs[ TIMER_ENUM_MAX ] =
{
  // using the below macro add timers to the definition table
  // TIMER_TCCPWMSINGUS( chan, prescale, initon, standby, oneshot, period, cc0pct, cc1pct, cc2pct, cc3pct, cc0enb, cc1enb, cc2enb, cc3enb, callback )
  // TIMER_TCCPWMSINGHZ( chan, prescale, initon, standby, oneshot, period, cc0pct, cc1pct, cc2pct, cc3pct, cc0enb, cc1enb, cc2enb, cc3enb, callback )
  // TIMER_TCCPWMDUALBOT( chan, prescale, initon, standby, oneshot, period, cc0pct, cc1pct, cc2pct, cc3pct, cc0enb, cc1enb, cc2enb, cc3enb, callback )
  // TIMER_TCCCAPDEF( chan, prescale, initon, standby, ovfirqenable, resettozero, invertedge, callback )
  // TIMER_TCWAVMFDEF( chan, invert, oneshot, initon, standby, outenable, ovfenable, matchirqenable, ovfirqenable, direction, prescale, ratehz, priority, callback )
  // TIMER_TCCAPDEF( chan, prescale, initon, standby, ovfirqenable, resettozero, invertedge, callback )
  // TIMER_TCCAPPWPDEF( chan, prescale, initon, standby, cc0enb, cc1enb, ovfirqenable, resettozero, invertedge, callback )
  // TIMER_TCCAPPPWDEF( chan, prescale, initon, standby, cc0enb, cc1enb, ovfirqenable, resettozero, invertedge, callback )
  // TIMER_TCMPWMFDEF( chan, invert0, invert1, initon, standby, ovfenable, matchirqenable0, matchirqenable1, ovfirqenable, direction, prescale, priority, callback )
  // TIMER_TCCOUNTDEF( chan, invert, initon, standby, outenable, ovfenable, ovfirqenable, direction, callback )
  TIMER_TCWAVMFDEF( MANCHESTERCODEC_TXTIMER_SELECT, FALSE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE, TIMER_DIRECTION_UP, TIMER_PRESCALE_1, MANCHESTERCODEC_HALFBIT_FREQ, ON, ManchesterCodec_TransmitCallback ),
  TIMER_TCCAPDEF( MANCHESTERCODEC_RXTIMER_SELECT, TIMER_PRESCALE_1, TRUE, FALSE, FALSE, TRUE, FALSE, ManchesterCodec_ReceiveCallback ),
  TIMER_TCMPWMFDEF( LIGHTHANDLER_PWMTIMER_SELECT, OFF, OFF, ON, OFF, OFF, OFF, OFF, OFF, TIMER_DIRECTION_UP, TIMER_PRESCALE_1, OFF, NULL ),
};
 
/**@} EOF Timers_cfg.c */
