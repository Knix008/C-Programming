#include <stdio.h>
#include <stdlib.h>

#include <string.h>
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

typedef struct NODE {
	int value;
	unsigned int height;
	struct NODE *left;
	struct NODE *right;
} NODE_T;

static inline int MAX(int a, int b) {
	return (a > b) ? a : b;
}

static inline int HEIGHT(NODE_T* node) {
	if (node == NULL) {
		return -1;
	}
	return (node->height);
}

NODE_T* single_rotate_left(NODE_T* parent) {
	NODE_T* child = parent->left;

	/* Rotate left */
	parent->left = child->right;
	child->right = parent;
	/* Update height */
	parent->height = MAX(HEIGHT(parent->left), HEIGHT(parent->right)) + 1;
	child->height = MAX(HEIGHT(child->left), parent->height) + 1;
	/* Return new parent */
	return child;
}

NODE_T* single_rotate_right(NODE_T *parent) {
	NODE_T* child = parent->right;

	/* Rotate right */
	parent->right = child->left;
	child->left = parent;
	parent->height = MAX(HEIGHT(parent->right), HEIGHT(parent->left)) + 1;
	child->height = MAX(HEIGHT(child->right), parent->height) + 1;
	/* Return new parent */
	return child;
}

NODE_T* double_rotate_left(NODE_T* node) {
	node->left = single_rotate_right(node->left);
	return single_rotate_left(node);
}

NODE_T* double_rotate_right(NODE_T* node) {
	node->right = single_rotate_left(node->right);
	return single_rotate_right(node);
}

NODE_T* make_node(int value) {
	NODE_T *temp;

	temp = (NODE_T*) malloc(sizeof(NODE_T));
	if (temp == NULL) {
		return NULL;
	}
	return temp;
}

NODE_T* insert_node(NODE_T* node, int value) {
	/* Is NULL? */
	if (node == NULL) {
		/* Make node */
		if ((node = make_node(value)) == NULL) {
			printf("Cannot create node!!!\n");
			return NULL;
		}
		node->value = value;
		node->height = 0;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	/* Left Insert? */
	if (value < node->value) {
		node->left = insert_node(node->left, value);
		if ((HEIGHT(node->left) - HEIGHT(node->right)) == 2) {
			/* Balancing */
			if (value < node->left->value) {
				node = single_rotate_left(node);
			} else {
				node = double_rotate_left(node);
			}
		}
	}
	/* Right Insert? */
	if (value > node->value) {
		node->right = insert_node(node->right, value);
		if ((HEIGHT(node->right) - HEIGHT(node->left)) == 2) {
			/* balancing */
			if (value > node->right->value) {
				node = single_rotate_right(node);
			} else {
				node = double_rotate_right(node);
			}
		}
	}
	/* Same Value? */
	if (value == node->value) {
		return node;
	}
	node->height = MAX(HEIGHT(node->left), HEIGHT(node->right)) + 1;
	return node;
}

void print_node_inorder(NODE_T* node) {
	if (node->left != NULL) {
		printf("%d : Go left!!!\n", node->value);
		print_node_inorder(node->left);
	}
	printf("Current : %d\n", node->value);
	if (node->right != NULL) {
		printf("%d : Go right!!!\n", node->value);
		print_node_inorder(node->right);
	}
	return;
}

void print_tree(NODE_T* node) {
	if (node == NULL) {
		return;
	}
	print_node_inorder(node);
	return;
}

int main(void) {
	int input[] = { 50, 60, 70, 90, 80, 75, 73, 72, 78 };
	unsigned int size = sizeof(input) / sizeof(int);
	unsigned int i = 0;
	NODE_T* tree = NULL;
	uint64_t ticks = 0;

	puts("AVL Tree Example01");
	puts("==================");

	/* Insert node */
	ticks = get_cpu_cycle();
	for (i = 0; i < size; i++) {
		tree = insert_node(tree, input[i]);
	}
	ticks = get_cpu_cycle() - ticks;
	print_tick_count(ticks);

	/* Tree traversal */
	print_tree(tree);
	printf("\n");

	return EXIT_SUCCESS;
}
