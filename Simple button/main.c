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


#define Premido 0
#define NaoPremido GPIO_PIN_4

volatile uint32_t millis=0;

void SycTickInt(){
  millis++;
}
void SysTickbegin(){
  SysTickPeriodSet(80000);
  SysTickIntRegister(SycTickInt);
  SysTickIntEnable();
  SysTickEnable();
}

void Wait(uint32_t time){
	uint32_t temp = millis;
	while( (millis-temp) < time){
	}	
}


int main(){
	  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	  SysTickbegin();

	  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	  SysCtlDelay(3);

	  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
	  GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

	  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
	  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_INT_PIN_2);
	  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);


	  uint8_t state=0;
	  while(1){
		 // GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);  // = 000x 0000

		    uint32_t value=0;

		     value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);

		     while((value & GPIO_PIN_4)==NaoPremido) {                // espera que seja premido
		    	 value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);

		     }


			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);
			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);

			do{
				value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
			}while((value & GPIO_PIN_4) == Premido);



		     while((value & GPIO_PIN_4)==NaoPremido){
		    	value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);

		    }

			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);
			 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);


			 do{
			 				value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
			 			}while((value & GPIO_PIN_4) == Premido);

			  while((value & GPIO_PIN_4)==NaoPremido){
					    	value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);


					    	 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
					    				 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
					    				 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);



					    do{
					    		value = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
					    		}while((value & GPIO_PIN_4) == Premido);




	  }

}

