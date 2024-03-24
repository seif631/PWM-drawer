/*
 * HTimer0_init.h
 *
 * Created: 1/9/2024 8:47:06 PM
 *  Author: Seif
 */ 


#ifndef HTIMER0_INIT_H_
#define HTIMER0_INIT_H_

void (*HTIMER0_OVF_INT)();
void (*HTIMER0_CTC_INT)();

void HTIMER0_vidInit();

void HTIMER0_vidStart();
void HTIMER0_vidStop();

void HTIMER0_vidcopyTCNT0(uint8 Copy_Start_Value);
void HTIMER0_vidcopyOCR0(uint8 Copy_Start_Value);

void HTIMER0_vidOVRInterruptEN();
void HTIMER0_vidOVRInterruptDis();

void HTIMER0_vidCOMPInterruptEN();
void HTIMER0_vidCOMPInterruptDis();


#endif /* HTIMER0_INIT_H_ */