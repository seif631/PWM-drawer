/*
 * MTimer0_reg.h
 *
 * Created: 1/9/2024 8:18:00 PM
 *  Author: Seif
 */ 


#ifndef MTIMER0_REG_H_
#define MTIMER0_REG_H_

#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		    \
	void vector(void)
	
#define TCCR0_ADDRESS (0x53)
#define TCNT0_ADDRESS (0x52)
#define OCR0_ADDRESS (0x5C)
#define TIMSK_ADDRESS (0x59)
#define TIFR_ADDRESS (0x58)



#define TCCR0 *((volatile uint8 *) TCCR0_ADDRESS)
#define TCNT0 *((volatile uint8 *) TCNT0_ADDRESS)
#define OCR0 *((volatile uint8 *) OCR0_ADDRESS)
#define TIMSK *((volatile uint8 *) TIMSK_ADDRESS)
#define TIFR *((volatile uint8 *) TIFR_ADDRESS)
#define SREG *((volatile uint8 *) 0x5F)

typedef enum {
	TCCR0_CS00,
	TCCR0_CS01,
	TCCR0_CS02,
	TCCR0_WGM01,
	TCCR0_COM00,
	TCCR0_COM01,
	TCCR0_WGM00,
	TCCR0_FOC0	
}TCCR0_BIT_reg;

#define TIMSK_TOIE0 (uint8)0
#define TIMSK_OCIE0 (uint8)1

#define SREG_GIE (uint8)7

#endif /* MTIMER0_REG_H_ */