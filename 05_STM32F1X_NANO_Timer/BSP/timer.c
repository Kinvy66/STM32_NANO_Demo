/**
* @file timer.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/8 21:11
* @description: 
**/
#include "timer.h"
#include "stm32f1xx_hal.h"
#include "led.h"

extern TIM_HandleTypeDef htim3;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3) {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
}