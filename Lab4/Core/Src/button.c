/*
 * button.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Welcome
 */


#include "button.h"

#define DURATION_FOR_AUTO_INCREASING 200;

int button_flag[4] = {0};

int KeyReg[4][4] = {
				   {0, 0, 0, 0},
		           {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
				   {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE},
				   {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}
};

int timeForKeyPress = 100;

int button_ports[4] = {0, BUTTON_0_GPIO_Port, BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port};
int button_pins[4] = {0, BUTTON_0_Pin, BUTTON_1_Pin, BUTTON_2_Pin};

int counterForButtonPress1s[4] = {0};

int isButtonPressed(int key){
	if(button_flag[key] == 1){
		button_flag[key] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int key){
	button_flag[key] = 1;
}
void getKeyInput(){
	for(int i = 1; i <= 3; i++){
		KeyReg[i][0] = KeyReg[i][1];
		KeyReg[i][1] = KeyReg[i][2];
		KeyReg[i][2] = HAL_GPIO_ReadPin(button_ports[i],button_pins[i]);
		if((KeyReg[i][0] == KeyReg[i][1]) && (KeyReg[i][1] == KeyReg[i][2])){
			if(KeyReg[i][3] != KeyReg[i][2]){
				KeyReg[i][3] = KeyReg[i][2];
				if(KeyReg[i][2] == PRESSED_STATE){
					subKeyProcess(i);
					timeForKeyPress = 100;
				}
			}else{
				timeForKeyPress--;
				if(timeForKeyPress == 0){
					KeyReg[i][3] = NORMAL_STATE;
				}
			}
		}
	}
}
