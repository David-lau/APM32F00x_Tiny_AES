/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
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

&par Example Description

This example provides a basic communication between USART1 and USART2 using interrupts.

&par Hardware Description

J2 and J3 Should be shorted.
using LED2(PB5).
using LED3(PB4).
USART1 TX(PD5) -> USART2 RX(PD2)
USART1 RX(PD6) -> USART2 TX(PD3)

&par Software Description

After Initialization, USART2 will send some data to USART1 using interrupts.

&par Directory contents

  - USART/USART_Interrupt/Source/apm32f0xx_int.c     Interrupt handlers
  - USART/USART_Interrupt/Source/main.c                   Main program

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V9.20.2.43979

&par Hardware and Software environment

  - This example runs on APM32F003 MINI Devices.
