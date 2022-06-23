/***********************************************************************/
/*                                                                     */
/*  FILE        :TIME.c                                                */
/*  DATE        :Thu, Jun 23, 2022                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/3694F                                              */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  


#include "led.h"
#include "lcd.h"
#include "ad.h"
#include "timeV.h"

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void main(void)
{

    InitLcd();
    initAD();
	InitLED();
	initTimev();
	
	while(1){
		//waitTimeMS(10);
		getADVal();
		
    	LcdXY(1,1);
		LcdPuts("RV2; ");	
		putLCDNumber(4,(unsigned int)g_adRV2);

		LcdXY(1,2);
		LcdPuts("RV3; ");
		putLCDNumber(4,(unsigned int)g_adRV3);	
			
		setLEDLevel((unsigned int)(g_adRV2<<8));
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
