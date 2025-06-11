/**
* @file app.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/2 18:03
* @description: 
**/
#include "app.h"
#include "stdio.h"
#include "usart.h"
#include "key.h"
#include "qmi8658.h"


/**
 * @brief app entry
 */
void app_main(void)
{
    lcd_init();
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "IIC QMI8658");
    QMI8658_Init();
    // HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET);
    t_sQMI8658 p;
    while (1) {
        qmi8658_fetch_angleFromAcc(&p);
        HAL_Delay(2000);
    }
}