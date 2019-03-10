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

#define WIDTH 	1000
#define HEIGHT 	1000

static unsigned int global;

int main(void) {
	puts("GlobalVariable Example 03");
	unsigned int ticks;
	unsigned int local = 0;

	ticks = get_cpu_cycle();
	for (unsigned int i = 1; i <= WIDTH; i++) {
		for (unsigned int j = 1; j <= HEIGHT; j++) {
			global += i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	puts("global Variable : ");
	printf("%d\n", global);
	print_tick_count(ticks);

	ticks = get_cpu_cycle();
	for (unsigned int i = 1; i <= WIDTH; i++) {
		for (unsigned int j = 1; j <= HEIGHT; j++) {
			local += i * j;
		}
	}
	ticks = get_cpu_cycle() - ticks;
	puts("local Variable : ");
	printf("%d\n", local);
	print_tick_count(ticks);

	return EXIT_SUCCESS;
}
