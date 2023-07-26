/*
 ============================================================================
 Name        : StdTypes
 Layer		 : Service layer
 Target		 : Generic
 Author      : Muhamed REDA
 Version     : 1.0
 Date		 : 26/07/2023
 Copyright   : This is an open source code for all embedded systems students
 Description : This file defines the standard data types
 ============================================================================
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/*************************************/
#define CPU_TYPE (CPU_TYPE_64)
/*************************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef float f32;

#endif
/*************************************/


//Standard type for API's return type
typedef enum{
	E_OK,		//API status OK
	E_NOK		//API status Not OK
}StdReturn;




#endif /* STDTYPES_H_ */
