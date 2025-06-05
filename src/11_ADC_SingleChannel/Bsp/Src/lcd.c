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

/**
 * @brief
 * @param x
 * @param y
 * @param Color
 * @param fill
 * @param number
 * @param len
 */
void lcd_show_num(uint16_t x, uint16_t y,
                  uint32_t Color, uint8_t fill, int32_t number, uint8_t len)
{
    LCD_SetColor(Color);
    LCD_ShowNumMode(fill);
    LCD_DisplayNumber(x, y, number, len);
}

/**
 * @brief FIXME
 * @param x
 * @param y
 * @param Color
 * @param fill
 * @param decimals
 * @param len
 * @param decs
 */
void lcd_show_decimals(uint16_t x, uint16_t y, uint32_t Color, uint8_t fill,
                       double decimals, uint8_t len, uint8_t decs)
{
    LCD_SetColor(LIGHT_RED);									// 设置画笔，亮红色
    LCD_ShowNumMode(fill);
    LCD_DisplayDecimals( x, y, decimals, len, decs);		// 显示小数
}
