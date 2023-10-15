################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Lcd.c 

OBJS += \
./HAL/Lcd.o 

C_DEPS += \
./HAL/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Lcd.o: ../HAL/Lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit8/Uart/Lecture/USART/HAL/inc" -I"D:/kerollos course/unit 2/unit8/Uart/Lecture/USART/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

