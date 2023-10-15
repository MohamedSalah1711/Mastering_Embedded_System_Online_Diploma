/*
 * File Name :UART_Driver.h
 * Learn-In-Depth,
 * Author: mohamed salah
*/ 

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "Platform_Types.h"
#include <math.h>
//-----------------------------
//Base addresses for UART
//-----------------------------
#define UART_BASE		0x29
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef enum{
	Asynchronous,
	Synchronous
	}UART_Mode_Select;
typedef enum{
	Disabled,
	Even_Parity = 2,
	Odd_Parity
}Parity_Mode;
typedef enum{
	One_bit,
	Two_bit
}Stop_Bit_Select;
typedef enum{
	Five_bit,
	Six_bit,
	Seven_bit,
	Eight_bit,
	Nine_bit=7
}Frame_Data_Size;
typedef enum{
	Baud_Rate_2400=2400,
	Baud_Rate_4800=4800,
	Baud_Rate_9600=9600,
	Baud_Rate_14400=14400,
	Baud_Rate_19200=19200,
	Baud_Rate_28800=28800,
	Baud_Rate_38400=38400,
	Baud_Rate_115200=115200,
}Baud_Rate_Select;
typedef struct{
	UART_Mode_Select Mode;
	Parity_Mode      Parity;
	Stop_Bit_Select	 Stop_Bit;
	Frame_Data_Size	 Size;			
	Baud_Rate_Select Baud_Rate;	
	}UART_ConfigType;
/*UART Registers*/
#define	UBRRL		(*(volatile uint8 *)(0x29))
#define	UCSRB		(*(volatile uint8 *)(0x2A))
#define	UCSRA		(*(volatile uint8 *)(0x2B))
#define	UDR			(*(volatile uint8 *)(0x2C))
#define	UCSRC		(*(volatile uint8 *)(0x40))
#define	UBRRH		(*(volatile uint8 *)(0x40))
/*Define Cpu Freq*/
#define F_CPU 8000000UL
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
void UART_init(UART_ConfigType* Uart_Config);
void UART_Deinit(void);
void UART_SendCharacter(uint8 character);
void UART_SendString(uint8* String);
uint8 UART_ReceiveCharacter(void);
void UART_ReceiveString(uint8* string);
#endif /* UART_DRIVER_H_ */