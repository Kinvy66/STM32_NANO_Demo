/**
* @file beep.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 20:08
* @description: 
**/
#include "beep.h"

void beepInit() {
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOB_CLK_ENABLE();           //开启GPIOB时钟

    GPIO_Initure.Pin=BEEP_Pin; 			//PB8
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
    HAL_GPIO_Init(BEEP_GPIO_Port,&GPIO_Initure);

    HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET);	//蜂鸣器对应引脚GPIOB8拉高，
}

