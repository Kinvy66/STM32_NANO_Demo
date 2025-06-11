#include "main.h"
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Ack(void);
uint8_t I2C_WaitAck(void);
void I2C_SendByte(uint8_t SendByte);
uint8_t I2C_ReadByte(void);
uint8_t I2C_WriteData(uint8_t SlaveAddress, uint8_t *Data, uint8_t len);
uint8_t I2C_ReadDate(uint8_t SlaveAddress, uint8_t *Data, uint8_t len);