/*
 * dio_privt.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Bunny
 */

#ifndef MCAL_DIO_DIO_PRIVT_H_
#define MCAL_DIO_DIO_PRIVT_H_

#define PORTA_REG      ((volatile uint8 *) 0x3B)
#define PORTB_REG      ((volatile uint8 *) 0x38)
#define PORTC_REG      ((volatile uint8 *) 0x35)
#define PORTD_REG      ((volatile uint8 *) 0x32)

#define DDRA_REG       ((volatile uint8 *) 0x3A)
#define DDRB_REG       ((volatile uint8 *) 0x37)
#define DDRC_REG       ((volatile uint8 *) 0x34)
#define DDRD_REG       ((volatile uint8 *) 0x31)

#define PINA_REG       ((volatile uint8 *) 0x39)
#define PINB_REG       ((volatile uint8 *) 0x36)
#define PINC_REG       ((volatile uint8 *) 0x33)
#define PIND_REG       ((volatile uint8 *) 0x30)


#endif /* MCAL_DIO_DIO_PRIVT_H_ */
