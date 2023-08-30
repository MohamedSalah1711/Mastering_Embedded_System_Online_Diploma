#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"
#include "driver.h"
#include "MainAlg.h"
#include "Pressure_Sensor_driver.h"
void setup(){
	

	GPIO_INITIALIZATION();
	Pressure_Sensor_init();
	Alarm_init();
}
int main () {
	
	setup();
	while(1){
		(*P_sensor)();
		(*P_main)();
		(*P_Alarm_monitor)();
		(*P_Alarm_actuator)();
		
	}
	
	
	
	
	
	
	return 0;
}