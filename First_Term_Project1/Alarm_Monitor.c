/*
 * Alarm_Monitor.c
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */
#include "driver.h"
#include "Alarm_Monitor.h"
void (*P_Alarm_monitor)() = State(Alarm_OFF_state) ;
void High_Pressure_Detected(){

	P_Alarm_monitor = State(Alarm_ON_state);

}

New_State(Alarm_OFF_state){

	Alarm_Monitor_Sname = Alarm_OFF;
	
}
New_State(Alarm_ON_state){
	Alarm_Monitor_Sname = Alarm_ON;

	Start_Alarm();


	P_Alarm_monitor = State(Waiting_state);

}
New_State(Waiting_state){
	Alarm_Monitor_Sname = Waiting;
	Delay(Alarm_Period);
	Stop_Alarm();
	P_Alarm_monitor = State(Alarm_OFF_state);

}
