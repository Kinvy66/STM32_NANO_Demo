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
#include "lcd_test.h"
#include "rtc.h"

/**
 * @brief app entry
 */
void app_main(void)
{
    RTC_TimeTypeDef sTime = {0};
    RTC_DateTypeDef sDate = {0};
    char str[100];
    while (1)
    {
        // 获取的时间是BCD码，需要转换成十进制打印
        // 每隔1秒钟，用串口打印一次时间和日期
        HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD);
        HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BCD);
        sprintf(str, "20%02x-%02x-%02x %02x:%02x:%02x\r\n", sDate.Year, sDate.Month, sDate.Date, sTime.Hours, sTime.Minutes, sTime.Seconds);
        printf("%s", str);
        HAL_Delay(1000);
    }
}