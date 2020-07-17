#include "peripherals.h"
#include "irq_handles.h"
#ifdef __cplusplus
extern "C" {
#endif
void PIT_1_IRQHANDLER(void) {
  if (PIT_GetStatusFlags(PIT_1_PERIPHERAL, kPIT_Chnl_0)) {
    PIT_ClearStatusFlags(PIT_1_PERIPHERAL, kPIT_Chnl_0, kPIT_TimerFlag);
    count = QTMR_GetCurrentTimerCount(QUADTIMER_1_PERIPHERAL,
                                      QUADTIMER_1_CHANNEL_0_CHANNEL);
    if (QTMR_GetStatus(QUADTIMER_1_PERIPHERAL, QUADTIMER_1_CHANNEL_0_CHANNEL) &
        0x8) {
      count = -1 * (UINT16_MAX - count);
      QTMR_ClearStatusFlags(QUADTIMER_1_PERIPHERAL,
                            QUADTIMER_1_CHANNEL_0_CHANNEL, kQTMR_OverflowFlag);
    }
    QUADTIMER_1_PERIPHERAL->CHANNEL[QUADTIMER_1_CHANNEL_0_CHANNEL].CNTR = 0x00;
  }
  __DSB();
}
#ifdef __cplusplus
}
#endif