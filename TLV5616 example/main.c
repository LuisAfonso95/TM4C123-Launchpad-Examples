/*
 *
 * This was made to control a TLV5616 DAC by SPI
 *
 * It uses the SSI module:
 *
 *
 * 	Pins used:
 *
 *  TX: PA5
 * 	RX: PA4
 * 	CLK: PA2
 *
 * 	Slave select on chip always on with a pull-up. (remember to use it.)
 *
 * Luís Afonso
 *
 */



#define PART_TM4C123GH6PM

#include <stdint.h>
#include <stdbool.h>
#include "stdlib.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_pwm.h"
#include "inc/hw_types.h"
#include "driverlib/timer.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/pwm.h"
#include "driverlib/ssi.h"
#include "driverlib/systick.h"
#include <string.h>

volatile uint32_t millis=0;

void SycTickInt(){
  millis++;
}
void SysTickbegin(){
  SysTickPeriodSet(80);
  SysTickIntRegister(SycTickInt);
  SysTickIntEnable();
   SysTickEnable();
}

void Wait(uint32_t time){
	uint32_t temp = millis;
	while( (millis-temp) < time){
	}	
}



/*
 * 	This configures the SSI.
 *
 * 	SSI used: SSI0
 *
 * 	TX: PA5
 * 	CLK: PA2
 *
 * 	Clock speed: 20Mhz
 * 	Data Width: 16
 *
 * 	Expects a system clock of 80Mhz.
 *
 * 	SSI0 pins are alredy configured from the get go, but for the example sake they are configured here anyway.
 *
 */
void SPIInit()
{
  // put your setup code here, to run once:
  SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
  SysCtlDelay(3);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlDelay(3);

  GPIOPinConfigure(GPIO_PA5_SSI0TX);
  GPIOPinConfigure(GPIO_PA3_SSI0FSS);
  GPIOPinConfigure(GPIO_PA2_SSI0CLK);

  GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_3|GPIO_PIN_2);



  SSIConfigSetExpClk(SSI0_BASE, 80000000, SSI_FRF_MOTO_MODE_1,SSI_MODE_MASTER, 20000000, 16);

  SSIEnable(SSI0_BASE);
}


/*
 *
 * This function adds configuration bits to the DAC value and sends it.
 *
 */
void DACDataPut(uint32_t data) {

	//set to fast mode and normal operation
	data |= (0x4 << 12);

	SSIDataPut(SSI0_BASE, data);

}

// 400/4095 = 1/20
//

uint32_t step = 1365; // 1365 = 4095/3 - so each for executes 4 times. This makes a simetrical wave
uint32_t time = 200; // in micro-seconds
int main() {
	SysCtlClockSet(
	SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	SysTickbegin();

	SPIInit();

	int i;
	while (1) {
		for (i = 0; i <= 4095; i += step) {

			DACDataPut(i);
			Wait(time);
		}
		for (i=4095 ; i >= 0; i -= step) {

			DACDataPut(i);
			Wait(time);
		}
	}

}

