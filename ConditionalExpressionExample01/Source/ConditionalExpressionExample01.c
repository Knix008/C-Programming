/*
 ============================================================================
 Name        : ConditionalExpressionExample01.c
 Author      : knix008
 Version     :
 Copyright   : Copyleft @2016, 2017
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#if defined(__GNUC__) && (defined(__MINGW32__) || defined( __MING64__))
static inline uint64_t get_cpu_cycle(void) {
	uint64_t ticks;

	__asm volatile("rdtsc" : "=A"(ticks));
	return ticks;
}
#elif defined(_MSC_BUILD)
#include <intrin.h>
#pragma intrinsic( __rdtsc)
static inline uint64_t get_cpu_cycle(void) {
	return __rdtsc();
}
#elif defined(__APPLE__)
static inline uint64_t get_cpu_cycle(void) {
	uint64_t ticks;
	__asm volatile("rdtsc" : "=A"(ticks));
	return ticks;
}
#endif

void print_tick_count(uint64_t input) {
#if defined(__GNUC__) && (defined(__MINGW32__) || defined( __MING64__))
	printf("The time tick counter : %I64d\n", input);
#elif defined(_MSC_BUILD)
	printf("The time tick counter : %I64d\n", input);
#elif defined(__APPLE__)
	printf("The time tick counter : %10" PRIu64 "\n", input);
#endif
}

#define MAX_TIMES 1000000
enum {
	FIRST = 0, SECOND
};

void init(unsigned int array[], unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		array[i] = i;
	}
}

int main(void) {
	puts("Conditional Expression Example 01"); /* prints Conditional Expression Example 01 */
	unsigned int flags = FIRST;
	unsigned int first[MAX_TIMES];
	unsigned int second[MAX_TIMES];
	unsigned int ticks;

	init(first, MAX_TIMES);
	init(second, MAX_TIMES);

	/* for() -> if() */
	ticks = get_cpu_cycle();
	for (unsigned int i = 0; i < MAX_TIMES; i++) {
		if (flags == FIRST) {
			first[i] = i * i;
		} else if (flags == SECOND) {
			second[i] = i + i;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	/* if() -> for() */
	ticks = get_cpu_cycle();
	if (flags == FIRST) {
		for (unsigned int i = 0; i < MAX_TIMES; i++) {
			first[i] = i * i;
		}
	} else {
		for (unsigned int i = 0; i < MAX_TIMES; i++) {
			second[i] = i + i;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	return EXIT_SUCCESS;
}
