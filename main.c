/*
 * main.c
 *
 *  Created on: Apr 25, 2021
 *      Author: MeGa
 */
#include <avr/io.h>
#include <util/delay.h>
#include <Ultra_sonic.h>
#include <timer_own.h>
#include <lcd.h>

int main(){
unsigned char z=0;
unsigned  char y=0;
unsigned int Distance =0;
timer1_init();
init_Ultra_sonic();
LCD_init();
    LCD_go_to(1,1);
	LCD_Send_string("Distance= ");
while(1){

	Distance =Ultra_sonic_Get_Distance();
	 	z=Distance/10;
	 	LCD_go_to(2,11);
		LCD_Send_data(z+'0');
		_delay_ms(2000);
		y=Distance%10;
		LCD_go_to(2,12);
		LCD_Send_data(y+'0');
		_delay_ms(2000);

}






}
