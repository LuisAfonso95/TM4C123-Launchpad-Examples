/*
 * 	This code was made using CCS V6 with TI compiler
 * 	It used TivaWare APIs to help coding
 *
 * 	This code is to control a WS2812B strip with 30 LEDs. It only supports 1 single output. It was made for
 * 	a hat used in a event.
 * 	It cycles through 5 different patterns and it has accepts a digital input in the PF1. When LOW it would
 * 	increasse the LEDs brightness to the max, when at HIGH it would set the brightness just to 50 out of 255.
 *
 *	I won't explain how i made the Patterns, only the WS2812B control. Sorry if some comments are in portuguese.
 *They are from when i was making the first code.
 *
 *
 */



#include <stdint.h>
#include <stdbool.h>
#include "stdlib.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ssi.h"
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


#define size 90 //number of LEDs

//Needed for some Patterns
#define SireneA 10
#define SireneP 15


uint8_t Maxbrilho = 50; //Sets the maximum brightness
uint32_t values[size]; //Array that stores the values to send to each WS2812B. Each 32bits has the values for the 3 LEDs in a WS2812B

//Needed for patterns. A lazy way of making some patterns
uint8_t Red[1530];
uint8_t Green[1530];
uint8_t Blue[1530];

uint8_t PadraoInit = 0; //Needed. If the same pattern was being repetead over and over again then some things didn't need to be remade
uint8_t MudaPadrao = 0; //This is a flag to say if the button was pressed



/*
 * The folowing are for configuring the systick
 */

//This is the interrupt handler for the SysTick
void SycTickInt(){
  millis++;
}
//This configures the Systick to interrupt every mili-second
void SysTickbegin(){
  SysTickPeriodSet(80000);
  SysTickIntRegister(SycTickInt);
  SysTickIntEnable();
  SysTickEnable();
}
//This funtion works as a delay. It stops the code for the mili-seconds specified by parameter
void Wait(uint32_t time){
	uint32_t temp = millis;
	while( (millis-temp) < time){
	}	
}
/*
 * End of Systick configurations and functions
 */

/*
 * This is the interrupt handler for the button that changes the LEDs brightness
 */
void PortFIntHandler(){
  uint32_t status=0;

  status = GPIOIntStatus(GPIO_PORTF_BASE,true);
  GPIOIntClear(GPIO_PORTF_BASE,status);

  if( GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1) == 0)
	  Maxbrilho = 255;
  else
	  Maxbrilho = 50;
  MudaPadrao = 1;


}

/*
 * 	This configures the SSI.
 * 	Setups only the TX and configures the SSI to work at 6.4Mhz and 8bit packets.
 * 	It's 6.4Mhz because 6.4Mhz/8 is about 800Khz, the frequency needed for the WS2812B
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

  GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5);
  SSIIntClear(SSI0_BASE,SSI_TXEOT);
  SSIConfigSetExpClk(SSI0_BASE, 80000000, SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER, 6400000, 8);
  SSIEnable(SSI0_BASE);
}

/*
 * 	This is used to assist changing the value of the LEDs in the array
 *
 * 	I use a uint32_t to save the values of the 3 LEDs. RED starts at the bit8, Green at bit0 and blue at bit16.
 * It was not the best way to save the values since it wastes 8bits, i should have used 3 arrays of uint8_t but for
 * some reason i tought it was the best way at the time. I made the base of the code just when i started learning to program the SSI.
 * 	First parameter says which WS2812B you want to control, Second it's the color you want to change and lastly it's the value you want it
 * to be.
 */
int LEDNum=0;
int bitNum=23;
void changeValue(uint32_t pos, uint8_t color, uint32_t _brightness){
	  if(color == 'r'){
	    values[pos] &= ~(0xFF << 8);
	    values[pos] +=(_brightness << 8);
	  }
	  else if(color == 'b'){
	    values[pos] &= ~(0xFF);
	    values[pos] +=(_brightness);
	  }
	  else if(color == 'g'){
	    values[pos] &= ~(0xFF << 16);
	    values[pos] += (_brightness << 16);
	  }

}

/*
 * 	This function starts sending new data.
 * 	It loads as fast as it can the FIFO. It's bloking so the processor can't do anything else while doing this
 * 	It works because the FIFO as multiple data values saved up so when it sends one the processor should be waiting for the
 * FIFO to have room for more data.
 *
 * 	It converts the values. Remember that we used 6.4Mhz. Each packet of 8bits represents 1bit for the WS2812B.
 * 	If a value is 1 then it converts it to 0b11111000 which forms the wave required to send a 1 for the WS2812B,
 *if it's 0 then it's to 0b11000000 which represents a 0 for the WS2812B.
 *
 */
void SendData(uint32_t values[],int number){
	int k, i;
  for( k = 0; k < number; k++){
    for( i=23; i >= 0; i--){
      volatile uint8_t convert = 0xC0 ;//0b11000000;
      if((values[k] >> i) & 0x1 != 0){
        convert = 0xF8;// 0b11111000;
      }
      SSIDataPut(SSI0_BASE, convert);
    }
  }
}

/*
 * This changes the array values all to 0 and sends them, doing so it turns off al the LEDs.
 */
void TurnOFFAll(){
	int i;
	if(PadraoInit==0){
		for(i=0; i < size; i+=1){
		  values[i]=0;
		}
		SendData(values,size);
	}
}


void Pattern4(){



	if(PadraoInit==0){
		TurnOFFAll();
		PadraoInit=1;
	}

	int16_t i;
	uint16_t p = 0;
	for(i=0; i <= Maxbrilho; i++){
		Red[p] = Maxbrilho;
		Green[p] = i;
		Blue[p] = 0;
		p++;
	}
	for(i=Maxbrilho; i >= 0; i--){
		Red[p] = i;
		Green[p] = Maxbrilho;
		Blue[p] = 0;
		p++;
	}
	for(i=0; i <= Maxbrilho; i++){
		Red[p] = 0;
		Green[p] = Maxbrilho;
		Blue[p] = i;
		p++;
	}
	for(i=Maxbrilho; i >= 0; i--){
		Red[p] = 0;
		Green[p] = i;
		Blue[p] = Maxbrilho;
		p++;
	}
	for(i=0; i <= Maxbrilho; i++){
		Red[p] = i;
		Green[p] = 0;
		Blue[p] = Maxbrilho;
		p++;
	}
	for(i=Maxbrilho; i >= 0; i--){
		Red[p] = Maxbrilho;
		Green[p] = 0;
		Blue[p] = i;
		p++;
	}

	uint8_t time=7;
	uint16_t diference=20+(Maxbrilho>>4);
	uint16_t step=1+(Maxbrilho>>4);
	uint16_t LedPosition[size];
	uint16_t k=0;
	for(i=0; i <size; i+=1){

		LedPosition[i] =  k;

		k+=diference;
		if(k >= p)
			k=0;
	}



	for(k=0; k < 1000 && MudaPadrao==0; k++){
		for(i=0; i < size/2 && MudaPadrao==0; i+=1){
		  if(LedPosition[i] >= p)
			  LedPosition[i]=0;

	        changeValue(i,'r',Red[LedPosition[i]]);
			changeValue(i,'g',Green[LedPosition[i]]);
			changeValue(i,'b',Blue[LedPosition[i]]);

	        changeValue(size-1-i,'r',Red[LedPosition[i]]);
			changeValue(size-1-i,'g',Green[LedPosition[i]]);
			changeValue(size-1-i,'b',Blue[LedPosition[i]]);
			LedPosition[i]+= step;
		}
		SendData(values,size);

		Wait(time);
	}







}

void Policia(){
	uint8_t brilho = Maxbrilho;
	int i;

	if(PadraoInit==0){
		TurnOFFAll();
		PadraoInit=1;
	}

	uint8_t LedPosition[SireneP];
	for(i=0; i <SireneP; i++)
		LedPosition[i] =  i;
	int k;
	for(k=0; k < 500 && MudaPadrao==0; k++){
		for(i=0; i < SireneP && MudaPadrao==0; i+=1){
		  if(LedPosition[i] >= size)
			  LedPosition[i]=0;
		  changeValue(LedPosition[i],'b',brilho);
		  changeValue(LedPosition[i],'r',0);
		  LedPosition[i]++;
		}

		if(LedPosition[0] !=0){
			changeValue(LedPosition[0]-1,'b',0);
			changeValue(LedPosition[0]-1,'r',brilho);
		}
		else{
			changeValue(size,'b',0);
			changeValue(size,'r',brilho);

		}
		SendData(values,size);

		Wait(25);
	}




}

void Ambulancia(){
	uint8_t brilho = Maxbrilho;
	int i;

	if(PadraoInit==0){
		for(i=0; i < size; i+=1){
		  values[i]=0;
		}
		SendData(values,size);
		PadraoInit=1;
	}

	uint8_t LedPosition[SireneA];
	for(i=0; i <SireneA; i++)
		LedPosition[i] =  i;
	int k;
	for(k=0; k < 500 && MudaPadrao==0; k++){
		for(i=0; i < SireneA && MudaPadrao==0; i+=1){
		  if(LedPosition[i] >= size)
			  LedPosition[i]=0;
		  changeValue(LedPosition[i],'b',brilho);
		  LedPosition[i]++;
		}
		if(LedPosition[0] !=0)
			changeValue(LedPosition[0]-1,'b',0);
		else
			changeValue(size,'b',0);
		SendData(values,size);

		Wait(25);
	}




}



void Pattern3(){
  uint8_t resolution=Maxbrilho;
  int tick=1;
  int time=5;
  int time2= 0;
  int div=1;
  int valor1 =0;
  int valor2 = 0;

	if(PadraoInit==0){
		int i;
		for(i=0; i < size; i+=1){
		  values[i]=0;
		}
		int k;
		  for(k=1; k <= div ; k++){
		    valor1=(k-1)*resolution/div;
		    valor2=(k)*resolution/div;
		    int n;
		    for(n=0; n < size;n++){
		    	int i;
		      for(i=valor1; i <= valor2; i+=tick){
		        changeValue(n,'b',i);

		      }
		      SendData(values,size);
		      if(time !=0)
		        Wait(time);
		      if(time2 !=0)
		        Wait(time2);
		    }
		  }
		SendData(values,size);
		PadraoInit=1;
	}

  int k;

  //==========Sobe vermelho==================
  for(k=1; k <= div; k++){
    valor1=(k-1)*(resolution)/div;
    valor2=(k)*(resolution)/div;
    int n;
    for(n=0; n < size && MudaPadrao==0;n++){
    	int i;
      for(i=valor1; i <= valor2; i+=tick){
        changeValue(n,'r',i);
      }
      SendData(values,size);
      Wait(time);
    }
  }


  //====Desce azul=================
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'b',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
  //==============Sobe verde=======================
  for(k=1; k <= div; k++){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor1; i <= valor2 && MudaPadrao==0; i+=tick){
        changeValue(n,'g',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }

  //=====Desce vermelho=========
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'r',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
  //==========Sobe azul===============
  for(k=1; k <= div; k++){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor1; i <= valor2 && MudaPadrao==0; i+=tick){
        changeValue(n,'b',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }

  //======desce verde========
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'g',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
}


void Pattern2(){
  int resolution=Maxbrilho;
  int tick=1;
  int time=3;
  int time2= 0;
  int div=3;
  int valor1 =0;
  int valor2 = 0;


	if(PadraoInit==0){

		TurnOFFAll();
		int k;
		  for(k=1; k <= div ; k++){
		    valor1=(k-1)*resolution/div;
		    valor2=(k)*resolution/div;
		    int n;
		    for(n=0; n < size;n++){
		    	int i;
		      for(i=valor1; i <= valor2; i+=tick){
		        changeValue(n,'b',i);

		      }
		      SendData(values,size);
		      if(time !=0)
		        Wait(time);
		      if(time2 !=0)
		        Wait(time2);
		    }
		  }
		SendData(values,size);
		PadraoInit=1;
	}

  int k;

  //==========Sobe vermelho==================
  for(k=1; k <= div; k++){
    valor1=(k-1)*(resolution)/div;
    valor2=(k)*(resolution)/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor1; i <= valor2 && MudaPadrao==0; i+=tick){
        changeValue(n,'r',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }


  //====Desce azul=================
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'b',i);

      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
  //==============Sobe verde=======================
  for(k=1; k <= div; k++){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor1; i <= valor2 && MudaPadrao==0; i+=tick){
        changeValue(n,'g',i);
      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }

  //=====Desce vermelho=========
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'r',i);
      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
  //==========Sobe azul===============
  for(k=1; k <= div; k++){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor1; i <= valor2 && MudaPadrao==0; i+=tick){
        changeValue(n,'b',i);
      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }

  //======desce verde========
  for(k=div; k >= 1; k--){
    valor1=(k-1)*resolution/div;
    valor2=(k)*resolution/div;
    int n;
    for(n=0; n < size;n++){
    	int i;
      for(i=valor2; i >= valor1 && MudaPadrao==0; i-=tick){
        changeValue(n,'g',i);
      }
      SendData(values,size);
      if(time !=0)
        Wait(time);
      if(time2 !=0)
        Wait(time2);
    }
  }
}

/*
 * This Pattern was not used
 */
void Pattern1(){
  uint32_t green =0, red=0, blue=0;
  int i;
  for( i=1; i <= size; i++){
     if(i%8==0){
      red = 255;
      green =255;
      blue=0;
    }
    else if(i%7==0){
      red = 0;
      green =255;
      blue=0;
    }
    else if(i%6==0){
      red = 0;
      green =255;
      blue=255;
    }
    else if(i%5==0){
      red = 0;
      green =0;
      blue=255;
    }
    else if(i%4==0){
      red = 255;
      green =0;
      blue=255;
    }
    else if(i%3==0){
      red = 255;
      green =255;
      blue=255;
    }
    else if(i%2==0){
        red = 255;
        green =0;
        blue=0;
    }
    values[i-1] = green;
    values[i-1] = (values[i-1] << 8) + red;
    values[i-1] = (values[i-1] << 8) + blue;
  }

  SendData(values,size);
  Wait(10);
  //while(1);
  int temp;
  int anterior;
  while(1){
	  int i;
    for( i =0; i < size; i++){
      if(i==0)
        anterior = values[size-1];

      temp = values[i];
      values[i] = anterior;
      anterior = temp;
    }
    SendData(values,size);
    Wait(50);
  }
}




 int main(){
	  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

	  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	  SysCtlDelay(3);

	  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_1);
	  GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	  GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_BOTH_EDGES);
	  GPIOIntRegister(GPIO_PORTF_BASE,PortFIntHandler);
	  GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_1);

	  int i;
	  for( i=0; i < size; i++)
	    values[i] = 0;
	  SysTickbegin();
	  SPIInit();
	  SendData(values,size);
	  Wait(1000);


	  while(1){
		  int i;
		  Policia();
		  PadraoInit=0;
		  MudaPadrao = 0;


		  for(i=0; i < 3 && MudaPadrao==0; i++)
			  Pattern3();
		  	  PadraoInit=0;
		  	  MudaPadrao = 0;

		  Ambulancia();
		  PadraoInit=0;
		  MudaPadrao = 0;

		  for(i=0; i < 3 && MudaPadrao==0; i++)
			  Pattern2();
		  	  PadraoInit=0;
		  	  MudaPadrao = 0;

		  Pattern4();
	  	  PadraoInit=0;
	  	  MudaPadrao = 0;
	  }
}

