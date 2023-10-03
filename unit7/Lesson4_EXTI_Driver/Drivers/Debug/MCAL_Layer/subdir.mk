################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_Layer/Stm32f103C6_Driver_gpio.c \
../MCAL_Layer/Stm32f103C6_EXTI_Driver.c 

OBJS += \
./MCAL_Layer/Stm32f103C6_Driver_gpio.o \
./MCAL_Layer/Stm32f103C6_EXTI_Driver.o 

C_DEPS += \
./MCAL_Layer/Stm32f103C6_Driver_gpio.d \
./MCAL_Layer/Stm32f103C6_EXTI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_Layer/Stm32f103C6_Driver_gpio.o: ../MCAL_Layer/Stm32f103C6_Driver_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/HAL_Layer/inc" -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/MCAL_Layer/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_Layer/Stm32f103C6_Driver_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL_Layer/Stm32f103C6_EXTI_Driver.o: ../MCAL_Layer/Stm32f103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/HAL_Layer/inc" -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/MCAL_Layer/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL_Layer/Stm32f103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

