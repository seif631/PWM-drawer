/*
 * ext_reg.h
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */

#ifndef MCAL_EXT_REG_H_
#define MCAL_EXT_REG_H_


#define ISR(vector)            \
    void vector (void)  __attribute__ ((signal,used, externally_visible)); \
    void vector (void)

#define INT0_VECTRO    __vector_1
#define INT1_VECTRO    __vector_2
#define INT2_VECTRO    __vector_3


#define MCUCR    *((volatile uint8 *) 0x55)
#define MCUCSR   *((volatile uint8 *) 0x54)
#define GICR     *((volatile uint8 *) 0x5B)
#define GIFR     *((volatile uint8 *) 0x5A)
#define SREG     *((volatile uint8 *) 0x5F)


#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3


#define MCUCSR_ISC2   6

#define GICR_INT0   6
#define GICR_INT1   7
#define GICR_INT2   5


#define SREG_GIE   7


#endif /* MCAL_EXT_EXT_REG_H_ */
