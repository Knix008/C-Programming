/*
 ============================================================================
 Name        : DecoratorExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Message
{
	char message[100];
} MESSAGE;

typedef struct Decorator DECORATOR;
struct Decorator
{
	char *decorator_name;
	DECORATOR *next_decorator;
	void (*do_something)(MESSAGE *msg);
};

void do_something_method(MESSAGE *msg)
{
	printf("Message : %s\n", msg->message);
	strcat(msg->message, "More!!!");
	return;
}

void do_decorator(DECORATOR *deco, MESSAGE *msg)
{
	do
	{
		deco->do_something( msg );
		deco = deco->next_decorator;
	}while(deco != NULL);
}

DECORATOR myThirdDecorator = { "Third Decorator", NULL, do_something_method };
DECORATOR mySecondDecorator = { "Second Decorator", &myThirdDecorator, do_something_method };
DECORATOR myFirstDecorator = { "First Decorator", &mySecondDecorator, do_something_method };

int main(void)
{
	puts("Decorator Example 01");
	MESSAGE msg = { "Let's enjoy!!!" };

	do_decorator(&myFirstDecorator, &msg);
	return EXIT_SUCCESS;
}

