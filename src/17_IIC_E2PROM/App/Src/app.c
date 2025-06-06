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

void key1_short_press(void)
{

}

void key2_short_press(void)
{

}

void key3_short_press(void)
{

}

void key4_short_press(void)
{

}

/**
 * @brief app entry
 */
void app_main(void)
{
    if (EP24C_IsDeviceReady() == HAL_OK) {
        //TODO:
    }
    // Flash_TestReadStatus();
    uint8_t num1 = 107, num2;
    uint16_t addr_any = 4;
    uint16_t addr_page = 2*8;
    uint8_t infoStr[50];
    key_init();
    while (1) {
        // uint8_t key = key_scan(0);
        // switch (key)
        // {
        // case KEY1_PRES:
        //     if (EP24C_WriteOneByte(addr_any, num1) == HAL_OK) {
        //         // lcd_fill(10, 10 * 20 + 10, 479, 12 * 20 + 10, WHITE);
        //         // sprintf(infoStr, "Write %d at Address %d\0", num1, addr_any);
        //         // lcd_show_str(10, 10 * 20 + 10, 16, infoStr, RED);
        //     }
        //     break;
        // case KEY2_PRES:
        //     if (EP24C_ReadOneByte(addr_any, &num2) == HAL_OK) {
        //         // lcd_fill(10, 10 * 20 + 10, 479, 12 * 20 + 10, WHITE);
        //         // sprintf(infoStr, "Read out %d at Address %d\0", num2, addr_any);
        //         // lcd_show_str(10, 10 * 20 + 10, 16, infoStr, RED);
        //     }
        //     break;
        // case KEY3_PRES:
        //     uint8_t strIn[] = "University of Petroleum";
        //     if (EP24C_WriteLongData(addr_page, strIn, sizeof(strIn)) == HAL_OK) {
        //         // lcd_fill(10, 10 * 20 + 10, 479, 12 * 20 + 10, WHITE);
        //         // lcd_show_str(10, 10 * 20 + 10, 16, "Write string from Page 2:", RED);
        //         // lcd_show_str(10, 11 * 20 + 10, 16, strIn, RED);
        //     }
        //     break;
        // case WKUP_PRES:
        //     uint8_t strOut[50];
        //     if (EP24C_ReadBytes(addr_page, strOut, 50) == HAL_OK) {
        //         // lcd_fill(10, 10 * 20 + 10, 479, 12 * 20 + 10, WHITE);
        //         // lcd_show_str(10, 10 * 20 + 10, 16, "Read string from Page 2:", RED);
        //         // lcd_show_str(10, 11 * 20 + 10, 16, strOut, RED);
        //     }
        //     break;
        // }
        // HAL_Delay(500);
    }
}