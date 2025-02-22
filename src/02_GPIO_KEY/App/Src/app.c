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
    uint8_t key = 0;
    while (1) {
        key = key_scan(0);
        switch (key) {
            case KEY0_PRES://KEY0
                HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
                break;

            case KEY1_PRES://KEY1
                HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
                break;

            case KEY2_PRES://控制BEEP
                HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
                break;

            case WKUP_PRES://KEY_UP
                HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
                HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
                break;

            default:
                HAL_Delay(10);
        }
        }
    return 0;
}
