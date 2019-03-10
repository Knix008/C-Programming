/*
 ============================================================================
 Name        : GlobalVariableExample01.c
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

#define WIDTH  1000
#define HEIGHT 1000
unsigned int global[WIDTH][HEIGHT]; /* 4 x 1000 x 1000 bytes */

int main(void) {
	puts("GlobalVariable Example 01"); /* prints GlobalVariable Example 01 */
	unsigned int local[ WIDTH][HEIGHT];
	unsigned int ticks;

	ticks = get_cpu_cycle();
	for (unsigned int i = 0; i < WIDTH; i++) {
		for (unsigned int j = 0; j < HEIGHT; j++) {
			global[i][j] = i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	ticks = get_cpu_cycle();
	for (unsigned int i = 0; i < WIDTH; i++) {
		for (unsigned int j = 0; j < HEIGHT; j++) {
			local[i][j] = i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	return EXIT_SUCCESS;
}
