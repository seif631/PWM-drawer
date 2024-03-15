#define  F_CPU 8000000UL

#include "../SERV/std_type.h"
#include "../MCAL/DIO/dio_init.h"
#include "../HAL/HTIMER1/HTimer1_init.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/GLCD/glcd_init.h"
#include <string.h>


#define PWM_PIN PD5 // OC1A

float32 duty_cycle =70;
uint16 frequency = 100;

void PWM_Drawer_internal_init(uint16 freq,float32 duty_cycle); 
void PWM_Drawer_external_init();
void PWM_Draw_Signal();
void display_frequency(uint16 frequency);
void display_duty_cycle(float32 duty_cycle);
void display_time(uint16 frequency);
void PWM_Start(uint16 freq,float32 duty_cycle);
void PWM_Draw_Signal();

int main(void) {
	PWM_Drawer_internal_init(frequency,duty_cycle);
	//PWM_Drawer_external_init();
	

	while (1) {
		
		
		display_frequency(frequency);
		display_duty_cycle(duty_cycle);
		display_time(frequency);
		_delay_ms(50);
		PWM_Draw_Signal();

		//Add delay for visual stability
	}
}
// Function to calculate and display frequency
void display_frequency(uint16 frequency) {
	uint8 freq_str[50];
	sprintf(freq_str,"Freq:%dHz",frequency);
	GLCD_String(0,freq_str,Left);
}

// Function to calculate and display duty_cycle cycle (replace with calculation based on OCR1A)
void display_duty_cycle(float32 duty_cycle) {
	uint8 duty_str[50];
	sprintf(duty_str,"Duty:%.2f%",duty_cycle);
	GLCD_String(0,duty_str,Right);
	
}

void PWM_Start(uint16 freq,float32 duty_cycle){
		uint16 ICR = (1.0/freq) * 1000000 -1;
		HTIMER1_vidInit();
		HTIMER1_vidWriteICR(ICR);
		HTIMER1_vidStart();
		HTIMER1_vidWriteOCRA((ICR+1)*(duty_cycle/100));
}

void PWM_Drawer_internal_init(uint16 freq,float32 duty_cycle)
{
	GLCD_Init();
	GLCD_ClearAll();
	PWM_Start(freq,duty_cycle);
}

/* if u use external PWM Signal Source use this function to initiation the APP */

void PWM_Drawer_external_init()
{
	GLCD_Init();
	GLCD_ClearAll();
}

void PWM_Draw_Signal(){
	uint8 duty = (uint8)duty_cycle;
	int period_on=0; 
	int period_off=0;
	/* Start time arrow */
	
	char arrow[15]={0};
	strcat(arrow,"$"); // left arrow 

	
	
	/* Start square wave */
	char pulse [40];
	strcat(pulse,"&");	//rising edge
	
	
	
	
	for (uint8 i = 0;i<2;i++)
	{
		for (uint32 j=0;j<(duty/10);j++)
		{
			strcat(pulse,"'");	//on time
			period_on++;
		}
		strcat(pulse,")");	//falling edge
		for (uint32 k=0;k<(10-(duty/10));k++)
		{
			strcat(pulse,"("); // off time
			period_off++;
		}
		strcat(pulse,"&");	// rising edge
	}
	
	
	/* This loop made To make the arrow completely in sync with the cycle time */
	for(int i=(period_on+period_off)/2;i>0;i--)
	{
		strcat(arrow,"#"); // arrow body
	}
	strcat(arrow,"@"); // right arrow
	
	GLCD_String(6,arrow,Left); /* Display arrow */
	for(uint8 i=0;i<30;i++){
		pulse[i]=pulse[i+11];	
	}
	GLCD_String(7,pulse,Left); /* Display squareWave */
}

void display_time(uint16 frequency){
	float32 period = (1.0/frequency)*1000;
	uint8 time_str[50];
	sprintf(time_str,"Time:%.2fms",period);
	GLCD_String(5,time_str,Left);
	
}