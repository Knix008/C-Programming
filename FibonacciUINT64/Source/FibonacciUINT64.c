/*
 ============================================================================
 Name        : FibonacciUINT64.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t fibo( uint16_t index )
{
	if(( index == 0 ) || ( index == 1))
	{
		return 1;
	}
	return fibo( index - 2 ) + fibo( index - 1 );
}

int main(void) {
	puts("Fibonacci Unsigned Integer 64 Example01"); /* prints Fibonacci Unsigned Integer 64 Example01 */
	unsigned int index = 50;

	printf("The %dth Fibonacci Number is : %llu\n", index, fibo( index ));
	return EXIT_SUCCESS;
}
