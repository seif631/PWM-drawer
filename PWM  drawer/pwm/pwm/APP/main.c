#define  F_CPU 8000000UL

#include "../SERV/std_type.h"

#include "../MCAL/DIO/dio_init.h"
#include "../HAL/HTIMER0/HTimer0_init.h"
#include "../HAL/HTIMER1/HTimer1_init.h"
#include <util/delay.h>
#include "../HAL/GLCD/glcd_init.h"
#include <string.h>


float32 duty_cycle =60, measured_duty_cycle;
float32 measured_frequency;
float32 period;

void PWM_Drawer_internal_init(float32 duty_cycle); 
void PWM_Drawer_external_init();
void PWM_Draw_Signal();
void display_frequency(float32 frequency);
void display_duty_cycle(float32 duty_cycle);
void display_time(float32 frequency);
void PWM_Start(float32 duty_cycle);
void PWM_Draw_Signal();
void PWM_Get_Signal();

int main(void) {
	DIO_vidSetPinDir(11,OUTPUT_PIN);
	PWM_Drawer_internal_init(duty_cycle);
	//PWM_Drawer_external_init();

	while (1) {
		
		PWM_Get_Signal();
		
		display_frequency(measured_frequency);
		display_duty_cycle(measured_duty_cycle);
		display_time(measured_frequency);
		
		PWM_Draw_Signal();

		//Add delay for visual stability
	}
}
// Function to calculate and display frequency
void display_frequency(float32 frequency) {
	uint8 freq_str[50];
	sprintf(freq_str,"Frequency: %.2fkHz",frequency);
	GLCD_String(0,freq_str,Left);
}

// Function to calculate and display duty_cycle cycle (replace with calculation based on OCR1A)
void display_duty_cycle(float32 duty_cycle) {
	uint8 duty_str[50];
	sprintf(duty_str,"Duty: %.2f",duty_cycle);
	strcat(duty_str, "%");
	GLCD_String(1,duty_str,Left);
	
}
void PWM_Drawer_internal_init(float32 duty_cycle)
{
	GLCD_Init();
	GLCD_ClearAll();
	PWM_Start(duty_cycle);
}
void PWM_Start(float32 duty_cycle){
		HTIMER0_vidInit();
		HTIMER0_vidStart();
		HTIMER0_vidwriteOCR(256*(uint8)duty_cycle/100);
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

void display_time(float32 frequency){
	float32 period = (1.0/frequency);
	uint8 time_str[50];
	sprintf(time_str,"Time:%.3fms",period);
	GLCD_String(5,time_str,Left);
	
}

void PWM_Get_Signal(){
	uint16 A,B,C,Ton,T;

		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	

		TCCR1B = 0x41;  	
		while ((TIFR&(1<<ICF1)) == 0);
		A = ICR1;  		
		TIFR = (1<<ICF1);  
		
		TCCR1B = 0x41;  	
		while ((TIFR&(1<<ICF1)) == 0);
		B = ICR1;  		
		TIFR = (1<<ICF1);  	
		
		TCCR1B = 0x01;  	
		while ((TIFR&(1<<ICF1)) == 0);
		C = ICR1;  		
		TIFR = (1<<ICF1);  	

		TCCR1B = 0;  		
		
		if(A<B && B<C) 
		{
			Ton=C-B;
			T=B-A;
			
			
			/* Calculate frequency */
			measured_frequency= F_CPU/T;
			measured_frequency /= 1000;
			
			/* Calculate duty cycle */
			measured_duty_cycle =((float) Ton /(float)T)*100;	
		}
		else
		{
			GLCD_ClearAll();
			GLCD_String(1,"OUT OF RANGE!!",Left);
		}
		_delay_ms(50);
}

