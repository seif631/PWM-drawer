/*
 * HTimer0_init.h
 *
 * Created: 1/9/2024 8:47:06 PM
 *  Author: Seif
 */ 


#ifndef HTIMER1_HTIMER1_INIT_H_
#define HTIMER1_HTIMER1_INIT_H_


void (*HTIMER1_OVF_INT)(void);
void (*HTIMER1_COMPA_INT)(void);
void (*HTIMER1_COMPB_INT)(void);
void (*HTIMER1_CAP_INT)(void);


void HTIMER1_vidInit(void);

void HTIMER1_vidStart(void);
void HTIMER1_vidStop(void);


/******-------Input Capture Reg ------------*********/
void HTIMER1_vidINCAPFalling(void);
void HTIMER1_vidINCAPRissing(void);
uint16 HTIMER1_u16INCAPRead(void);



void HTIMER1_vidWriteTCNT1(uint16 Copy_u16ValueTCNT);
void HTIMER1_vidWriteOCRA(uint16 Copy_u16ValueOCRA);
void HTIMER1_vidWriteOCRB(uint16 Copy_u16ValueOCRB);
void HTIMER1_vidWriteICR(uint16 Copy_u16ValueICR);



void HTIMER1_vidOVRInterruptEnable(void);
void HTIMER1_vidCOMPAInterruptEnable(void);
void HTIMER1_vidCOMBInterruptEnable(void);
void HTIMER1_vidCAPInterruptEnable(void);

void HTIMER1_vidOVRInterruptDisable(void);
void HTIMER1_vidCOMPAInterruptDisable(void);
void HTIMER1_vidCOMBInterruptDisable(void);
void HTIMER1_vidCAPInterruptDisable(void);

#endif /* HTIMER1_HTIMER1_INIT_H_ */