################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c 

C_DEPS += \
./src/hal_entry.d 

OBJS += \
./src/hal_entry.o 

SREC += \
RA6M3E.srec 

MAP += \
RA6M3E.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/src" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra/fsp/inc" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra/fsp/inc/api" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra/fsp/inc/instances" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra_gen" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra_cfg/fsp_cfg/bsp" -I"C:/Users/yugut/Desktop/Workspace/e2studio/RA6M3E/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

