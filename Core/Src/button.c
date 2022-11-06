/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Lenovo
 */

#include "button.h"
#include "main.h"

#define TIMER_FOR_1S 100

//keyTime for RESET button
int key_RESET_Time1 = NORMAL_STATE;
int key_RESET_Time2 = NORMAL_STATE;
int key_RESET_Time3 = NORMAL_STATE;
int key_RESET_Time4 = NORMAL_STATE;

//keyTime for INC button
int key_INC_Time1 = NORMAL_STATE;
int key_INC_Time2 = NORMAL_STATE;
int key_INC_Time3 = NORMAL_STATE;
int key_INC_Time4 = NORMAL_STATE;

//keyTime for DEC button
int key_DEC_Time1 = NORMAL_STATE;
int key_DEC_Time2 = NORMAL_STATE;
int key_DEC_Time3 = NORMAL_STATE;
int key_DEC_Time4 = NORMAL_STATE;


int counter_3S1 = 0;
int counter_3S2 = 0;
int counter_3S3 = 0;


int RESET_flag1 = 0;  //set flag for RESET button
int INC_flag1 = 0;  //set flag for INC button
int DEC_flag1 = 0;  //set flag for DEC button
int AUTODEC_flag1 = 0; //set flag for AUTODEC button


int RESET_flag3S = 0;  //set flag for RESET button 3S
int INC_flag3S = 0;  //set flag for INC button 3S
int DEC_flag3S = 0;  //set flag for DEC button 3S


int Timer_for_keyPress1 = TIMER_FOR_1S;
int Timer_for_keyPress2 = TIMER_FOR_1S;
int Timer_for_keyPress3 = TIMER_FOR_1S;


void sub_for_Process1(){
	//turn RESET FLAG ON
	RESET_flag1= 1;
}

void sub_for_Process2(){
	//turn INC FLAG ON
	INC_flag1= 1;
}

void sub_for_Process3(){
	//turn DEC FLAG ON
	DEC_flag1= 1;
}

void sub_for_Process4(){
	//turn DEC FLAG ON
	AUTODEC_flag1= 1;
}

//FLAG ON FOR 3S
void sub_for_Process3S1(){
	//turn RESET FLAG ON
	RESET_flag3S= 1;
}

void sub_for_Process3S2(){
	//turn INC FLAG ON
	INC_flag3S= 1;
}

void sub_for_Process3S3(){
	//turn DEC FLAG ON
	DEC_flag3S= 1;
}



//Set up reset flag button function
int reset_button_flag(){
	if(RESET_flag1 == 1){
		RESET_flag1 = 0;
		return 1;
	}
	return 0;
}
//setup for INC flag button function
int inc_button_flag(){
	if(INC_flag1 == 1){
		INC_flag1 = 0;
		return 1;
	}
	return 0;
}
//setup for DEC flag button function
int dec_button_flag(){
	if(DEC_flag1 == 1){
		DEC_flag1 = 0;
		return 1;
	}
	return 0;
}

////setup for AUTODEC flag button function
//int auto_button_flag(){
//	if(AUTODEC_flag1 == 1){
//		AUTODEC_flag1 = 0;
//		return 1;
//	}
//	return 0;
//}

//SETUP FOR RESET 3S FLAG FUNCTION
int reset_button_flag3S(){
	if(RESET_flag3S == 1){
		RESET_flag3S = 0;
		return 1;
	}
	return 0;
}
//setup for INC 3S flag button function
int inc_button_flag3S(){
	if(INC_flag3S == 1){
//		INC_flag3S = 0;
		return 1;
	}
	return 0;
}
//setup for DEC 3S flag button function
int dec_button_flag3S(){
	if(DEC_flag3S == 1){
		DEC_flag3S = 0;
		return 1;
	}
	return 0;
}


void get_key_INPUT1(){				//Evoke in timer every 10ms for RESET button
	key_RESET_Time1 = key_RESET_Time2;
	key_RESET_Time2 = key_RESET_Time3;
	key_RESET_Time3 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin); 			//Recent status of RESET button
	if((key_RESET_Time1 == key_RESET_Time2) && (key_RESET_Time2 == key_RESET_Time3)){	// debouncing condition
		if(key_RESET_Time4 != key_RESET_Time3){ 								//Pressed one time
			counter_3S1 = 0; 										//reset counter3s1
			key_RESET_Time4 = key_RESET_Time3;									//UPDATE STANDARD CONDITION AGAIN
			if(key_RESET_Time3 == PRESSED_STATE){
				sub_for_Process1();
			}
		}else{													//else nay la th nhan' de`
			Timer_for_keyPress1--;
			if(Timer_for_keyPress1 == 0){
				if(key_RESET_Time3 == PRESSED_STATE){
				Timer_for_keyPress1 = TIMER_FOR_1S;
				counter_3S1++;
				if(counter_3S1 >= 3){
				sub_for_Process3S1();

				}
				}
			}
	return;
}
	}
	}

void get_key_INPUT2(){				//Evoke in timer every 10ms for INC button
	key_INC_Time1 = key_INC_Time2;
	key_INC_Time2 = key_INC_Time3;
	key_INC_Time3 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin); 			//Recent status of INC button
	if((key_INC_Time1 == key_INC_Time2) && (key_INC_Time2 == key_INC_Time3)){			// debouncing condition
		if(key_INC_Time4 != key_INC_Time3){ 								//Pressed one time
			counter_3S2 = 0; 										//reset counter3s1
			key_INC_Time4 = key_INC_Time3;								//UPDATE STANDARD CONDITION AGAIN
			if(key_INC_Time3 == PRESSED_STATE){
				sub_for_Process2();
			}
		}else{													//else IS ALWAYS PRESSED STATE
			Timer_for_keyPress2--;
						if(Timer_for_keyPress2 == 0){
							if(key_INC_Time3 == PRESSED_STATE){
							Timer_for_keyPress2 = TIMER_FOR_1S;
							counter_3S2++;
							if(counter_3S2 >= 3){
							sub_for_Process3S2();

							}
							}
						}
				return;
			}
				}
				}



void get_key_INPUT3(){				//Evoke in timer every 10ms for DEC button
	key_DEC_Time1 = key_DEC_Time2;
	key_DEC_Time2 = key_DEC_Time3;
	key_DEC_Time3 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin); 			//Recent status of DEC button
	if((key_DEC_Time1 == key_DEC_Time2) && (key_DEC_Time2 == key_DEC_Time3)){			// debouncing condition
		if(key_DEC_Time4 != key_DEC_Time3){ 								//Pressed one time
			counter_3S3 = 0;
			key_DEC_Time4 = key_DEC_Time3;							//UPDATE STANDARD CONDITION AGAIN
			if(key_DEC_Time3 == PRESSED_STATE){
				sub_for_Process3();
			}

		}else{								//else is always pressed
			Timer_for_keyPress3--;
						if(Timer_for_keyPress3 == 0){
							if(key_DEC_Time3 == PRESSED_STATE){
							Timer_for_keyPress3 = TIMER_FOR_1S;
							counter_3S3++;
							if(counter_3S3 >= 3){				// signal to turnn on flag 3s for fsm step 2
							sub_for_Process3S3();

							}
							}
						}
				return;
			}
				}
				}




