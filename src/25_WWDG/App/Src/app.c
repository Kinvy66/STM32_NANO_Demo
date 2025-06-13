/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"
#include "stdio.h"
#include "usart.h"
#include "key.h"
#include  "wwdg.h"
uint8_t seconds_count = 0;

void key1_short_press(void)
{
    lcd_show_str(10, 10+20*3, &ASCII_Font20, LCD_RED, "Press any key to refresh IWDG");
}


/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "Independent WatchDog");
    lcd_show_str(10, 10+20*1, &ASCII_Font20, LCD_RED, "IWDG should be refreshed in 8s");
    lcd_show_str(10, 10+20*2, &ASCII_Font20, LCD_RED, "Press key1 to refresh IWDG");
    key_init();
    LED1_ON();
    while (1) {
        // seconds_count++;
        // uint8_t tempStr[30];
        // sprintf(tempStr, "Seconds after last refresh: %d", seconds_count);
        // lcd_show_str(10, 10+20*3, &ASCII_Font20, LCD_RED, tempStr);
        // HAL_Delay(1000);
    }
}