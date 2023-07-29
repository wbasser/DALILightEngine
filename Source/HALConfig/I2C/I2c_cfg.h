/******************************************************************************
 * @file I2C_cfg.h
 *
 * @brief I2C configuration declarations
 *
 * This file contains the I2C configuration declarations
 *
 * @copyright Copyright (c) 2014 CyberIntegration
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
 * \addtogroup I2C
 * @{
 *****************************************************************************/
 
// ensure only one instatiation
#ifndef _I2C_CFG_H
#define _I2C_CFG_H

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "I2C/I2c_def.h"

// library includes -----------------------------------------------------------

// Macros and Defines ---------------------------------------------------------
/// set these to one when selecting a channel to use
#if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
  #define I2C_CHAN0_IN_USE      ( ON  )
  #define I2C_CHAN1_IN_USE      ( OFF )
  #define I2C_CHAN2_IN_USE      ( OFF )
  #define I2C_CHAN3_IN_USE      ( OFF )
  #define I2C_CHAN4_IN_USE      ( OFF )
  #define I2C_CHAN5_IN_USE      ( OFF )
#else
  #define I2C_CHAN0_IN_USE      ( OFF )
  #define I2C_CHAN1_IN_USE      ( ON  )
  #define I2C_CHAN2_IN_USE      ( OFF )
  #define I2C_CHAN3_IN_USE      ( OFF )
  #define I2C_CHAN4_IN_USE      ( OFF )
  #define I2C_CHAN5_IN_USE      ( OFF )
#endif

// enumerations ---------------------------------------------------------------
/// declare the I2C enuemrations
typedef enum  _I2CDEVENUM
{
  // add enuemrations below
  I2C_DEV_ENUM_LCLBUS = 0,
 
  // do not remove the below items
  I2C_DEV_ENUM_MAX,
  I2C_DEV_ENUM_ILLEGAL
} I2CDEVENUM;

// global parameter declarations -----------------------------------------------

// global function prototypes --------------------------------------------------
extern  const I2CDEF g_atI2cDefs[ ];

/**@} EOF I2c_cfg.h */

#endif  // _I2C_CFG_H
