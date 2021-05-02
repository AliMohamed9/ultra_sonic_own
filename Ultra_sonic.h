/*
 * Ultra_sonic.h
 *
 *  Created on: Oct 25, 2019
 *      Author: Nmr
 */

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include <avr/io.h>
#include "timer_own.h"
#include <util/delay.h>



void init_Ultra_sonic(void);
unsigned int Ultra_sonic_Get_Distance(void);

#endif /* ULTRA_SONIC_H_ */
