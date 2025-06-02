/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/16 21:13
* @description: 
**/

#include "common_inc.h"
#include "test.h"
#include "lcd.h"

/**
 * @brief Application entry
 * @return
 */
void app_main(void)
{
    while(1)
    {
        // led_test();
        // key_test();
        // uart_test();
        // lcd_test();
        // tim_led();
        tim_pwm();
    }

}
