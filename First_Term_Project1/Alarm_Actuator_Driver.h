/*
 * Alarm_Actuator_Driver.h
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_
#include "State.h"
#include "driver.h"
enum{
	waiting_driver,
	Alarm_On,
	Alarm_Off

}Alarm_Actuator_Sname;
extern void (*P_Alarm_actuator)();
void Alarm_init();
New_State(Alarm_waiting_driver_state);
New_State(Alarm_On_state);
New_State(Alarm_Off_state);

#endif /* ALARM_ACTUATOR_DRIVER_H_ */
