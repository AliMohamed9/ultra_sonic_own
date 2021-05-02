/*
 * Ultra_sonic.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Nmr
 */

#include "Ultra_sonic.h"



void init_Ultra_sonic(void)
{

	timer1_init();
	DDRD |=(1<<PD3);            //make pd3 output as a trigger
	DDRD &=~(1<<PD2);           //make pd2 input as it will be ECHO

}


unsigned int Ultra_sonic_Get_Distance(void)
{

	unsigned int total_time_=0,No_of_counts_=0,Distance=0;

	PORTD |=(1<<PD3);        //sent pulse with width 2 ms
    _delay_ms(2);
    PORTD &=~(1<<PD3);


	while(!((PIND&(1<<PD2))>>PD2));      //wait until receive high from echo

	TCNT1=0;                            //clear the timer to start counts

	while(((PIND&(1<<PD2))>>PD2));      //wait until receive LOW from echo


	No_of_counts_=TCNT1;

	total_time_=No_of_counts_*32;         //convert the counts to time as sys tick is 32US

    Distance=total_time_ / 58;                   //convert time to distance

return Distance;

}
