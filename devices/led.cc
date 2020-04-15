#include "led.h"

// Low level trigger LED
int LEDInit()
{
    // IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_07_GPIO2_IO23, 0x10B0u);
    // IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_40_GPIO3_IO26, 0x10B0u);
    // IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_41_GPIO3_IO27, 0x10B0u);

    //gpio output config
    gpio_pin_config_t GPIO_Output_Config = {
        kGPIO_DigitalOutput, //GPIO output direction
        0,                   //low level
        kGPIO_NoIntmode      //non interrpt mode
    };

    GPIO_PinInit(GPIO3, 26, &GPIO_Output_Config); //A7   led red
    GPIO_PinInit(GPIO2, 23, &GPIO_Output_Config); //B12  led green
    GPIO_PinInit(GPIO3, 27, &GPIO_Output_Config); //C7   led blue
    return 0;
}

void LEDColor(LED_t color)
{
    switch (color)
    {
    case white:
        GPIO_PinWrite(GPIO2, 23, 0U);
        GPIO_PinWrite(GPIO3, 26, 0U);
        GPIO_PinWrite(GPIO3, 27, 0U);
        break;
    case black:
        GPIO_PinWrite(GPIO2, 23, 1U);
        GPIO_PinWrite(GPIO3, 26, 1U);
        GPIO_PinWrite(GPIO3, 27, 1U);
        break;
    case red:
        GPIO_PinWrite(GPIO2, 23, 1U);
        GPIO_PinWrite(GPIO3, 26, 0U);
        GPIO_PinWrite(GPIO3, 27, 1U);
        break;
    case green:
        GPIO_PinWrite(GPIO2, 23, 0U);
        GPIO_PinWrite(GPIO3, 26, 1U);
        GPIO_PinWrite(GPIO3, 27, 1U);
        break;
    case blue:
        GPIO_PinWrite(GPIO2, 23, 1U);
        GPIO_PinWrite(GPIO3, 26, 1U);
        GPIO_PinWrite(GPIO3, 27, 0U);
        break;
    case yellow:
        GPIO_PinWrite(GPIO2, 23, 0U);
        GPIO_PinWrite(GPIO3, 26, 0U);
        GPIO_PinWrite(GPIO3, 27, 1U);
        break;
    case violet:
        GPIO_PinWrite(GPIO2, 23, 1U);
        GPIO_PinWrite(GPIO3, 26, 0U);
        GPIO_PinWrite(GPIO3, 27, 0U);
        break;
    case cyan:
        GPIO_PinWrite(GPIO2, 23, 0U);
        GPIO_PinWrite(GPIO3, 26, 1U);
        GPIO_PinWrite(GPIO3, 27, 0U);
        break;
    }
}