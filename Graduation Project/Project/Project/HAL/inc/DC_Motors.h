/*
 * DC_Motors.h
 *
 *  Created on: Dec 6, 2023
 *      Author: LEGION
 */

#ifndef INC_DC_MOTORS_H_
#define INC_DC_MOTORS_H_
#include "Stm32F103C8_Advanced_Timer_Driver.h"
/*
 *
 * MACROS Definitions
 */
#define MOTORS_PWM_TIMER					TIM1
#define	MOTOR1_PORT							GPIOA
#define	MOTOR1_PIN1							PIN_4
#define	MOTOR1_PIN2							PIN_5
#define	MOTOR2_PORT							GPIOA
#define	MOTOR2_PIN1							PIN_6
#define	MOTOR2_PIN2							PIN_7
#define	MOTOR3_PORT							GPIOB
#define	MOTOR3_PIN1							PIN_0
#define	MOTOR3_PIN2							PIN_1
#define	MOTOR4_PORT							GPIOB
#define	MOTOR4_PIN1							PIN_13
#define	MOTOR4_PIN2							PIN_14
//-----------------------------
//User type definitions (ENUM)
//-----------------------------
typedef enum{
	Stop,
	Clock_Wise,
	CounterClock_Wise
}Motor_State;
typedef enum{
		M1,
		M2,
		M3,
		M4

}Motor_Number;

/*
 *
 * API's Prototype
 *
 */
void Dc_Motors_Init(void);
void DC_Motor_Move_Stop(Motor_Number Motor,Motor_State State);
void Stop_CAR(void);
#endif /* INC_DC_MOTORS_H_ */
