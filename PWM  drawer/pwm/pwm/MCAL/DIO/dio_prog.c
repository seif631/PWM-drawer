/*
 * dio_prog.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "dio_privt.h"
#include "dio_init.h"

volatile uint8 *Arr_PORT[4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};
volatile uint8 *Arr_DIR[4]={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
volatile uint8 *Arr_PIN[4]={PINA_REG,PINB_REG,PINC_REG,PIND_REG};

void DIO_vidSetPortDir(uint8 u8CopyPort,uint8 u8CopyDir){
	uint8 ER=0;
	if(u8CopyPort <=PORTD){
		*Arr_DIR[u8CopyPort] = u8CopyDir;
	}else{
		ER=1;
	}
}
void DIO_vidSetPortVal(uint8 u8CopyPort,uint8 u8CopyVal){
	uint8 ER=0;
	if(u8CopyPort <=PORTD){
		*Arr_PORT[u8CopyPort] = u8CopyVal;
	}else{
		ER=1;
	}
}
uint8 DIO_u8GetPortVal(uint8 u8CopyPort){
	uint8 ER=0,u8CopyVal=0;
	if(u8CopyPort <=PORTD){
		u8CopyVal = *Arr_PIN[u8CopyPort];
	}else{
		ER=1;
	}
	return u8CopyVal;
}

//void DIO_vidSetPinDir(uint8 u8CopyPort,uint8 u8CopyPin,uint8 u8CopyDir){
//	if(u8CopyDir == OUTPUT_PIN){
//		SET_BIT(*Arr_DIR[u8CopyPort],u8CopyPin);
//	}else if(u8CopyDir == INPUT_PIN){
//		CLR_BIT(*Arr_DIR[u8CopyPort],u8CopyPin);
//	}
//}

void DIO_vidSetPinDir(uint8 u8CopyPin,uint8 u8CopyDir){
	if(u8CopyDir == OUTPUT_PIN){
		SET_BIT(*Arr_DIR[(u8CopyPin/8)],(u8CopyPin%8));
	}else if(u8CopyDir == INPUT_PIN){
		CLR_BIT(*Arr_DIR[(u8CopyPin/8)],(u8CopyPin%8));
	}
}

void DIO_vidSetPinVal(uint8 u8CopyPin,uint8 u8CopyVal){
	switch (u8CopyVal){
	case HIGH_PIN:SET_BIT(*Arr_PORT[(u8CopyPin/8)],(u8CopyPin%8));break;
	case LOW_PIN:CLR_BIT(*Arr_PORT[(u8CopyPin/8)],(u8CopyPin%8));break;
	case TOGGLE_PIN:TOGGLE_BIT(*Arr_PORT[(u8CopyPin/8)],(u8CopyPin%8));break;
	}
}

void DIO_vidSetPinsVal(uint8 *u8Pin,uint8 u8CopyBound,uint8 u8CopyVal){
	uint8 i;
	for(i = 0;i<u8CopyBound;i++){
		switch(u8CopyVal){
			case HIGH_PIN:SET_BIT(*Arr_PORT[(u8Pin[i]/8)],(u8Pin[i]%8));break;
			case LOW_PIN :CLR_BIT(*Arr_PORT[(u8Pin[i]/8)],(u8Pin[i]%8));break;
		}
	}
}

void DIO_vidSetPinsDir(uint8 *u8Pin,uint8 u8CopyBound,uint8 u8CopyDir){
	for(int i=0;i<u8CopyBound;i++){
		if(u8CopyDir == OUTPUT_PIN){
			SET_BIT(*Arr_DIR[(u8Pin[i]/8)],(u8Pin[i]%8));
			}
		else if(u8CopyDir == INPUT_PIN){
			CLR_BIT(*Arr_DIR[(u8Pin[i]/8)],(u8Pin[i]%8));
		}
		
	}
}
uint8 DIO_u8GetPinVal(uint8 u8CopyPin){
	return GET_BIT(*Arr_PIN[(u8CopyPin/8)],(u8CopyPin%8));
}

