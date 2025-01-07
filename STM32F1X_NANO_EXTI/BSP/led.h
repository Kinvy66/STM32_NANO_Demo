/**
* @file led.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7
* @description:
**/
#include "stm32f1xx_hal.h"

#ifndef STM32F1X_NANO_LED_LED_H
#define STM32F1X_NANO_LED_LED_H

#define LED0_Pin            GPIO_PIN_0
#define LED0_GPIO_Port      GPIOC
#define LED1_Pin            GPIO_PIN_1
#define LED1_GPIO_Port      GPIOC
#define LED2_Pin            GPIO_PIN_2
#define LED2_GPIO_Port      GPIOC
#define LED3_Pin            GPIO_PIN_3
#define LED3_GPIO_Port      GPIOC

void ledInit();

void ledBlink(int delay);

#endif //STM32F1X_NANO_LED_LED_H
