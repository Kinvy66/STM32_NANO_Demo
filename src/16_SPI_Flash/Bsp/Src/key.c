/**
* @file key.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 21:03
* @description: 
**/
#include "key.h"

keyCategory_t keys[KEY_NUM] = {
        [KEY1] = {
                .fsm.keyGpio.keyPort = KEY1_GPIO_Port,
                .fsm.keyGpio.keyPin = KEY1_Pin,
                .fsm.keyShield = ENABLE,
                .fsm.keyDownLevel = Bit_RESET,
                .func.ShortPressCb = key1_short_press,
                .func.longPressCb = key1_long_press,
                .func.dbclPressCb = key1_dbclk_press,
        },
        [KEY2] = {
                .fsm.keyGpio.keyPort = KEY2_GPIO_Port,
                .fsm.keyGpio.keyPin = KEY2_Pin,
                .fsm.keyShield = ENABLE,
                .fsm.keyDownLevel = Bit_RESET,
                .func.ShortPressCb = key2_short_press,
                .func.longPressCb = key2_long_press,
                .func.dbclPressCb = key2_dbclk_press,
        },
        [KEY3] = {
                .fsm.keyGpio.keyPort = KEY3_GPIO_Port,
                .fsm.keyGpio.keyPin = KEY3_Pin,
                .fsm.keyShield = ENABLE,
                .fsm.keyDownLevel = Bit_RESET,
                .func.ShortPressCb = key3_short_press,
                .func.longPressCb = key3_long_press,
                .func.dbclPressCb = key3_dbclk_press,
        },
        [KEY4] = {
                .fsm.keyGpio.keyPort = WK_UP_GPIO_Port,
                .fsm.keyGpio.keyPin = WK_UP_Pin,
                .fsm.keyShield = ENABLE,
                .fsm.keyDownLevel = Bit_SET,
                .func.ShortPressCb = key4_short_press,
                .func.longPressCb = key4_long_press,
                .func.dbclPressCb = key4_dbclk_press,
        },
};

__weak void key1_short_press(void){}
__weak void key2_short_press(void){}
__weak void key3_short_press(void){}
__weak void key4_short_press(void){}

__weak void key1_long_press(void){}
__weak void key2_long_press(void){}
__weak void key3_long_press(void){}
__weak void key4_long_press(void){}

__weak void key1_dbclk_press(void){}
__weak void key2_dbclk_press(void){}
__weak void key3_dbclk_press(void){}
__weak void key4_dbclk_press(void){}


void key_init(void)
{
    keyParaInit(keys);
}

void key_handle(void)
{
    keyHandle();
}

