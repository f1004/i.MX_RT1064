/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_EMC_01 (coord F3), flexio_i2c_SDA */
#define BOARD_INITPINS_flexio_i2c_SDA_PERIPHERAL                         FLEXIO1   /*!< Device name: FLEXIO1 */
#define BOARD_INITPINS_flexio_i2c_SDA_SIGNAL                                  IO   /*!< FLEXIO1 signal: IO */
#define BOARD_INITPINS_flexio_i2c_SDA_CHANNEL                                 1U   /*!< FLEXIO1 IO channel: 01 */

/* GPIO_EMC_02 (coord F4), flexio_i2c_SCL */
#define BOARD_INITPINS_flexio_i2c_SCL_PERIPHERAL                         FLEXIO1   /*!< Device name: FLEXIO1 */
#define BOARD_INITPINS_flexio_i2c_SCL_SIGNAL                                  IO   /*!< FLEXIO1 signal: IO */
#define BOARD_INITPINS_flexio_i2c_SCL_CHANNEL                                 2U   /*!< FLEXIO1 IO channel: 02 */

/* GPIO_EMC_40 (coord A7), led_red */
#define BOARD_INITPINS_led_red_GPIO                                        GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_led_red_PORT                                        GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_led_red_PIN                                           26U   /*!< GPIO3 pin index: 26 */

/* GPIO_B1_07 (coord B12), led_green */
#define BOARD_INITPINS_led_green_GPIO                                      GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_led_green_PORT                                      GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_led_green_PIN                                         23U   /*!< GPIO2 pin index: 23 */

/* GPIO_EMC_41 (coord C7), led_blue */
#define BOARD_INITPINS_led_blue_GPIO                                       GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_led_blue_PORT                                       GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_led_blue_PIN                                          27U   /*!< GPIO3 pin index: 27 */

/* GPIO_EMC_27 (coord A2), oled_d0 */
#define BOARD_INITPINS_oled_d0_GPIO                                        GPIO4   /*!< GPIO device name: GPIO4 */
#define BOARD_INITPINS_oled_d0_PORT                                        GPIO4   /*!< PORT device name: GPIO4 */
#define BOARD_INITPINS_oled_d0_PIN                                           27U   /*!< GPIO4 pin index: 27 */

/* GPIO_EMC_20 (coord A3), oled_d1 */
#define BOARD_INITPINS_oled_d1_GPIO                                        GPIO4   /*!< GPIO device name: GPIO4 */
#define BOARD_INITPINS_oled_d1_PORT                                        GPIO4   /*!< PORT device name: GPIO4 */
#define BOARD_INITPINS_oled_d1_PIN                                           20U   /*!< GPIO4 pin index: 20 */

/* GPIO_EMC_17 (coord A4), oled_res */
#define BOARD_INITPINS_oled_res_GPIO                                       GPIO4   /*!< GPIO device name: GPIO4 */
#define BOARD_INITPINS_oled_res_PORT                                       GPIO4   /*!< PORT device name: GPIO4 */
#define BOARD_INITPINS_oled_res_PIN                                          17U   /*!< GPIO4 pin index: 17 */

/* GPIO_EMC_14 (coord B6), oled_dc */
#define BOARD_INITPINS_oled_dc_GPIO                                        GPIO4   /*!< GPIO device name: GPIO4 */
#define BOARD_INITPINS_oled_dc_PORT                                        GPIO4   /*!< PORT device name: GPIO4 */
#define BOARD_INITPINS_oled_dc_PIN                                           14U   /*!< GPIO4 pin index: 14 */

/* GPIO_EMC_39 (coord B7), oled_cs */
#define BOARD_INITPINS_oled_cs_GPIO                                        GPIO3   /*!< GPIO device name: GPIO3 */
#define BOARD_INITPINS_oled_cs_PORT                                        GPIO3   /*!< PORT device name: GPIO3 */
#define BOARD_INITPINS_oled_cs_PIN                                           25U   /*!< GPIO3 pin index: 25 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/