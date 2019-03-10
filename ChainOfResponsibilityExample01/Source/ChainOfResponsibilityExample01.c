/*
 ============================================================================
 Name        : ChainOfResponsibilityExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct message
{
	unsigned int ID;
	char msg[ 100 ];
} MESSAGE;

typedef struct chain CHAIN;
struct chain
{
	unsigned int ID;
	char *name;
	CHAIN *next;
	bool (*do_somthing)( CHAIN *target, MESSAGE *msg );
};

bool myHandler( CHAIN *target, MESSAGE *msg )
{
	if ( target->ID == msg->ID )
	{
		printf( "Message Handler Name : %s, Message : %s\n", target->name, msg->msg );
		return true;
	}
	return false;
}

CHAIN handler1 = { 1, "1st Handler", NULL, myHandler };
CHAIN handler2 = { 2, "2nd Handler", &handler1, myHandler };
CHAIN handler3 = { 3, "3rd Handler", &handler2, myHandler };

bool sendMessage( CHAIN *target, MESSAGE *msg )
{
	while( target )
	{
		if( target->do_somthing( target, msg ))
		{
			break;
		}
		target = target->next;
	}
	if ( target == NULL )
	{
		printf( "Cannot handle the message : %d, %s\n", msg->ID, msg->msg );
		return false;
	}
	return true;
}

int main(void)
{
	MESSAGE message1 = { 1, "This Message is for the First!!!" };
	MESSAGE message2 = { 2, "This Message is for the Second!!!" };
	MESSAGE message3 = { 3, "This Message is for the Third!!!" };

	puts("Chain of Responsibility Example 01"); /* prints Chain of Responsibility Example 01 */

	sendMessage( &handler3, &message1 );
	sendMessage( &handler3, &message2 );
	sendMessage( &handler3, &message3 );

	return EXIT_SUCCESS;
}
