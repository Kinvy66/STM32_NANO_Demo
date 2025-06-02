/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"

void app_main(void)
{
    uint8_t key = 0;
    while (1) {
        key = key_scan(0);
        switch (key) {
            case KEY1_PRES://KEY0
                LED1_TOGGLE();
                break;

            case KEY2_PRES://KEY1
                LED2_TOGGLE();
                // LED1_TOGGLE();
                break;

            case KEY3_PRES://控制BEEP
                LED1_TOGGLE();
                LED2_TOGGLE();
                break;

            case WKUP_PRES://KEY_UP
                LED1_TOGGLE();
                LED2_TOGGLE();
                break;
            default:
                HAL_Delay(10);
                break;
        }
    }
}