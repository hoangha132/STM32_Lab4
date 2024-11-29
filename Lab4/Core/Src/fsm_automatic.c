/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */


#include "fsm_automatic.h"

int status = 10;
int red_time = 5;
int green_time = 3;
int yellow_time = 2;
int index_7LED = 0;


void fsm_automatic(){
	switch(status){
	case 10:
		set_X_axis_light(1, 1, 1);
		set_Y_axis_light(1, 1, 1);
		if(isButtonPressed(1)){
			status = INIT;
		}
		break;
		case INIT:
			setTraffic(red_time, green_time);
			setTimer(0, green_time*1000);
			setTimer(1, 1000);
			setTimer(2, 250);
			status = RED_GREEN;
			break;
		case RED_GREEN:
			set_X_axis_light(1, 0, 0);
			set_Y_axis_light(0, 1, 0);
			if (timer_flag[0] == 1){
				setTraffic(yellow_time, yellow_time);
				setTimer(0, yellow_time*1000);
				status = RED_YELLOW;
			}
			if (timer_flag[1] == 1){
				countDown();
				setTimer(1, 1000);
			}
			if (isButtonPressed(1)){
				set_X_axis_light(0, 0, 0);
				set_Y_axis_light(0, 0, 0);
				setTimer(3, 500);
				setTimer(4, 50000);
				man_red_time = 0;
				man_green_time = 0;
				man_yellow_time = 0;
				status = MAN_RED;
			}
			break;
		case RED_YELLOW:
			set_X_axis_light(1, 0, 0);
			set_Y_axis_light(0, 0, 1);
			if (timer_flag[0] == 1){
				setTraffic(green_time, red_time);
				setTimer(0, green_time*1000);
				status = GREEN_RED;
			}
			if (timer_flag[1] == 1){
				updateClockBuffer();
						update7seg(index_7LED++);
						if (index_7LED >= 4){
							index_7LED = 0;
						}
				countDown();
				setTimer(1, 1000);
			}
			if (isButtonPressed(1)){
				set_X_axis_light(0, 0, 0);
				set_Y_axis_light(0, 0, 0);
				setTimer(3, 500);
				setTimer(4, 10000);
				man_red_time = 0;
				man_green_time = 0;
				man_yellow_time = 0;
				status = MAN_RED;
			}
			break;
		case GREEN_RED:
			set_X_axis_light(0, 1, 0);
			set_Y_axis_light(1, 0, 0);
			if (timer_flag[0] == 1){
				setTraffic(yellow_time, yellow_time);
				setTimer(0, yellow_time*1000);
				status = YELLOW_RED;
			}
			if (timer_flag[1] == 1){
				updateClockBuffer();
						update7seg(index_7LED++);
						if (index_7LED >= 4){
							index_7LED = 0;
						}
				countDown();
				setTimer(1, 1000);
			}
			if (isButtonPressed(1)){
				set_X_axis_light(0, 0, 0);
				set_Y_axis_light(0, 0, 0);
				setTimer(3, 500);
				setTimer(4, 10000);
				man_red_time = 0;
				man_green_time = 0;
				man_yellow_time = 0;
				status = MAN_RED;
			}
			break;
		case YELLOW_RED:
			set_X_axis_light(0, 0, 1);
			set_Y_axis_light(1, 0, 0);
			if (timer_flag[0] == 1){
				setTraffic(red_time, green_time);
				setTimer(0, red_time*1000);
				status = RED_GREEN;
			}
			if (timer_flag[1] == 1){
				updateClockBuffer();
						update7seg(index_7LED++);
						if (index_7LED >= 4){
							index_7LED = 0;
						}
				countDown();
				setTimer(1, 1000);
			}
			if (isButtonPressed(1)){
				set_X_axis_light(0, 0, 0);
				set_Y_axis_light(0, 0, 0);
				setTimer(3, 500);
				setTimer(4, 10000);
				man_red_time = 0;
				man_green_time = 0;
				man_yellow_time = 0;
				status = MAN_RED;
			}
			break;
		default:
			break;
	}

	if (timer_flag[2] == 1) {
		updateClockBuffer();
		update7seg(index_7LED++);
		if (index_7LED >= 4){
			index_7LED = 0;
		}
		setTimer(2, 250);
	}
}
