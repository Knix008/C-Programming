################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/Dependency.c \
../Source/DependencyInjection.c \
../Source/Handler.c 

OBJS += \
./Source/Dependency.o \
./Source/DependencyInjection.o \
./Source/Handler.o 

C_DEPS += \
./Source/Dependency.d \
./Source/DependencyInjection.d \
./Source/Handler.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


