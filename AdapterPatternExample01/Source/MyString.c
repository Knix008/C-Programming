/*
 * MyString.c
 *
 *  Created on: 2016. 4. 4.
 *      Author: shkwon
 */
#include <string.h>

unsigned int mystrlen(const char *str)
{
	unsigned int length = strlen(str) + 1;

	if (str == NULL)
	{
		return 0;
	}
	return length;
}

char *mystrcpy(char *destination, const char* source)
{
	return strncpy(destination, source, strlen(source) + 1);
}

