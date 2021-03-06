/*
 * This file is part of the OpenMV project.
 *
 * Copyright (c) 2013-2019 Ibrahim Abdelkader <iabdalkader@openmv.io>
 * Copyright (c) 2013-2019 Kwabena W. Agyeman <kwagyeman@openmv.io>
 *
 * This work is licensed under the MIT license, see the file LICENSE for details.
 *
 * Board configuration and pin definitions.
 */
#ifndef __OMV_BOARDCONFIG_H__
#define __OMV_BOARDCONFIG_H__

// Architecture info
#define OMV_ARCH_STR            "OMV3 F7 512" // 33 chars max
#define OMV_BOARD_TYPE          "M7"
#define OMV_UNIQUE_ID_ADDR      0x1FF0F420

// Flash sectors for the bootloader.
// Flash FS sector, main FW sector, max sector.
#define OMV_FLASH_LAYOUT        {1, 4, 11}

#define OMV_XCLK_MCO            (0U)
#define OMV_XCLK_TIM            (1U)

// Sensor external clock source.
#define OMV_XCLK_SOURCE         (OMV_XCLK_TIM)

// Sensor external clock timer frequency.
#define OMV_XCLK_FREQUENCY      (9000000)

// Sensor PLL register value.
#define OMV_OV7725_PLL_CONFIG   (0x81)  // x6

// Sensor Banding Filter Value
#define OMV_OV7725_BANDING      (0x8F)

// Bootloader LED GPIO port/pin
#define OMV_BOOTLDR_LED_PIN     (GPIO_PIN_1)
#define OMV_BOOTLDR_LED_PORT    (GPIOC)

// RAW buffer size
#define OMV_RAW_BUF_SIZE        (307200)

// If buffer size is bigger than this threshold, the quality is reduced.
// This is only used for JPEG images sent to the IDE not normal compression.
#define JPEG_QUALITY_THRESH     (160*120*2)

// Low and high JPEG QS.
#define JPEG_QUALITY_LOW        35
#define JPEG_QUALITY_HIGH       60

// FB Heap Block Size
#define OMV_UMM_BLOCK_SIZE      16

// Linker script constants (see the linker script template stm32fxxx.ld.S).
// Note: fb_alloc is a stack-based, dynamically allocated memory on FB.
// The maximum available fb_alloc memory = FB_ALLOC_SIZE + FB_SIZE - (w*h*bpp).
#define OMV_FB_MEMORY       SRAM1   // Framebuffer, fb_alloc
#define OMV_MAIN_MEMORY     CCM     // data, bss, stack and heap
#define OMV_DMA_MEMORY      CCM     // Misc DMA buffers

#define OMV_FB_SIZE         (301K)  // FB memory: header + VGA/GS image
#define OMV_FB_ALLOC_SIZE   (83K)   // minimum fb alloc size
#define OMV_STACK_SIZE      (4K)
#define OMV_HEAP_SIZE       (54K)

#define OMV_LINE_BUF_SIZE   (3K)    // Image line buffer round(640 * 2BPP * 2 buffers).
#define OMV_MSC_BUF_SIZE    (2K)    // USB MSC bot data
#define OMV_VFS_BUF_SIZE    (1K)    // VFS sturct + FATFS file buffer (624 bytes)
#define OMV_FFS_BUF_SIZE    (32K)   // Flash filesystem cache
#define OMV_JPEG_BUF_SIZE   (22 * 1024) // IDE JPEG buffer (header + data).

#define OMV_BOOT_ORIGIN     0x08000000
#define OMV_BOOT_LENGTH     32K
#define OMV_TEXT_ORIGIN     0x08020000
#define OMV_TEXT_LENGTH     1920K
#define OMV_CCM_ORIGIN      0x20000000
#define OMV_CCM_LENGTH      128K    // Note DTCM/ITCM memory is not cacheable on M7
#define OMV_SRAM1_ORIGIN    0x20020000
#define OMV_SRAM1_LENGTH    384K

/* SCCB/I2C */
#define SCCB_I2C                (I2C1)
#define SCCB_AF                 (GPIO_AF4_I2C1)
#define SCCB_CLK_ENABLE()       __I2C1_CLK_ENABLE()
#define SCCB_CLK_DISABLE()      __I2C1_CLK_DISABLE()
#define SCCB_PORT               (GPIOB)
#define SCCB_SCL_PIN            (GPIO_PIN_8)
#define SCCB_SDA_PIN            (GPIO_PIN_9)
#define SCCB_TIMING             (0x1090699B) // Frequency: 100KHz Rise Time: 100ns Fall Time: 20ns

/* DCMI */
#define DCMI_TIM                (TIM1)
#define DCMI_TIM_PIN            (GPIO_PIN_8)
#define DCMI_TIM_PORT           (GPIOA)
#define DCMI_TIM_AF             (GPIO_AF1_TIM1)
#define DCMI_TIM_CHANNEL        (TIM_CHANNEL_1)
#define DCMI_TIM_CLK_ENABLE()   __TIM1_CLK_ENABLE()
#define DCMI_TIM_CLK_DISABLE()  __TIM1_CLK_DISABLE()
#define DCMI_TIM_PCLK_FREQ()    HAL_RCC_GetPCLK2Freq()

#define DCMI_RESET_PIN          (GPIO_PIN_10)
#define DCMI_RESET_PORT         (GPIOA)

#define DCMI_PWDN_PIN           (GPIO_PIN_5)
#define DCMI_PWDN_PORT          (GPIOB)

#define DCMI_D0_PIN             (GPIO_PIN_6)
#define DCMI_D1_PIN             (GPIO_PIN_7)
#define DCMI_D2_PIN             (GPIO_PIN_0)
#define DCMI_D3_PIN             (GPIO_PIN_1)
#define DCMI_D4_PIN             (GPIO_PIN_4)
#define DCMI_D5_PIN             (GPIO_PIN_6)
#define DCMI_D6_PIN             (GPIO_PIN_5)
#define DCMI_D7_PIN             (GPIO_PIN_6)

#define DCMI_D0_PORT            (GPIOC)
#define DCMI_D1_PORT            (GPIOC)
#define DCMI_D2_PORT            (GPIOE)
#define DCMI_D3_PORT            (GPIOE)
#define DCMI_D4_PORT            (GPIOE)
#define DCMI_D5_PORT            (GPIOB)
#define DCMI_D6_PORT            (GPIOE)
#define DCMI_D7_PORT            (GPIOE)

#define DCMI_HSYNC_PIN          (GPIO_PIN_4)
#define DCMI_VSYNC_PIN          (GPIO_PIN_7)
#define DCMI_PXCLK_PIN          (GPIO_PIN_6)

#define DCMI_HSYNC_PORT         (GPIOA)
#define DCMI_VSYNC_PORT         (GPIOB)
#define DCMI_PXCLK_PORT         (GPIOA)

#define DCMI_RESET_LOW()        HAL_GPIO_WritePin(DCMI_RESET_PORT, DCMI_RESET_PIN, GPIO_PIN_RESET)
#define DCMI_RESET_HIGH()       HAL_GPIO_WritePin(DCMI_RESET_PORT, DCMI_RESET_PIN, GPIO_PIN_SET)

#define DCMI_PWDN_LOW()         HAL_GPIO_WritePin(DCMI_PWDN_PORT, DCMI_PWDN_PIN, GPIO_PIN_RESET)
#define DCMI_PWDN_HIGH()        HAL_GPIO_WritePin(DCMI_PWDN_PORT, DCMI_PWDN_PIN, GPIO_PIN_SET)

#define DCMI_VSYNC_IRQN         EXTI9_5_IRQn
#define DCMI_VSYNC_IRQ_LINE     (7)

#define WINC_SPI                (SPI2)
#define WINC_SPI_AF             (GPIO_AF5_SPI2)
#define WINC_SPI_TIMEOUT        (1000)
// SPI1/2/3 clock source is PCLK1 (54MHz/2 == 27MHz).
#define WINC_SPI_PRESCALER      (SPI_BAUDRATEPRESCALER_2)
#define WINC_SPI_CLK_ENABLE()   __HAL_RCC_SPI2_CLK_ENABLE()

#define WINC_SPI_SCLK_PIN       (GPIO_PIN_13)
#define WINC_SPI_MISO_PIN       (GPIO_PIN_14)
#define WINC_SPI_MOSI_PIN       (GPIO_PIN_15)

#define WINC_SPI_SCLK_PORT      (GPIOB)
#define WINC_SPI_MISO_PORT      (GPIOB)
#define WINC_SPI_MOSI_PORT      (GPIOB)

#define WINC_EN_PIN             (GPIO_PIN_5)
#define WINC_CS_PIN             (GPIO_PIN_12)
#define WINC_RST_PIN            (GPIO_PIN_12)
#define WINC_IRQ_PIN            (pin_D13)

#define WINC_EN_PORT            (GPIOA)
#define WINC_CS_PORT            (GPIOB)
#define WINC_RST_PORT           (GPIOD)

#define WINC_CS_LOW()           HAL_GPIO_WritePin(WINC_CS_PORT, WINC_CS_PIN, GPIO_PIN_RESET)
#define WINC_CS_HIGH()          HAL_GPIO_WritePin(WINC_CS_PORT, WINC_CS_PIN, GPIO_PIN_SET)

#define I2C_PORT                GPIOB
#define I2C_SIOC_PIN            GPIO_PIN_10
#define I2C_SIOD_PIN            GPIO_PIN_11

#define I2C_SIOC_H()            HAL_GPIO_WritePin(I2C_PORT, I2C_SIOC_PIN, GPIO_PIN_SET)
#define I2C_SIOC_L()            HAL_GPIO_WritePin(I2C_PORT, I2C_SIOC_PIN, GPIO_PIN_RESET)

#define I2C_SIOD_H()            HAL_GPIO_WritePin(I2C_PORT, I2C_SIOD_PIN, GPIO_PIN_SET)
#define I2C_SIOD_L()            HAL_GPIO_WritePin(I2C_PORT, I2C_SIOD_PIN, GPIO_PIN_RESET)

#define I2C_SIOD_READ()         HAL_GPIO_ReadPin(I2C_PORT, I2C_SIOD_PIN)
#define I2C_SIOD_WRITE(bit)     HAL_GPIO_WritePin(I2C_PORT, I2C_SIOD_PIN, bit);

#define I2C_SPIN_DELAY          24

#endif //__OMV_BOARDCONFIG_H__
