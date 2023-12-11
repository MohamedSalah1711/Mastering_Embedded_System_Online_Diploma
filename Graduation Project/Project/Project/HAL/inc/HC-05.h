/*
 * HC-05.h
 *
 *  Created on: Dec 5, 2023
 *      Author: mohamed salah
 */

#ifndef INC_HC_05_H_
#define INC_HC_05_H_
/*
 *
 * HAL Layer includes MCAL layer
 *
 */
#include "Stm32f103C6_Driver_USART.h"
extern uint16 Received_char;

/*
 *
 * Define Macros
 */
#define Bluetooth_Uart					USART2
#define Default_Baud					Baud_Rate_9600

/*
 *  	API Prototype
 */
void HAL_HC05_Init();
void HAL_HC05_Deinit();
void HAL_HC05_RecieveChar(void);

#endif /* INC_HC_05_H_ */
