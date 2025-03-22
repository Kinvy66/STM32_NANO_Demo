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
#include "uart.h"
#include <stdio.h>
#include "lcd_spi_169.h"
#include "w25xx_flash.h"
#include <string.h>

/**
 * @brief Hardware Init
 */
void hw_init(void) {
    LED0_OFF;
    LED1_OFF;
    BEEP_OFF;
    uart_recv();

}

/**
 * @brief Application Entry
 * @return
 */
int app(void) {
    // uart_send();
    // uart_recv();
    flash_test();

    return 0;
}

static void Flash_TestWrite() {
    uint8_t BlockNo = 0;
    uint8_t SubSectorNo = 0;
    uint8_t SubPageNo = 0;
    uint32_t memAddress = 0;
    memAddress = Flash_Addr_byBlockSectorPage(BlockNo, SubSectorNo, SubPageNo);
    uint8_t bufStr1[30] = "Hello from beginning";
    Flash_WriteInPage(memAddress, bufStr1, strlen(bufStr1) + 1);
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Write in Page0:0             ");
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 80,bufStr1);

    uint8_t bufStr2[30] = "Hello in page";
    Flash_WriteInPage(memAddress + 100, bufStr2, strlen(bufStr2) + 1);
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Write in Page0:100             ");
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 80,bufStr2);

    uint8_t bufPage[FLASH_PAGE_SIZE];
    for (uint16_t i = 0; i < FLASH_PAGE_SIZE; ++i) {
        bufPage[i] = i;
    }
    SubPageNo = 1;
    memAddress = Flash_Addr_byBlockSectorPage(BlockNo, SubSectorNo, SubPageNo);
    Flash_WriteInPage(memAddress, bufPage, FLASH_PAGE_SIZE);
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Write 0~255 in Page1           ");
}

static void Flash_TestRead() {
    uint8_t BlockNo = 0;
    uint8_t SubSectorNo = 0;
    uint8_t SubPageNo = 0;
    uint32_t memAddress = Flash_Addr_byBlockSectorPage(BlockNo, SubSectorNo, SubPageNo);
    uint8_t bufStr[50];
    Flash_ReadBytes(memAddress, bufStr, 50);

    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Read in Page0:0             ");
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 80,bufStr);


    Flash_ReadBytes(memAddress + 100, bufStr, 50);
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Read in Page0:100             ");
    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 80,bufStr);

    SubPageNo = 1;
    memAddress = Flash_Addr_byBlockSectorPage(BlockNo, SubSectorNo, SubPageNo);
    uint8_t randData12 = Flash_ReadOneByte(memAddress + 12);
    uint8_t randData136 = Flash_ReadOneByte(memAddress + 136);
    uint8_t randData210 = Flash_ReadOneByte(memAddress + 210);
    uint8_t tempStrRandData[30];
    sprintf(tempStrRandData, "Page1[12]=%d,[136]=%d,[210]=%d",
            randData12, randData136, randData210);

    LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,tempStrRandData);

}

/**
 * @brief
 */
void flash_test(void) {
    uint8_t key = key_scan(0);
    switch (key) {
        case KEY0_PRES:
            LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Erasing chip, about 30 sec...");
            Flash_EraseChip();
            LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0, 60,"Chip is erased.              ");
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            break;
        case KEY1_PRES:
            Flash_TestWrite();
            break;
        case KEY2_PRES:
            Flash_TestRead();
            break;
    }
}
