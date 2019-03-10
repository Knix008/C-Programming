/*
 * ChangeInformationTest.cpp
 *
 *  Created on: 2016. 3. 23.
 *      Author: shkwon
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "InformationHandler.h"
#include "ChangeInformation.h"

// To delete warning message in pointer initialization to constant string
#pragma GCC diagnostic ignored "-Wwrite-strings" // Turn-off compiler warning option.

INFO newinfo;

// Define Mock Type Comparator
class MyTypeComparator: public MockNamedValueComparator
{
public:
	virtual bool isEqual(const void *object1, const void *object2)
	{
		return object1 == object2;
	}
	virtual SimpleString valueToString(const void *object)
	{
		return StringFrom(object);
	}
};

// Define Test Group here!!!
TEST_GROUP( CHANGE_INFORMATION ) {
	MyTypeComparator comparator;
	// Setup
	void setup() {
		// Install Type Comparator
		mock().installComparator("INFO*", comparator);
		// Global information
		myinfo.name = "Suho Kwon";
		myinfo.age = 44;
		myinfo.alive = true;

		// New information
		newinfo.name = "MJ Yoon";
		newinfo.age = 44;
		newinfo.alive = true;
	}
	// Teardown
	void teardown() {
		// Restore default value
		newinfo.name = "";
		newinfo.age = 0;
		newinfo.alive = false;

		// Uninstall Type Comparator
		mock().removeAllComparators();
		// Clear Mock
		mock().clear();
	}
};

// Define Mock
INFO* get_information( void )
{
	return (INFO*) mock().actualCall("get_information").returnPointerValueOrDefault(&myinfo);
}
void  print_information( INFO *info )
{
	mock().actualCall("print_information").withParameterOfType("INFO*", "info", &myinfo);
}

INFO* set_information(INFO *info)
{
	return (INFO*) mock().actualCall("set_information").withParameterOfType("INFO*", "info", &newinfo).returnPointerValueOrDefault(&myinfo);
}

// Test script starts here!!!
TEST( CHANGE_INFORMATION, ChangeInformationSuccess )
{
	// function name, parameter type, parameter name, parameter value for function.
	mock().expectOneCall("get_information").andReturnValue(&myinfo);                        // Record expected call
	mock().expectOneCall("print_information").withParameterOfType("INFO*","info", &myinfo); // Record expected call
	mock().expectOneCall("set_information").withParameterOfType("INFO*", "info", &newinfo); // Record expected call

	LONGS_EQUAL(true, change_information(&newinfo));   // Check the return value

	// We need to define comparator for this
	mock().checkExpectations();        //Check the expected calls and real calls
}

// Test script starts here!!!
TEST( CHANGE_INFORMATION, ChangeInformationGetInformationFailure )
{
	// function name, parameter type, parameter name, parameter value for function.
	mock().expectOneCall("get_information").andReturnValue((void*)NULL);                      // Record expected call
	//mock().expectOneCall("print_information").withParameterOfType("INFO*","info", &myinfo); // Record expected call
	//mock().expectOneCall("set_information").withParameterOfType("INFO*", "info", &newinfo); // Record expected call

	LONGS_EQUAL(false, change_information(&newinfo));   // Check the return value

	// We need to define comparator for this
	mock().checkExpectations();        //Check the expected calls and real calls
}

// Test script starts here!!!
TEST( CHANGE_INFORMATION, ChangeInformationSetInformationFailure )
{
	// function name, parameter type, parameter name, parameter value for function.
	mock().expectOneCall("get_information").andReturnValue(&myinfo);                      // Record expected call
	mock().expectOneCall("print_information").withParameterOfType("INFO*","info", &myinfo); // Record expected call
	mock().expectOneCall("set_information").withParameterOfType("INFO*", "info", &newinfo).andReturnValue((void*)NULL); // Record expected call

	LONGS_EQUAL(false, change_information(&newinfo));   // Check the return value

	// We need to define comparator for this
	mock().checkExpectations();        //Check the expected calls and real calls
}

// Test script starts here!!!
TEST( CHANGE_INFORMATION, ChangeInformationWithNUllParameter )
{
	LONGS_EQUAL(false, change_information(NULL));   // Check the return value
}
