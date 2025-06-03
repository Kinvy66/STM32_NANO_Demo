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

uint8_t  model = 0;
extern uint16_t pulseWidth;
void key1ShortPress(void)
{
    model = !model;
}

void key2ShortPress(void)
{
    pulseWidth -= 5;
    if (pulseWidth <= 0 || pulseWidth >= 100) {
        pulseWidth = 0;
    }
    __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, pulseWidth);
}

void key3ShortPress(void)
{
    pulseWidth += 5;
    if (pulseWidth >= 100) {
        pulseWidth = 100;
    }
    __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, pulseWidth);
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

};

/**
 * @brief app entry
 */
void app_main(void)
{

    lcd_init();
    lcd_show_str(10, 10, ASCII_Font20, LCD_RED, "Timer PWM OUT");
    lcd_show_str(10, 10 + 20, ASCII_Font20, LCD_RED, "HW: LED2");
    lcd_show_str(10, 10 + 20*2, ASCII_Font20, LCD_RED, "Model: ");
    lcd_show_str(10, 10 + 20*3, ASCII_Font20, LCD_RED, "PWM: ");
    HAL_TIM_Base_Start_IT(&htim5);
    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_2);

    keyParaInit(keys);
    while (1) {
        if (model == 0) {
            lcd_show_str(80, 10 + 20*2, ASCII_Font20, LCD_RED, "Auto");
        } else if (model == 1) {
            lcd_show_str(80, 10 + 20*2, ASCII_Font20, LCD_RED, "Manu");
            pulseWidth = __HAL_TIM_GET_COMPARE(&htim5, TIM_CHANNEL_2);
            lcd_show_str(50, 10 + 20*3, ASCII_Font20, LCD_RED, "Manu");
        }
    }
}