/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Lenovo
 */

#include"software_timer.h"
#include"main.h"


//declare variable for timer
int timer_counter1;
int timer_counter2;
int timer_counter3;
int timer_counter4;




//set flag for 7SEG and led
int timer_AUTODEC_flag = 0;
int timer_LED_flag = 0;

int timer3_flag_finish = 0;

int counter_timer1_INC ;
int counter_timer1_DEC;



 int timer_flag1 = 0;
 int timer_flag2 = 0;
 int timer_flag3 = 0;
 int timer_flag4 = 0;

// set flag for INC and DEC 3s


//segment case
void zero()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	return;
}

void one()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, SET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	return;
}

void two()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, SET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}

void three()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}

void four()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, SET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}


void five()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, SET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}

void six()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, SET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}

void seven()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, SET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, SET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, SET);
	return;
}


void eight()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, RESET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}

void nine()
{
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, RESET);
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, RESET);
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, RESET);
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, RESET);
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, SET);
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, RESET);
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, RESET);
	return;
}



////declare seg buffet
//int index_7SEG = 0;
//int SEG_buffer[]={0,1,2,3,4,5,6,7,8,9};

//display 7SEG
void display7SEG1(int num){
//	num=SEG_buffer[index_7SEG];
	switch (num)
		{
		case 0:
			zero();
				break;
		case 1:
			one();
				break;
		case 2:
			two();
				break;
		case 3:
			three();
				break;
		case 4:
			four();
				break;
		case 5:
			five();
				break;
		case 6:
			six();
				break;
		case 7:
			seven();
				break;
		case 8:
			eight();
				break;
		case 9:
			nine();
				break;
		default:
				break;
		}
//	index_7SEG = index_7SEG + 1;
//	if(index_7SEG > 9){
//		index_7SEG = 0;
//	}
		return;
	}

//display LED
void display_LED(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	return;
}

//set timer 1 for SEG
void setTimer1(int duration1){
	timer_counter1 = duration1/10;
	return;
}
//setTimer 2 for LED
void setTimer2(int duration2){
	timer_counter2 = duration2/10;
	return;
}

void setTimer3(int duration3){
	timer_counter3 = duration3/10;
	return;
}

void setTimer4(int duration4){
	timer_counter4 = duration4/10;
	return;
}

////set Timer for INC todo 1s
//void set_Timer_for_INC3s(int INCtimer){
//	INCtimer = 100;
//	counter_timer1_INC = INCtimer;
//}
//void set_Timer_for_DEC3s(int DECtimer){
//	DECtimer = 100;
//	counter_timer1_DEC = DECtimer;
//}




//compare 7 seg FLag = 1 or not
int reset_AUTODEC_Flag(){
	if(timer_AUTODEC_flag == 1){
		timer_AUTODEC_flag = 0;
		return 1;
	}
	return 0;
}

//compare LED FLag = 1 or not
int reset_LED_Flag(){
	if(timer_LED_flag == 1){
		timer_LED_flag = 0;
		return 1;
	}
	return 0;
}

//Timer 3
int isTimer3Finish(){
	if(timer3_flag_finish == 1){
			timer3_flag_finish = 0;
			return 1;
		}
		return 0;
	}

//Timer Run
void timerRun(){
	if(timer_counter1 > 0){
		timer_counter1--;
	if(timer_counter1 <= 0){
		timer_flag1 = 1;
	}
	}
	if(timer_counter2 > 0){
			timer_counter2--;
		if(timer_counter2 <= 0){
			timer_flag2 = 1;
		}
	}
		if(timer_counter3 > 0){
				timer_counter3--;
			if(timer_counter3 <= 0){
				timer_flag3 = 1;
			}
		}
			if(timer_counter4 > 0){
					timer_counter4--;
				if(timer_counter4 <= 0){
					timer_flag4 = 1;
				}
			}

	return;
			}
