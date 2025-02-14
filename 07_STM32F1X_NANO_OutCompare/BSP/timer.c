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

// #define  ARR_REGISTER   899   // ARR寄存器的值
extern TIM_HandleTypeDef htim3;
// uint8_t pulseChangeDirection = 1;  // pwm 脉冲方向
// uint16_t pulseWidth = 50;  // 脉冲宽度

/**
 * @brief 更新事件中断
 * @param htim
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3) {
        // HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
}

