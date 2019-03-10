/*
 * temp.c
 *
 *  Created on: 2017. 9. 16.
 *      Author: shkwon
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

void function(void) {
	unsigned int array[MAX_ARRAY_SIZE] = { 0 };

	/*
	 unsigned int i = 1;
	 unsigned int j = 10;

	 for (; (i < MAX_ARRAY_SIZE) && (j < MAX_ARRAY_SIZE / 2); i++, j++) {
	 array[i] = j;
	 }
	 */

	unsigned int j = 10;
	for (unsigned int i = 1; i < MAX_ARRAY_SIZE; i++) {
		array[i] = j;
		if (j >= (MAX_ARRAY_SIZE / 2)) {
			break;
		}
		j++;
	}

	for (unsigned int k = 0; k < MAX_ARRAY_SIZE; k++) {
		printf("The array value[ %d ] : %d\n", k, array[k]);
	}

	return;
}

int main(void) {
	puts("!!!Operator Precedence!!!"); /* prints !!!Operator Precedence!!! */
	function();
	return EXIT_SUCCESS;
}
