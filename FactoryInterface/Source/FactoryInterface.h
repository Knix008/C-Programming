/*
 * FactoryInterface.h
 *
 *  Created on: 2016. 4. 9.
 *      Author: shkwon
 */

#ifndef FACTORYINTERFACE_H_
#define FACTORYINTERFACE_H_

typedef enum

{

	MODEL_X = 0,

	MODEL_Y,

	MODEL_Z,

	MODEL_NONE

} MODEL_TYPE;

typedef struct product_handle PRODUCT_HANDLE;

#ifdef __cplusplus

extern "C" {

#endif

extern MODEL_TYPE get_model_type(PRODUCT_HANDLE *handle);

extern void print_model_name(PRODUCT_HANDLE *handle);

extern PRODUCT_HANDLE *create_product_model(MODEL_TYPE);

#ifdef __cplusplus

}

#endif

#endif /* FACTORYINTERFACE_H_ */
