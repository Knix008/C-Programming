################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test/ChangeInformationTest.cpp \
../src/Test/CppUTestExample01.cpp 

OBJS += \
./src/Test/ChangeInformationTest.o \
./src/Test/CppUTestExample01.o 

CPP_DEPS += \
./src/Test/ChangeInformationTest.d \
./src/Test/CppUTestExample01.d 


# Each subdirectory must supply rules for building sources it contributes
src/Test/%.o: ../src/Test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I"/Users/shkwon/Documents/workspace/CppUTestExample01/src/Include" -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


