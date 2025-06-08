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

uint8_t num1 = 107, num2;
uint16_t addr_any = 8;
uint16_t addr_page = 2*8;
uint8_t infoStr[50];

const uint8_t TEXT_Buffer[] = {"NANO STM32 IIC TEST"};
#define SIZE sizeof(TEXT_Buffer)
uint8_t datatemp[SIZE];


void key1_short_press(void)
{
    if (EP24C_WriteOneByte(addr_any, num1) == HAL_OK) {
        sprintf(infoStr, "Write %d at Addr %d\0", num1, addr_any);
        printf(infoStr);
        lcd_show_str(10, 10 + 20*2, &ASCII_Font20, LCD_RED, infoStr);

    }

}

void key2_short_press(void)
{
    if (EP24C_ReadOneByte(addr_any, &num2) == HAL_OK) {
        sprintf(infoStr, "Read out %d at Addr %d\0", num2, addr_any);
        printf(infoStr);
        lcd_show_str(10, 10 + 20*2, &ASCII_Font20, LCD_RED, infoStr);
    }
}

void key3_short_press(void)
{
    uint8_t strIn[] = "University of Petroleum";
    if (EP24C_WriteLongData(addr_page, strIn, sizeof(strIn)) == HAL_OK) {
        lcd_show_str(10, 10 + 20*2, &ASCII_Font20, LCD_RED, "Write to from Page 2:");
        lcd_show_str(10, 10 + 20*3, &ASCII_Font20, LCD_RED, strIn);
    }
}

void key4_short_press(void)
{
    uint8_t strOut[50];
    if (EP24C_ReadBytes(addr_page, strOut, 50) == HAL_OK) {
        lcd_show_str(10, 10 + 20*2, &ASCII_Font20, LCD_RED, "Read str from Page 2:");
        lcd_show_str(10, 10 + 20*3, &ASCII_Font20, LCD_RED, strOut);
    }
}

/**
 * @brief app entry
 */
void app_main(void)
{

    lcd_init();
    lcd_show_str(10, 10, &ASCII_Font20, LCD_RED, "IIC E2PROM");
    key_init();

    if (EP24C_IsDeviceReady() == HAL_OK) {
        printf("OK\r\n");
        lcd_show_str(10, 10+20, &ASCII_Font20, LCD_RED, "Deivce is Ready.");


    }

    while (1) {

    }

}