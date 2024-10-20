################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/extra.c \
../src/sevenSeg_new.c \
../src/timing.c 

OBJS += \
./src/extra.o \
./src/sevenSeg_new.o \
./src/timing.o 

C_DEPS += \
./src/extra.d \
./src/sevenSeg_new.d \
./src/timing.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I/home/parallels/workspace/153aHardware/export/153aHardware/sw/153aHardware/standalone_domain/bspinclude/include -mlittle-endian -mxl-barrel-shift -mcpu=v11.0 -mno-xl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


