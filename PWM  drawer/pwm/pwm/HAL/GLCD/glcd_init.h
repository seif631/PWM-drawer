/*
 * lcd_init.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hp
 */

#ifndef HAL_GLCD_GLCD_INIT_H_
#define HAL_GLCD_GLCD_INIT_H_

#include "../../MCAL/DIO/dio_init.h"
#include "glcd_conf.h"


void GLCD_Init(void);		/* initiation function */
void GLCD_Command(char Command);	/* send instruction */
void GLCD_ClearAll(void);		/* clear all on screen */
void GLCD_String(char page_no, const char *str,uint8 side);		/* Display string from custom char */



#endif /* HAL_GLCD_GLCD_INIT_H_ */
