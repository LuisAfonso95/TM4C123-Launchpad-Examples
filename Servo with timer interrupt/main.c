/*
 * 	This code was made in CCS v6 and using TivaWare. All from Texas Instruments
 *
 * 	The code was made to control servos in multiple pins with the help on 1 timer.
 * 	The timer interrupts every 5uS and increments a counter variable. This variable works as load value that sets the period.
 *For 50Hz frequency the value needs to be 4000 (5uS * 4000 = 0.2mS)
 *  There's a array called ServoPos that works like a match value that controls the positive pulse width of the PWM.
 *
 *	The arrays size are made so you can have 6 pins but you can change that. Remember that the more servos you use,
 *the more slow the interrupt is.
 *
 *
 * Luís Afonso
 */

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

volatile uint32_t ServoCount = 0;
uint32_t ServoBase[6];
uint32_t ServoPin[6];
uint32_t ServoPos[6];
uint32_t ServoPosTemp[6];
uint32_t ServoNumber = 0;


void ServoInterrupt(){

	//Remember to clear the interrupt flags
  uint32_t status=0;

  status = TimerIntStatus(TIMER5_BASE,true);
  TimerIntClear(TIMER5_BASE,status);

  /*
   * 	This increments the counter
   *	The counter works like a timer in PWM mode in count up mode.
   * 	The value 4000 sets the wave period.
   *	Then we have the "match" values that set the positive pulse width,
   * those are the values saved in the array ServoPos. The outputs start as HIGH and go to LOW
   * when the match value is reached
   */
  ServoCount++;
  uint32_t i;
  if(ServoCount > 4000)
	  ServoCount = 0;
	  for(i=0; i < ServoNumber; i++){
		  ServoPos[i] = ServoPosTemp[i];
	  }

  for(i=0; i < ServoNumber; i++){
	  if(ServoCount > ServoPos[i])
		  GPIOPinWrite(ServoBase[i],ServoPin[i], 0);
	  else
		  GPIOPinWrite(ServoBase[i],ServoPin[i], ServoPin[i]);
  }
}


/*
 * This function changes the
 *
 */
int32_t ServoWrite(uint32_t value, uint32_t pos){

	/*
	 * Check the counter value and wait for it to roll back to 0
	 * This is a crude way to wait for the end of the PWM period
	 */
	uint32_t temp = ServoCount;
	while(ServoCount >= temp);

	//Check if the values are correct
	if(value > 200)
		return -1;

	//Increment 199 since the real values are from 200 to 400, not 0 to 200
	value = value + 199;

	//Save value in array for the interrupt
	ServoPosTemp[pos] = value;

	return 0;
}

int32_t ServoAttach(uint32_t peripheral, uint32_t base, uint32_t pin){

	//Remember to check if you aren't controling more servos than the arrays can handle
	if(ServoNumber < 6){

		//Enable the GPIO you want to use
		SysCtlPeripheralEnable(peripheral);
		SysCtlDelay(3);
		//Set pin as output
		GPIOPinTypeGPIOOutput(base,pin);
		//Save which GPIO and pin you want to use
		ServoBase[ServoNumber] = base;
		ServoPin[ServoNumber] = pin;

		//Increment variable so we know we have 1 more servo
		ServoNumber++;
	}
	else
		return -1;

	return 0;
}


/*
  Timer setup
*/
void TimerBegin(){


  /*
   * 200Khz - 5uS. (um servo precisa de um pulse de  1000uS a  2000uS ou 1mS a 2mS)
   * 200-400
   */
  //We set the load value so the timer interrupts each 1ms
  uint32_t Period;
  Period = 400;

  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);
  SysCtlDelay(3);
  /*
    Configure the timer as periodic, by omission it's in count down mode.
    It counts from the load value to 0 and then resets back to the load value.
  REMEMBER: You need to configure the timer before setting the load and match
  */
  TimerConfigure(TIMER5_BASE, TIMER_CFG_PERIODIC);
  TimerLoadSet(TIMER5_BASE, TIMER_A, Period -1);

  TimerIntRegister(TIMER5_BASE, TIMER_A, ServoInterrupt);

  /*
    Enable the timeout interrupt. In count down mode it's when the timer reaches
  0 and resets back to load. In count up mode it's when the timer reaches load
  and resets back to 0.
  */
  TimerIntEnable(TIMER5_BASE, TIMER_TIMA_TIMEOUT);

  TimerEnable(TIMER5_BASE, TIMER_A);
}


int main(void) {

	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);


	ServoAttach(SYSCTL_PERIPH_GPIOF,GPIO_PORTF_BASE,GPIO_PIN_1);
	TimerBegin();

	int i=0;
	while(1){
		for(i=0; i < 200 ; i++){
			ServoWrite(i,0);
			SysCtlDelay(300000);
		}
		ServoWrite(0,0);
		SysCtlDelay(3000000);

	}


	//return 0;
}
