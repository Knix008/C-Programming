/*
 ============================================================================
 Name        : AnonymousStructureExample.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct named
{
	unsigned int value;
	struct {
		char *name;
		unsigned age;
	};
};

int main(void) {
	puts("Anonymous Structure Example 01"); /* prints Anonymous Structure Example 01 */
	struct named myStruct = { 100, { "SH Kwon", 44 }};
	printf( "The name : %s\n", myStruct.name );
	return EXIT_SUCCESS;
}
