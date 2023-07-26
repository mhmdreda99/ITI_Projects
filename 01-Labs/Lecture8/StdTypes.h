/*
 ============================================================================
 Name        : StdTypes
 Layer		 : Service layer
 Target		 : Generic
 Author      : Muhamed REDA
 Version     : 1.0
 Date		 : 20/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : This file defines the standard data types
 ============================================================================
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

//Unsigned data types
typedef unsigned char u8;		//Unsigned number with max 8 bits long
typedef unsigned short u16;		//Unsigned number with max 16 bits long
typedef unsigned long int u32;	//Unsigned number with max 8 bits long

//Signed data types
typedef signed char s8;			//Signed number with max 8 bits long
typedef signed short s16;		//Signed number with max 8 bits long
typedef signed long int s32;		//Signed number with max 8 bits long

//Fraction numbers
typedef float f32;			//Float number with 32 bits long

//Standard type for API's return type
typedef enum{
	E_OK,		//API status OK
	E_NOK		//API status Not OK
}StdReturn;




#endif /* STDTYPES_H_ */
