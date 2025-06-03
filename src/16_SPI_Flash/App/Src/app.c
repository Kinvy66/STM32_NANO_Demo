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

/**
 * @brief app entry
 */
void app_main(void)
{
    // Flash_TestReadStatus();
    while (1) {
        uint8_t key = key_scan(0);
        switch (key)
        {
        case KEY1_PRES:
            Flash_EraseChip();
            break;
        case KEY2_PRES:
            uint32_t globalAddr = 0;
            Flash_EraseBlock64K(globalAddr);
            break;
        case KEY3_PRES:
            // Flash_TestWrite();
            break;
        case WKUP_PRES:
            // Flash_TestRead();
            break;
        }
        HAL_Delay(500);
    }
}