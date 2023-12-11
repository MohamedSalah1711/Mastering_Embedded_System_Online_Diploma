################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC_Sys_CLK.c \
../MCAL/Stm32f103C6_Driver_I2C.c \
../MCAL/Stm32f103C6_Driver_gpio.c \
../MCAL/Stm32f103C6_EXTI_Driver.c 

OBJS += \
./MCAL/RCC_Sys_CLK.o \
./MCAL/Stm32f103C6_Driver_I2C.o \
./MCAL/Stm32f103C6_Driver_gpio.o \
./MCAL/Stm32f103C6_EXTI_Driver.o 

C_DEPS += \
./MCAL/RCC_Sys_CLK.d \
./MCAL/Stm32f103C6_Driver_I2C.d \
./MCAL/Stm32f103C6_Driver_gpio.d \
./MCAL/Stm32f103C6_EXTI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC_Sys_CLK.o: ../MCAL/RCC_Sys_CLK.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/HAL/inc" -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/RCC_Sys_CLK.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_Driver_I2C.o: ../MCAL/Stm32f103C6_Driver_I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/HAL/inc" -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_Driver_I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_Driver_gpio.o: ../MCAL/Stm32f103C6_Driver_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/HAL/inc" -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_Driver_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32f103C6_EXTI_Driver.o: ../MCAL/Stm32f103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/HAL/inc" -I"D:/kerollos course/unit 2/unit8/I2C/Lesson/I2C/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32f103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

