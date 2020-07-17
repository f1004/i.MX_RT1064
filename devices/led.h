#include "MIMXRT1064.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "fsl_video_common.h"
#include "pin_mux.h"

#ifndef _LED_H_
#define _LED_H_
#ifdef __cplusplus
extern "C"
{
#endif
    int LEDInit();
    int LEDSwitch();
#ifdef __cplusplus
}
#endif
#endif

