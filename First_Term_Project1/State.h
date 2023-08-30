/*
 * State.h
 *
 *  Created on: Aug 27, 2023
 *      Author: mohamed salah
 */

#ifndef STATE_H_
#define STATE_H_
/*State Definition*/
#include <stdlib.h>
#include <stdio.h>
#define New_State(_statename_) void _statename_()
#define State(_statename_) _statename_

/*State Conncetion*/
void Set_Pressure_Val(int Pval);
void High_Pressure_Detected();
void Stop_Alarm();
void Start_Alarm();
#endif /* STATE_H_ */
