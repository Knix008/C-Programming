/*
 ============================================================================
 Name        : ArrayDelimiterExample01.c
 Author      : knix008
 Version     :
 Copyright   : Copyleft @2016, 2017
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DELIMITER '\0'

void function( char array[] )
{
	unsigned int i = 0;

	printf("Array has : ");
	while( array[ i ] != DELIMITER )
	{
		printf("%c", array[i]);
		i++;
	}
	printf(".\n");
}

int main(void) {
	puts("Array Delimiter Example 01"); /* prints ArrayDelimiter Example 01 */

	char array[] = { "HELLO, WORLD!!!" };
	function( array );

	return EXIT_SUCCESS;
}
