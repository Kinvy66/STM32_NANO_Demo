/**
* @file led.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2024/12/28 
* @description: 
**/

#ifndef STM32F1X_NANO_TEMPLATE_LED_H
#define STM32F1X_NANO_TEMPLATE_LED_H

#include "stm32f1xx_hal.h"

#define LED_GPIO_Port   GPIOC
#define LED_0_Pin       GPIO_PIN_0
#define LED_1_Pin       GPIO_PIN_1
#define LED_2_Pin       GPIO_PIN_2
#define LED_3_Pin       GPIO_PIN_3
#define LED_4_Pin       GPIO_PIN_4
#define LED_5_Pin       GPIO_PIN_5
#define LED_6_Pin       GPIO_PIN_6
#define LED_7_Pin       GPIO_PIN_7

/// LED 初始化
void LED_Init();

/// LED 闪烁
void LED_Blink(int ms);

#endif //STM32F1X_NANO_TEMPLATE_LED_H
