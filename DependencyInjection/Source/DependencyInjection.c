/*
 ============================================================================
 Name        : DependencyInjection.c
 Author      : Suho Kwon
 Version     :
 Copyright   : Copyleft @2016
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Message.h"
#include "Handler.h"
#include "DependencyInjection.h"

int main(void) {
	puts("Dependency Injection Example 01"); /* prints Dependency Injection Example 01 */
	MESSAGE msg = { "Hello, World!!!" };

	HANDLER *handler = getHandler(HANDLER_TYPE_A);
	DEPENDENCY_INJECTION *di = createDependencyInjection(handler);
	run_handler(di, &msg);

	handler = getHandler(HANDLER_TYPE_B);
	di = createDependencyInjection(handler);
	run_handler(di, &msg);

	return EXIT_SUCCESS;
}
