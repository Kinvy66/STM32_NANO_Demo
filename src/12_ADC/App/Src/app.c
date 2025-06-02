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
#include "adc.h"
#include "stdio.h"

/**
 * @brief Application entry
 * @return
 */

uint32_t	dmaDataBuffer = 0;
void app_main(void)
{
    // printf("adc val:%d\r\n", dmaDataBuffer);
    // HAL_ADC_Start_DMA(&hadc1, &dmaDataBuffer, 1);
    HAL_ADC_Start(&hadc1);
    while (1) {

        if (HAL_ADC_PollForConversion(&hadc1, 200) == HAL_OK) {
             dmaDataBuffer = HAL_ADC_GetValue(&hadc1);
            printf("adc val:%d\r\n", dmaDataBuffer);

            uint32_t Volt = 3300 * dmaDataBuffer >> 12;
            printf("Volt: %d\r\n", Volt);
            HAL_Delay(500);
        }
    }
}
