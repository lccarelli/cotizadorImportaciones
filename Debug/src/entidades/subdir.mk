################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/entidades/Articulo.c \
../src/entidades/PosicionArancelaria.c \
../src/entidades/Transporte.c 

OBJS += \
./src/entidades/Articulo.o \
./src/entidades/PosicionArancelaria.o \
./src/entidades/Transporte.o 

C_DEPS += \
./src/entidades/Articulo.d \
./src/entidades/PosicionArancelaria.d \
./src/entidades/Transporte.d 


# Each subdirectory must supply rules for building sources it contributes
src/entidades/%.o: ../src/entidades/%.c src/entidades/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


