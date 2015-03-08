/*
 * 	This template is for the TM4C launchpad MCU, the TM4C123GH6PM.
 * 	The clock is alredy configured for 80Mhz
 * 	It has alredy TivaWare included.
 *
 * 	You can use it for any TM4C123 series MCU if you change the PART define and variant in the configs.
 * 	For TM4C1294 series it needs a modification on the CPU clock setup, SysCtlClockSet
 * can't be used, instead use SysCtlClockFreqSet.
 * 	Also since this is for the launchpad, if you use a different debugger/programmer, change that on the
 * configs too
 *
 *
 * 	It comes alredy with various includes for some driverlib source files.
 *
 * 	It comes with the system tick set up to call a interrupt every 1mS.
 * 	The interrupt increments the variable millis by 1 every time it's called.
 * 	A delay function "Wait" is implemented for making more precise delays than SysCtlDelay.
 *
 * 	This was made not only for my personal use but also for my Tiva Workshop.
 *
 * 	Lu�s Afonso
 *
 */


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

/*
 * Variable for keeping time
 */
volatile uint32_t millis=0;

/*
 * Interrupt handler for System tick, increments millis by 1 everytime it's called.
 */
void SycTickInt(){
  millis++;
}

/*/
 *
 * This configures the system tick timer to interrupt every 1mS
 * It expects a CPU clock to be at 80Mhz. I don't use SysCtlClockGet to be
 * compatible with all CPU clocks because there is a bug currently with it.
 *
 * The math for the value is
 * CPU_CLOCK / ( 1 / time_unit )
 * time_unit is the time in secondsyou want to be counted, in this case
 * it's 1mS = 0,001.
 */
void SysTickbegin(){
  SysTickPeriodSet(80000);
  SysTickIntRegister(SycTickInt);
  SysTickIntEnable();
   SysTickEnable();
}

/*
 * Delay function.
 * Creates a delay milliseconds if you haven't changed the frequency that the systick interrupts.
 */
void Wait(uint32_t time){
	uint32_t temp = millis;
	while( (millis-temp) < time){
	}	
}


int main(){
	  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	  SysTickbegin();

}

