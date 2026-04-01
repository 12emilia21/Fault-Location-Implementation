################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=5 --fp_mode=relaxed --fp_reassoc=off --include_path="_FLASH" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/FPUfastRTS/c28/include" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original/device" --include_path="C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --advice:performance=all --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1200277804: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.15.0/sysconfig_cli.bat" -s "C:/ti/c2000/C2000Ware_4_03_00_00/.metadata/sdk.json" -d "F28004x" -p "F28004x_100PZ" -r "F28004x_100PZ" --script "C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original/c2000.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1200277804 ../c2000.syscfg
syscfg/board.h: build-1200277804
syscfg/board.cmd.genlibs: build-1200277804
syscfg/board.opt: build-1200277804
syscfg/pinmux.csv: build-1200277804
syscfg/epwm.dot: build-1200277804
syscfg/adc.dot: build-1200277804
syscfg/c2000ware_libraries.cmd.genlibs: build-1200277804
syscfg/c2000ware_libraries.opt: build-1200277804
syscfg/c2000ware_libraries.c: build-1200277804
syscfg/c2000ware_libraries.h: build-1200277804
syscfg/clocktree.h: build-1200277804
syscfg: build-1200277804

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=5 --fp_mode=relaxed --fp_reassoc=off --include_path="_FLASH" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/FPUfastRTS/c28/include" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original/device" --include_path="C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --advice:performance=all --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/CCS_workspace_clean/buck_converter_dma_original/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


