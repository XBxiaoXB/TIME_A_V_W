#include "iodefine.h"
#include "ad.h"

#define WAIT_LOOP_FOR_1MSEC   3500

unsigned char g_adRV2; 
unsigned char g_adRV3;

void waitTimeMS(unsigned int mSec)
{
	unsigned int loopCount1,loopCount2;
    
	for(loopCount1=0; loopCount1<mSec; loopCount1++){
	    for(loopCount2=0; loopCount2 < WAIT_LOOP_FOR_1MSEC; loopCount2++);   
    }
    
}

void initAD(void)
{
	TV.TCRV1.BIT.TRGE=0;
	AD.ADCSR.BIT.SCAN=1;
	AD.ADCSR.BIT.CKS=1;
	AD.ADCSR.BIT.CH=1;
	AD.ADCSR.BIT.ADIE=0;
	
}

void getADVal(void)
{	
	AD.ADCSR.BIT.ADST=1;
	
	while(AD.ADCSR.BIT.ADF==0){
		
	}
	
	AD.ADCSR.BIT.ADST=0;
	AD.ADCSR.BIT.ADF=0;
		
	g_adRV2=AD.ADDRB>>8;
	g_adRV3=AD.ADDRA>>8;
}