/*
 * timer.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Nmr
 */

#include "timer_own.h"



void timer1_init(void)
{
	TCCR1A=0x00;             // diconnect all compare mode options
	TCCR1B=0b00000100;      // set prescaler to clk/256
	TCNT1=0;               // clear the timer
}
