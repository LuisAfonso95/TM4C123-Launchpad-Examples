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
//about 2ms at 80Mhz
#define time 56666


void SycTickInt(){
  millis++;
}
void SysTickbegin(){
  SysTickPeriodSet(80000);
  SysTickIntRegister(SycTickInt);
  SysTickIntEnable();
   SysTickEnable();
}

void Wait(uint32_t _time){
	uint32_t temp = millis;
	while( (millis-temp) < _time){
	}	
}


//PWM frequency in hz
uint32_t freq = 100000;

int main()
{

  //Set system clock to 80Mhz
  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
  SysTickbegin();

  uint32_t Period, dutyCycle;
  Period = SysCtlClockGet()/freq ;
  dutyCycle = Period-2;

  /*
    Configure PF1 as T0CCP1
    Configure PF2 as T1CCP0
    Configure PF3 as T1CCP1
  */

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  SysCtlDelay(3);
  GPIOPinConfigure(GPIO_PF1_T0CCP1);
  GPIOPinConfigure(GPIO_PF2_T1CCP0);
  GPIOPinConfigure(GPIO_PF3_T1CCP1);
  GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
  //

  /*
    Configure timer 0 to split pair and timer B in PWM mode
    Set period and starting duty cycle.
  */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
  SysCtlDelay(3);
  TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);
  TimerLoadSet(TIMER0_BASE, TIMER_B, Period -1);
  TimerMatchSet(TIMER0_BASE, TIMER_B, dutyCycle); // PWM


  /*
    Configure timer 1 to split pair and timer A and B in PWM mode
    Set period and starting duty cycle.
  */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
  SysCtlDelay(3);
  TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM);
  TimerLoadSet(TIMER1_BASE, TIMER_A, Period -1);
  TimerLoadSet(TIMER1_BASE, TIMER_B, Period -1);
  TimerMatchSet(TIMER1_BASE, TIMER_A, dutyCycle);
  TimerMatchSet(TIMER1_BASE, TIMER_B, dutyCycle);

  //Turn on both timers
  TimerEnable(TIMER0_BASE, TIMER_B);
  TimerEnable(TIMER1_BASE, TIMER_A|TIMER_B);

  int i;
  //Start by rising Red LED
  for(i=Period-2; i >  0;i--){
    TimerMatchSet(TIMER0_BASE, TIMER_B, i);
    SysCtlDelay(time);
  }
  while(1){

    //Blue brightness goes up - PF2
    for(i=Period-2; i > 0;i--){
      TimerMatchSet(TIMER1_BASE, TIMER_A, i);
      SysCtlDelay(time);
    }
    //Red brightness goes down - PF1
    for(i=1; i < Period-1; i++){
      TimerMatchSet(TIMER0_BASE, TIMER_B, i);
      SysCtlDelay(time);
    }
    //Green brightness goes up - PF3
    for(i=Period-2; i >  0;i--){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i);
      SysCtlDelay(time);
    }
    //Blue brightness goes down - PF2
    for(i=1; i < Period-1; i++){
      TimerMatchSet(TIMER1_BASE, TIMER_A, i);
      SysCtlDelay(time);
    }
    //Red brightness goes up - PF1
    for(i=Period-2; i > 0;i--){
      TimerMatchSet(TIMER0_BASE, TIMER_B, i);
      SysCtlDelay(time);
    }
    //Green brightness goes down - PF3
    for(i=1; i < Period-1; i++){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i);
      SysCtlDelay(time);
    }
  }

}












