#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"

	/* MPU6050 Register Address ------------------------------------------------------------*/
#define	SMPLRT_DIV		0x19	
#define	CONFIG			0x1A	
#define	GYRO_CONFIG		0x1B	
#define	ACCEL_CONFIG	0x1C	
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	
#ifndef __HAL_IIC_H  
#define   __HAL_IIC_H  
  
	
#ifdef __cplusplus
	extern "C" {
#endif
#include "stm32f4xx.h" 
  
/* �ߵ͵�ƽ */  
#define HIGH    1  
#define LOW     0  
  
/* IO�������� */  
#define SDA_IN()  {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=0<<5*2;}       //PH5����ģʽ  
#define SDA_OUT() {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=1<<5*2;}   //PH5���ģʽ  
/* IO���� */  
#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_RESET)) //SCL  
#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_RESET)) //SDA  
#define READ_SDA    HAL_GPIO_ReadPin(GPIOH,GPIO_PIN_5)                  //����SDA    
	void IIC_Init(void);                                        //IIC��ʼ��  
	void IIC_Start(void);                                       //����IIC��ʼ�ź�  
	void IIC_Stop(void);                                        //����IICֹͣ�ź�  
	uint8_t   IIC_Wait_Ack(void);                                    //�ȴ�ACK�źŵ���  
	void IIC_Ack(void);                                         //����ACKӦ��  
	void IIC_NAck(void);                                        //������ACKӦ��  
	void IIC_Send_Byte(uint8_t txd);                                 //IIC����һ���ֽ�  
	uint8_t   IIC_Read_Byte(unsigned char ack);  
#ifdef __cplusplus
}
#endif

#endif