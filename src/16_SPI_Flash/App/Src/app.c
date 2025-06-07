/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"
#include "stdio.h"
#include "tim.h"

uint16_t dev_id = 0;
void key1_short_press(void)
{
    if (dev_id)
    {
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Erasing chip,about 30s.");
        Flash_EraseChip();
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Chip is erased.        ");
    }
}

void key2_short_press(void)
{
    if (dev_id)
    {
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Erasing Block 0.       ");
        uint32_t globalAddr = 0;
        Flash_EraseBlock64K(globalAddr);
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Block 0 is erased.     ");
    }

}

void key3_short_press(void)
{
    if (dev_id)
    {
        Flash_TestWrite();
    }
}

void key4_short_press(void)
{
    if (dev_id)
    {
        Flash_TestRead();
    }

}

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    key_init();
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "SPI Flash");
    lcd_show_str(10, 10 + 20, &ASCII_Font20, LCD_RED, "K1 Erase Chip");
    lcd_show_str(10, 10 + 20*2, &ASCII_Font20, LCD_RED, "K2 Erase Block 0");
    lcd_show_str(10, 10 + 20*3, &ASCII_Font20, LCD_RED, "K3 Write Page 0-1");
    lcd_show_str(10, 10 + 20*4, &ASCII_Font20, LCD_RED, "WK Read Page 0-1");
    lcd_show_str(10, 10 + 20*5, &ASCII_Font20, LCD_RED, "Flash ID:");
    dev_id =   Flash_TestReadStatus();
    if (dev_id)
    {
        lcd_show_num(10 + 100, 10 + 20*5, LCD_RED, Fill_Space, dev_id, 5);
    } else
    {
        lcd_show_str(10 + 100, 10 + 20*5, &ASCII_Font20, LCD_RED, "No Flash");
    }
    while (1)
    {


    }
}