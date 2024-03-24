/*
 * HTimer0_prog.c
 *
 * Created: 1/9/2024 8:45:57 PM
 *  Author: Seif
 */ 
#include "../../SERV/bit_math.h"
#include "../../SERV/std_type.h"
#include "../../MCAL/MTIMER0/MTimer0_reg.h"
#include "../../MCAL/DIO/dio_init.h"
#include "HTimer0_conf.h"
#include "HTimer0_init.h"

ISR(__vector_11){
	HTIMER0_OVF_INT();
}

ISR(__vector_10){
	HTIMER0_CTC_INT();
}


void HTIMER0_vidInit(){
#if HTIMER0_MODE==NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif HTIMER0_MODE==PWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif HTIMER0_MODE==CTC_MODE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif HTIMER0_MODE==FAST_PWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;

#endif	
	
}


void HTIMER0_vidStart(){
	TCCR0 |= HTIMER0_SELECT_ENABLE;
	
}
void HTIMER0_vidStop(){
	TCCR0 &= TIMER0_CLOCK_STOP;
	
}

void HTIMER0_vidwriteTCNT(uint8 Copy_Start_Value){
	TCNT0 = Copy_Start_Value;
}
void HTIMER0_vidwriteOCR(uint8 Copy_Start_Value){
	OCR0 = Copy_Start_Value;
	
}

void HTIMER0_vidOVRInterruptEN(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_TOIE0);
}
void HTIMER0_vidOVRInterruptDis(){
	CLR_BIT(TIMSK,TIMSK_TOIE0);
}

void HTIMER0_vidCOMPInterruptEN(){
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TIMSK_OCIE0);
}
void HTIMER0_vidCOMPInterruptDis(){

	CLR_BIT(TIMSK,TIMSK_OCIE0);
}
