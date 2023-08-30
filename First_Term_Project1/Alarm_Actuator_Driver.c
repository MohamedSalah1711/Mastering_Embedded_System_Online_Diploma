/*
 * Alarm_Actuator_Driver.c
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */


#include "Alarm_Actuator_Driver.h"
void (*P_Alarm_actuator)();
void Alarm_init(){
	Set_Alarm_actuator(1);
	P_Alarm_actuator = State(Alarm_waiting_driver_state);
}
void Stop_Alarm(){

	P_Alarm_actuator = State(Alarm_Off_state);

}
void Start_Alarm(){

	P_Alarm_actuator = State(Alarm_On_state);


}
New_State(Alarm_waiting_driver_state){

	Alarm_Actuator_Sname = waiting_driver;

}
New_State(Alarm_On_state){
	Alarm_Actuator_Sname = Alarm_On;
	 Set_Alarm_actuator(0);
	 P_Alarm_actuator = State(Alarm_waiting_driver_state);
}

New_State(Alarm_Off_state){
	Alarm_Actuator_Sname = Alarm_Off;
	Set_Alarm_actuator(1);
	P_Alarm_actuator = State(Alarm_waiting_driver_state);
}
