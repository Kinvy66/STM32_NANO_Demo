/**
* @file key.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 
* @description: 
**/
#include "stm32f1xx_hal.h"

#ifndef STM32F1X_NANO_KEY_BEEP_KEY_H
#define STM32F1X_NANO_KEY_BEEP_KEY_H


#define KEY_UP_Pin GPIO_PIN_0
#define KEY_UP_GPIO_Port GPIOA
#define KEY0_Pin GPIO_PIN_8
#define KEY0_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_2
#define KEY2_GPIO_Port GPIOD

#define KEY0        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)  //KEY0按键PC8
#define KEY1        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  //KEY1按键PC9
#define KEY2        HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)  //KEY2按键PD2
#define WK_UP       HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)  //WKUP按键PA0

#define KEY0_PRES	1	//KEY0
#define KEY1_PRES	2	//KEY1
#define KEY2_PRES	3	//KEY2
#define WKUP_PRES	4	//WK_UP


void keyInit();
uint8_t keyScan(uint8_t mode);

#endif //STM32F1X_NANO_KEY_BEEP_KEY_H
