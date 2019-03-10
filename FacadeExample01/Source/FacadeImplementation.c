/*
 * FacadeImplementation.c
 *
 *  Created on: 2016. 4. 10.
 *      Author: shkwon
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Facade.h"

static void myTurnOn( COMPUTER *comp )
{
	printf( "Computer %s is Turned On!!!\n", comp->CPU );
}

static void myTurnOff( COMPUTER *comp )
{
	printf( "Computer %s is Turned Off!!!\n", comp->CPU );
}

static COMPUTER_INFORMATION *myGetInfo( COMPUTER *comp )
{
	COMPUTER_INFORMATION *info = NULL;

	if(( info = (COMPUTER_INFORMATION *)malloc( sizeof( COMPUTER_INFORMATION ))) == NULL )
	{
		printf("Cannot allocate memory for computer information!!!\n");
	}
	if(( info->CPU = (char *)malloc( strlen( comp->CPU ) + 1 )) == NULL )
	{
		printf("Cannot allocate memory for CPU information!!!\n");
	}
	if ( info == NULL )
	{
		return NULL;
	}
	if ( info->CPU == NULL )
	{
		free( info );
		return NULL;
	}
	strncpy( info->CPU, comp->CPU, strlen( comp->CPU ) + 1 );
	info->GHz  = comp->GHz;
	info->RAM = comp->RAM;
	info->HDD = comp->HDD;
	return info;
}

COMPUTER myComputer = { "Intel Centrino QuadCore", 3, 8, 500, myTurnOn, myTurnOff, myGetInfo };
