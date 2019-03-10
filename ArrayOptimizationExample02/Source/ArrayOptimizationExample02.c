
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

#define HEIGHT 100
#define WIDTH 1000

static unsigned int array[HEIGHT][WIDTH];

int main(void) {
	puts("Array Optimization 01");
	unsigned int ticks;

	ticks = get_cpu_cycle();
	for (unsigned int i = 0; i < HEIGHT; i++) {
		for (unsigned int j = 0; j < WIDTH; j++) {
			array[i][j] = i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	ticks = get_cpu_cycle();
	for (unsigned int i = 0; i < WIDTH; i++) {
		for (unsigned int j = 0; j < HEIGHT; j++) {
			array[j][i] = i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	return EXIT_SUCCESS;
}
