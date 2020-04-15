#ifndef _LED_H_
#define _LED_H_
#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        white = 0,  //白色
        black = 1,  //黑色
        red = 2,    //红
        green = 3,  //绿
        blue = 4,   //蓝色
        yellow = 5, //黄色
        violet = 6, //紫色
        cyan = 7,   //青色
    } LED_t;

    int LEDInit();
    void LEDColor(LED_t color);
#ifdef __cplusplus
}
#endif
#endif

#include "fsl_gpio.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"
#include "fsl_video_common.h"

#include "MIMXRT1064.h"
