/*!
 * @file        Board_APM32F003_MINI.h
 *
 * @brief       This file contains definitions for APM32F003_MINIBOARD's Leds, push-buttons hardware resources
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

#ifndef BOARD_APM32F003_MINI_H
#define BOARD_APM32F003_MINI_H

#include "apm32f00x.h"

#define BOARD_LED2_GPIO_PORT            GPIOB
#define BOARD_LED2_GPIO_PIN             GPIO_PIN_5

#define BOARD_LED3_GPIO_PORT            GPIOB
#define BOARD_LED3_GPIO_PIN             GPIO_PIN_4

#define BOARD_KEY1_GPIO_PORT            GPIOD
#define BOARD_KEY1_GPIO_PIN             GPIO_PIN_6

/**
 * @brief   Led number definition
 */
typedef enum
{
    BOARD_LED2,
    BOARD_LED3
}BOARD_LED_T;

/**
 * @brief   Key button number definition
 */
typedef enum
{
    BOARD_KEY1
}BOARD_KEY_T;

/** LED */
void Board_LedInit(BOARD_LED_T led);
void Board_LedOn(BOARD_LED_T led);
void Board_LedOff(BOARD_LED_T led);
void Board_LedToggle(BOARD_LED_T led);

/** Key button */
void Board_KeyInit(BOARD_KEY_T key, uint8_t intEnable);
uint8_t Board_ReadKeyState(BOARD_KEY_T key);
#endif
