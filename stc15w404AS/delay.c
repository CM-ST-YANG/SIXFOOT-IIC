
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/


/*************	����˵��	**************

���ļ�ΪSTC15xxxϵ�е���ʱ����,�û��������Բ��޸��������.


******************************************/

#include	"delay.h"



//========================================================================
// ����: void  delay_ms(unsigned char ms)
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~255ms. �Զ���Ӧ��ʱ��.
// ����: none.
// �汾: VER1.0
// ����: 2013-4-1
// ��ע: 
//========================================================================
void  delay_ms(unsigned char ms)
{
     unsigned int i;
	 do{
	      i = MAIN_Fosc / 13000;
		  while(--i)	;   //14T per loop
     }while(--ms);
}
void Delay1us(unsigned char us )
{
   unsigned char i;
   switch(us)
   {
     case 1: _nop_();_nop_();_nop_();break;
	 case 2:                        i = 3; while (--i);break;
	 case 3:_nop_();_nop_();_nop_();i = 5; while (--i);break;
	 case 4:_nop_();_nop_();        i = 8; while (--i);break;
	 case 5:_nop_();                i = 11;while (--i);break;
	 case 6:                        i = 14;while (--i);break;
	 case 7:_nop_();_nop_();_nop_();i = 16;while (--i);break;
	 case 8:_nop_();_nop_();        i = 19;while (--i);break;
	 case 9:_nop_();_nop_();        i = 22;while (--i);break;
	 default: ;
   }
}

