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

/**
 * @brief 串口dma
 */
static void uart_dma_demo()
{
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_TC);
    __HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
    uint8_t hello1[] = "Hello, DMA transmit\n";
    HAL_UART_Transmit_DMA(&huart1, hello1, sizeof(hello1));

    HAL_UART_Receive_DMA(&huart1, rxBuffer, RX_CMD_LEN);

}

void app_main(void)
{
    // tx_and_rx_demo();
    uart_dma_demo();
    while (1) {
        printf("test\r\n");
        HAL_Delay(500);
    }
}