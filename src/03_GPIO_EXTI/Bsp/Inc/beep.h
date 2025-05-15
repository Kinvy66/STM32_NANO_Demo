/**
* @file beep.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/22 
* @description: 
**/

#ifndef __BEEP_H
#define __BEEP_H
#include "main.h"

#define BEEP_ON()     HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET)
#define BEEP_OFF()    HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET)


#endif //__BEEP_H
