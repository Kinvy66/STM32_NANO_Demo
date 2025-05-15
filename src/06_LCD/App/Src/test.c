//
// Created by admin on 2025/5/15.
//
#include "test.h"
#include "led.h"
#include "key.h"
#include "usart.h"
#include "lcd_test.h"
#include <string.h>

void led_test()
{
    LED0_ON();
    LED1_TOGGLE();
    HAL_Delay(500);
}

void key_test()
{
    uint8_t key = 0;
    while (1) {
        key = key_scan(0);
        switch (key) {
        case KEY0_PRES://KEY0
            LED0_TOGGLE();
            break;

        case KEY1_PRES://KEY1
            LED1_TOGGLE();
            break;

        case KEY2_PRES://控制BEEP
            // TODO:
            HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
            break;

        case WKUP_PRES://KEY_UP
            LED0_TOGGLE();
            LED1_TOGGLE();
            break;

        default:
            HAL_Delay(10);
        }
    }
}

uint8_t dataRecv;
/**
 * @brief
 * @return
 */
static HAL_StatusTypeDef uart_send() {

    HAL_StatusTypeDef ret;
    uint8_t byteNumber = 0x5a;
    uint8_t byteArray[] = {1, 2, 3, 4, 5};
    char ch = 'a';
    char *str = "hello world!";
    // HAL_UART_Transmit(&huart1, &byteNumber, 1, HAL_MAX_DELAY);
    // HAL_UART_Transmit(&huart1, byteArray, 5, HAL_MAX_DELAY);
    // HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    // ret = HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);

    HAL_UART_Transmit_IT(&huart1, &byteNumber, 1);
    HAL_UART_Transmit_IT(&huart1, byteArray, 5);
    HAL_UART_Transmit_IT(&huart1, (uint8_t*)&ch, 1);
    ret = HAL_UART_Transmit_IT(&huart1, (uint8_t*)str, strlen(str));

    return ret;
}

/**
 * @brief
 * @return
 */
static HAL_StatusTypeDef uart_recv() {
    // HAL_UART_Receive(&huart1, &dataRecv, 1, HAL_MAX_DELAY);
    HAL_UART_Receive_IT(&huart1, &dataRecv, 1);
    return  0;
}


void uart_test()
{
    uart_send();
    uart_recv();
}

#define RX_CMD_LEN 5
void usart_dma_test()
{
    uint8_t proBuffer[10] = "#S45;\n";
    uint8_t rxBuffer[10] = "#H12;\n";
    uint8_t rxCompleted = RESET;
    uint8_t isUploadTime = 1;
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_TC);
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
    uint8_t hello1[] = "Hello, DMA transmit\n";
    HAL_UART_Transmit_DMA(&huart1, hello1, sizeof(hello1));

    HAL_UART_Receive_DMA(&huart1, rxBuffer, RX_CMD_LEN);
}

void lcd_test()
{
    LCD_Init();
    LCD_Test_Clear();
    LCD_Test_Text();
}