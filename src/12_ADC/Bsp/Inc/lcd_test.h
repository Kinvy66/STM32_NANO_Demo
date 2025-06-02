/**
* @file lcd_test.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/2/27 
* @description: 
**/

#ifndef _LCD_TEST_H
#define _LCD_TEST_H
#include "lcd_spi_169.h"

// LCD测试函数，函数定义在底部
void 	LCD_Test_Clear(void);			// 清屏测试
void 	LCD_Test_Text(void);			   // 文本测试
void 	LCD_Test_Variable (void);	   // 变量显示，包括整数和小数
void 	LCD_Test_Color(void);			// 矩形填充测试
void 	LCD_Test_Grahic(void);		   // 2D图形绘制
void 	LCD_Test_Image(void);			// 图片显示
void  LCD_Test_Direction(void);	   // 更换显示方向
#endif //_LCD_TEST_H
