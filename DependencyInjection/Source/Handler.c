/*
 * Handler.c
 *
 *  Created on: 2016. 4. 26.
 *      Author: shkwon
 */

#include <stdio.h>
#include "Message.h"
#include "Handler.h"

struct handler {
	void (*handle)(MESSAGE *msg);
};

void handler_A(MESSAGE *msg) {
	printf("This is HANDLER A : %s\n", msg->message);
}

void handler_B(MESSAGE *msg) {
	printf("This is HANDLER B : %s\n", msg->message);
}

HANDLER handler_type_a = { handler_A };
HANDLER handler_type_b = { handler_B };

HANDLER *getHandler(HANDLER_TYPE type) {
	switch (type) {
	case HANDLER_TYPE_A:
		return &handler_type_a;
		break;
	case HANDLER_TYPE_B:
		return &handler_type_b;
		break;
	default:
		return NULL;
		break;
	}
}

void handle(HANDLER *handler, MESSAGE *msg) {
	handler->handle(msg);
}
