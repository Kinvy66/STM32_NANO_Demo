/**
* @file key.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/22 17:19
* @description: 
**/

#include "key.h"

/**
 * @brief 按键扫描
 * @param mode 0: 单次触发， 1:长按模式
 * @return
 */
uint8_t key_scan(uint8_t mode) {
    static uint8_t key_up=1;//按键按松开标志
    if(mode)key_up=1;  //支持连按
    if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
    {
        HAL_Delay(10);//去抖动
        key_up=0;
        if(KEY0==0)return KEY0_PRES;
        else if(KEY1==0)return KEY1_PRES;
        else if(KEY2==0)return KEY2_PRES;
        else if(WK_UP==1)return WKUP_PRES;
    }else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1;
    return 0;// 无按键按下
}

/**
 * @brief GPIO 外部中断回调函数
 * @param GPIO_Pin
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == KEY0_Pin)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        HAL_Delay(500);
    }
    else if (GPIO_Pin == KEY1_Pin)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        HAL_Delay(1000);
    }
    else if (GPIO_Pin == KEY2_Pin)
    {
        __HAL_GPIO_EXTI_GENERATE_SWIT(WK_UP_Pin);
        HAL_Delay(1000);
    }
    else if (GPIO_Pin == WK_UP_Pin)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        HAL_Delay(1000);
    }
}