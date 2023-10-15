/*
 * File Name :GPIO_Driver.h
 * Learn-In-Depth,
 * Author: mohamed salah
 */ 

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "Platform_Types.h"
//-----------------------------
//Base addresses for GPIO
//-----------------------------
#define GPIOA_BASE		0X39
#define GPIOB_BASE		0X36
#define GPIOC_BASE		0X33
#define GPIOD_BASE		0X30
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct {
	uint8 PINx_Port;
	uint8 DDRx_Port;
	uint8 PORTx_Port;		
}GPIO_typedef;
typedef enum {
	input_mode,output_mode
}GPIO_Mode;
typedef enum {
	PIN_LOW,PIN_HIGH
}PIN_Mode;
typedef struct {
	GPIO_Mode Mode;
	PIN_Mode Pin_State;
	uint8	PUD;  //@ref Pull up configration
	uint8 PIN_NUM;
}GPIO_PinConfig;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA						((GPIO_typedef *)GPIOA_BASE)
#define GPIOB						((GPIO_typedef *)GPIOB_BASE)
#define GPIOC						((GPIO_typedef *)GPIOC_BASE)
#define GPIOD						((GPIO_typedef *)GPIOD_BASE)
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NULL						((void *)0)
#define	SREG						(*(uint8*)(0x5F))
#define Enable_Global_Interrupt		SREG|=(1<<7);
#define PIN_LOW						0
#define PIN_HIGH					1
//-----------------------------
//Macros Configuration References
//-----------------------------
#define PIN_0	(0U)
#define PIN_1	(1U)
#define PIN_2	(2U)
#define PIN_3	(3U)
#define PIN_4	(4U)
#define PIN_5	(5U)
#define PIN_6	(6U)
#define PIN_7	(7U)
//@ref Pull up configration
#define Input_Pullup	(1u)
#define Input_NoPullup	(0u)
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
void MCAL_GPIO_Init(GPIO_typedef* GPIOx,GPIO_PinConfig* Pin_Config);
uint8 MCAL_GPIO_ReadPin(GPIO_typedef* GPIOx,uint8 Pin_Num);
uint8 MCAL_GPIO_ReadPort(GPIO_typedef* GPIOx);
void MCAL_GPIO_WritePin(GPIO_typedef* GPIOx,uint8 Pin_Num,uint8 value);
void MCAL_GPIO_WritePort(GPIO_typedef* GPIOx,uint8 value);
#endif /* GPIO_DRIVER_H_ */