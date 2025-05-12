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
#include "beep.h"
#include "key.h"

/**
 * @brief Hardware Init
 */
void hw_init(void) {
    LED0_OFF;
    LED1_OFF;
    BEEP_ON;
}

/**
 * @brief Application Entry
 * @return
 */
int app(void) {

    return 0;
}
