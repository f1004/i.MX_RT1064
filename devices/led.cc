#include "led.h"

// Low level trigger LED
//int LEDInit() {
//  // gpio output config
//  gpio_pin_config_t LED_GPIO_output_config = {
//      kGPIO_DigitalOutput,  // GPIO output direction
//      1,                    // low level
//      kGPIO_NoIntmode       // non interrpt mode
//  };
//
//  GPIO_PinInit(GPIO2, 8, &LED_GPIO_output_config);
//  return 0;
//}

int LEDSwitch() {
  GPIO_PortToggle(GPIO1,1 << 9);
  return 0;
}