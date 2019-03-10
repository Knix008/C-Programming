/*
 ============================================================================
 Name        : DijkstraExample01.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define WIDTH  5
#define HEIGHT WIDTH
#define INF    INT_MAX

int find_shortest_path(int input[], unsigned int visited[]) {
	unsigned int i;
	unsigned int min = UINT_MAX;
	unsigned int index = -1;

	/* Use just sequential search */
	for (i = 0; i < WIDTH; i++) {
		if (visited[i] == 0) {
			if ((min > input[i]) && (input[i] != INF)) {
				min = input[i];
				index = i;
			}
		}
	}
	return index;
}

void update_weight(int (*input)[WIDTH], unsigned int current,
		unsigned int index, unsigned int visited[]) {
	unsigned int i;

	for (i = 0; i < WIDTH; i++) {
		if (i != current) {
			if ((visited[i] == 0) && (i != index) && (input[index][i] != INF)) {
				if (input[current][i]
						> input[index][i] + input[current][index]) {
					input[current][i] = input[index][i] + input[current][index];
				}
			}
		}
	}
}

void dikstra(int (*input)[WIDTH]) {
	unsigned int next = 0;
	unsigned int i, j;
	unsigned int visited[WIDTH] = { 0 };

	/* Find shortest cost to each node */
	for (i = 0; i < HEIGHT; i++) {
		/* Mark fist node visited */
		visited[i] = 1;
		/* Find shortest path for each node */
		for (j = 0; j < WIDTH; j++) {
			next = find_shortest_path(input[i], visited);
			/* Any other minimum node? */
			if( next == -1 )
			{
				break;
			}
			/* Mark visited node */
			visited[next] = 1;
			/* Update weight to each node */
			update_weight(input, i, next, visited);
		}
		/* Clear for restart */
		memset(visited, 0, sizeof(visited));
	}
	return;
}

void print_path(int (*input)[WIDTH], char *message) {
	unsigned int i, j;

	printf("--------------------\n");
	printf(" %s Path Matrix\n", message);
	printf("--------------------\n");
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (input[i][j] == INT_MAX) {
				printf(" INF");
			} else {
				printf("%4d", input[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int main(void) {
	int input[][WIDTH] = { { 0, 4, 1, INF, INF }, { INF, 0, INF, INF, 4 }, {
	INF, 2, 0, 4, INF }, { INF, INF, INF, 0, 4 }, { INF, INF, INF, INF, 0 } };

	puts(" Dijkstra Example01"); /* prints Dijkstra Example01 */
	print_path(input, "Input");
	dikstra(input);
	print_path(input, "Output");
	return EXIT_SUCCESS;
}
