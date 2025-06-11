#include "qmi8658.h"
#include "i2c_soft.h"
uint8_t QMI8658_ReadReg(uint8_t dAddr, uint8_t Reg)
{
    uint8_t Value = 0;
    //1.启动IIC
    I2C_Start();
    //2.写设备地址
    I2C_SendByte((dAddr << 1)|0);
    //3.wait
    if(I2C_WaitAck())
    {
        I2C_Stop();
        return 1;
    }
    //4.寄存器地址
    I2C_SendByte(Reg);
    //5.wait
    if(I2C_WaitAck())
    {
        I2C_Stop();
        return 1;
    }
    //6.启动IIC
    I2C_Start();
    //7.设备地址
    I2C_SendByte((dAddr << 1)|1);
    //8.wait read ack
    if(I2C_WaitAck())
    {
        I2C_Stop();
        return 1;
    }

    Value = I2C_ReadByte();
    //9.stop
    I2C_Stop();
    return Value;
}

void QMI8658_WriteReg(uint8_t dAddr, uint8_t Reg, uint8_t Value)
{
    //1.启动IIC
    I2C_Start();
    //2.写设备地址
    I2C_SendByte((dAddr << 1)|0);
    //3.wait
    while(I2C_WaitAck());
    //4.写寄存器地址
    I2C_SendByte(Reg);
    //5.wait
    I2C_WaitAck();
    //6.写value
    I2C_SendByte(Value);
    //7.wait
    I2C_WaitAck();
    //8.stop
    I2C_Stop();
}

void QMI8658_Init()
{
    uint8_t uChipID = 0;
    uint16_t AX=0,AY=0,AZ=0,GX=0,GY=0,GZ=0;
    // 1.Device Reset & check Device
    QMI8658_WriteReg(QMI8658_DEV,CTRL9,0xA2); //PowerReset
    delay_ms(2000);                           // wait stable
    uChipID = QMI8658_ReadReg(QMI8658_DEV,0x00); // Read ID
    while(uChipID != 0x5) delay_ms(2000);        // device check
    printf("QMC5883 check Pass!:deviceID = 0x%x \r\n",uChipID);

    //2.Device Settings
    QMI8658_WriteReg(QMI8658_DEV,CTRL1,0x40); //地址自增，小端
    QMI8658_WriteReg(QMI8658_DEV,CTRL2,0x33); //配置加速度计 量程+-16g，采样率ODR==1kHZ
    QMI8658_WriteReg(QMI8658_DEV,CTRL3,0x73); //配置陀螺仪  量程±2048 dps ,采样率是940HZ
    QMI8658_WriteReg(QMI8658_DEV,CTRL5,0x0); //不使用低通滤波器
    QMI8658_WriteReg(QMI8658_DEV,CTRL6,0x0); //不使用Motion on Demand
    QMI8658_WriteReg(QMI8658_DEV,CTRL7,0x03); // 使能加速度计和陀螺仪

    delay_ms(2000);

    for(;;){
        AX = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AX_H);
        AX = AX<<8;
        AX = AX | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AX_L);

        AY = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AY_H);
        AY = AY<<8;
        AY = AY | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AY_L);

        AZ = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AZ_H);
        AZ = AZ<<8;
        AZ = AZ | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,AZ_L);

        GX = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GX_H);
        GX = GX<<8;
        GX = GX | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GX_L);

        GY = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GY_H);
        GY = GY<<8;
        GY = GY | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GY_L);

        GZ = (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GZ_H);
        GZ = GZ<<8;
        GZ = GZ | (uint16_t)QMI8658_ReadReg(QMI8658_DEV,GZ_L);

        printf("QMC5883 GX=%d\r\n", GX);
        printf("QMC5883 GY=%d\r\n", GY);
        printf("QMC5883 GZ=%d\r\n", GZ);
        delay_ms(60000);
    }
}

