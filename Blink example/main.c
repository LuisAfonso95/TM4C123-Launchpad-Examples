//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.1.0.12573 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************






//#define PART_TM4C123GH6PM
#include <stdint.h>
#include <stdbool.h>
#include "stdlib.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_timer.h"
#include "inc/hw_types.h"

#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/udma.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"


#include <string.h>

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************

#define LEDbase GPIO_PORTF_BASE
#define LEDred GPIO_PIN_1
#define LEDblue GPIO_PIN_2
#define LEDgreen GPIO_PIN_3

int main(){

  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  SysCtlDelay(3);

  GPIOPinTypeGPIOOutput(LEDbase, LEDred|LEDblue|LEDgreen);

  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
  GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

  uint32_t value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);

   //================Turn on red=======================
          GPIOPinWrite(LEDbase,LEDred, ~0x2);

          //Wait for a button press
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         //Wait for the button to be let go
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
  //=======================================


    while(1){

      //==================Get purple color=======================
      //======================Turn on blue=================
          GPIOPinWrite(LEDbase,LEDblue, LEDblue);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
     //====================================================


     //=================Get blue color==========================
     //======================Turn off red=================
          GPIOPinWrite(LEDbase,LEDred, 0);
          do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
     //===================================================


    //====================Get light blue color==================
    //========================Turn on green===============
          GPIOPinWrite(LEDbase,LEDgreen, LEDgreen);
          do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
     //====================================================


     //=====================Get green color================
     //======================Turn off blue=================
          GPIOPinWrite(LEDbase,LEDblue, 0);
          do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
     //====================================================


     //===============Get yellow color===================
     //================Turn on Red=======================
            GPIOPinWrite(LEDbase,LEDred, LEDred);
            do{
              value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
            } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
    //====================================================


      //====================Get red color===================
      //======================Turn off green=================
          GPIOPinWrite(LEDbase,LEDgreen, 0);
          do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)!=0);
         do{
            value =  GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
          } while ((value&GPIO_PIN_4)==0);
     //======================================================
      }

}































/*#define LED_PERIPH SYSCTL_PERIPH_GPIOD
#define LED_BASE GPIO_PORTD_BASE
#define ButtonBase GPIO_PORTF_BASE
#define RED_LED GPIO_PIN_3
#define BLUE_LED GPIO_PIN_2
#define GREEN_LED GPIO_PIN_1


int main(void)
{
 volatile uint32_t ui32Loop;






  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

  SysCtlPeripheralEnable(LED_PERIPH);
  SysCtlDelay(3);

  GPIOPinTypeGPIOOutput(LED_BASE, RED_LED|BLUE_LED|GREEN_LED);


  while(1){
	  GPIOPinWrite(LED_BASE,GREEN_LED, ~GREEN_LED);
	  SysCtlDelay(13333333);
	  GPIOPinWrite(LED_BASE,GREEN_LED, GREEN_LED);
	  SysCtlDelay(13333333);
  }
    GPIOPinWrite(LED_BASE,RED_LED, RED_LED);
    GPIOPinWrite(LED_BASE,GREEN_LED, ~GREEN_LED);
    GPIOPinWrite(LED_BASE,BLUE_LED, ~BLUE_LED);
    SysCtlDelay(13333333);

  while(1){



    GPIOPinWrite(LED_BASE,GREEN_LED, GREEN_LED);
    SysCtlDelay(13333333);
    GPIOPinWrite(LED_BASE,RED_LED, ~RED_LED);
    SysCtlDelay(13333333);
    GPIOPinWrite(LED_BASE,BLUE_LED, BLUE_LED);
    SysCtlDelay(13333333);
    GPIOPinWrite(LED_BASE,GREEN_LED, ~GREEN_LED);
    SysCtlDelay(13333333);
     GPIOPinWrite(LED_BASE,RED_LED, RED_LED);
    SysCtlDelay(13333333);
     GPIOPinWrite(LED_BASE,BLUE_LED, ~BLUE_LED);
    SysCtlDelay(13333333);
  }

}
*/
