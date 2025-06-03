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
    while (1) {
        LCD_Test_Clear();
        LCD_Test_Text();
        HAL_Delay(500);
    }
}