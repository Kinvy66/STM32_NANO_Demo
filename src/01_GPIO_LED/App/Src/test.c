//
// Created by admin on 2025/5/15.
//
#include "test.h"
#include "led.h"

void led_test()
{
    LED0_ON();
    LED1_TOGGLE();
    HAL_Delay(500);
}