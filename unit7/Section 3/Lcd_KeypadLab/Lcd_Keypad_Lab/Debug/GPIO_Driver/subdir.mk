################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_Driver/Stm32f103C6_Driver_gpio.c 

OBJS += \
./GPIO_Driver/Stm32f103C6_Driver_gpio.o 

C_DEPS += \
./GPIO_Driver/Stm32f103C6_Driver_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_Driver/Stm32f103C6_Driver_gpio.o: ../GPIO_Driver/Stm32f103C6_Driver_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Key_pad/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Lcd_Driver/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/GPIO_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO_Driver/Stm32f103C6_Driver_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

