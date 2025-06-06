/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"
#include "stdio.h"
#include "hal_key.h"

uint16_t dev_id = 0;
void key1ShortPress(void)
{
    if (dev_id)
    {
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Erasing chip, about 30 sec...");
        Flash_EraseChip();
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Chip is erased.              ");
    }
}

void key2ShortPress(void)
{
    if (dev_id)
    {
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Erasing Block 0(256 pages)...");
        uint32_t globalAddr = 0;
        Flash_EraseBlock64K(globalAddr);
        lcd_show_str(10, 10 + 20*6, &ASCII_Font20, LCD_RED, "Block 0 is erased.           ");
    }

}

void key3ShortPress(void)
{
    if (dev_id)
    {
        Flash_TestWrite();
    }
}

void key4ShortPress(void)
{
    if (dev_id)
    {
        Flash_TestRead();
    }

}

keyCategory_t keys[KEY_NUM] = {
    [KEY1] = {
        .fsm.keyGpio.keyPort = KEY1_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY1_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key1ShortPress,
    },
    [KEY2] = {
        .fsm.keyGpio.keyPort = KEY2_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY2_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key2ShortPress,
    },
    [KEY3] = {
        .fsm.keyGpio.keyPort = KEY3_GPIO_Port,
        .fsm.keyGpio.keyPin = KEY3_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_RESET,
        .func.ShortPressCb = key3ShortPress,
    },
    [KEY4] = {
        .fsm.keyGpio.keyPort = WK_UP_GPIO_Port,
        .fsm.keyGpio.keyPin = WK_UP_Pin,
        .fsm.keyShield = ENABLE,
        .fsm.keyDownLevel = Bit_SET,
        .func.ShortPressCb = key4ShortPress,
    },
};

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
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