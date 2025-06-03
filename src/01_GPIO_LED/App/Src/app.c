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
    while (1) {
        LED1_TOGGLE();
        LED2_ON();
        HAL_Delay(500);
    }
}