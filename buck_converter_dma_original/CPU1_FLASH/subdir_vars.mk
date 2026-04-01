################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28004x_generic_flash_lnk.cmd 

SYSCFG_SRCS += \
../c2000.syscfg 

LIB_SRCS += \
C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib/ccs/Debug/driverlib.lib 

C_SRCS += \
../Controller.c \
./syscfg/board.c \
./syscfg/c2000ware_libraries.c \
../control_functions.c \
../ls_algorithm.c \
../transient_det.c 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./Controller.d \
./syscfg/board.d \
./syscfg/c2000ware_libraries.d \
./control_functions.d \
./ls_algorithm.d \
./transient_det.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt 

OBJS += \
./Controller.obj \
./syscfg/board.obj \
./syscfg/c2000ware_libraries.obj \
./control_functions.obj \
./ls_algorithm.obj \
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
"Controller.obj" \
"syscfg\board.obj" \
"syscfg\c2000ware_libraries.obj" \
"control_functions.obj" \
"ls_algorithm.obj" \
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
"Controller.d" \
"syscfg\board.d" \
"syscfg\c2000ware_libraries.d" \
"control_functions.d" \
"ls_algorithm.d" \
"transient_det.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" 

C_SRCS__QUOTED += \
"../Controller.c" \
"./syscfg/board.c" \
"./syscfg/c2000ware_libraries.c" \
"../control_functions.c" \
"../ls_algorithm.c" \
"../transient_det.c" 

SYSCFG_SRCS__QUOTED += \
"../c2000.syscfg" 


