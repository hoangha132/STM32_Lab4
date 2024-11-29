/*
 * traffic_light.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */


#include "traffic_light.h"

void setTraffic(int x_axis, int y_axis){
	x_axis_time = x_axis;
	y_axis_time = y_axis;
}

void set_X_axis_light(int red, int green, int yellow){
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, red);
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, green);
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, yellow);
}
void set_Y_axis_light(int red, int green, int yellow){
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, red);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, green);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, yellow);
}

void countDown(){
	x_axis_time--;
	y_axis_time--;
}
