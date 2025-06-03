/**
* @file key.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/22 
* @description: 
**/
#ifndef __KEY_KEY_H
#define __KEY_KEY_H
#include "main.h"

#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)  //KEY0按键PC8
#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)  //KEY1按键PC9
#define KEY2        HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)  //KEY2按键PD2
#define WK_UP       HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)  //WKUP按键PA0

#define KEY0_PRES	1	//KEY0
#define KEY1_PRES	2	//KEY1
#define KEY2_PRES	3	//KEY2
#define WKUP_PRES	4	//WK_UP

uint8_t key_scan(uint8_t mode);

#endif //__KEY_KEY_H
