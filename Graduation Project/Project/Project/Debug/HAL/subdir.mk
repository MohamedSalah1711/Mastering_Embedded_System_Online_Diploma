################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC_Motors.c \
../HAL/HC-05.c 

OBJS += \
./HAL/DC_Motors.o \
./HAL/HC-05.o 

C_DEPS += \
./HAL/DC_Motors.d \
./HAL/HC-05.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/DC_Motors.o: ../HAL/DC_Motors.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/DC_Motors.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/HC-05.o: ../HAL/HC-05.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/HC-05.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

