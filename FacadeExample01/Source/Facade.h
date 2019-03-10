/*
 * Facade.h
 *
 *  Created on: 2016. 4. 10.
 *      Author: shkwon
 */

#ifndef FACADE_H_
#define FACADE_H_

typedef struct computer_information
{
	char *CPU;
	unsigned int GHz;
	unsigned int RAM;
	unsigned int HDD;
}COMPUTER_INFORMATION;

typedef struct computer COMPUTER;
struct computer
{
	char *CPU;
	unsigned int GHz;
	unsigned int RAM;
	unsigned int HDD;

	void (*turnOn)( COMPUTER *comp );
	void (*turnOff)( COMPUTER *comp );
	COMPUTER_INFORMATION *(*getInfo)( COMPUTER *comp );
};

#ifdef __cplusplus
extern "C" {
#endif

extern COMPUTER *getComputer( void );
extern void turnOnComputer( COMPUTER *comp );
extern void turnOffComputer( COMPUTER *comp );
extern COMPUTER_INFORMATION *getComputerInformation( COMPUTER *comp );
extern void print_computer_information( COMPUTER_INFORMATION *info );

#ifdef __cplusplus
}
#endif

#endif /* FACADE_H_ */
