/*
 * Pressure_Sensor_driver.c
 *
 *  Created on: Aug 27, 2023
 *      Author: mohamed salah
 */

#include "Pressure_Sensor_driver.h"
#include "driver.h"
#define delay_time 10000
void (*P_sensor)();
int Pressure=0;
void Pressure_Sensor_init(){

	P_sensor=State(reading_state);

}
New_State(reading_state){
	P_Sensor_StateName = reading ;

	Pressure=getPressureVal();

	Set_Pressure_Val(Pressure);


	P_sensor=State(waiting_state);

}
New_State(waiting_state){
	P_Sensor_StateName = waiting ;
	Delay(delay_time);
	P_sensor=State(reading_state);

}
