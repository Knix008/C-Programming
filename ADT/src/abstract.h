/*
 * abstract.h
 *
 *  Created on: 2016. 2. 27.
 *      Author: shkwon
 */

#ifndef ABSTRACT_H_
#define ABSTRACT_H_

typedef struct MyAbstractDataTypeStructure *MyADT;

MyADT ADT_Create();
char *getAddress( MyADT adt );
void setAddress( MyADT adt );

#endif /* ABSTRACT_H_ */
