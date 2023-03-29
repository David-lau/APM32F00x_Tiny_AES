/*!
 * @file        Board_APM32F003_MINI.c
 *
 * @brief       This file provides firmware functions to manage Leds and key buttons
 *
 * @version     V1.0.1
 *
 * @date        2022-04-11
 *
 * @attention
 *
 *  Copyright (C) 2018-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */
#include "Board_APM32F003_MINI.h"
#include "apm32f00x_gpio.h"
#include "apm32f00x_eint.h"

/**
 * @brief   GPIO Structure
 */
typedef struct
{
    GPIO_T *port;
    GPIO_PIN_T pin;
} BOARD_GPIO_T;

/** LED GPIO Port and pin table */
const BOARD_GPIO_T g_ledGPIO[] =
{
    {BOARD_LED2_GPIO_PORT, BOARD_LED2_GPIO_PIN},
    {BOARD_LED3_GPIO_PORT, BOARD_LED3_GPIO_PIN},
} ;

/** Key button GPIO port and pin table */
const BOARD_GPIO_T g_keyGPIO[] =
{
    {BOARD_KEY1_GPIO_PORT,BOARD_KEY1_GPIO_PIN}
} ;

/*!
 * @brief       Led initialization
 *
 * @param       led:    Specifies the Led to be initialized
 *                      This parameter can be one of following parameters
 *                      @arg LED2
 *                      @arg LED3
 *
 * @retval      None
 *
 * @note
 */
void Board_LedInit(BOARD_LED_T led)
{
    GPIO_Config_T gpioConfig;

    gpioConfig.mode = GPIO_MODE_OUT_OD;
    gpioConfig.speed = GPIO_SPEED_10MHz;
    gpioConfig.pin = g_ledGPIO[led].pin;

    GPIO_Config(g_ledGPIO[led].port, &gpioConfig);
}

/*!
 * @brief       Turns the specified led on
 *
 * @param       led:    Specifies the Led to be set on
 *
 * @retval      None
 *
 * @note
 */
void Board_LedOn(BOARD_LED_T led)
{
    GPIO_ClearBit(g_ledGPIO[led].port, g_ledGPIO[led].pin);
}

/*!
 * @brief       Turns the specified led off
 *
 * @param       led:    Specifies the Led to be set off
 *
 * @retval      None
 *
 * @note
 */
void Board_LedOff(BOARD_LED_T led)
{
    GPIO_SetBit(g_ledGPIO[led].port, g_ledGPIO[led].pin);
}

/*!
 * @brief       Toggles the specified LED
 *
 * @param       led:    Specifies the Led to be toggled
 *
 * @retval      None
 *
 * @note
 */
void Board_LedToggle(BOARD_LED_T led)
{
    GPIO_Toggle(g_ledGPIO[led].port, g_ledGPIO[led].pin);
}

/*!
 * @brief       Key GPIO and EINT configuration
 *
 * @param       key:        Specifies the Key button to be configured
 *
 * @param       intEnable:  Enable or Disable external interrupt.
 *                          It can be ENABLE or DISABLE.
 *
 * @retval      None
 *
 * @note
 */
void Board_KeyInit(BOARD_KEY_T key, uint8_t intEnable)
{
    GPIO_Config_T gpioConfig;
    EINT_PORT_T eintPortTab[] = {EINT_PORT_D};

    gpioConfig.mode = GPIO_MODE_IN_PU;
    gpioConfig.pin = g_keyGPIO[key].pin;
    gpioConfig.intEn = GPIO_EINT_DISABLE;

    if(intEnable)
    {
        gpioConfig.intEn = GPIO_EINT_ENABLE;
        EINT_Config(eintPortTab[key], EINT_TRIGGER_FALLING);
    }

    GPIO_Config(g_keyGPIO[key].port, &gpioConfig);
}

/*!
 * @brief       Read the specified key button state
 *
 * @param       key:    Specifies the Key button to be read
 *
 * @retval      The Key GPIO pin value
 *
 * @note
 */
uint8_t Board_ReadKeyState(BOARD_KEY_T key)
{
    return(GPIO_ReadInputBit(g_keyGPIO[key].port, g_keyGPIO[key].pin));
}
