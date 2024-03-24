/*
 * HTimer0_conf.h
 *
 * Created: 1/9/2024 8:47:57 PM
 *  Author: Seif
 */ 


#ifndef HTIMER0_CONF_H_
#define HTIMER0_CONF_H_

#define NORMAL_MODE 0U
#define PWM_MODE 1U
#define CTC_MODE 2U
#define FAST_PWM_MODE 3U

#define HTIMER0_MODE FAST_PWM_MODE

#define COMPARE1_MODE 0x00
#define COMPARE2_MODE 0x10
#define COMPARE3_MODE 0x20
#define COMPARE4_MODE 0x30

#define TIMER_COMP_OUTPUT_MODE COMPARE3_MODE

#define TIMER0_CLOCK_STOP (uint8) 0xF8

#define TIMER0_FACTOR_1 (uint8) 0x01
#define TIMER0_FACTOR_8  (uint8) 0x02
#define TIMER0_FACTOR_64  (uint8) 0x03
#define TIMER0_FACTOR_256  (uint8) 0x04
#define TIMER0_FACTOR_1024  (uint8) 0x05
#define TIMER0_FACTOR_FALLING  (uint8) 0x06
#define TIMER0_FACTOR_RISING  (uint8) 0x07

#define HTIMER0_SELECT_ENABLE TIMER0_FACTOR_8





#endif /* HTIMER0_CONF_H_ */