#ifndef _AD_H_
#define _AD_H_

void waitTimeMS(unsigned int mSec);
void initAD(void);
void getADVal(void);

#define RV2  1
#define RV3  0

extern unsigned char g_adRV2;
extern unsigned char g_adRV3;

#endif