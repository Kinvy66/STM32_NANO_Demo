/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/16 21:13
* @description: 
**/

#include "app.h"
#include "stm32f1xx_hal.h"
#include "main.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "uart.h"
#include <stdio.h>
#include "tim.h"

/**
 * @brief Hardware Init
 */
void hw_init(void) {
    LED0_OFF();
    LED1_OFF();
    BEEP_OFF();
}

/**
 * @brief Application Entry
 * @return
 */
int app(void) {

    printf("Hello world!\r\n");
    HAL_Delay(1000);
    return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &htim2) {
        LED0_TOGGLE();
    }
}
