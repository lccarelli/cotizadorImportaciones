################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/collections/Collections.c \
../src/collections/Dictionary.c \
../src/collections/LinkedList.c \
../src/collections/Set.c 

OBJS += \
./src/collections/Collections.o \
./src/collections/Dictionary.o \
./src/collections/LinkedList.o \
./src/collections/Set.o 

C_DEPS += \
./src/collections/Collections.d \
./src/collections/Dictionary.d \
./src/collections/LinkedList.d \
./src/collections/Set.d 


# Each subdirectory must supply rules for building sources it contributes
src/collections/%.o: ../src/collections/%.c src/collections/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


