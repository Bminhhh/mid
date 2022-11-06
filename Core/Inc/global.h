/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Lenovo
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//Include required library
#include"software_timer.h"
#include"button.h"
#include"main.h"


//define status of LED
#define RESET 1
#define INC 2
#define DEC 3
#define AUTODEC 4
#define INC_3S 5
#define DEC_3S 6
#define INIT 0


extern int status_BUTTONS;





#endif /* INC_GLOBAL_H_ */
