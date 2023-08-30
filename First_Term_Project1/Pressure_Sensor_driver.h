/*
 * Pressure_Sensor_driver.h
 *
 *  Created on: Aug 27, 2023
 *      Author: LEGION
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_
#include "State.h"
enum{
	reading,
	waiting

}P_Sensor_StateName;
extern void (*P_sensor)();
New_State(reading_state);
New_State(waiting_state);
void Pressure_Sensor_init();
#endif /* PRESSURE_SENSOR_DRIVER_H_ */
