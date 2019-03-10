/*
 * ChangeInformation.c
 *
 *  Created on: 2016. 3. 23.
 *      Author: shkwon
 */
#include <stdbool.h>
#include <string.h>

#include "InformationHandler.h"
#include "ChangeInformation.h"

INFO myinfo;

bool change_information( INFO *info )
{
	INFO *oldinfo = NULL;

	if( info == NULL )
	{
		return false;
	}
	oldinfo = get_information( );
	if ( oldinfo == NULL )
	{
		return false;
	}
	print_information( oldinfo );
	if( set_information( info ) == NULL )
	{
		return false;
	}
	return true;
}


