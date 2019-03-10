/*
 ============================================================================
 Name        : ArrayArguments01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void init_array_element(int array[])
{
	for (int i = 0; i < 100; i++)
	{
		array[i] = i;
	}
}

void change_array_element(int array[])
{
	for (int i = 0; i < 100; i++)
	{
		array[100 - (i + 1)] = i;
	}
}

void print_array_element(int array[])
{
	for (int i = 0; i < 100; i++)
	{
		printf("%3d", array[i]);
		if (i % 25 == 24)
		{
			printf("\n");
		}
	}
}

int main(void)
{
	puts("!!!Array Passing Test!!!"); /* prints !!!Array Passing Test!!! */
	int Array[100];
	init_array_element(Array);
	printf("===Before Changed===\n");
	print_array_element(Array);

	printf("===After Changed===\n");
	change_array_element(Array);
	print_array_element(Array);

	return EXIT_SUCCESS;
}

