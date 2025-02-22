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

/**
 * @brief hardware init
 */
void hw_init() {
    LED0_OFF;
    LED1_OFF;
}

/**
 * @brief Application entry
 * @return
 */
int app(void) {
    LED0_BLINK(500);
    return 0;
}

