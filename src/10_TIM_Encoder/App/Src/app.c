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
    lcd_show_str(10, 10, ASCII_Font20, LCD_RED, "Timer Encoder");
    lcd_show_str(10, 10 + 20, ASCII_Font20, LCD_RED, "HW: EC11");
    lcd_show_str(10, 10 + 20*2, ASCII_Font20, LCD_RED, "Angle:");
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    char send_buf[50] = {0};
    uint16_t cnt_encoder = 0;
    // 先设置TIM1的CNT值为1000，旋转编码器使得CNT值上下变化
    htim3.Instance->CNT = 1000;
    while (1)
    {
        // 如果CNT值发生变化，就打印出来
        if (cnt_encoder != __HAL_TIM_GET_COUNTER(&htim3))
        {
            cnt_encoder = __HAL_TIM_GET_COUNTER(&htim3);
            sprintf(send_buf, "%d", cnt_encoder);
            printf("%s", send_buf);
            // TODO: lcd 显示编码器变化值
            lcd_show_str(10+70, 10 + 20*2, ASCII_Font20, LCD_RED, send_buf);

        }
        HAL_Delay(10);

    }
}