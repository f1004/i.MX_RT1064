#include "clock_config.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_video_common.h"
#include "delay.h"
#include "led.h"
#include "oled.h"
#include "fsl_qtmr.h"

#define test_num 3

#if test_num == 0
//gpio test
int main()
{
    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();
    BOARD_InitPins();
    
//    LEDInit();
    for (;;)
    {
        LEDSwitch();
        VIDEO_DelayMs(1000);
    }
    return 0;
}
#endif

#if test_num == 1
// oled test
#define NVIC_Group2 0x05
int main()
{
    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();
    BOARD_InitPins();
    
    uint8_t t;
    OLED_Init(); //初始化OLED
    //NVIC_SetPriorityGrouping(NVIC_Group2);
    OLED_Clear();
    t = ' ';
    LEDInit();
    LEDColor(red);
    while (1)
    {
        LEDColor(black);
        OLED_Clear();
        OLED_ShowString(0, 0, "Plectranthus_fg?");
        OLED_ShowString(0, 6, "ASCII:");
        OLED_ShowString(63, 6, "CODE:");
        OLED_ShowChar(48, 6, t); //显示ASCII字符
        t++;
        if (t > '~')
            t = ' ';
        OLED_ShowNum(103, 6, t, 3, 16); //显示ASCII字符的码值
        LEDColor(green);
        VIDEO_DelayMs(100);
        OLED_Clear();
    }
}
#endif

#if test_num == 2

#include "fsl_flexio_i2c_master.h"
#include <string>

// volatile bool completionFlag = false;

// void L3G4200_MasterCallback(FLEXIO_I2C_Type *base, flexio_i2c_master_handle_t *L3G4200_handle, status_t status, void *userData)
// {
//     userData = userData;
//     if (kStatus_Success == status)
//     {
//         completionFlag = true;
//     }
// }
#define NVIC_Group2 0x05
int main()
{
    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();

    // NVIC_SetPriorityGrouping(NVIC_Group2);
    uint8_t data[1] = {0};
    OLED_Init();
    OLED_ShowString(0, 0, "OLED ON");

    // flexio_i2c_master_handle_t L3G4200_handle;
    // FLEXIO_I2C_MasterTransferCreateHandle(&L3G4200_peripheralConfig, &L3G4200_handle, L3G4200_MasterCallback, NULL);

    flexio_i2c_master_transfer_t L3G4200_transfer;
    L3G4200_transfer.slaveAddress = 0b11010000;
    L3G4200_transfer.subaddress = (uint32_t)0x0F;
    L3G4200_transfer.direction = kFLEXIO_I2C_Read;
    L3G4200_transfer.data = data;
    L3G4200_transfer.dataSize = 1U;
    L3G4200_transfer.flags = 0;
    OLED_ShowString(0,6,"Transfer start");
    if (FLEXIO_I2C_MasterTransferBlocking(&L3G4200_peripheralConfig, &L3G4200_transfer) == kStatus_Fail)
    {
        OLED_ShowString(0, 3, "Transfer failed");
    }
    else
    {
        std::string buf = std::to_string((unsigned)data);
        OLED_ShowString(0, 9, (char *)buf.c_str());
    }
    return 0;
}

#endif

#if test_num == 3
// pit test
int count = 0;
int main() {
    DisableGlobalIRQ();
    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();
    BOARD_InitPins();
    
    EnableGlobalIRQ(0);

    for (;;)
    {
        LEDSwitch();
        VIDEO_DelayMs(100);


    }
    return 0;
}

#endif

#if test_num  == 4

#endif