/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMG8
#define PWM_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                              4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_6
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM23)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM23_PF_TIMG8_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOB
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM50)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM50_PF_TIMG8_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_ECO */
#define TIMER_ECO_INST                                                   (TIMG0)
#define TIMER_ECO_INST_IRQHandler                               TIMG0_IRQHandler
#define TIMER_ECO_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define TIMER_ECO_INST_LOAD_VALUE                                         (799U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                         DL_GPIO_PIN_1
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                      (IOMUX_PINCM2)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                       IOMUX_PINCM2_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_FREQUENCY                                           32000000
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOB
#define GPIO_UART_1_TX_PORT                                                GPIOB
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_5
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_4
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM18)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM17)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM18_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM17_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_3 */
#define UART_3_INST                                                        UART3
#define UART_3_INST_FREQUENCY                                           32000000
#define UART_3_INST_IRQHandler                                  UART3_IRQHandler
#define UART_3_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_3_RX_PORT                                                GPIOB
#define GPIO_UART_3_TX_PORT                                                GPIOB
#define GPIO_UART_3_RX_PIN                                        DL_GPIO_PIN_13
#define GPIO_UART_3_TX_PIN                                        DL_GPIO_PIN_12
#define GPIO_UART_3_IOMUX_RX                                     (IOMUX_PINCM30)
#define GPIO_UART_3_IOMUX_TX                                     (IOMUX_PINCM29)
#define GPIO_UART_3_IOMUX_RX_FUNC                      IOMUX_PINCM30_PF_UART3_RX
#define GPIO_UART_3_IOMUX_TX_FUNC                      IOMUX_PINCM29_PF_UART3_TX
#define UART_3_BAUD_RATE                                                (115200)
#define UART_3_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_3_FBRD_32_MHZ_115200_BAUD                                      (23)




/* Defines for SPI_0 */
#define SPI_0_INST                                                         SPI0
#define SPI_0_INST_IRQHandler                                   SPI0_IRQHandler
#define SPI_0_INST_INT_IRQN                                       SPI0_INT_IRQn
#define GPIO_SPI_0_PICO_PORT                                              GPIOA
#define GPIO_SPI_0_PICO_PIN                                       DL_GPIO_PIN_5
#define GPIO_SPI_0_IOMUX_PICO                                   (IOMUX_PINCM10)
#define GPIO_SPI_0_IOMUX_PICO_FUNC                   IOMUX_PINCM10_PF_SPI0_PICO
#define GPIO_SPI_0_POCI_PORT                                              GPIOA
#define GPIO_SPI_0_POCI_PIN                                       DL_GPIO_PIN_4
#define GPIO_SPI_0_IOMUX_POCI                                    (IOMUX_PINCM9)
#define GPIO_SPI_0_IOMUX_POCI_FUNC                    IOMUX_PINCM9_PF_SPI0_POCI
/* GPIO configuration for SPI_0 */
#define GPIO_SPI_0_SCLK_PORT                                              GPIOA
#define GPIO_SPI_0_SCLK_PIN                                       DL_GPIO_PIN_6
#define GPIO_SPI_0_IOMUX_SCLK                                   (IOMUX_PINCM11)
#define GPIO_SPI_0_IOMUX_SCLK_FUNC                   IOMUX_PINCM11_PF_SPI0_SCLK
#define GPIO_SPI_0_CS0_PORT                                               GPIOA
#define GPIO_SPI_0_CS0_PIN                                        DL_GPIO_PIN_2
#define GPIO_SPI_0_IOMUX_CS0                                     (IOMUX_PINCM7)
#define GPIO_SPI_0_IOMUX_CS0_FUNC                      IOMUX_PINCM7_PF_SPI0_CS0



/* Port definition for Pin Group GPIO_ENCODER */
#define GPIO_ENCODER_PORT                                                (GPIOB)

/* Defines for PIN_A_L: GPIOB.23 with pinCMx 51 on package pin 22 */
// pins affected by this interrupt request:["PIN_A_L","PIN_B_L","PIN_A_R","PIN_B_R"]
#define GPIO_ENCODER_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_ENCODER_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_ENCODER_PIN_A_L_IIDX                           (DL_GPIO_IIDX_DIO23)
#define GPIO_ENCODER_PIN_A_L_PIN                                (DL_GPIO_PIN_23)
#define GPIO_ENCODER_PIN_A_L_IOMUX                               (IOMUX_PINCM51)
/* Defines for PIN_B_L: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_ENCODER_PIN_B_L_IIDX                           (DL_GPIO_IIDX_DIO27)
#define GPIO_ENCODER_PIN_B_L_PIN                                (DL_GPIO_PIN_27)
#define GPIO_ENCODER_PIN_B_L_IOMUX                               (IOMUX_PINCM58)
/* Defines for PIN_A_R: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_ENCODER_PIN_A_R_IIDX                            (DL_GPIO_IIDX_DIO1)
#define GPIO_ENCODER_PIN_A_R_PIN                                 (DL_GPIO_PIN_1)
#define GPIO_ENCODER_PIN_A_R_IOMUX                               (IOMUX_PINCM13)
/* Defines for PIN_B_R: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_ENCODER_PIN_B_R_IIDX                           (DL_GPIO_IIDX_DIO14)
#define GPIO_ENCODER_PIN_B_R_PIN                                (DL_GPIO_PIN_14)
#define GPIO_ENCODER_PIN_B_R_IOMUX                               (IOMUX_PINCM31)
/* Defines for AIN1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define TB6612_AIN1_PORT                                                 (GPIOB)
#define TB6612_AIN1_PIN                                          (DL_GPIO_PIN_8)
#define TB6612_AIN1_IOMUX                                        (IOMUX_PINCM25)
/* Defines for AIN2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define TB6612_AIN2_PORT                                                 (GPIOA)
#define TB6612_AIN2_PIN                                         (DL_GPIO_PIN_12)
#define TB6612_AIN2_IOMUX                                        (IOMUX_PINCM34)
/* Defines for BIN1: GPIOA.7 with pinCMx 14 on package pin 49 */
#define TB6612_BIN1_PORT                                                 (GPIOA)
#define TB6612_BIN1_PIN                                          (DL_GPIO_PIN_7)
#define TB6612_BIN1_IOMUX                                        (IOMUX_PINCM14)
/* Defines for BIN2: GPIOA.18 with pinCMx 40 on package pin 11 */
#define TB6612_BIN2_PORT                                                 (GPIOA)
#define TB6612_BIN2_PIN                                         (DL_GPIO_PIN_18)
#define TB6612_BIN2_IOMUX                                        (IOMUX_PINCM40)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_ECO_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_3_init(void);
void SYSCFG_DL_SPI_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
