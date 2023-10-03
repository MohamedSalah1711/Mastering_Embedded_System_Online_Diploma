################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Key_pad/Keypad.c 

OBJS += \
./Key_pad/Keypad.o 

C_DEPS += \
./Key_pad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Key_pad/Keypad.o: ../Key_pad/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Key_pad/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Lcd_Driver/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/GPIO_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Key_pad/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

