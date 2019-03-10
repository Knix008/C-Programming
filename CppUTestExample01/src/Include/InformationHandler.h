/*
 * InformationHandler.h
 *
 *  Created on: 2016. 3. 23.
 *      Author: shkwon
 */

#ifndef INCLUDE_INFORMATIONHANDLER_H_
#define INCLUDE_INFORMATIONHANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct INFORMATION
{
	char *name;
	int  age;
	bool alive;
}INFO;

INFO* get_information( void );
void  print_information( INFO *info );
INFO* set_information( INFO *info );

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_INFORMATIONHANDLER_H_ */
