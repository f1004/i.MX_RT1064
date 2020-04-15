#ifndef __OLED_H
#define __OLED_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"
#include "fsl_video_common.h"
#include "stdlib.h"
#include "MIMXRT1064.h"
//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0
#define SIZE 16
#define XLevelL 0x00
#define XLevelH 0x10
#define Max_Column 128
#define Max_Row 64
#define Brightness 0xFF
#define X_WIDTH 128
#define Y_WIDTH 64

//-----------------测试LED端口定义----------------
// #define LED_ON GPIO_ResetBits(GPIOB,GPIO_Pin_8)//DC
// #define LED_OFF GPIO_SetBits(GPIOB,GPIO_Pin_8)

//-----------------OLED端口定义----------------

#define OLED_SCLK_Clr() GPIO_PinWrite(GPIO4, 27, 0U) //CLK
#define OLED_SCLK_Set() GPIO_PinWrite(GPIO4, 27, 1U)

#define OLED_SDIN_Clr() GPIO_PinWrite(GPIO4, 20, 0U) //DIN
#define OLED_SDIN_Set() GPIO_PinWrite(GPIO4, 20, 1U)

#define OLED_RST_Clr() GPIO_PinWrite(GPIO4, 17, 0U) //RES
#define OLED_RST_Set() GPIO_PinWrite(GPIO4, 17, 1U)

#define OLED_DC_Clr() GPIO_PinWrite(GPIO4, 14, 0U) //DC
#define OLED_DC_Set() GPIO_PinWrite(GPIO4, 14, 1U)

#define OLED_CS_Clr() GPIO_PinWrite(GPIO3, 25, 0U) //CS
#define OLED_CS_Set() GPIO_PinWrite(GPIO3, 25, 1U)

#define OLED_CMD 0  //写命令
#define OLED_DATA 1 //写数据

//OLED控制用函数

void OLED_WR_Byte(uint8_t dat, uint8_t cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t t);
void OLED_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t dot);
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr);
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size);
void OLED_ShowString(uint8_t x, uint8_t y, char *p);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(uint8_t x, uint8_t y, uint8_t no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);
#ifdef __cplusplus
}
#endif
#endif
