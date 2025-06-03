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
#include "adc.h"

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, ASCII_Font20, LCD_RED, "ADC SingleChannel");
    lcd_show_str(10, 10 + 20, ASCII_Font20, LCD_RED, "HW: ");
    char send_buf[40] = {0};
    uint16_t result = 0;
    float voltage = 0.0f;
    // 开始连续ADC转换
    HAL_ADC_Start(&hadc1);
    // 等待ADC稳定
    HAL_Delay(500);
    while (1)
    {
        // 获取ADC值
        result = HAL_ADC_GetValue(&hadc1);
        // 计算电压值
        voltage = result * 3.3f / 4095;
        // 将变量打印为字符串
        sprintf(send_buf, "ADC value: %d, Voltage: %.3f V\r\n", result, voltage);
        printf("%s", send_buf);
        HAL_Delay(500);
        // TODO: lcd 显示数据
    }
}