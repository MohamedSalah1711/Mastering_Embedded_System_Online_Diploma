/*
 * DC_motor.h
 *
 *  Created on: Aug 22, 2023
 *      Author: LEGION
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "state.h"
enum {
DC_idle,
DC_busy
}DC_state_name;
New_State(Dc_idle_state);
New_State(Dc_busy_state);
void DC_init();
extern void (*Dc_state)();



#endif /* DC_MOTOR_H_ */
