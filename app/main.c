/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*******************************************************************************/
#include "debug.h"

/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Return         : None
*******************************************************************************/
void GPIO_Toggle_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int main(void)
{
    int i = 0;

	Delay_Init();
	USART_Printf_Init(115200); /* PA9 default */
	printf("SystemClk:%d\r\n",SystemCoreClock);
	printf("WCH ^V^\r\n");

    GPIO_Toggle_init();

    lcd_init();

    while (1)
    {
        Delay_Ms(250);
        GPIO_WriteBit(GPIOA, GPIO_Pin_3, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
    }

	while(1);
}







