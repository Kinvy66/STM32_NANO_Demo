/**
* @file exti.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 
* @description: 
**/
#ifndef STM32F1X_NANO_EXTI_EXTI_H
#define STM32F1X_NANO_EXTI_EXTI_H

#include "stm32f1xx_hal.h"
#include "key.h"
#define KEY_UP_EXTI_IRQn    EXTI0_IRQn
#define KEY0_EXTI_IRQn      EXTI9_5_IRQn
#define KEY1_EXTI_IRQn      EXTI9_5_IRQn
#define KEY2_EXTI_IRQn      EXTI2_IRQn


void extiInit();

#endif //STM32F1X_NANO_EXTI_EXTI_H
