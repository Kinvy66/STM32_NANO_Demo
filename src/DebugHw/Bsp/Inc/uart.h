/**
* @file uart.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/24 
* @description: 
**/

#ifndef __UART_H
#define __UART_H
#include "usart.h"

HAL_StatusTypeDef uart_send();
HAL_StatusTypeDef uart_recv();

#endif //__UART_H
