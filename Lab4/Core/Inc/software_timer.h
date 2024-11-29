/*
 * software_timer.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#include "main.h"

extern int timer_flag[10];
extern int timer_counter[10];
void setTimer(int index, int counter);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
