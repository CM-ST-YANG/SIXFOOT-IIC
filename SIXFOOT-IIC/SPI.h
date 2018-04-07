#ifndef __SPI1_H__
#define __SPI1_H__

#ifdef __cplusplus
extern "C" {
#endif
	 
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "system_stm32f4xx.h"  
	
#define SPIFT1_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET)
#define SPIFT1_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET)
	
#define SPIFT2_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)
#define SPIFT2_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)

#define SPIFT3_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET)
#define SPIFT3_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET)

#define SPIFT4_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET)
#define SPIFT4_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET)
	
#define SPIFT5_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET)
#define SPIFT5_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET)

#define SPIFT6_HIGH()  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET)
#define SPIFT6_LOW()   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET)
	


	void SET_CS(uint16_t val);
	void spi1_init(void);
	uint8_t SPI1_WriteRead(uint8_t Byte);
	void SIXFOOT_SENT(uint8_t SFSPI[5], uint8_t recieve[5]);

#ifdef __cplusplus
}
#endif

#endif
