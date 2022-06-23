#include "iodefine.h"
#include "ad.h"
#include "led.h"
#include "timeV.h"
//#include "machine.h"

const unsigned int g_LED_ON = 0xff;
unsigned int g_LED_OFF = 0xAA;
unsigned int i = 0;

void initTimev(void)
{
	TV.TCRV0.BIT.CMIEA = 0;
	
    TV.TCRV0.BIT.CCLR = 1;
    TV.TCRV0.BIT.CKS =3 ;
    TV.TCRV1.BIT.ICKS = 1;
	TV.TCSRV.BIT.OS = 1;

    TV.TCSRV.BIT.CMFA = 0;
    TV.TCSRV.BIT.CMFB = 0;
    TV.TCRV0.BIT.CMIEA = 1;
    TV.TCRV0.BIT.CMIEB = 1;
	
	TV.TCORA = g_LED_ON;
	TV.TCORB = g_LED_OFF;

	
	TV.TCRV0.BIT.CMIEA = 1;

}

void setLEDLevel(unsigned int level)
{
	if(level<g_LED_ON){
		g_LED_OFF=level;
	}
}

unsigned int getLEDLevel(void)
{
	return g_LED_OFF;
}


#pragma section IntPRG
__interrupt(vect=22) void INT_TimerV(void) 

{
	//i++;
	
	if(TV.TCSRV.BIT.CMFA == 1){
		
		TV.TCSRV.BIT.CMFA = 0;
		
		LED1_OFF();
		LED2_ON();
		
		TV.TCORA=g_LED_ON;
		TV.TCORB=g_LED_OFF;

	}

	if(TV.TCSRV.BIT.CMFB == 1){
		
		TV.TCSRV.BIT.CMFA = 0;
		
		LED1_ON();
		LED2_OFF();
		
		TV.TCORA=g_LED_ON;
		TV.TCORB=g_LED_OFF;

	}
}
