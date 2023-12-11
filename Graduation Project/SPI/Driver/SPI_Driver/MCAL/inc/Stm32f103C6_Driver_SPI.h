/*
 * Stm32f103C6_Driver_SPI.h
 *
 *  Created on: Oct 19, 2023
 *      Author: mohamed salah
 */

#ifndef INC_STM32F103C6_DRIVER_SPI_H_
#define INC_STM32F103C6_DRIVER_SPI_H_
//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
#include "Stm32f103C6_Driver_gpio.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------
struct S_IRQ_SRC{
	uint8 TXE:1;
	uint8 RXNE:1;
	uint8 ERRIE:1;
	uint8 Reserved:5;
};
typedef enum{
	EIGHT_BITS,SIXTEEN_BIT
}Frame_Format;
typedef enum{
	Idle_Zero,Idle_One
}Clock_Polarity;
typedef enum{
	First_Edge,Second_Edge
}Clock_Phase;
typedef enum{
	MSB,LSB
}Endian_Transmitt;
typedef enum{
	HardWare,SoftWare
}NSS_mode;
typedef enum{
	Polling,Interrupt
}Check_Mechanism;
typedef enum{
	fPCLK_2,fPCLK_4,fPCLK_8,fPCLK_16,fPCLK_32,fPCLK_64,
	fPCLK_128,fPCLK_256
}Baud_Rate;
typedef enum{
	Output,Input
}NSS_Pin_mode;
typedef enum{
	Master,Slave
}Device_Mode;
typedef enum{
	TXEIE,RXNEIE,ERRIE,TXDMAEN,RXDMAEN
}Interrupt_Type;
typedef struct{
	Frame_Format		Format;
	Clock_Polarity		Polarity;
	Clock_Phase			Phase;
	Endian_Transmitt	Endian_Format;
	NSS_mode			Nss_mode;
	Check_Mechanism		Interrupt_Pooling;
	Interrupt_Type		type;
	Baud_Rate			BaudRate;
	NSS_Pin_mode		Pin_Mode;
	Device_Mode			Mode;
	void (*P_CallBack)(struct S_IRQ_SRC IRQ_SRC);
}SPI_Config;
/*
 * Generic macros
 * */
#define BIT_SET			(1u)
#define BIT_RESET		(0u)
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
void MCAL_SPI_Init(SPI_Reg* SPIx,SPI_Config* Config);
void MCAL_SPI_Deinit(SPI_Reg* SPIx);
void MCAL_SPI_SendData(SPI_Reg* SPIx,uint16* P_bufferTx,Check_Mechanism Check);
void MCAL_SPI_ReceiveData(SPI_Reg* SPIx,uint16* P_bufferRx,Check_Mechanism Check);
void MCAL_SPI_TX_RX(SPI_Reg* SPIx,uint16* P_bufferRx,Check_Mechanism Check);
void MCAL_SPI_GPIO_Set_Pins(SPI_Reg* SPIx);
#endif /* INC_STM32F103C6_DRIVER_SPI_H_ */
