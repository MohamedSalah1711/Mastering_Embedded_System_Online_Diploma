/*
 * state.h
 *
 *  Created on: Aug 21, 2023
 *      Author: mohamed salah fathy
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>
#include <stdlib.h>
#define New_State(_StateName_) void _StateName_ ()
#define State(_StateName_) _StateName_

//states connection
void US_Get_signal (int d);
void DC_Speed(int s);
#endif /* STATE_H_ */
