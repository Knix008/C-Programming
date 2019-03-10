/*
 ============================================================================
 Name        : FacadeExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Facade.h"

int main(void) {
	puts("Facade Example 01"); /* prints Facade Example 01 */

	COMPUTER *computer = getComputer();
	COMPUTER_INFORMATION *info = getComputerInformation( computer );

	turnOnComputer( computer );
	turnOffComputer( computer );
	print_computer_information( info );

	return EXIT_SUCCESS;
}
