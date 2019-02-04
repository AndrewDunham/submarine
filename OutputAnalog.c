#include <stdio.h>
#include "diag/Trace.h"

#include <stdlib.h>
#include <time.h>


int main(int argc, char∗ argv[]) {
 trace   printf (”System clock : %u Hz\n” ,SystemCoreClock);

// initialize GPIO
SystemCoreClock) ;
myGPIOA Init ( ) ;
myGPIOB Init ( ) ;
//initialize analog in/out
myADC Init();
myDAC Init();
// initialize frequency detection timing/interrupt myTIM2 Init();
myEXTI Init();
// initialize SPI and configure the LCD
mySPI Init () ;
configure LCD () ;
//poll the ADC and write the value to the DAC
while (1){
adc value = ADC1−>DR;
DAC−>DHR12R1 = adc value ;
//wait  ̃50ms
//myWait(5) ;
// write values to the LCD write   values () ;
}
return 0; }
void myGPIOA-Init(){
	
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	GPIOA->MODER |= (GPIO_MODER_MODER0) | (GPIO_MODER_MODER4);

	GPIOA−>PUPDR &=  ̃(GPIO PUPDR PUPDR0) ; 
	GPIOA−>PUPDR &=  ̃(GPIO PUPDR PUPDR4) ; 
	trace_printf (”GPIOA initialized \n”) ;
}