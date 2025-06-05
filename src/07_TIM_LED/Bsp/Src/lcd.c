/**
* @file lcd.h.cpp
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/4/19 13:04
* @description: 
**/
#include "lcd.h"
#include "lcd_test.h"

void lcd_init()
{
    LCD_Init();
}

void lcd_test()
{
    LCD_Init();
    LCD_Clear();
    LCD_Test_Text();
}

void lcd_show_str(uint16_t x, uint16_t y, pFONT* Asciifonts, uint32_t Color, char* str)
{
    LCD_SetBackColor(LCD_WHITE);
    LCD_SetColor(Color);
    LCD_SetAsciiFont(Asciifonts);
    LCD_DisplayString(x, y,str);
}