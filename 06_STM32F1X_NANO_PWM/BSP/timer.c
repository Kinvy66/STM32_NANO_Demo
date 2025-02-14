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
#include "tim.h"

extern TIM_HandleTypeDef htim3;

#define  ARR_REGISTER   199   // ARR寄存器的值
extern uint8_t pulseChangeDirection; //= 1;  // pwm 脉冲方向
extern uint16_t pulseWidth;// = 10;  // 脉冲宽度

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


/**
 * @brief pwm中断
 * @param htim
 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance != TIM3) {
        return;
    }

    if (pulseChangeDirection) {
        pulseWidth++;
        if (pulseWidth >= ARR_REGISTER) {
            pulseWidth = ARR_REGISTER;
            pulseChangeDirection = 0;
        }
    } else {
        pulseWidth--;
        if(pulseWidth <= 5) {
            pulseWidth = 5;
            pulseChangeDirection  = 1;
        }
    }
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulseWidth);
    // HAL_Delay(10);

}

