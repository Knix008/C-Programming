/*
 * Handler.h
 *
 *  Created on: 2016. 4. 26.
 *      Author: shkwon
 */

#ifndef HANDLER_H_
#define HANDLER_H_

#include "Message.h"

typedef enum {
	HANDLER_TYPE_A = 0, HANDLER_TYPE_B, HANDLER_NONE,
} HANDLER_TYPE;

typedef struct handler HANDLER;
void handle(HANDLER *handler, MESSAGE *msg);
HANDLER *getHandler(HANDLER_TYPE type);

#endif /* HANDLER_H_ */
