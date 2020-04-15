
#include "delay.h"
#include "fsl_video_common.h"
#if defined(FSL_RTOS_FREE_RTOS)
#include "FreeRTOS.h"
#include "task.h"
#endif

void Delayus(uint32_t us)
{
#if defined(FSL_RTOS_FREE_RTOS)
    TickType_t tick;

    tick = us * configTICK_RATE_HZ / 1000000;

    tick = (0 == tick) ? 1 : tick;

    vTaskDelay(tick);
#else
    uint32_t i;
    uint32_t loopPerus = SystemCoreClock / 3000000;

    while (us--)
    {
        i = loopPerus;
        while (i--)
        {
            __NOP();
        }
    }
#endif
}

void delay_ms(uint32_t ms)
{
#if defined(FSL_RTOS_FREE_RTOS)
    TickType_t tick;

    tick = ms * configTICK_RATE_HZ / 1000;

    tick = (0 == tick) ? 1 : tick;

    vTaskDelay(tick);
#else
    uint32_t i;
    uint32_t loopPerMs = SystemCoreClock / 3000;

    while (ms--)
    {
        i = loopPerMs;
        while (i--)
        {
            __NOP();
        }
    }
#endif
}