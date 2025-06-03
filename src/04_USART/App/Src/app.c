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

/**
 * @brief 串口收发
 */
static void tx_and_rx_demo()
{
    uint8_t hello1[] = "Hello, blocking\n";
    HAL_UART_Transmit(&huart1, hello1, sizeof(hello1), 500);
    HAL_Delay(10);

    uint8_t hello2[] = "Hello, none blocking\n";
    HAL_UART_Transmit_IT(&huart1, hello2, sizeof(hello2));
    HAL_UART_Receive_IT(&huart1, rxBuffer, RX_CMD_LEN);
}

void app_main(void)
{
    tx_and_rx_demo();
    HAL_Delay(500);
    while (1) {
        printf("test\r\n");
        HAL_Delay(500);
    }
}