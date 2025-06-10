/**
* @file key.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 
* @description: 
**/

#ifndef __KEY_H
#define __KEY_H
#include "main.h"

#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)  //KEY0按键PC8
#define KEY2        HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)  //KEY1按键PC9
#define KEY3        HAL_GPIO_ReadPin(KEY3_GPIO_Port,KEY3_Pin)  //KEY2按键PD2
#define WK_UP       HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)  //WKUP按键PA0

#define KEY1_PRES	1	//KEY0
#define KEY2_PRES	2	//KEY1
#define KEY3_PRES	3	//KEY2
#define WKUP_PRES	4	//WK_UP

uint8_t key_scan(uint8_t mode);

#endif //__KEY_H
