/**
* @file lcd_display.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/3/2 
* @description: 
**/

#ifndef __LCD_DISPLAY_H
#define __LCD_DISPLAY_H

#include "lcd_spi_169.h"

void LCD_Text(pFONT *font, uint32_t color, uint16_t x, uint16_t y, char* ch);



#endif //__LCD_DISPLAY_H
