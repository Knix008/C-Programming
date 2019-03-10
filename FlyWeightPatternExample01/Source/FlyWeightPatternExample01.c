/*
 ============================================================================
 Name        : FlyWeightPatternExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct messasge
{
	char *msg;
} MESSAGE;

#define MAX_POOL_SIZE 10
#define MAX_NAME_LENGTH 100

typedef struct flyweight FLYWEIGHT;
typedef struct flyweight_factory FLYWEIGHT_FACTORY;

struct flyweight
{
	char key[MAX_NAME_LENGTH]; /* Flyweight intrincs state */
	bool empty;
	void (*operation)(char *key, MESSAGE *extrincs_state);
};

struct flyweight_factory
{
	FLYWEIGHT pool[MAX_POOL_SIZE];
	FLYWEIGHT *(*create)(FLYWEIGHT_FACTORY *factory, char *key);
	FLYWEIGHT *(*getFlyWeight)( FLYWEIGHT_FACTORY *factory, char *key );
};

static void print_flyweight_information(char *name, MESSAGE *extrincs_state)
{

	printf("The flyweight information : %s, %s\n", name, extrincs_state->msg);
}

FLYWEIGHT noneFlyWeight = {"None FlyWeight", false, print_flyweight_information};
static FLYWEIGHT *create(FLYWEIGHT_FACTORY *factory, char *key)
{
	FLYWEIGHT *temp;
	int i;

	/* Fine key */
	for (i = 0; i < MAX_POOL_SIZE; i++)
	{
		temp = &(factory->pool[i]);
		if (temp->empty == true)
		{
			continue;
		}
		if (strncmp(key, temp->key, strlen(key) + 1) == 0)
		{
			/* Found */
			printf("Found same flyweight!!!\n");
			return temp;
		}
	}
	/* Find empty slot */
	for (i = 0; i < MAX_POOL_SIZE; i++)

	{
		temp = &(factory->pool[i]);
		if (temp->empty == true)
		{
			break;
		}
	}
	/* Check end of pool */
	if (i >= MAX_POOL_SIZE)
	{
		printf("Cannot allocate flywight in pool!!!\n");
		return &noneFlyWeight;
	}
	strncpy(temp->key, key, strlen(key) + 1);
	temp->empty = false;
	temp->operation = print_flyweight_information;
	printf("Flyweight created: %d\n", i);
	return temp;
}

FLYWEIGHT *getFlyWeight( FLYWEIGHT_FACTORY *factory, char *key )
{
	FLYWEIGHT *temp = NULL;

	/* Fine key */
	for (int i = 0; i < MAX_POOL_SIZE; i++)
	{
		temp = &(factory->pool[i]);
		if (temp->empty == true)
		{
			continue;
		}
		if (strncmp(key, temp->key, strlen(key) + 1) == 0)
		{
			/* Found */
			printf("Found same flyweight!!!\n");
			return temp;
		}
	}
	printf("Cannot find flyweight!!!\n");
	return &noneFlyWeight;
}

void init_flyweight_factory(FLYWEIGHT_FACTORY *factory)
{
	for (int i = 0; i < MAX_POOL_SIZE; i++)
	{
		factory->pool[i].empty = true;
	}
}

FLYWEIGHT_FACTORY myFlyweightFactory = {{}, create, getFlyWeight};

int main(void)
{
	MESSAGE extrinc_state = { "Hello, My FlyWeight!!!" };
	puts("Fly Weight Pattern Example 01");

	init_flyweight_factory(&myFlyweightFactory); /* Make sure that all Flyweight pool is empty */
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight00");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight01");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight02");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight03");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight04");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight05");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight06");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight07");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight08");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight09");
	myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight10"); /* Cannot allocate flyweight in pool!!! */
	FLYWEIGHT *myFlyWeight = myFlyweightFactory.create(&myFlyweightFactory, "myFlyWeight10");
	myFlyWeight->operation(myFlyWeight->key, &extrinc_state);

	myFlyWeight = myFlyweightFactory.getFlyWeight( &myFlyweightFactory, "myFlyWeight09");
	myFlyWeight->operation(myFlyWeight->key, &extrinc_state);

	return EXIT_SUCCESS;
}
