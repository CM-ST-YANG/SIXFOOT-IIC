#include <stm32f4xx_hal.h>
#include <stm32_hal_legacy.h>
#include ""
uint32_t i=500;
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

//	__GPIOE_CLK_ENABLE();
//	GPIO_InitTypeDef GPIO_InitStructure;
//
//	GPIO_InitStructure.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
//
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
//
//	for (;;)
//	{
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET);
//		HAL_Delay(i);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
//		HAL_Delay(i);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);
//		HAL_Delay(i);
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//		HAL_Delay(i);
//	}
}
