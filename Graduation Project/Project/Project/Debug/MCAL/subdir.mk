################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32F103C8_Advanced_Timer_Driver.c \
../MCAL/Stm32f103C6_Driver_USART.c \
../MCAL/Stm32f103C6_Driver_gpio.c \
../MCAL/Stm32f103C6_EXTI_Driver.c 

OBJS += \
./MCAL/Stm32F103C8_Advanced_Timer_Driver.o \
./MCAL/Stm32f103C6_Driver_USART.o \
./MCAL/Stm32f103C6_Driver_gpio.o \
./MCAL/Stm32f103C6_EXTI_Driver.o 

C_DEPS += \
./MCAL/Stm32F103C8_Advanced_Timer_Driver.d \
./MCAL/Stm32f103C6_Driver_USART.d \
./MCAL/Stm32f103C6_Driver_gpio.d \
./MCAL/Stm32f103C6_EXTI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Stm32F103C8_Advanced_Timer_Driver.o: ../MCAL/Stm32F103C8_Advanced_Timer_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32F103C8_Advanced_Timer_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_Driver_USART.o: ../MCAL/Stm32f103C6_Driver_USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_Driver_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_Driver_gpio.o: ../MCAL/Stm32f103C6_Driver_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_Driver_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_EXTI_Driver.o: ../MCAL/Stm32f103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/unit 2/unit9/ProjectV2/Project/HAL/inc" -I"C:/unit 2/unit9/ProjectV2/Project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

