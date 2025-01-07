/**
* @file key.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 20:08
* @description: 
**/
#include "key.h"
#include "exti.h"

void keyInit() {
 /*   GPIO_InitTypeDef GPIO_InitStruct = {0};

    *//* GPIO Ports Clock Enable *//*
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    *//*Configure GPIO pin : PtPin *//*
    GPIO_InitStruct.Pin = KEY_UP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(KEY_UP_GPIO_Port, &GPIO_InitStruct);

    *//*Configure GPIO pins : PCPin PCPin *//*
    GPIO_InitStruct.Pin = KEY0_Pin|KEY1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    *//*Configure GPIO pin : PtPin *//*
    GPIO_InitStruct.Pin = KEY2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY2_GPIO_Port, &GPIO_InitStruct);*/
    extiInit();
}

uint8_t keyScan(uint8_t mode) {

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
