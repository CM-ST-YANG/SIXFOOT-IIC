#ifndef __IIC1_H__
#define __IIC1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32f4xx_hal.h"
#define HIGH 1
#define LOW 0
#define SDA1_IN() {iic1.Mode = GPIO_MODE_INPUT ;}
#define SDA1_OUT() {iic1.Mode = GPIO_MODE_OUTPUT_OD;}
#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET))
#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET))
#define READ_SDA    HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)
	void IIC_INIT();
	void IIC_START();
	void IIC_STOP();
	uint8_t IIC_WAIT_ACK();
	void IIC_ACK();
	void IIC_NACK();
	void IIC_SEND_BATE(uint8_t txd);
	uint8_t IIC_READ_BYTE(unsigned char ack);
	void WriteCmd(uint8_t command);
	void WriteDat(uint8_t data);
#ifdef __cplusplus
}
#endif

#endif
