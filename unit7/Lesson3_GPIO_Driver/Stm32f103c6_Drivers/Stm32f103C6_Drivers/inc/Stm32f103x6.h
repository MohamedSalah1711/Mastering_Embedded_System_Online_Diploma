/* Learn-In-Depth
 * File name :Stm32f103x6.h
 *  Description: Header file for MCU stm32f103x6 >>>LQFP48
 * Created By: mohamed salah fathy
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//-----------------------------
//Includes
//-----------------------------
#include "Platform_Types.h"


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define SRAM_BASE 						(uint32) 0X20000000UL
#define FLASH_MEMORY_BASE 				(uint32) 0X08000000UL
#define PERIPHERALS_BASE 				(uint32) 0X40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS  (uint32) 0XE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE 0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIOA and GPIOB is fully used in >>> (MCU)LQFP48
#define GPIOA_BASE 0x40010800UL
#define GPIOB_BASE 0x40010C00UL
//GPIOA and GPIOB is partially used in >>> (MCU)LQFP48
#define GPIOC_BASE 0x40011000UL
#define GPIOD_BASE 0x40011400UL
//GPIOE is not used in >>> (MCU)LQFP48
#define GPIOE_BASE 0x40011800UL

#define EXTI_BASE  0x40010400UL
#define AFIO_BASE  0x40010000UL


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32 CRL;
	vuint32 CRH;
	vuint32 IDR;
	vuint32 ODR;
	vuint32 BSRR;
	vuint32 BRR;
	vuint32 LCKR;
}GPIO_Typedef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32 RCC_CR;
	vuint32 RCC_CFGR;
	vuint32 RCC_CIR;
	vuint32 RCC_APB2RSTR;
	vuint32 RCC_APB1RSTR;
	vuint32 RCC_AHBENR;
	vuint32 RCC_APB2ENR;
	vuint32 RCC_APB1ENR;
	vuint32 RCC_BDCR;
}RCC_Typedef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32 EXTI_IMR;
	vuint32 EXTI_EMR;
	vuint32 EXTI_RTSR;
	vuint32 EXTI_FTSR;
	vuint32 EXTI_SWIER;
	vuint32 EXTI_PR;
}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vuint32 AFIO_EVCR;
	vuint32 AFIO_MAPR;
	vuint32 AFIO_EXTICR1;
	vuint32 AFIO_EXTICR2;
	vuint32 AFIO_EXTICR3;
	vuint32 AFIO_EXTICR4;
	vuint32 RESERVED;
	vuint32 AFIO_MAPR2;
}AFIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA		((GPIO_Typedef *)GPIOA_BASE)
#define GPIOB		((GPIO_Typedef *)GPIOB_BASE)
#define GPIOC		((GPIO_Typedef *)GPIOC_BASE)
#define GPIOD		((GPIO_Typedef *)GPIOD_BASE)
#define GPIOE		((GPIO_Typedef *)GPIOE_BASE)
#define AFIO		((AFIO_Typedef*)AFIO_BASE)
#define EXTI		((EXTI_Typedef*)EXTI_BASE)
#define RCC			((RCC_Typedef*)RCC_BASE)
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define ENABLE_CLOCK_GPIOA()		(RCC->RCC_APB2ENR |= (1<<2))
#define ENABLE_CLOCK_GPIOB()		(RCC->RCC_APB2ENR |= (1<<3))
#define ENABLE_CLOCK_GPIOC()		(RCC->RCC_APB2ENR |= (1<<4))
#define ENABLE_CLOCK_GPIOD()		(RCC->RCC_APB2ENR |= (1<<5))
#define ENABLE_CLOCK_GPIOE()		(RCC->RCC_APB2ENR |= (1<<6))
//-*-*-*-*-*-*-*-*-*-*-*-
//Reset macros:
//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
#define GPIOA_RESET()		(RCC->RCC_APB2RSTR |= (1<<2))
#define GPIOB_RESET()		(RCC->RCC_APB2RSTR |= (1<<3))
#define GPIOC_RESET()		(RCC->RCC_APB2RSTR |= (1<<4))
#define GPIOD_RESET()		(RCC->RCC_APB2RSTR |= (1<<5))
#define GPIOE_RESET()		(RCC->RCC_APB2RSTR |= (1<<6))

//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NULL ((void *)0)
#define CNF_SHIFT (2U)
#define OUTPUT_MODE_E (4U)


#endif /* INC_STM32F103X6_H_ */
