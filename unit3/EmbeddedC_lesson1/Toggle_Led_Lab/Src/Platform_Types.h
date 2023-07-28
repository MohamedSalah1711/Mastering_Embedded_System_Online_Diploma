/*
 * Platform_Types.h
 * Specification of Platform Types AUTOSAR CP R20-11
 * Created on: Jul 27, 2023
 * Author: Mohamed salah fathy abdelhamid
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
/*CPU_TYPE_Definition*/
#define CPU_TYPE_8 			(8u)
#define CPU_TYPE_16 		(16u)
#define CPU_TYPE_32 		(32u)
#define CPU_TYPE_64 		(64u)
/*CPU_BYTE_ORDER*/
#define LOW_BYTE_ORDER  	(0u)
#define HIGH_BYTE_ORDER 	(1u)
/*CPU_BIT_ORDER*/
#define LSB_FIRST 			(0u)
#define MSB_FIRST 			(1u)

/*Symbols*/
#define CPU_TYPE 			CPU_TYPE_32
#define CPU_BIT_ORDER 		LSB_FIRST
#define CPU_BYTE_ORDER 		LOW_BYTE_FIRST

/*Boolean definitions*/
#ifndef TRUE
#define TRUE   				(1u)
#endif
#ifndef FALSE
#define FALSE 				(0u)
#endif
/*Type definitions*/
typedef unsigned char 		boolean;
typedef unsigned char 		uint8;
typedef unsigned short 		uint16;
typedef unsigned int 		uint32;
typedef unsigned long long 	uint64;
typedef signed char 		sint8;
typedef signed short 		sint16;
typedef signed int 			sint32;
typedef signed long long 	sint64;
typedef float  				float32;
typedef double				float64;
typedef void* 				VoidPtr;
typedef const void*			ConstVoidPtr;

#endif /* PLATFORM_TYPES_H_ */
