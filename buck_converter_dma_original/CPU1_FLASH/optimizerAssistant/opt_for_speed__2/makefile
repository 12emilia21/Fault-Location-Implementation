################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Controller.obj" \
"./syscfg/board.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./control_functions.obj" \
"./device/device.obj" \
"./device/f28004x_codestartbranch.obj" \
"../28004x_generic_flash_lnk.cmd" \
"C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib/ccs/Debug/driverlib.lib" \
$(GEN_CMDS__FLAG) \
-lc2000ware_libraries.cmd.genlibs \
-lrts2800_fpu32_eabi.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include device/subdir_vars.mk
-include subdir_rules.mk
-include device/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
buck_converter_dma.out \

EXE_OUTPUTS__QUOTED += \
"buck_converter_dma.out" \

BIN_OUTPUTS += \
buck_converter_dma.hex \

BIN_OUTPUTS__QUOTED += \
"buck_converter_dma.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "buck_converter_dma.out"

# Tool invocations
buck_converter_dma.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=2 --fp_mode=relaxed --fp_reassoc=on --advice:performance=all --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"buck_converter_dma.map" --heap_size=0x200 --stack_size=0x3F8 --warn_sections -i"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/lib" -i"C:/ti/c2000/C2000Ware_4_03_00_00" -i"C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg" -i"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --reread_libs --define=_FLASH --diag_wrap=off --display_error_number --xml_link_info="buck_converter_dma_linkInfo.xml" --entry_point=code_start --rom_model -o "buck_converter_dma.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

buck_converter_dma.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/hex2000" --diag_wrap=off -o "buck_converter_dma.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Controller.obj" "syscfg\board.obj" "syscfg\c2000ware_libraries.obj" "control_functions.obj" "device\device.obj" "device\f28004x_codestartbranch.obj" 
	-$(RM) "Controller.d" "syscfg\board.d" "syscfg\c2000ware_libraries.d" "control_functions.d" "device\device.d" 
	-$(RM) "device\f28004x_codestartbranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-if 0 == 1  mkdir "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation"
	-if 0 == 1  C:/TDM-GCC-64/bin/g++  -c -DCLB_SIM -IC:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/src -IC:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/include/type2 -IC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma -IC:/TDM-GCC-64/bin/include -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MFC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/clb_sim.d -MTC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/clb_sim.o -IC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg   -fno-threadsafe-statics  -oC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/clb_sim.o C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg/clb_sim.cpp
	-if 0 == 1  C:/TDM-GCC-64/bin/g++ -DCLB_SIM -Og -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,-Map,C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/simulation_output.map -LC:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/build/src -oC:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/simulation_output.exe C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/simulation/clb_sim.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_FSM_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_HLC_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_LUT4_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_OutputLUT_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_counter_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_counter_top_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_FSM_top_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_LUT4_top_SC_model.o C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type2/CLB_OutputLUT_top_SC_model.o  -Wl,--start-group -lsystemc -Wl,--end-group
	-if 0 == 1  "./simulation/simulation_output.exe"
	-if 0 == 1  C:/ti/ccs1210/ccs/tools/node/node.exe "C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/dot_file_libraries/clbDotUtility.js"  "C:/ti/c2000/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/" "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg" "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg/clb.dot"
	-if 0 == 1  mkdir "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/diagrams"
	-if 0 == 1  C:/ti/ccs1210/ccs/tools/node/node.exe "C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/.meta/generate_diagrams.js" "C:/ti/c2000/C2000Ware_4_03_00_00" "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/diagrams" "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

