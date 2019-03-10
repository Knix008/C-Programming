/*
 * Factory.c
 *
 *  Created on: 2016. 4. 9.
 *      Author: shkwon
 */

#include <stdio.h>

#include "FactoryInterface.h"

struct product_handle

{

	MODEL_TYPE model_type;

	char *model_name;

	MODEL_TYPE (*get_model_type)(void);

	void (*print_model_name)(PRODUCT_HANDLE *handle);

};

static MODEL_TYPE model_x_get_type(void)

{

	return MODEL_X;

}

static MODEL_TYPE model_y_get_type(void)

{

	return MODEL_Y;

}

static MODEL_TYPE model_z_get_type(void)

{

	return MODEL_Z;

}

static MODEL_TYPE model_none_get_type(void)

{

	return MODEL_NONE;

}

static void print_each_model_name(PRODUCT_HANDLE *handle)

{

	printf("The Model Name : %s\n", handle->model_name);

}

static void print_model_name_none(PRODUCT_HANDLE *handle)

{

	printf("Nothing to print!!!\n");

}

MODEL_TYPE get_model_type(PRODUCT_HANDLE *handle)

{

	return handle->get_model_type();

}

void print_model_name(PRODUCT_HANDLE *handle)

{

	handle->print_model_name(handle);

}

PRODUCT_HANDLE model_x = { MODEL_X, "Model X", model_x_get_type,
		print_each_model_name };

PRODUCT_HANDLE model_y = { MODEL_Y, "Model Y", model_y_get_type,
		print_each_model_name };

PRODUCT_HANDLE model_z = { MODEL_Z, "Model Z", model_z_get_type,
		print_each_model_name };

PRODUCT_HANDLE model_none = { MODEL_NONE, "Model None", model_none_get_type,
		print_model_name_none };

PRODUCT_HANDLE *create_product_model(MODEL_TYPE model_type)

{

	switch (model_type)

	{

	case MODEL_X:

		return &model_x;

		break;

	case MODEL_Y:

		return &model_y;

		break;

	case MODEL_Z:

		return &model_z;

		break;

	default:

		printf("Cannot create your model!!!\n");

		return &model_none;

		break;

	}

}

