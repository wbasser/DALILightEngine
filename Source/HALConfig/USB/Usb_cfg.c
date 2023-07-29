/******************************************************************************
 * @file Usb_cfg.c
 *
 * @brief USB configuration implementation
 *
 * This file provides the configuration implementation
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
 * \addtogroup Usb_cfg
 * @{
 *****************************************************************************/

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "Usb/Usb_cfg.h"

// library includes -----------------------------------------------------------
#include "UsbGenHandler/UsbGenHandler.h"

// Macros and Defines ---------------------------------------------------------

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations ----------------------------------------------

// local parameter declarations -----------------------------------------------

// local function prototypes --------------------------------------------------

// constant parameter initializations -----------------------------------------

/******************************************************************************
 * @function Usb_HandleStandardRequest
 *
 * @brief handle a standard request
 *
 * This function will call the desired standard request handler
 *
 * @param[in]   pnBuffer    pointer to the data buffer
 *
 *****************************************************************************/
void Usb_HandleStandardRequest( PU8 pnBuffer )
{
  // call the standard request handler
  UsbGenHandler_HandleStandardRequest(( PUSBREQUEST )pnBuffer );
}

/******************************************************************************
 * @function Usb_ProcessRecvCallback
 *
 * @brief process the receive callback
 *
 * This function will process the receive callback
 *
 * @param[in]   nEp   endoint that requires servicing
 *
 *****************************************************************************/
void Usb_ProcessRecvCallback( U8 nEp, U16 wCount )
{
  // based on endoint, call the appropriate handler
  switch( nEp )
  {
    case USB_CDCENDPOINT_CTL :
      break;

    case USB_CDCENDPOINT_RCV :
      UsbGenHandler_RecvCallback( nEp, wCount );
      break;

    default :
      break;
  }
}

/******************************************************************************
 * @function Usb_ProcessSendCallback
 *
 * @brief process the send callback
 *
 * This function will process the send callback
 *
 * @param[in]   nEp   endoint that requires servicing
 *
 *****************************************************************************/
void Usb_ProcessSendCallback( U8 nEp )
{
  // based on endpoint, call the appropriate handler
  switch( nEp )
  {
    case USB_CDCENDPOINT_XMT :
      UsbGenHandler_SendCallback( nEp, 0 );
      break;

    default :
      break;
  }
}

/**@} EOF Usb_cfg.c */
