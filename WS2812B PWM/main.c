/*
 * 	This code uses a Timer to generate a PWM of 800Khz to control WS2812B strips.
 * 	A interrupt on the PWM rising edge is used to update the PWM duty according to the array of brightness values.
 *
 * 	For a 800Khz PWM at 80Mhz a value of 100-1 is loaded into the timer.
 * 	A match value of 32 is used to send a 1.
 * 	A match value of 68 is used to send a 0.
 *
 * 	The sending of data keeps the processor busy most of the time, leaving only really short intervals (about 0.5uS) of the
 * 	processor free. This is due to the interrupt firing every 1.25uS and keeping the processor busy about 0.6uS (check interrupt coments)
 * 	For this code i use a function to send data that keeps the code in a empty while, while the data is being sent.
 *
 * 	To change a LED brightness simply change the byte value in the array "values" in the position you want.
 * 	values[0] is the green LED of the first WS2812, values[1] is the red LED of the first WS2812, values[2] is the
 * blue LED of the first WS2812. values[3] is alredy the green LED of the second WS2812, and so on.
 *
 *
 * 	Luís Afonso
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

#define LEDNum  3*60 //Number of LEDs used. Number of WS2812 = Number of LEDs*3
#define CounterMax  LEDNum*8 //Number of bits set so it's Number of LEDs*8
uint8_t values[LEDNum]; //Stores the values of brightness to send

/*
 * Basically a bit counter
 * Needs to start at 0-1. This is because there's a dummy (almost 0% duty) cycle.
 */
volatile uint32_t LEDCounter = 0xFFFFFFFF;

/*
 *
 * Configures the systick to interrupt every 1ms (when clock at 80Mhz)
 *
 */
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
//This waits the number of miliseconds specified by parameter
void Wait(uint32_t time){
	uint32_t temp = millis;
	while( (millis-temp) < time){
	}	
}

/*
 *
 * 	Should take a maximum of 51 cycles (including 22 cycles of interrupt push and pop) in the
 * most important part. The if that is executed in the end of sending data takes much longer but that
 * is not a problem while data is being sent.
 *
 * 	At 80Mhz that should represent 0,6375uS which is less than the 1,25uS maximum. I consider 1 instruction per cycle,
 * note that in the datasheet the MCU has 100 DMIPS.
 *
 * 	 This is not considering pipelining abilities nor the use of pseudo-instructions (that would mean
 * there's more instructions than meets the eye).
 *
 */
void TimerInt(){

	HWREG(TIMER0_BASE + TIMER_O_ICR) = HWREG(TIMER0_BASE + TIMER_O_MIS); //TimerIntClear(TIMER0_BASE, TimerIntStatus(TIMER0_BASE,1));

	LEDCounter++; //Increment bit counter

	/*
	 * If all bits are sent it stops the timer, and sets the output to 0 so the ws2812b aknowledges the values sent.
	 * The pin needs to be set as a Output
	 * Also resets the counter to the inital value of 0xFFFFFFFF
	 */
	if(LEDCounter >= CounterMax){
		TimerDisable(TIMER0_BASE, TIMER_B);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		LEDCounter = 0xFFFFFFFF;
	}
	/*
	 * 	LEDCounter/8 gives the array position (which LED) to send data. Ex: LEDCounter=7, 7/8=0 since it's not a float
	 * 	LEDCounter %8 gives the bit to send in each array position. Ex: LEDCounter=7, 7%8=7.
	 *
	 * 	It's 7-(LEDCounter%8) because the most significant bits need to be sent first. The array could be prepared
	 * so it would not be needed the subtration, but that only adds 1 instruction and there was enough time for that.
	 *
	 * 	The AND operation with 1, isolates the bit. This makes the final result be 1 or 0.
	 * LEDCounter/8 = LEDCounter >> 3
	 * LEDCounter%8 = LEDCounter & 7
	 */
	else{
		if( ( (values[LEDCounter>>3]) >> (7- (LEDCounter & 7)) ) & 1)
		  HWREG(TIMER0_BASE + TIMER_O_TBMATCHR) = 36; // TimerMatchSet(TIMER0_BASE, TIMER_B, 32);
		else
		  HWREG(TIMER0_BASE + TIMER_O_TBMATCHR) = 68; // TimerMatchSet(TIMER0_BASE, TIMER_B, 68);
	}
}

/*
 * 	This sets a PWM output on PF1, timer0B with 800Khz.
 * 	It does not start the timer, it only configures it.
 *
 * 	A Interrupt is set with the PWM rising edge since in PWM mode there isn't a timeout
 * interrupt (at least it didn't work and i also it seemed so in the datasheet)
 *
 * 	I use IntRegister to set the interrupt handler
 */
void PWMInit(){

	uint32_t Period;
	Period = 100 ; //800Khz - 1.25uS


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlDelay(3);
	GPIOPinConfigure(GPIO_PF1_T0CCP1);
	GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	SysCtlDelay(3);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
	TimerLoadSet(TIMER0_BASE, TIMER_B, Period -1);

	//This should make so the match register value only updates after a timeout (after the end of the PWM cycle)
	HWREG(TIMER0_BASE+TIMER_TBMR_TBMRSU) =1;

	TimerIntRegister(TIMER0_BASE,TIMER_B,TimerInt);
	TimerControlEvent(TIMER0_BASE,TIMER_B,TIMER_EVENT_POS_EDGE);
	TimerIntEnable(TIMER0_BASE,TIMER_CAPB_EVENT);

	IntEnable(INT_TIMER0B_TM4C123);

}

/*
 * 	To send new data use this function
 * 	It setups the PF1 as a Timer output again (remember that the interrupt at the end sets it as a GPIO output)
 * 	Enables a dummy cycle with almost 0% duty (Period value = 100-1, and 100% PWM doesn't work so the value 98 is used)
 * 	This waits for all the data to be sent, 90 cycles are waited so the LEDCounter value updates and then it waits for it
 * to return to the inital value. So it blocks the code while the data is being sent
 *
 */
void SendData(){

	GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);
    TimerMatchSet(TIMER0_BASE, TIMER_B, 98);
    TimerEnable(TIMER0_BASE, TIMER_B);
    SysCtlDelay(30);
    while(LEDCounter !=0xFFFFFFFF);

}


uint32_t brilho=255;
uint32_t time = 1000;

int main(){

	//Clock to 80Mhz, start system tick, configure PWM.
	SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	SysTickbegin();
	PWMInit();

	//Set all LEDs to 0
	int i;
	for(i=0; i < LEDNum; i++){
	  values[i]=0;
	}

	/*
	 * the k is used for a test patern. It flashes each LED once at 255 brightness so it can be checked if there is
	 * any "leakage" into other LEDs. Right now that partern is not being used.
	 * Right now all LEDs are geting random values.
	 */
	int k=0;
	while(1){

		if(k !=0)
		  values [k-1]=0;
		else
		  values[LEDNum-1]=0;
		values[k] = 0xFF;
		k++;
		if(k>= LEDNum)
		  k=0;

		/*i;
		for(i=0; i < LEDNum; i++){
		  values[i]=rand()%brilho;
		}*/
		Wait(time); //Stops the code for 200mS

		//Start timer to send data
		SendData();

	}
}

