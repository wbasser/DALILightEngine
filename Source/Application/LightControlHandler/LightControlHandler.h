/******************************************************************************
 * @file LightControlHandler.h
 *
 * @brief light control handler
 *
 * This file provides the defintions for the light control handler
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
 
// ensure only one instantiation
#ifndef _LIGHTCONTROLHANDLER_H
#define _LIGHTCONTROLHANDLER_H

// system includes ------------------------------------------------------------
#include "Timers/Timers.h"
#include "Types/Types.h"

// local includes -------------------------------------------------------------

// library includes -----------------------------------------------------------

// Macros and Defines ---------------------------------------------------------
/// define the timer channel for the PWM out
#define LIGHTHANDLER_PWMTIMER_SELECT            ( TIMER_CHAN_3 )
#define LIGHTHANDLER_PWMCHAN_SELECT             ( TIMER_CMPCAP_CHAN_1 )

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations -----------------------------------------------

// global function prototypes --------------------------------------------------
extern  BOOL  LightControlHandler_Initialize( void );
extern  void  LightControlHandler_SetLightLevel( U16 wPercent );

/**@} EOF LightControlHandler.h */

#endif  // _LIGHTCONTROLHANDLER_H