/******************************************************************************
 * @file Event_cfg.c
 *
 * @brief Event generator configuration implementation
 *
 * This file provides the implementation for the event configuration
 *
 * @copyright Copyright (c) 2012 CyberIntegration
 * This document contains proprietary data and information of CyberIntegration 
 * LLC. It is the exclusive property of CyberIntegration, LLC and will not be 
 * disclosed in any form to any party without prior written permission of 
 * CyberIntegration, LLC. This document may not be reproduced or further used 
 * without the prior written permission of CyberIntegration, LLC.
 *
 * $Date: $
 *
 * Version History
 * ======
 * $Rev: $
 * 
 *
 * \addtogroup Event
 * @{
 *****************************************************************************/

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "Event\Event_cfg.h"

// library includes -----------------------------------------------------------

// Macros and Defines ---------------------------------------------------------

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations ----------------------------------------------
const EVENTDEF g_atEventDefs[ EVENT_ENUM_MAX ] =
{
  // create events here using the below macro
  // EVENTDEF( chan, eventgen, user, edge )
  #if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
    EVENTDEF( EVENT_CHAN_0, EVENT_GEN_EXT_INT8, EVENT_USERMUX_TC4, EVENT_EDGE_NONE ),
  #else
    EVENTDEF( EVENT_CHAN_0, EVENT_GEN_EXT_INT9, EVENT_USERMUX_TC4, EVENT_EDGE_NONE ),
  #endif
};
 
/**@} EOF Event_cfg.c */
