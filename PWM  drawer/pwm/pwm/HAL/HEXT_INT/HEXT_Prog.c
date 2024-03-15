/*
 * ext_prog.c
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "../../MCAL/MEXT_INT/MEXT_reg.h"
#include "HEXT_Conf.h"
#include "HEXT_Init.h"




ISR(INT0_VECTRO){
	INT0_ISR_FUN();
}
ISR(INT1_VECTRO){
	INT1_ISR_FUN();
}
ISR(INT2_VECTRO){
	INT2_ISR_FUN();
}


void HEXT_vidControlInt0(uint8 u8StCopy);
void HEXT_vidControlInt1(uint8 u8StCopy);
void HEXT_vidControlInt2(uint8 u8StCopy);


void HEXT_vidInit(uint8 u8ExtIntNum, uint8 u8ISRStCont){
	SET_BIT(SREG,SREG_GIE);

	switch(u8ExtIntNum){
	case INT0:
		DIO_vidSetPinDir(INT0_PIN,INPUT_PIN);
		HEXT_vidControlInt0(u8ISRStCont);
		SET_BIT(GICR,GICR_INT0);
		break;
	case INT1:
		DIO_vidSetPinDir(INT1_PIN,INPUT_PIN);
		HEXT_vidControlInt1(u8ISRStCont);
		SET_BIT(GICR,GICR_INT1);
		break;
	case INT2:
		DIO_vidSetPinDir(INT2_PIN,INPUT_PIN);
		HEXT_vidControlInt2(u8ISRStCont);
		SET_BIT(GICR,GICR_INT2);
		break;
	}
}

void HEXT_vidControlInt0(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		DIO_vidSetPinVal(INT0_PIN,HIGH_PIN);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case RISSING:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case LOW:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ANY_LOG:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	}
}
void HEXT_vidControlInt1(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		DIO_vidSetPinVal(INT1_PIN,HIGH_PIN);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	case RISSING:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	case LOW:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case ANY_LOG:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	}
}
void HEXT_vidControlInt2(uint8 u8StCopy){
	switch(u8StCopy){
	case FALLING:
		DIO_vidSetPinVal(INT2_PIN,HIGH_PIN);
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	case RISSING:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	}
}
