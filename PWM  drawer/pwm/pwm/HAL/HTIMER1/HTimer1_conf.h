/*
 * HTimer0_conf.h
 *
 * Created: 1/9/2024 8:47:57 PM
 *  Author: Seif
 */ 


#ifndef HTIMER1_CONFG_H_
#define HTIMER1_CONFG_H_

/*********-------INputCAP-----**********/

///*********** Timer1 Noise**************/
//#define TIMER1_NO_NOISE     0
//#define TIMER1_NOISE        1
//#define TIMER1_NOISE_SEL   TIMER1_NO_NOISE


#define NORMAL_MODE 0U
#define PWM_MODE 1U
#define FAST_PWM_MODE 2U

#define HTIMER1_MODE FAST_PWM_MODE

/*---Compare Output Mode  OCA---*/

#define NORMAL_OUTPUT_MODE       0x00
#define START_TOGGLE_COMPA       0x40
#define START_CLEAR_COMPA        0x80
#define START_SET_COMPA          0xC0

#define HTIMER1_COMPA_OUT_MODE   START_CLEAR_COMPA

/*---Compare Output Mode  OCB---*/

#define NORMAL_OUTPUT_MODE       0x00
#define START_TOGGLE_COMPB       0x10
#define START_CLEAR_COMPB        0x20
#define START_SET_COMPB          0x30

#define HTIMER1_COMPB_OUT_MODE   NORMAL_OUTPUT_MODE

/**********-------Select Pin-----------************/

#define HTIEMR1_OC1A_SEL         0U
#define HTIEMR1_OC1B_SEL         1U
#define HTIEMR1_OC1A_OC1B_SEL    2U

#define HTIMER1_SELECTION_OUTPUT    HTIEMR1_OC1A_SEL

/******----------TIMER1 PIN NUMBER --------*******/

#define HTIMER1_PIN_OC1A    PD5
#define HTIMER1_PIN_OC1B    PD4
#define HTIMER1_PIN_ICP1    PD6





/******** Stop Timer Clear Bit ********/

#define TIMER1_CLOCK_STOP     (uint8)0xF8

/***** Clock Select ENABLE TIMER*****/

/*---TIMER SELSET FACTOR---*/
#define TIMER1_FACTOR_1                     (uint8)0x01    // 1U
#define TIMER1_FACTOR_8                     (uint8)0x02    // 2U
#define TIMER1_FACTOR_64                    (uint8)0x03    // 3U
#define TIMER1_FACTOR_256                   (uint8)0x04    // 4U
#define TIMER1_FACTOR_1024                  (uint8)0x05    // 5U
#define TIMER1_FACTOR_EXT_FALLING_PIN_T0    (uint8)0x06    // 6U   //using Counter with S.W
#define TIMER1_FACTOR_EXT_RISING_PIN_T0     (uint8)0x07    // 7U   //using Counter with S.W

#define HTIMER1_SELECT_ENABLE         TIMER1_FACTOR_8

#endif /* HTIMER1_CONFG_H_ */