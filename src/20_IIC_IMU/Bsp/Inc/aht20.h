/**
* @file aht20.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/7 
* @description: 
**/

#ifndef __AHT20_H
#define __AHT20_H

#include "i2c_soft.h"

void AHT20_Init(void );
void AHT20_Read(float *Temperature, float *Humidity);


#endif //__AHT20_H
