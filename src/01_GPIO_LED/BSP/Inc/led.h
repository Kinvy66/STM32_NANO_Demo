/**
* @file led.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 
* @description: 
**/

#ifndef __LED_H
#define __LED_H

#include "main.h"

#define LED1_ON()       HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED1_OFF()      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED2_ON()       HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET)
#define LED2_OFF()      HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET)
#define LED1_TOGGLE     HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)
#define LED2_TOGGLE     HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin)



#endif //__LED_H
