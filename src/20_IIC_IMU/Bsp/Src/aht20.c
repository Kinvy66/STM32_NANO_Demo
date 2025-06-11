/**
* @file aht20.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/7 21:45
* @description: 
**/
#include "aht20.h"

#define AHT20_ADDRESS 0x70

void AHT20_Init() {
    uint8_t readBuffer;
    HAL_Delay(40);

    I2C_ReadDate(AHT20_ADDRESS, &readBuffer, 1);
    if ((readBuffer & 0x08) == 0x00) {
        uint8_t sendBuffer[3] = {0xBE, 0x08, 0x00};
        I2C_WriteData(AHT20_ADDRESS, sendBuffer, 3);
    }
}

void AHT20_Read(float *Temperature, float *Humidity) {
    uint8_t sendBuffer[3] = {0xAC, 0x33, 0x00};
    uint8_t readBuffer[6];

    I2C_WriteData(AHT20_ADDRESS, sendBuffer, 3);
    HAL_Delay(75);
    I2C_ReadDate(AHT20_ADDRESS, readBuffer, 6);

    if ((readBuffer[0] & 0x80) == 0x00) {
        uint32_t data = 0;
        data = ((uint32_t)readBuffer[3] >> 4) + ((uint32_t)readBuffer[2] << 4) + ((uint32_t)readBuffer[1] << 12);
        *Humidity = data * 100.0f / (1 << 20);

        data = (((uint32_t)readBuffer[3] & 0x0F) << 16) + (((uint32_t)readBuffer[4]) << 8) + (uint32_t)readBuffer[5];
        *Temperature = data * 200.0f / (1 << 20) - 50;
    }
}
