/*
 * fsm_AUTOMATIC_LED.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Lenovo
 */


// Source file of control status of LED

#include "fsm.h"
#include"main.h"
#include"button.h"
#include "software_timer.h"




//declare counter
int counter = 0;
//int counter_for_AUTODEC = 1000;
//void setTimer_FOR_10s(int time){
//	counter_for_AUTODEC = time;
//}



//void change_TODO_BUTTONS(){
//	if(inc_button_flag() == 1){
//
////				setTimer3(500);
//				status_BUTTONS = INC;
//				//todo
//				counter = (counter + 1)%10;
//				display7SEG1(counter);
//				return;
//			}
//	if(dec_button_flag() == 1){
////				setTimer3(500);
//				status_BUTTONS = DEC;
//				//todo
//				if(counter>0){
//					counter = (counter - 1)%10;
//				}
//				else{
//					counter=9;
//				}
//				display7SEG1(counter);
//				return;
//			}
//	if(reset_button_flag() == 1){
//					status_BUTTONS = RESET;
//					//TODO
//					counter=0;
//					display7SEG1(counter);
//					return;
//		}
//
//}

void fsm_simple_buttons_run(){
	switch(status_BUTTONS){
	case INIT:
		display7SEG1(counter);
		if(inc_button_flag() == 1){
			status_BUTTONS = INC;
			counter = (counter + 1)%10;
		}
		if(reset_button_flag() == 1){
					status_BUTTONS = RESET;
				}
		if(dec_button_flag() == 1){
					status_BUTTONS = DEC;
				}
		status_BUTTONS = AUTODEC;
		setTimer2(10000);
		break;
	case RESET:
		counter = 0;
		display7SEG1(counter);
		status_BUTTONS = INIT;
		break;
	case INC:
		display7SEG1(counter);
		if(inc_button_flag() != 1){
			status_BUTTONS = INIT;
		}
		if(inc_button_flag3S() == 1){
			status_BUTTONS = INC_3S;
			counter = (counter + 1)%10;
			setTimer1(1000);
			}

		break;
	case INC_3S:
		if(timer_flag1 == 1){
			setTimer1(1000);
			counter = (counter + 1)%10;
		}
		if(inc_button_flag() != 1){
					status_BUTTONS = INIT;
				}
		break;
	case DEC:
			display7SEG1(counter);
			if(dec_button_flag() != 1){
				status_BUTTONS = INIT;
			}
			if(dec_button_flag3S() == 1){
				status_BUTTONS = DEC_3S;
				if(counter>0){
				counter = (counter - 1)%10;
					if(counter <= 0){
						counter = 9;
					}
				}
				setTimer1(1000);

			}
			break;
		case DEC_3S:
			if(timer_flag1 == 1){
				setTimer1(1000);
				if(counter>0){
					counter = (counter - 1)%10;
					if(counter <= 0){
						counter = 9;
				}
				}
			}
			if(dec_button_flag() != 1){
						status_BUTTONS = INIT;
					}
			break;
		case AUTODEC:
			if(timer_flag2 == 1){
				if(counter>0){
						counter = (counter - 1)%10;
						if(counter <= 0){
							counter = 9;
								}
				}
				setTimer2(10000);
			}
			break;
		default:
			break;

}
}
