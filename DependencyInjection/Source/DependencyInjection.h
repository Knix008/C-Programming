/*
 * DependencyInjection.h
 *
 *  Created on: 2016. 4. 26.
 *      Author: shkwon
 */

#ifndef DEPENDENCYINJECTION_H_
#define DEPENDENCYINJECTION_H_

#include "Message.h"
#include "Handler.h"

typedef struct dependencyinjection DEPENDENCY_INJECTION;

DEPENDENCY_INJECTION *createDependencyInjection(HANDLER *handler);
void run_handler(DEPENDENCY_INJECTION *di, MESSAGE *msg);

#endif /* DEPENDENCYINJECTION_H_ */
