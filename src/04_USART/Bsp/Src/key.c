/**
* @file key.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 21:03
* @description: 
**/
#include "key.h"

uint8_t key_scan(uint8_t mode) {
    static uint8_t key_up=1;//按键按松开标志
    if(mode)key_up=1;  //支持连按
    if(key_up&&(KEY1==0||KEY2==0||KEY3==0||WK_UP==1))
    {
        HAL_Delay(10);//去抖动
        key_up=0;
        if(KEY1==0)return KEY1_PRES;
        else if(KEY2==0)return KEY2_PRES;
        else if(KEY3==0)return KEY3_PRES;
        else if(WK_UP==1)return WKUP_PRES;
    }else if(KEY1==1&&KEY2==1&&KEY3==1&&WK_UP==0)key_up=1;
    return 0;// 无按键按下
}

