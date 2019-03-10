/*
 ============================================================================
 Name        : CommandLineParserExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_usage(void)
{
	printf("=============\n");
	printf("Usage:\n");
	printf("CommandLineParsingExample [-x<name>] [-y<name>][-z<name>]\n");
	printf("=============\n");
	exit(1);
}

bool xOption = false;
bool yOption = false;
bool zOption = false;
char xName[100] = { '\0' };
char yName[100] = { '\0' };
char zName[100] = { '\0' };

void parse_arguments(int argc, const char *argv[])
{
	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
		case 'x':
			printf("%s\n", &argv[1][2]);
			strncpy(xName, &argv[1][2], strlen(&argv[1][2]));
			xOption = true;
			break;
		case 'y':
			printf("%s\n", &argv[1][2]);
			strncpy(yName, &argv[1][2], strlen(&argv[1][2]));
			yOption = true;
			break;
		case 'z':
			printf("%s\n", &argv[1][2]);
			strncpy(zName, &argv[1][2], strlen(&argv[1][2]));
			zOption = true;
			break;
		default:
			printf("Wrong Argument: %s\n", argv[1]);
			print_usage();
			break;
		}
		++argv;
		--argc;
	}
}

void print_options(void)
{
	if ((xOption) || (yOption) || (zOption))
	{
		printf("The Option and Name : ");
		if (xOption)
		{
			printf("%s ", xName);
		}
		if (yOption)
		{
			printf("%s ", yName);
		}
		if (zOption)
		{
			printf("%s ", zName);
		}
		printf("\n");
	}
}

int main(int argc, const char *argv[])
{

	puts("Command Line Parsing Example 01"); /* prints Command Line Parsing Example 01 */
	printf("Program name: %s\n", argv[0]);
	parse_arguments(argc, argv);
	print_options();

	return EXIT_SUCCESS;
}
