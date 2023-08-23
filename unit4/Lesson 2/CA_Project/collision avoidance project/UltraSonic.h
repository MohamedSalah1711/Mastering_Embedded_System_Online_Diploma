/*
 * UltraSonic.h
 *
 *  Created on: Aug 21, 2023
 *      Author: LEGION
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "state.h"
enum {
busy
}US_state_name;
New_State(Us_busy);
void init_Us();
void (*Us_state)();
#endif /* ULTRASONIC_H_ */
