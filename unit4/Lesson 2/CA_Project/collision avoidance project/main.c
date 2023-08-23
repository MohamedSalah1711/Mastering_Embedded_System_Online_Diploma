/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: LEGION
 */
#include "CA.h"
#include "UltraSonic.h"
#include "DC_motor.h"
void setup(){
	init_Us();
	DC_init();
	init_Us();
	CA_state = State(CA_waiting_state);
	Dc_state = State(Dc_idle_state);
	Us_state=State(Us_busy);
}

void main(){

	setup();
	while (1){
		Us_state();
		CA_state();
		Dc_state();
		for(int i =0 ; i<1500; i++);

	}

}
