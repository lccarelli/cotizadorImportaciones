################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/controllers/controllerArticulo.c \
../src/controllers/controllerInformes.c \
../src/controllers/controllerPosicionArancelaria.c \
../src/controllers/controllerTransporte.c 

OBJS += \
./src/controllers/controllerArticulo.o \
./src/controllers/controllerInformes.o \
./src/controllers/controllerPosicionArancelaria.o \
./src/controllers/controllerTransporte.o 

C_DEPS += \
./src/controllers/controllerArticulo.d \
./src/controllers/controllerInformes.d \
./src/controllers/controllerPosicionArancelaria.d \
./src/controllers/controllerTransporte.d 


# Each subdirectory must supply rules for building sources it contributes
src/controllers/%.o: ../src/controllers/%.c src/controllers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


