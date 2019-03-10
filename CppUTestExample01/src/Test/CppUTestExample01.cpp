//============================================================================
// Name        : CppUTestExample01.cpp
// Author      : Suho Kwon
// Version     :
// Copyright   : Copyleft @2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "CppUTest/CommandLineTestRunner.h"

int main( int argc, const char**argv )
{
	return CommandLineTestRunner::RunAllTests( argc, argv );
}
