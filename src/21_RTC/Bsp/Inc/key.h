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
#include "hal_key.h"

void key1_short_press(void);
void key2_short_press(void);
void key3_short_press(void);
void key4_short_press(void);

void key1_long_press(void);
void key2_long_press(void);
void key3_long_press(void);
void key4_long_press(void);

void key1_dbclk_press(void);
void key2_dbclk_press(void);
void key3_dbclk_press(void);
void key4_dbclk_press(void);

void key_init(void);
void key_handle(void);

#endif //__KEY_H
