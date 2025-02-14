/**
* @file led.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2024/12/28 20:20
* @description: 
**/
#include "led.h"
#include "stm32f1xx_hal.h"

/**
 * @brief LED GPIO 初始化
 */
void LED_Init() {

    // 初始化结构体
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    //1. 时钟使能
    __HAL_RCC_GPIOC_CLK_ENABLE();

    //2.配置GPIO
    GPIO_InitStruct.Pin = LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin
                          | LED_4_Pin | LED_5_Pin | LED_6_Pin | LED_7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

    //3. 设置默认的输出值
    HAL_GPIO_WritePin(LED_GPIO_Port,
                      LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin
                      | LED_4_Pin | LED_5_Pin | LED_6_Pin | LED_7_Pin,
                      GPIO_PIN_SET);
}
/**
 * @brief LED闪烁
 * @param ms
 */
void LED_Blink(int ms) {
    HAL_GPIO_WritePin(LED_GPIO_Port,
                      LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin
                      | LED_4_Pin | LED_5_Pin | LED_6_Pin | LED_7_Pin,
                      GPIO_PIN_SET);
    HAL_Delay(ms);
    HAL_GPIO_WritePin(LED_GPIO_Port,
                      LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin
                      | LED_4_Pin | LED_5_Pin | LED_6_Pin | LED_7_Pin,
                      GPIO_PIN_RESET);
    HAL_Delay(ms);
}
