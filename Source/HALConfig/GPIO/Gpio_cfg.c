/******************************************************************************
 * @file GPIO_cfg.c
 *
 * @brief GPIO configuraiton implementation
 *
 * This file pvoides the GPIO configuration implementation
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
 * \addtogroup GPIO
 * @{
 *****************************************************************************/

// local includes -------------------------------------------------------------
#include "GPIO/Gpio_cfg.h"

// constant parameter initializations -----------------------------------------
const CODE GPIOPINDEF g_atGpioPinDefs[ GPIO_PIN_ENUM_MAX ] = 
{
  // declare the pins using one of the helper macros below
  // GPIOPINDEF( port, pin, mode, hidrive, invert, init )
  #if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
    GPIOPINDEF( GPIO_PORT_A,  5, GPIO_MODE_OUTPUT_INPDSB, ON,  ON,  OFF ),  // GPIO_PIN_ENUM_DALITX
    GPIOPINDEF( GPIO_PORT_A,  0, GPIO_MODE_OUTPUT_INPDSB, ON,  ON,  OFF ),  // GPIO_PIN_ENUM_STSLED
    GPIOPINDEF( GPIO_PORT_A,  1, GPIO_MODE_OUTPUT_INPDSB, ON,  ON,  OFF ),  // GPIO_PIN_ENUM_CFGLED
    GPIOPINDEF( GPIO_PORT_A, 15, GPIO_MODE_OUTPUT_INPDSB, OFF, OFF, OFF ),  // GPIO_PIN_ENUM_USRGPIO0
    GPIOPINDEF( GPIO_PORT_A, 14, GPIO_MODE_INPUT_PULLUP,  OFF, OFF, OFF ),  // GPIO_PIN_ENUM_USRGPIO1
  #else
    GPIOPINDEF( GPIO_PORT_B,  9, GPIO_MODE_OUTPUT_INPDSB, ON,  OFF, OFF ),  // GPIO_PIN_ENUM_DALITX
    GPIOPINDEF( GPIO_PORT_A, 27, GPIO_MODE_OUTPUT_INPDSB, ON,  ON,  OFF ),  // GPIO_PIN_ENUM_STSLED
    GPIOPINDEF( GPIO_PORT_A, 28, GPIO_MODE_OUTPUT_INPDSB, ON,  ON,  OFF ),  // GPIO_PIN_ENUM_CFGLED
    GPIOPINDEF( GPIO_PORT_A,  4, GPIO_MODE_OUTPUT_INPDSB, OFF, OFF, OFF ),  // GPIO_PIN_ENUM_USRGPIO0
    GPIOPINDEF( GPIO_PORT_A,  5, GPIO_MODE_INPUT_PULLUP,  OFF, OFF, OFF ),  // GPIO_PIN_ENUM_USRGPIO1
    GPIOPINDEF( GPIO_PORT_A,  8, GPIO_MODE_OUTPUT_INPDSB, OFF, OFF, OFF ),  // GPIO_PIN_ENUM_DEBUG
  #endif
};

const CODE GPIOFNCDEF g_atGpioFncDefs[ GPIO_FNC_ENUM_MAX ] =
{
  // declare the pins using one of the helper macros below
  // GPIOFNCDEF( port, pin, func, allowinp, pullenb )
  GPIOFNCDEF( GPIO_PORT_A, 24, GPIO_FUNCMUX_G, ON,  OFF ),                // GPIO_FNC_ENUM_USBDPM
  GPIOFNCDEF( GPIO_PORT_A, 25, GPIO_FUNCMUX_G, ON,  OFF ),                // GPIO_FNC_ENUM_USBDPP
  GPIOFNCDEF( GPIO_PORT_A,  2, GPIO_FUNCMUX_B, OFF, OFF ),                // GPIO_FNC_ENUM_LVLOUT

  // options based on platform
  #if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
    GPIOFNCDEF( GPIO_PORT_A,  8, GPIO_FUNCMUX_C, OFF, ON  ),                // GPIO_FNC_ENUM_I2CSDA
    GPIOFNCDEF( GPIO_PORT_A,  9, GPIO_FUNCMUX_C, OFF, OFF ),                // GPIO_FNC_ENUM_I2CSCL
    GPIOFNCDEF( GPIO_PORT_A, 22, GPIO_FUNCMUX_E, OFF, OFF ),                // GPIO_FNC_ENUM_LVLPWM
  #else
    GPIOFNCDEF( GPIO_PORT_A, 16, GPIO_FUNCMUX_C, OFF, ON  ),                // GPIO_FNC_ENUM_I2CSDA
    GPIOFNCDEF( GPIO_PORT_A, 17, GPIO_FUNCMUX_C, OFF, OFF ),                // GPIO_FNC_ENUM_I2CSCL
    GPIOFNCDEF( GPIO_PORT_A, 19, GPIO_FUNCMUX_E, OFF, OFF ),                // GPIO_FNC_ENUM_LVLPWM
  #endif
};

const CODE GPIOIRQDEF g_atGpioIrqDefs[ GPIO_IRQ_ENUM_MAX ] =
{
  // declare the pins using one of the helper macros below
  // GPIOIRQDEF( port, pin, pupdn, sense, wakeup, filter, callback, event, initon )
  // GPIOEVNDEF( port, pin, pupdn, sense, wakeup, filter )
  #if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
    GPIOEVNDEF( GPIO_PORT_A, 28, GPIO_IRQPUPDN_PULLUP, GPIO_SENSE_BOTH, OFF, ON ),                // GPIO_IRQ_ENUM_DALIRX
  #else
    GPIOEVNDEF( GPIO_PORT_A,  9, GPIO_IRQPUPDN_PULLUP, GPIO_SENSE_BOTH, OFF, ON ),                // GPIO_IRQ_ENUM_DALIRX
  #endif
};

/**@} EOF GPIO_cfg.c */
  #if ( SYSTEMDEFINE_PLATFORM_SELECTED == SYSTEMDEFINE_PLATFORM_PROD )
  #else
  #endif
