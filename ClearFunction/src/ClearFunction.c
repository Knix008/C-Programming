/*
 ============================================================================
 Name        : ClearFunction.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_ENTRIES 47

static unsigned int Data[MAXIMUM_ENTRIES];

static void init_data_entries(void) {
	for (unsigned int i = 0; i < MAXIMUM_ENTRIES; i++) {
		Data[i] = 0;
	}
}

static unsigned int make_fibonacci_sequence(const unsigned xth) {
	/* Sanity Check */
	if (xth >= MAXIMUM_ENTRIES) {
		printf(
				"Cannot calculate fibonacci sequence number for more than : %d\n",
				MAXIMUM_ENTRIES);
		exit(1);
	}
	/* 1st and 2nd */
	if ((xth <= 0) || (xth == 1)) {
		Data[xth] = 1;
		return 1;
	}
	/* Others */
	if ((Data[xth - 2] != 0) && (Data[xth - 1] != 0)) {
		Data[xth] = Data[xth - 2] + Data[xth - 1];
	} else {
		Data[xth] = make_fibonacci_sequence(xth - 2)
				+ make_fibonacci_sequence(xth - 1);
	}
	return Data[xth];
}

static inline bool isEndofData(const unsigned int i, const unsigned int x) {
	return ((i < MAXIMUM_ENTRIES - 1) && (x != 0));
}

void print_data_entries(void) {
	for (unsigned int i = 0; isEndofData(i, Data[i]); i++) {
		printf("%3dth Fibonacci Number : %10d\n", i + 1, Data[i]);
	}
}

static unsigned int make_argument(int argc, const char *argv[]) {
	if (argc > 1) {
		return atoi(argv[1]);
	}
	return ( MAXIMUM_ENTRIES - 1);
}

int main(int argc, const char *argv[]) {
	unsigned int xth = 0;

	puts("Data manipulation"); /* prints Data manipulation */
	init_data_entries();
	xth = make_argument(argc, argv);
	make_fibonacci_sequence(xth);
	print_data_entries();
	return EXIT_SUCCESS;
}
