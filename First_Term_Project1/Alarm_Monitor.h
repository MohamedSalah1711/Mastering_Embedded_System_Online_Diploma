/*
 * Alarm_Monitor.h
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "State.h"
#define Alarm_Period 10000
enum{
	Alarm_OFF,
	Alarm_ON,
	Waiting

}Alarm_Monitor_Sname;
extern void (*P_Alarm_monitor)();
New_State(Alarm_OFF_state);
New_State(Alarm_ON_state);
New_State(Waiting_state);
#endif /* ALARM_MONITOR_H_ */
