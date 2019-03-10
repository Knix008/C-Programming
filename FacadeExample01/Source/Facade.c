/*
 * Facade.c
 *
 *  Created on: 2016. 4. 10.
 *      Author: shkwon
 */

#include <stdio.h>
#include "Facade.h"

extern COMPUTER myComputer;

COMPUTER *getComputer( void )
{
	return &myComputer;
}

void turnOnComputer( COMPUTER *comp )
{
	comp->turnOn( comp );
}

void turnOffComputer( COMPUTER *comp )
{
	comp->turnOff( comp );
}

COMPUTER_INFORMATION *getComputerInformation( COMPUTER *comp )
{
	return comp->getInfo( comp );
}

void print_computer_information( COMPUTER_INFORMATION *info )
{
	printf( "The CPU : %s\n", info->CPU );
	printf( "Clock   : %dGHz\n", info->GHz );
	printf( "HDD     : %dGByte\n", info->HDD );
	printf( "RAM     : %dGByte\n", info->RAM );
}
