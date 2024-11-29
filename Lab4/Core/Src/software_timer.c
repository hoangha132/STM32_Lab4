/*
 * software_timer.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */


#include "software_timer.h"

int timer_flag[10];
int timer_count[10];
int timer_cycle = 10;

void setTimer(int index, int counter){
	timer_flag[index] = 0;
	timer_count[index] = counter / timer_cycle;
}

void timerRun(){
	for(int i=0; i < 10; i++){
		if(timer_count[i] > 0){
			timer_count[i]--;
			if(timer_count[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
