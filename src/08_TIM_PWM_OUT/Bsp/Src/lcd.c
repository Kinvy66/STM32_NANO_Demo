/**
* @file lcd.h.cpp
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/4/19 13:04
* @description: 
**/
#include "lcd.h"
#include "lcd_test.h"

/**
 * @brief lcd init
 */
void lcd_init()
{
    LCD_Init();
}

/**
 * @brief TODO: lcd test
 */
void lcd_test()
{
    LCD_Init();
    LCD_Clear();
    LCD_Test_Text();
}

/**
 * @brief lcd show string
 * @param x
 * @param y
 * @param Asciifonts
 * @param Color
 * @param str
 */
void lcd_show_str(uint16_t x, uint16_t y, pFONT Asciifonts, uint32_t Color, char* str)
{
    LCD_SetBackColor(LCD_WHITE);
    LCD_SetColor(Color);
    LCD_SetAsciiFont(&Asciifonts);
    LCD_DisplayString(x, y,str);
}

/**
 * @brief lcd show integer number
 * @param x
 * @param y
 * @param Asciifonts
 * @param Color
 * @param fill
 * @param number
 */
void lcd_show_num(uint16_t x, uint16_t y, pFONT Asciifonts,
                  uint32_t Color, uint8_t fill, int32_t number, uint8_t len)
{
    LCD_SetColor(Color);
    LCD_SetAsciiFont(&Asciifonts);
    LCD_ShowNumMode(fill);
    LCD_DisplayNumber(x, y, number, len);
}

