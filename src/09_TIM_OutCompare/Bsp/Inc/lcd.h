/**
* @file lcd.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/4/19 
* @description: 
**/

#ifndef _LCD_H
#define _LCD_H
#include "lcd_spi_169.h"

void lcd_init();
void lcd_test();
void lcd_show_str(uint16_t x, uint16_t y, pFONT Asciifonts, uint32_t Color, char* str);

#endif //_LCD_H
