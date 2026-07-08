################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28004x_cla_ram_lnk.cmd 

SYSCFG_SRCS += \
../c2000.syscfg 

CLA_SRCS += \
../cla_tasks.cla 

C_SRCS += \
./syscfg/board.c \
./syscfg/c2000ware_libraries.c \
../control_functions.c \
../main.c \
../moving_avg.c \
../transient_det.c 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c 

CLA_DEPS += \
./cla_tasks.d 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./syscfg/board.d \
./syscfg/c2000ware_libraries.d \
./control_functions.d \
./main.d \
./moving_avg.d \
./transient_det.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt 

OBJS += \
./syscfg/board.obj \
./syscfg/c2000ware_libraries.obj \
./cla_tasks.obj \
./control_functions.obj \
./main.obj \
./moving_avg.obj \
./transient_det.obj 

GEN_MISC_FILES += \
./syscfg/board.h \
./syscfg/board.cmd.genlibs \
./syscfg/pinmux.csv \
./syscfg/epwm.dot \
./syscfg/adc.dot \
./syscfg/c2000ware_libraries.cmd.genlibs \
./syscfg/c2000ware_libraries.h \
./syscfg/clocktree.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"syscfg\board.obj" \
"syscfg\c2000ware_libraries.obj" \
"cla_tasks.obj" \
"control_functions.obj" \
"main.obj" \
"moving_avg.obj" \
"transient_det.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\board.h" \
"syscfg\board.cmd.genlibs" \
"syscfg\pinmux.csv" \
"syscfg\epwm.dot" \
"syscfg\adc.dot" \
"syscfg\c2000ware_libraries.cmd.genlibs" \
"syscfg\c2000ware_libraries.h" \
"syscfg\clocktree.h" 

C_DEPS__QUOTED += \
"syscfg\board.d" \
"syscfg\c2000ware_libraries.d" \
"control_functions.d" \
"main.d" \
"moving_avg.d" \
"transient_det.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" 

CLA_DEPS__QUOTED += \
"cla_tasks.d" 

SYSCFG_SRCS__QUOTED += \
"../c2000.syscfg" 

C_SRCS__QUOTED += \
"./syscfg/board.c" \
"./syscfg/c2000ware_libraries.c" \
"../control_functions.c" \
"../main.c" \
"../moving_avg.c" \
"../transient_det.c" 


