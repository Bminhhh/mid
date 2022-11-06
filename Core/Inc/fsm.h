/*
 * fsm_AUTOMATIC_LED.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Lenovo
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

//header file of control status of LED


//Include necessary library
//#include"Lab2_Ex3.h"
#include"button.h"
#include"global.h"							//chen cac status khai bao tu cac bien toan cuc cua global.h

void fsm_simple_buttons_run();					//function that evoke process( run status )

void setTimer_FOR_10s(int time);

int timer_flag_INC;


#endif /* INC_FSM_H_ */
