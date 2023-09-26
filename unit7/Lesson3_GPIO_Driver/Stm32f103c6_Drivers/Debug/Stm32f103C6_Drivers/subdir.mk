################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.c 

OBJS += \
./Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.o 

C_DEPS += \
./Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.o: ../Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Lesson3_GPIO_Driver/Stm32f103c6_Drivers/Stm32f103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103C6_Driver_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

