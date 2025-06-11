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


/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "IIC AHT20");
    AHT20_Init();
    char message[50];
    float temperature = 0.0, humidity = 0.0;

    while (1) {
        AHT20_Read(&temperature, &humidity);
        // sprintf(message, "temp: %.1f C, hum: %.1f %%", temperature, humidity);
        sprintf(message, "soft温度: %.1f ℃，湿度: %.1f %%\r\n", temperature, humidity);
        printf(message);
        // lcd_show_str(10, 10 + 20, &ASCII_Font20, LCD_RED, message);
        HAL_Delay(1000);
    }
}