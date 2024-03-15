/*
 * lcd_conf.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hp
 */

#ifndef HAL_GLCD_GLCD_CONF_H_
#define HAL_GLCD_GLCD_CONF_H_

#include <avr/io.h>			/* Include AVR std. library file */
#include "../../MCAL/DIO/dio_init.h"

#define Data_Port			PORTA	/* Define data port for GLCD */
#define Command_Port		PORTC	/* Define command port for GLCD */
#define Data_Port_Dir		DDRA	/* Define data port for GLCD */
#define Command_Port_Dir	DDRC	/* Define command port for GLCD */

#define RS					PC0		/* Define control pins */
#define RW					PC1		/* Define control pins */
#define EN					PC2		/* Define control pins */
#define CS1					PC3		/* Define control pins */
#define CS2					PC4		/* Define control pins */
#define RST					PC5		/* Define control pins */

#define Left				(0)			/* Define side */
#define Right				(1)			/* Define control pins */

#define TotalPage			8			/* number of pages */


#endif /* HAL_GLCD_GLCD_CONF_H_ */
