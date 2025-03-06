/**
* @file led.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/22 
* @description: 
**/

#ifndef __LED_H
#define __LED_H
#include "main.h"

#define LED0_OFF()                 HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET)
#define LED1_OFF()                  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED0_ON()                  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET)
#define LED1_ON()                   HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define  LED0_BLINK(delay)    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin); HAL_Delay(delay)
#define  LED1_BLINK(delay)    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin); HAL_Delay(delay)
#define LED0_TOGGLE()             HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin)
#define LED1_TOGGLE()            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)


#endif //__LED_H
