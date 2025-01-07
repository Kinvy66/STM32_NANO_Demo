/**
* @file beep.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 
* @description: 
**/
#ifndef STM32F1X_NANO_KEY_BEEP_BEEP_H
#define STM32F1X_NANO_KEY_BEEP_BEEP_H

#include "stm32f1xx_hal.h"

#define BEEP_Pin          GPIO_PIN_8
#define BEEP_GPIO_Port    GPIOB

void beepInit();


#endif //STM32F1X_NANO_KEY_BEEP_BEEP_H
