/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Lenovo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


//debouncing fucntion for 3 buttons
void get_key_INPUT1(void);

void get_key_INPUT2(void);

void get_key_INPUT3(void);


//flag for 3 buttons
int reset_button_flag();
int inc__button_flag();
int dec_button_flag();

extern int RESET_flag1;

//flag  for 3 buttons 3S
int reset_button_flag3S();
int inc_button_flag3S();
int dec_button_flag3S();

#endif /* INC_BUTTON_H_ */
