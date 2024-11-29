/*
 * button.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"
#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag[4];

int isButtonPressed(int key);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
