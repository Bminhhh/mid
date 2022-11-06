/*x
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Lenovo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"


//Init Timer for flag
void timerRun();

//setTimer for autodec
void setTimer1(int duration1);
//set timer for LED
void setTimer2(int duration2);
void setTimer3(int duration3);

int isTimer3Finish();

extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;
extern int timer_flag4;




//int counter_timer1_INC = 0;
//int flag_timer1_INC = 0;
//int counter_timer1_DEC = 0;
//int flag_timer1_DEC = 0;

//set timer for INC and DEC 3s
//void set_Timer_for_INC3s(int INCtimer);
//void set_Timer_for_DEC3s(int DECtimer);

//runTimer for INC and DEC 3s
//void runTimer_INC1s();							//dk for 1s condition in 1s
//void runTimer_DEC1s();							//dk for 1s DEC condtion in 1s


#endif /* INC_SOFTWARE_TIMER_H_ */
