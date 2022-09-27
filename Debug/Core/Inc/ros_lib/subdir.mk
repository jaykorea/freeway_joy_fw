################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/ros_lib/BufferedSerial.cpp \
../Core/Inc/ros_lib/duration.cpp \
../Core/Inc/ros_lib/time.cpp 

OBJS += \
./Core/Inc/ros_lib/BufferedSerial.o \
./Core/Inc/ros_lib/duration.o \
./Core/Inc/ros_lib/time.o 

CPP_DEPS += \
./Core/Inc/ros_lib/BufferedSerial.d \
./Core/Inc/ros_lib/duration.d \
./Core/Inc/ros_lib/time.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ros_lib/%.o Core/Inc/ros_lib/%.su: ../Core/Inc/ros_lib/%.cpp Core/Inc/ros_lib/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I/home/van/STM32CubeIDE/workspace_1.10.1/check/Core/Inc/ros_lib -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/Documents/STM32CubeIDE/workspace_1.7.0/check/Core/Inc/ros_lib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ros_lib

clean-Core-2f-Inc-2f-ros_lib:
	-$(RM) ./Core/Inc/ros_lib/BufferedSerial.d ./Core/Inc/ros_lib/BufferedSerial.o ./Core/Inc/ros_lib/BufferedSerial.su ./Core/Inc/ros_lib/duration.d ./Core/Inc/ros_lib/duration.o ./Core/Inc/ros_lib/duration.su ./Core/Inc/ros_lib/time.d ./Core/Inc/ros_lib/time.o ./Core/Inc/ros_lib/time.su

.PHONY: clean-Core-2f-Inc-2f-ros_lib

