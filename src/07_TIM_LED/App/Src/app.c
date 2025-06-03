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
#include "lcd_test.h"

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, ASCII_Font20, LCD_RED, "Timer LED Demo");
    lcd_show_str(10, 10 + 20, ASCII_Font20, LCD_RED, "HW: LED1 & LED2");
    HAL_TIM_Base_Start_IT(&htim6);
    uint8_t key = 0;
    while (1) {
        key = key_scan(0);
        if (key == KEY1_PRES) {
            LED1_ON();
            HAL_TIM_Base_Start_IT(&htim7);
            HAL_Delay(5000);
        }
    }
}