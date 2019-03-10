#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF UINT_MAX

typedef struct EDGE {
	unsigned int node;
	unsigned int weight;
	struct EDGE *next;
} EDGE_T;

typedef struct NODE {
	int node;
	struct EDGE *edge;
} NODE_T;

void print_graph(NODE_T *graph, unsigned int size) {
	EDGE_T *edge;
	unsigned int i;

	for (i = 0; i < size; i++) {
		edge = graph->edge;
		if (edge == NULL) {
			printf("The node %d has no edge.\n", i);
			graph++;
			continue;
		}
		while (edge != NULL) {
			printf("The node %d --> %d : %d\n", i, edge->node, edge->weight);
			edge = edge->next;
		}
		graph++;
	}
	return;
}

void print_distance(unsigned int *distance, unsigned int size) {
	unsigned int i;

	if (distance == NULL) {
		return;
	}
	printf("----------------------------------------\n");
	printf("Distance : ");
	for (i = 0; i < size; i++) {
		if (distance[i] == INF) {
			printf(" INF");
			continue;
		}
		printf("%3d", distance[i]);
	}
	printf("\n----------------------------------------\n");
	return;
}

void print_set(unsigned int *set, unsigned int size) {
	unsigned int i;

	printf("Set : ");
	for (i = 0; i < size; i++) {
		printf(" %d", set[i]);
	}
	printf("\n");
	return;
}

unsigned int *init_distance(NODE_T *graph, unsigned int size) {
	unsigned int *distance = NULL;

	if ((distance = (unsigned int *) malloc(sizeof(unsigned int) * size))
			== NULL) {
		printf("Cannot allocate memory for distance data!!!\n");
		exit(-1);
	}
	memset(distance, INF, sizeof(unsigned int) * size);
	return distance;
}

unsigned int *init_set(unsigned int size) {
	unsigned int *set;

	if ((set = (unsigned int *) malloc(sizeof(unsigned int) * size)) == NULL) {
		printf("Cannot allocate memory for visited marking set!!!\n");
		exit(-1);
	}
	memset(set, 0, sizeof(unsigned int) * size);
	return set;
}

NODE_T *make_graph(int *input, unsigned int size) {
	NODE_T *graph = NULL;
	NODE_T *node = NULL;
	EDGE_T **edge = NULL;
	unsigned int i, j, weight;

	/* Allocate node pointers */
	if ((graph = (NODE_T *) malloc(sizeof(NODE_T) * size)) == NULL) {
		printf("Cannot allocate memory for nodes!!!\n");
		exit(-1);
	}
	/* Set fist node */
	node = graph;
	for (i = 0; i < size; i++) {
		/* Initialize all node */
		node->edge = NULL;
		node->node = i;
		edge = &(node->edge);
		/* Make edge linked list */
		for (j = 0; j < size; j++) {
			/* Get weight */
			weight = *((input + i * size) + j);
			/* Not itself and not INF */
			if ((weight != INF) && (weight != 0)) {
				if (((*edge) = (EDGE_T *) malloc(sizeof(EDGE_T))) == NULL) {
					printf("Cannot allocate memory for edges!!!\n");
					exit(-1);
				}
				(*edge)->node = j;
				(*edge)->weight = weight;
				(*edge)->next = NULL;
				edge = &((*edge)->next);
			}
		}
		/* Go next node */
		node++;
	}
	return graph;
}

static inline EDGE_T *get_shortest_path(EDGE_T *edge, unsigned int *set) {
	EDGE_T *min_edge = NULL;
	unsigned int min_weight = INF;

	if (edge == NULL) {
		return NULL;
	}
	/* Find shortest path */
	while (edge != NULL) {
		if ((edge->weight < min_weight) && (set[edge->node] == 0)) {
			min_weight = edge->weight;
			min_edge = edge;
		}
		edge = edge->next;
	}
	return min_edge;
}

unsigned int *dijkstra(NODE_T *graph, unsigned size) {
	unsigned int *distance;
	unsigned int *set;
	EDGE_T *edge;
	unsigned int i = 0;
	unsigned int weight;
	unsigned int node;

	/* Initialize distance and set */
	distance = init_distance(graph, size);
	set = init_set(size);
	set[0] = 1;
	distance[0] = 0;

	/* Initialize weight */
	edge = graph[0].edge;
	while (edge != 0) {
		distance[edge->node] = edge->weight;
		edge = edge->next;
	}

	/* Find shortest path( weight ) from start to each node */
	for (i = 0; i < size; i++) {
		set[i] = 1;
		edge = get_shortest_path(graph[i].edge, set);
		/* Check null adjacent node list */
		if (edge == NULL) {
			continue;
		}
		/* Check adjacent node. */
		while (edge != NULL) {
			node = edge->node;
			/* Check it is terminal node. */
			if (node == size - 1) {
				if (set[node] == 0) {
					weight = edge->weight;
					/* Check new path with less weight */
					if (distance[i] + weight < distance[node]) {
						distance[node] = distance[i] + weight;
					}
					break;
				}
			} else {/* Transit node */
				edge = graph[node].edge;
				while (edge != NULL) {
					if (set[edge->node] == 0) {
						weight = edge->weight;
						/* Check new path with less weight */
						if (distance[node] + weight < distance[edge->node]) {
							distance[edge->node] = distance[node] + weight;
						}
					}
					edge = edge->next;
				}
			}
		}
	}
	return distance;
}

int main(void) {
	int input[][5] = { { 0, 4, 1, INF, INF }, { INF, 0, INF, INF, 4 }, {
	INF, 2, 0, 4, INF }, { INF, INF, INF, 0, 4 }, { INF,
	INF, INF,
	INF, 0 } };
	unsigned int size = sizeof(input) / sizeof(input[0]);
	NODE_T *graph = NULL;
	unsigned int *distance;

	puts("Dijkstra Example03"); /* prints Dijkstra Example03 */
	graph = make_graph(input[0], size);
	print_graph(graph, size);
	distance = dijkstra(graph, size);
	print_distance(distance, size);

	return EXIT_SUCCESS;
}
