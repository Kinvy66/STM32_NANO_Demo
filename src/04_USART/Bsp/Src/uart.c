/**
* @file uart.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/24 21:40
* @description: 
**/
#include "uart.h"
#include <stdio.h>
#include <string.h>
#include "led.h"
/**
 * @brief
 * @return
 */
HAL_StatusTypeDef uart_send() {

    HAL_StatusTypeDef ret;
    uint8_t byteNumber = 0x5a;
    uint8_t byteArray[] = {1, 2, 3, 4, 5};
    char ch = 'a';
    char *str = "hello world!";
    HAL_UART_Transmit(&huart1, &byteNumber, 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, byteArray, 5, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    ret = HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);

    return ret;
}

/**
 * @brief
 * @return
 */
HAL_StatusTypeDef uart_recv() {
    uint8_t dataRecv;
    HAL_UART_Receive(&huart1, &dataRecv, 1, HAL_MAX_DELAY);
    if(dataRecv == '0') {
        LED0_OFF;
    }
    else if(dataRecv == '1') {
        LED0_ON;
    }
    return  0;
}

