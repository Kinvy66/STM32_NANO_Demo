/**
* @file main.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2024/12/28 20:20
* @description: 
**/

#include "common_inc.h"
#include "retarget.h"

void  user_main() {
    printf("hello\n");
    static float f = 42.0;
    printf("float : %f\n", f);
    f += 0.1;
    LED_Blink(500);
    // HAL_Delay(1000);
}

void bsp_init() {
    LED_Init();
}
