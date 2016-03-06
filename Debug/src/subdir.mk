################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Linking_StringBuffer.cpp \
../src/Owned_StringBuffer.cpp \
../src/RefCount_StringBuffer.cpp \
../src/StringBuffer.cpp \
../src/main.cpp 

OBJS += \
./src/Linking_StringBuffer.o \
./src/Owned_StringBuffer.o \
./src/RefCount_StringBuffer.o \
./src/StringBuffer.o \
./src/main.o 

CPP_DEPS += \
./src/Linking_StringBuffer.d \
./src/Owned_StringBuffer.d \
./src/RefCount_StringBuffer.d \
./src/StringBuffer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


