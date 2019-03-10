/*
 ============================================================================
 Name        : AdapterPatternExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyString.h"

int main(void)
{
	char *test_string = "0123456789";
	char result_string[100];

	printf("\nUsing Adapter Pattern Example 02!!!\n");
	printf("The string Length : %d\n", mystrlen(test_string));
	printf("The Copyied string : %s\n", mystrcpy(result_string, test_string));
	return EXIT_SUCCESS;
}
