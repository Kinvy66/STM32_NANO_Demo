#include "qmi8658.h"
#include "i2c_soft.h"
#include "stdio.h"
#include "math.h"
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

void QMI8658_Init() {
    uint8_t uChipID = 0;
    // 读芯片的ID号
    uChipID = QMI8658_ReadReg(QMI8658_SENSOR_ADDR, QMI8658_WHO_AM_I); // Read ID
    while (uChipID != 0x5) {
        HAL_Delay(2000);        // device check
        uChipID = QMI8658_ReadReg(QMI8658_SENSOR_ADDR, QMI8658_WHO_AM_I); // Read ID
        printf("QMI8658 Error %d!\r\n", uChipID);

    }
    printf("QMI8658 OK!\r\n");

    //2.Device Settings
    QMI8658_WriteReg(QMI8658_SENSOR_ADDR, QMI8658_RESET, 0xb0); // 复位
    HAL_Delay(10);
    QMI8658_WriteReg(QMI8658_SENSOR_ADDR, QMI8658_CTRL1, 0x40); // CTRL1 设置地址自动增加
    QMI8658_WriteReg(QMI8658_SENSOR_ADDR, QMI8658_CTRL7, 0x03); // CTRL7 允许加速度和陀螺仪
    QMI8658_WriteReg(QMI8658_SENSOR_ADDR, QMI8658_CTRL2, 0x95); // CTRL2 设置ACC 4g 250Hz
    QMI8658_WriteReg(QMI8658_SENSOR_ADDR, QMI8658_CTRL3, 0xd5); // CTRL3 设置GRY 512dps 250Hz
}

// 读取加速度和陀螺仪寄存器值
void qmi8658_Read_AccAndGry(t_sQMI8658 *p)
{
    uint8_t status, data_ready=0;
    int8_t buf[12];

    status = QMI8658_ReadReg(QMI8658_SENSOR_ADDR, QMI8658_STATUS0); // 读状态寄存器
    if (status & 0x03) // 判断加速度和陀螺仪数据是否可读
        data_ready = 1;
    if (data_ready == 1){  // 如果数据可读
        data_ready = 0;
        for (int i = 0; i < 12; i++) {
            buf[i] =  QMI8658_ReadReg(QMI8658_SENSOR_ADDR, QMI8658_AX_L + i);
        }

        p->acc_x = (int16_t)((buf[1] << 8) | (buf[0] & 0xFF));
        p->acc_y = (int16_t)((buf[3] << 8) | (buf[2] & 0xFF));
        p->acc_z = (int16_t)((buf[5] << 8) | (buf[4] & 0xFF));
        p->gyr_x = (int16_t)((buf[7] << 8) | (buf[6] & 0xFF));
        p->gyr_y = (int16_t)((buf[9] << 8) | (buf[8] & 0xFF));
        p->gyr_z = (int16_t)((buf[11] << 8) | (buf[10] & 0xFF));

        printf("gx:%d, gy:%d, gz:%d\r\n", p->gyr_x, p->gyr_y, p->gyr_z);
    }
}


// 获取XYZ轴的倾角值
void qmi8658_fetch_angleFromAcc(t_sQMI8658 *p)
{
    float temp;

    qmi8658_Read_AccAndGry(p); // 读取加速度和陀螺仪的寄存器值
    // 根据寄存器值 计算倾角值 并把弧度转换成角度
    temp = (float)p->acc_x / sqrt( ((float)p->acc_y * (float)p->acc_y + (float)p->acc_z * (float)p->acc_z) );
    p->AngleX = atan(temp)*57.29578f; // 180/π=57.29578

    temp = (float)p->acc_y / sqrt( ((float)p->acc_x * (float)p->acc_x + (float)p->acc_z * (float)p->acc_z) );
    p->AngleY = atan(temp)*57.29578f; // 180/π=57.29578
    temp = sqrt( ((float)p->acc_x * (float)p->acc_x + (float)p->acc_y * (float)p->acc_y) ) / (float)p->acc_z;
    p->AngleZ = atan(temp)*57.29578f; // 180/π=57.29578

    printf("x:%f, y:%f, z:%f\r\n", p->AngleX, p->AngleY, p->AngleZ);

}