################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
device/driverlib/%.obj: ../device/driverlib/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=5 --fp_mode=relaxed --fp_reassoc=off --include_path="_CPU1" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/driverlib/f28004x/driverlib/" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/FPUfastRTS/c28/include" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/4_CODE_micro/microcontroller_code/Fault-Location-Implementation_10khz/buck_converter_dma_original" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/4_CODE_micro/microcontroller_code/Fault-Location-Implementation_10khz/buck_converter_dma_original/device" --include_path="C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --include_path="C:/ti/c2000/C2000Ware_4_03_00_00/libraries/math/CLAmath/c28/include" --advice:performance=all --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --gen_data_subsections=on --abi=eabi --cla_signed_compare_workaround=on --preproc_with_compile --preproc_dependency="device/driverlib/$(basename $(<F)).d_raw" --include_path="C:/Users/mem21/OneDrive - Simon Fraser University (1sfu)/4_CODE_micro/microcontroller_code/Fault-Location-Implementation_10khz/buck_converter_dma_original/CPU1_RAM/syscfg" --obj_directory="device/driverlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


