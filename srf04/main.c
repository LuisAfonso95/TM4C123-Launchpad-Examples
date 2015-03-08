#define PART_TM4C123GH6PM

#include <stdint.h>
#include <stdbool.h>
#include "stdlib.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_timer.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_pwm.h"
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"

#include "driverlib/timer.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/pwm.h"
#include "driverlib/ssi.h"
#include "driverlib/systick.h"


#include "utils/uartstdio.c"
#include <string.h>


void inputInt();
void Captureinit();
void InitConsole(void);

//This is to avoid doing the math everytime you do a reading
const double temp = 1.0/80.0;

//Stores the pulse length
volatile uint32_t pulse=0;

//Tells the main code if the a pulse is being read at the moment
volatile uint8_t echowait=0;

int main()
{
 //Set system clock to 80Mhz
  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

  //Configures the UART
  InitConsole();

  //Configures the timer
  Captureinit();

  //Configure Trigger pin
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlDelay(3);
  GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3);

  //Configure Echo pin
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlDelay(3);
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2);
  GPIOIntEnable(GPIO_PORTA_BASE, GPIO_PIN_2);
  GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_2,GPIO_BOTH_EDGES);
  GPIOIntRegister(GPIO_PORTA_BASE,inputInt);


  while(1)
  {

    //Checks if a pulse read is in progress
    if(echowait != 1){
      //Does the required pulse of 10uS
      GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);
      SysCtlDelay(266);
      GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, ~GPIO_PIN_3);

      /*
        This makes the code wait for a reading to finish
        You can omit this part if you want the code to be non-blocking but
        reading is only ready when echowait=0.
      */
      while(echowait != 0);

      //Converts the counter value to cm.
      pulse =(uint32_t)(temp * pulse);
      pulse = pulse / 58;

      //Prints out the distance measured.
      UARTprintf("distance = %2dcm \n" , pulse);
    }
      //wait about 10ms until the next reading.
      SysCtlDelay(400000);


  }
}
void inputInt(){
  //Clear interrupt flag. Since we only enabled on this is enough
  GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_2);

  /*
    If it's a rising edge then set he timer to 0
    It's in periodic mode so it was in some random value
  */
  if ( GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_2) == GPIO_PIN_2){
	HWREG(TIMER2_BASE + TIMER_O_TAV) = 0; //Loads value 0 into the timer.
    TimerEnable(TIMER2_BASE,TIMER_A);
    echowait=1;
  }
  /*
    If it's a falling edge that was detected, then get the value of the counter
  */
  else{
    pulse = TimerValueGet(TIMER2_BASE,TIMER_A); //record value
    TimerDisable(TIMER2_BASE,TIMER_A);
    echowait=0;
  }


}
void Captureinit(){
  /*
    Set the timer to be periodic.
  */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
  SysCtlDelay(3);
  TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC_UP);
  TimerEnable(TIMER2_BASE,TIMER_A);
}

void InitConsole(void)
{
    //
    // Enable GPIO port A which is used for UART0 pins.
    // TODO: change this to whichever GPIO port you are using.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlDelay(3);

    //
    // Configure the pin muxing for UART0 functions on port A0 and A1.
    // This step is not necessary if your part does not support pin muxing.
    // TODO: change this to select the port/pin you are using.
    //
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    //
    // Enable UART0 so that we can configure the clock.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //
    // Select the alternate (UART) function for these pins.
    // TODO: change this to select the port/pin you are using.
    //
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 115200, 16000000);

}
