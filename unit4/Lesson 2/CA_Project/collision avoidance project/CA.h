/*
 * CA.h
 *
 *  Created on: Aug 22, 2023
 *      Author: mohamed salah
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum {
CA_waiting,
CA_driving
}CA_state_name;
New_State(CA_waiting_state);
New_State(CA_driving_state);
extern void (*CA_state)();

#endif /* CA_H_ */
