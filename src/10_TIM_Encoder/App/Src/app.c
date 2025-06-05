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
#include "hal_key.h"

uint16_t cnt_encoder = 0;

void keyShortPress(void)
{
    cnt_encoder = 0;
    htim3.Instance->CNT = cnt_encoder;
    printf("test\r\n");
}

keyCategory_t keys[KEY_NUM] = {
        [ENC_KEY] = {
                .fsm.keyGpio.keyPort = ENC_KEY_GPIO_Port,
                .fsm.keyGpio.keyPin = ENC_KEY_Pin,
                .fsm.keyShield = ENABLE,
                .fsm.keyDownLevel = Bit_RESET,
                .func.ShortPressCb = keyShortPress,
        },
};

/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    keyParaInit(keys);
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "Timer Encoder");
    lcd_show_str(10, 10 + 1*20, &ASCII_Font20, LCD_RED, "HW: EC11");
    lcd_show_str(10, 10 + 2*20, &ASCII_Font20, LCD_RED, "Press EC_KEY Set Zero");
    lcd_show_str(10, 10 + 3*20, &ASCII_Font20, LCD_RED, "Angle:");
    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    char send_buf[50] = {0};
    // 先设置TIM1的CNT值为1000，旋转编码器使得CNT值上下变化
    while (1)
    {
        // 如果CNT值发生变化，就打印出来
        if (cnt_encoder != __HAL_TIM_GET_COUNTER(&htim3))
        {
            cnt_encoder = __HAL_TIM_GET_COUNTER(&htim3);
            sprintf(send_buf, "%d", cnt_encoder);
            printf("%s", send_buf);
            // TODO: lcd 显示编码器变化值
            if(cnt_encoder >= 400) {
                cnt_encoder = 0;
                htim3.Instance->CNT = cnt_encoder;
            }
        }
        lcd_show_num(10+70, 10 + 20*3, LCD_RED,Fill_Space,  cnt_encoder, 5);
        HAL_Delay(10);
    }
}