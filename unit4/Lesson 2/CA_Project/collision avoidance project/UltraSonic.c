/*
 * UltraSonic.c
 *
 *  Created on: Aug 21, 2023
 *      Author: LEGION
 */

#include "UltraSonic.h"
unsigned int distance ;
void init_Us(){

	printf("Init Us\n");
}
New_State(Us_busy){
	/*init ultrasonic sensor*/
	init_Us();
	/*get a random number between 45 and 55*/
	distance = (rand() % ( 55- 45+ 1 ) + 45);
	printf("US_Busy state : Distance = %d \n",distance);
	US_Get_signal (distance);
	Us_state=State(Us_busy);
}
