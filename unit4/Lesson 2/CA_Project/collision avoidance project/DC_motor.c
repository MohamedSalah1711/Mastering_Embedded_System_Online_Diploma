/*
 * DC_motor.c
 *
 *  Created on: Aug 22, 2023
 *      Author: mohamed salah
 */
#include "DC_motor.h"
unsigned int speed;
void (*Dc_state)();

void DC_init(){
	printf("DC init \n");
}
void DC_Speed(int s){
	speed = s;
	Dc_state = State(Dc_busy_state);
	printf("CA >>>>>> DC  \n\n");
}
New_State(Dc_idle_state){

	DC_state_name = DC_idle;
	Dc_state = State(Dc_idle_state);
	printf("DC_idle_speed = %d\n",speed);
}
New_State(Dc_busy_state){
	DC_state_name = DC_busy;
	Dc_state = State(Dc_idle_state);
	printf("DC_busy_speed = %d\n",speed);

}
