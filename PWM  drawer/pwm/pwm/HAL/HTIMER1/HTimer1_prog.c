/*
 * HTimer0_prog.c
 *
 * Created: 1/9/2024 8:45:57 PM
 *  Author: Seif
 */ 
#include "../../SERV/bit_math.h"
#include "../../SERV/std_type.h"
#include "../../MCAL/MTIMER1/MTimer1_reg.h"
#include "../../MCAL/DIO/dio_init.h"
#include "HTimer1_conf.h"
#include "HTimer1_init.h"

ISR(__vector_6){
	HTIMER1_CAP_INT();
}
ISR(__vector_7){
	HTIMER1_COMPA_INT();
}
ISR(__vector_8){
	HTIMER1_COMPB_INT();
}
ISR(__vector_9){
	HTIMER1_OVF_INT();
}

void HTIMER1_vidInit(){
	
	#if HTIMER1_MODE==NORMAL_MODE
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	#elif HTIMER1_MODE==PWM_MODE
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	#elif HTIMER1_MODE==FAST_PWM_MODE
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	#endif

	#if HTIMER1_SELECTION_OUTPUT == HTIEMR1_OC1A_SEL
		DIO_vidSetPinDir(HTIMER1_PIN_OC1A,OUTPUT_PIN);
		TCCR1A |= (uint8)HTIMER1_COMPA_OUT_MODE;
	#elif HTIMER1_SELECTION_OUTPUT == HTIEMR1_OC1B_SEL
		DIO_vidSetPinDir(HTIMER1_PIN_OC1B,OUTPUT_PIN);
		TCCR1A |=(uint8)HTIMER1_COMPB_OUT_MODE;
	#elif HTIMER1_SELECTION_OUTPUT == HTIEMR1_OC1A_OC1B_SEL
		DIO_vidSetPinDir(HTIMER1_PIN_OC1A,OUTPUT_PIN);
		DIO_vidSetPinDir(HTIMER1_PIN_OC1B,OUTPUT_PIN);
		TCCR1A |= (uint8)HTIMER1_COMPA_OUT_MODE | (uint8)HTIMER1_COMPB_OUT_MODE;
	#endif

}


void HTIMER1_vidStart(){
	TCCR1B |= HTIMER1_SELECT_ENABLE;
}
void HTIMER1_vidStop(){
	TCCR1B &= TIMER1_CLOCK_STOP;
}

void HTIMER1_vidWriteTCNT1(uint16 Copy_u16ValueTCNT){
	TCNT1 = Copy_u16ValueTCNT;
}
void HTIMER1_vidWriteOCRA(uint16 Copy_u16ValueOCRA){
	OCR1A = Copy_u16ValueOCRA;
}
void HTIMER1_vidWriteOCRB(uint16 Copy_u16ValueOCRB){
	OCR1B = Copy_u16ValueOCRB;
}
void HTIMER1_vidWriteICR(uint16 Copy_u16ValueICR){
	ICR1 = Copy_u16ValueICR;
}

/*************--------------------INPUT CAP **************/
//void TIMER1_vidINCAPFalling(void){
//	CLR_BIT(TCCR1B,ICES1);
//}
//void TIMER1_vidINCAPRissing(void){
//	SET_BIT(TCCR1B,ICES1);
//}
//
//uint16 TIMER1_u16INCAPRead(void){
//	return ICR1;
//}


void HTIMER1_vidOVRInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TOIE1);
}
void HTIMER1_vidCOMPAInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE1A);
}
void HTIMER1_vidCOMBInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE1B);
}
void HTIMER1_vidCAPInterruptEnable(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void HTIMER1_vidOVRInterruptDisable(){
	CLR_BIT(TIMSK,TIMSK_TOIE1);
}
void HTIMER1_vidCOMPAInterruptDisable(){
	CLR_BIT(TIMSK,TIMSK_OCIE1A);
}
void HTIMER1_vidCOMBInterruptDisable(){
	CLR_BIT(TIMSK,TIMSK_OCIE1B);
}
void HTIMER1_vidCAPInterruptDisable(){
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}