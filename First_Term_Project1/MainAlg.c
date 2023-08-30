/*
 * MainAlg.c
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */
#include "MainAlg.h"
#include "driver.h"
const int threshold = (20u);
int pressure_val=0;
void (*P_main)();
void Set_Pressure_Val(int Pval){

	pressure_val = Pval;
	P_main = State(High_Pressure_Detecet_STATE);
}

New_State(High_Pressure_Detecet_idle_STATE){

	P_Main_Alg = idle_state;
}

New_State(High_Pressure_Detecet_STATE){
	P_Main_Alg = High_Pressure_Detecet;

	if(pressure_val >= threshold){
		High_Pressure_Detected();
	}

	P_main = State(High_Pressure_Detecet_idle_STATE);
}
