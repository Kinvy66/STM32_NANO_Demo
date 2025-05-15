//
// Created by admin on 2025/5/15.
//
#include "test.h"
#include "led.h"
#include "key.h"

void led_test()
{
    LED0_ON();
    LED1_TOGGLE();
    HAL_Delay(500);
}

void key_test()
{
    uint8_t key = 0;
    while (1) {
        key = key_scan(0);
        switch (key) {
        case KEY0_PRES://KEY0
            LED0_TOGGLE();
            break;

        case KEY1_PRES://KEY1
            LED1_TOGGLE();
            break;

        case KEY2_PRES://控制BEEP
            // TODO:
            HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
            break;

        case WKUP_PRES://KEY_UP
            LED0_TOGGLE();
            LED1_TOGGLE();
            break;

        default:
            HAL_Delay(10);
        }
    }
}