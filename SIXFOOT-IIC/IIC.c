#include <IIC.h>
#include <delay.h>
GPIO_InitTypeDef iic1;
GPIO_InitTypeDef RST;

void IIC_INIT()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	iic1.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	iic1.Mode = GPIO_MODE_OUTPUT_OD;
	iic1.Pull = GPIO_PULLUP;
	iic1.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &iic1); 
	IIC_SDA(HIGH);
	IIC_SCL(HIGH);
}

void RST_INIT()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	iic1.Pin = GPIO_PIN_5;
	iic1.Mode = GPIO_MODE_OUTPUT_PP;
	iic1.Pull = GPIO_NOPULL;
	iic1.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &iic1); 
}

void IIC_START()
{
	SDA1_OUT();
	IIC_SDA(HIGH);
	IIC_SCL(HIGH);
	delay_us(4);
	IIC_SDA(LOW);
	delay_us(4);
	IIC_SCL(LOW);	
}

void IIC_STOP()
{
	SDA1_OUT();
	IIC_SDA(LOW);
	IIC_SCL(HIGH);
	delay_us(4);
	IIC_SDA(HIGH);
	delay_us(4);
}

uint8_t IIC_WAIT_ACK()
{
	uint8_t AckTime;
	SDA1_IN();
	IIC_SDA(HIGH);
	delay_us(1);
	IIC_SCL(HIGH);
	delay_us(1);
	while (READ_SDA)
	{
		AckTime++;
		if (AckTime > 250)
		{
			IIC_STOP();
			return 1;
		}
	}
	IIC_SCL(LOW);
	return 0;
}

void IIC_ACK()
{
	SDA1_OUT();
	IIC_SDA(LOW);
	IIC_SCL(LOW);
	delay_us(2);
	IIC_SCL(HIGH);
	delay_us(2);
	IIC_SCL(LOW);
}

void IIC_NACK()
{
	SDA1_OUT();
	IIC_SCL(LOW);
	IIC_SDA(HIGH);
	delay_us(2);
	IIC_SCL(HIGH);
	delay_us(2);
	IIC_SCL(LOW);
}

void IIC_SEND_BATE(uint8_t txd)
{
	uint8_t t;
	SDA1_OUT();
	IIC_SCL(LOW);
	for (t = 0;t < 8;t++)
	{
		IIC_SDA((txd & 0x80) >> 7); 
		txd <<= 1; 
		delay_us(2); 
		IIC_SCL(HIGH);
		delay_us(2);  
		IIC_SCL(LOW);  
		delay_us(2);
	}
}

uint8_t IIC_READ_BYTE(unsigned char ack)
{
	unsigned char i, receive = 0;
	SDA1_IN();
	for (i = 0; i < 8; i++) 
	{
		IIC_SCL(LOW);  
		delay_us(2);
		IIC_SCL(HIGH);
		receive <<= 1;  
		if (READ_SDA) receive++; 
		delay_us(1); 
	}
	if (!ack) IIC_NACK(); 
	else IIC_ACK();
	return receive;
}

void WriteCmd(uint8_t command)
{
	IIC_START();
	IIC_SEND_BATE(0x78);//OLEDµØÖ·
	IIC_WAIT_ACK();
	IIC_SEND_BATE(0x00);//¼Ä´æÆ÷µØÖ·
	IIC_WAIT_ACK();
	IIC_SEND_BATE(command);
	IIC_WAIT_ACK();
	IIC_STOP();
}

void WriteDat(uint8_t data)
{
	IIC_START();
	IIC_SEND_BATE(0x78);//OLEDµØÖ·
	IIC_WAIT_ACK();
	IIC_SEND_BATE(0x40);//¼Ä´æÆ÷µØÖ·
	IIC_WAIT_ACK();
	IIC_SEND_BATE(data);
	IIC_WAIT_ACK();
	IIC_STOP();
}
