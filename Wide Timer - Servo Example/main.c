/*
 * main.c
 */
#define PART_TM4C123GH6PM

#include <stdint.h>
#include <stdbool.h>
#include "stdlib.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_timer.h"
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/debug.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include <string.h>

#define  freq  50
#define Period  80000000/freq
#define dutyCycle1 Period-1-80000 //1ms
#define dutyCycle2  Period-1-160000 //2ms
//dutyCycle1 > dutyCycle2

void changeValue(uint32_t pos, uint8_t color, uint32_t brightness){
}

uint32_t ServoWrite(uint32_t valor) {
	uint32_t i = 0;
	i = Period - ( (valor * 444) + 80000);
	TimerMatchSet(WTIMER0_BASE, TIMER_B, i);
}

int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlDelay(3);
	GPIOPinConfigure(GPIO_PC5_WT0CCP1);
	GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_5);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
	SysCtlDelay(3);
	TimerConfigure(WTIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
	TimerLoadSet(WTIMER0_BASE, TIMER_B, Period-1);
	TimerMatchSet(WTIMER0_BASE, TIMER_B, Period-1);

	HWREG(WTIMER0_BASE+TIMER_TBMR_TBMRSU) =1;

	TimerEnable(WTIMER0_BASE, TIMER_B);
	
	uint32_t i = 1;

	while(1){

		for(i = 1; i < 180; i++)
		{
			//TimerDisable(WTIMER0_BASE, TIMER_B);
			ServoWrite(i);
			//TimerEnable(WTIMER0_BASE, TIMER_B);
			SysCtlDelay(26600);
		}
		SysCtlDelay(20000);
		for(i = 180-1; i > 0; i--)
		{
			//TimerDisable(WTIMER0_BASE, TIMER_B);
			ServoWrite(i);
			//TimerEnable(WTIMER0_BASE, TIMER_B);
			SysCtlDelay(26600);
		}
		SysCtlDelay(20000);
	}

	return 0;
}
