################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Layer/Keypad.c \
../HAL_Layer/Lcd.c 

OBJS += \
./HAL_Layer/Keypad.o \
./HAL_Layer/Lcd.o 

C_DEPS += \
./HAL_Layer/Keypad.d \
./HAL_Layer/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Layer/Keypad.o: ../HAL_Layer/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/HAL_Layer/inc" -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/MCAL_Layer/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_Layer/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL_Layer/Lcd.o: ../HAL_Layer/Lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/HAL_Layer/inc" -I"D:/kerollos course/unit 2/unit7/Lesson4_EXTI_Driver/Drivers/MCAL_Layer/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_Layer/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

