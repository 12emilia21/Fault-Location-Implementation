################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=2 --fp_mode=relaxed --fp_reassoc=on --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/FPUfastRTS/c28/include" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/device" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --advice:performance=all --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-18342559: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.15.0/sysconfig_cli.bat" -s "C:/ti/c2000/C2000Ware_4_03_00_00/.metadata/sdk.json" -d "F28004x" --script "C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/c2000.syscfg" -o "syscfg" --package F28004x_100PZ --part F28004x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-18342559 ../c2000.syscfg
syscfg/board.h: build-18342559
syscfg/board.cmd.genlibs: build-18342559
syscfg/board.opt: build-18342559
syscfg/pinmux.csv: build-18342559
syscfg/epwm.dot: build-18342559
syscfg/adc.dot: build-18342559
syscfg/c2000ware_libraries.cmd.genlibs: build-18342559
syscfg/c2000ware_libraries.opt: build-18342559
syscfg/c2000ware_libraries.c: build-18342559
syscfg/c2000ware_libraries.h: build-18342559
syscfg/clocktree.h: build-18342559
syscfg/: build-18342559

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=2 --fp_mode=relaxed --fp_reassoc=on --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/FPUfastRTS/c28/include" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/device" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --advice:performance=all --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/nacho/WorkspaceBoostHIL/buck_converter_dma/CPU1_FLASH__opt_for_speed__2/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


