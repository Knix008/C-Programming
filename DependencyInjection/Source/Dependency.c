/*
 * Dependency.c
 *
 *  Created on: 2016. 4. 26.
 *      Author: shkwon
 */

#include <stdio.h>
#include "Message.h"
#include "Handler.h"
#include "DependencyInjection.h"

struct dependencyinjection {
	HANDLER *handler;
};

DEPENDENCY_INJECTION di = { NULL };

DEPENDENCY_INJECTION*createDependencyInjection(HANDLER *handler) {
	if (handler != NULL) {
		di.handler = handler;
	}
	return &di;
}

void run_handler(DEPENDENCY_INJECTION *di, MESSAGE *msg) {
	if ((di != NULL) && (di->handler != NULL)) {
		handle(di->handler, msg);
	}
}
