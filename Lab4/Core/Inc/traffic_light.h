/*
 * traffic_light.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"
#include "main.h"

void setTraffic(int x_axis, int y_axis);
void set_X_axis_light(int red, int green, int yellow);
void set_Y_axis_light(int red, int green, int yellow);
void countDown();

#endif /* INC_TRAFFIC_LIGHT_H_ */
