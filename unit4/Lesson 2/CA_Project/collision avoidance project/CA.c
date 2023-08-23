/*
 * CA.c
 *
 *  Created on: Aug 22, 2023
 *      Author: mohamed salah
 */
#include "CA.h"
unsigned int CA_speed=0;
unsigned int distance=0;
unsigned int threshold=50;

void (*CA_state)();
void US_Get_signal (int d){
	distance = d ;
	if(distance >= threshold ){
		CA_state = State(CA_waiting_state);
	}else{
		CA_state = State(CA_driving_state);
	}
	printf("US >>>>Distance = ^d>>>>CA \n",distance);
}
New_State(CA_waiting_state){
	CA_state_name = CA_waiting;
	CA_speed=0;
	printf("CA waiting state : distance = %d  speed = %d \n",distance,CA_speed);
	DC_Speed(CA_speed);

}
New_State(CA_driving_state){
	CA_state_name = CA_driving;
	CA_speed=30;
	printf("CA driving state : distance = %d  speed = %d \n",distance,CA_speed);
	DC_Speed(CA_speed);


}
