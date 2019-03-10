/*
 ============================================================================
 Name        : FactoryInterface.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include <stdlib.h>

#include "FactoryInterface.h"

int main(void)

{

	PRODUCT_HANDLE *product;

	puts("Switch Removal Example 01"); /* prints Switch Removal Example 01 */

	product = create_product_model(MODEL_X);

	print_model_name(product);

	product = create_product_model(MODEL_Y);

	print_model_name(product);

	product = create_product_model(MODEL_Z);

	print_model_name(product);

	product = create_product_model(MODEL_NONE);

	print_model_name(product);

	return EXIT_SUCCESS;

}

