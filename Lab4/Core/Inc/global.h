/*
 * global.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "test.h"
#include "Scheduler.h"
#include "button.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "led7_segment.h"
#include "software_timer.h"
#include "traffic_light.h"
#include "main.h"

#define INIT 1
#define RED_GREEN 2
#define RED_YELLOW 3
#define GREEN_RED 4
#define YELLOW_RED 5
#define MAN_RED 6
#define MAN_YELLOW 7
#define MAN_GREEN 8

extern int timer_flag[10];
extern int timer_counter[10];
int x_axis_time;
int y_axis_time;
int led_buffer[4];
extern int status;
extern int red_time;
extern int green_time;
extern int yellow_time;
extern int man_red_time;
extern int man_green_time;
extern int man_yellow_time;

#endif /* INC_GLOBAL_H_ */
