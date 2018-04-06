#include <stm32f4xx_hal.h>
#include <stm32_hal_legacy.h>
#include "SPI.h"
#include "OLEDUPT.h"
uint16_t SPI_CS=0x00;
#ifdef __cplusplus
extern "C"
#endif
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

int main(void)
{
	HAL_Init();
	spi1_init();
	while (1);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //5ms

{	
	if (htim->Instance == TIM3)
	{
		TIM3_Handler();
	}
}