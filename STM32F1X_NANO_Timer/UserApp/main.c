/**
* @file main.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 19:24
* @description: 
**/
#include "common_inc.h"

void user_main() {
    // ledBlink(500);
    uint8_t key = keyScan(0); //得到键值
    switch (key)
    {
        case KEY0_PRES://KEY0
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            break;

        case KEY1_PRES://KEY1
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
            break;

        case KEY2_PRES://控制BEEP
            HAL_GPIO_TogglePin(BEEP_GPIO_Port,BEEP_Pin);
            break;

        case WKUP_PRES://KEY_UP
            HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
            HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
            break;
        default:
            HAL_Delay(10);
    }
}

void bsp_init() {
    ledInit();
    beepInit();
    keyInit();
}