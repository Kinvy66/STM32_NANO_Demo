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

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, ASCII_Font20, LCD_RED, "Timer PWM OUT");
    lcd_show_str(10, 10 + 20, ASCII_Font20, LCD_RED, "HW: LED2");
    HAL_TIM_Base_Start_IT(&htim5);
    HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_2);
    while (1) {

    }
}