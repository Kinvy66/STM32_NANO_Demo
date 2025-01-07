/**
* @file main.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/1/7 19:24
* @description: 
**/
#include "common_inc.h"

void user_main() {
    ledBlink(500);
}

void bsp_init() {
    ledInit();
}