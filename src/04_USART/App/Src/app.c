/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"
#include "stdio.h"

void app_main(void)
{

    while (1) {
        printf("test\r\n");
        HAL_Delay(500);
    }
}