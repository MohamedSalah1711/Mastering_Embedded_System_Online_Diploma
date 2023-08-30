/*
 * MainAlg.h
 *
 *  Created on: Aug 28, 2023
 *      Author: mohamed salah
 */

#ifndef MAINALG_H_
#define MAINALG_H_
#include "State.h"
enum{
	High_Pressure_Detecet,
	idle_state
}P_Main_Alg;
extern void (*P_main)();
New_State(High_Pressure_Detecet_STATE);
New_State(High_Pressure_Detecet_idle_STATE);
#endif /* MAINALG_H_ */
