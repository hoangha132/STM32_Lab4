/*
 * fsm_manual.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */


#include "fsm_manual.h"
#include "main.h"

int man_red_time = 0;
int man_yellow_time = 0;
int man_green_time = 0;

void fsm_manual(){
	switch(status){
	case MAN_RED:
		setTraffic(man_red_time, 2);
		if (timer_flag[3] == 1){
			HAL_GPIO_TogglePin(RED_0_GPIO_Port, RED_0_Pin);
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
			setTimer(3, 500);
		}
		if(timer_flag[4] == 1){
			status = INIT;
			red_time = 5;
			green_time = 3;
			yellow_time = 2;
		}
		if (isButtonPressed(1)){
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
			setTimer(3, 500);
			status = MAN_YELLOW;
			setTimer(4, 10000);
		}
		if(isButtonPressed(2)){
			man_red_time++;
			if(man_red_time > 99){
				man_red_time = red_time;
			}
			setTimer(4, 10000);
		}
		if(isButtonPressed(3)){
			red_time = man_red_time;
			green_time = red_time - yellow_time;
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
			status = MAN_YELLOW;
		}
		break;
	case MAN_YELLOW:
		setTraffic(man_yellow_time, 3);
		if (timer_flag[3] == 1){
			HAL_GPIO_TogglePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin);
			HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
			setTimer(3, 500);
		}
		if(timer_flag[4] == 1){
			status = INIT;
			red_time = 5;
			green_time = 3;
			yellow_time = 2;
		}
		if (isButtonPressed(1)){
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
			setTimer(3, 500);
			status = MAN_GREEN;
			setTimer(4, 10000);
		}
		if(isButtonPressed(2)){
			man_yellow_time++;
			if(man_yellow_time > 99){
				man_yellow_time = yellow_time;
			}
			setTimer(4, 10000);
		}
		if(isButtonPressed(3)){
			yellow_time = man_yellow_time;
			red_time = green_time + yellow_time;
			status = MAN_GREEN;
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
		}
		break;
	case MAN_GREEN:
		setTraffic(man_green_time, 4);
		if (timer_flag[3] == 1){
			HAL_GPIO_TogglePin(GREEN_0_GPIO_Port, GREEN_0_Pin);
			HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
			setTimer(3, 500);
		}
		if(timer_flag[4] == 1){
			status = INIT;
			red_time = 5;
			green_time = 3;
			yellow_time = 2;
		}
		if (isButtonPressed(1)){
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
			setTimer(3, 500);
			setTimer(4, 10000);
			status = INIT;
		}
		if(isButtonPressed(2)){
			man_green_time++;
			if(man_green_time > 99){
				man_green_time = green_time;
			}
			setTimer(4, 10000);
		}
		if(isButtonPressed(3)){
			green_time = man_green_time;
			red_time = green_time + yellow_time;
			status = INIT;
			set_X_axis_light(0, 0, 0);
			set_Y_axis_light(0, 0, 0);
		}
		break;
	default:
		break;
	}
}
