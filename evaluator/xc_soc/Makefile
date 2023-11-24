


#Update the module name for the DuT
MODULE=scarv_soc

SOC_HOME=../../eut/scarv-soc
XCRYPTO_RTL=../../eut/xcrypto/rtl
SCARV_CPU=../../eut/scarv-soc/extern/scarv-cpu



VMODULE=V$(MODULE)
# Top module
DUTPATH=$(SOC_HOME)/rtl/soc/$(MODULE).v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_addr_decode.v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_cpu_bus_bram_bridge.v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_cpu_bus_axi_bridge.v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_rsp_tracker.v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_error_rsp_stub.v
DUTPATH += $(SOC_HOME)/rtl/ic/ic_top.v

#  Random number generator sources
DUTPATH += $(SOC_HOME)/rtl/rng/scarv_rng_lfsr.v
DUTPATH += $(SOC_HOME)/rtl/rng/scarv_rng_top.v

#  Memories
DUTPATH += $(SOC_HOME)/rtl/mem/scarv_soc_bram_dual_sim.v

# Core
DUTPATH += $(XCRYPTO_RTL)/p_addsub/p_addsub.v 
DUTPATH += $(XCRYPTO_RTL)/p_shfrot/p_shfrot.v
DUTPATH += $(XCRYPTO_RTL)/xc_sha3/xc_sha3.v 
DUTPATH += $(XCRYPTO_RTL)/xc_sha256/xc_sha256.v
DUTPATH += $(XCRYPTO_RTL)/xc_aessub/xc_aessub.v
DUTPATH += $(XCRYPTO_RTL)/xc_aessub/xc_aessub_sbox.v
DUTPATH += $(XCRYPTO_RTL)/xc_aesmix/xc_aesmix.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu_divrem.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu_long.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu_mul.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu_pmul.v
DUTPATH += $(XCRYPTO_RTL)/xc_malu/xc_malu_muldivrem.v
DUTPATH += $(XCRYPTO_RTL)/b_bop/b_bop.v
DUTPATH += $(XCRYPTO_RTL)/b_lut/b_lut.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_common.vh
DUTPATH += $(SCARV_CPU)/rtl/core/frv_alu.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_asi.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_bitwise.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_core_fetch_buffer.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_core.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_counters.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_csrs.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_gprs.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_interrupts.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_leak.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_lsu.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_decode.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_execute.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_fetch.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_memory.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_register.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_pipeline_writeback.v
DUTPATH += $(SCARV_CPU)/rtl/core/frv_rngif.v

POWER_LIBS=../power_libs

TB= $(SOC_HOME)/verif/scarv-soc/memory_bus/memory_bus.cpp
TB += $(SOC_HOME)/verif/scarv-soc/memory_bus/memory_device.cpp
TB += $(SOC_HOME)/verif/scarv-soc/memory_bus/memory_device_ram.cpp
TB += $(SOC_HOME)/verif/scarv-soc/memory_bus/memory_device_uart.cpp
TB += $(SOC_HOME)/verif/scarv-soc/memory_bus/memory_device_gpio.cpp
TB += $(SOC_HOME)/verif/scarv-soc/axi4lite/a4l_slave_agent.cpp
TB += $(SOC_HOME)/verif/scarv-soc/dut_wrapper.cpp
TB += $(SOC_HOME)/verif/scarv-soc/testbench.cpp
TB += $(SOC_HOME)/verif/scarv-soc/main.cpp

all: $(VMODULE) # toggle concat
	./obj_dir/$(VMODULE)
	# ./obj_dir/toggle
	# ./obj_dir/concat $(MODULE).csv
	# rm actual.csv
	# rm toggle.csv
	# $(POWER_LIBS)/plotter $(MODULE).csv

$(VMODULE): obj_dir/$(VMODULE).mk
	make -C obj_dir -f $(VMODULE).mk $(VMODULE)

obj_dir/$(VMODULE).mk:
	verilator -Wall --trace --public-flat-rw --cc -I$(SCARV_CPU)/rtl/core/  -Wno-lint -CFLAGS "-DMODULENAME=$(VMODULE) -include $(VMODULE).h " $(DUTPATH) --top-module $(MODULE) --exe $(TB)


toggle:
	g++ $(POWER_LIBS)/toggle.cpp -o obj_dir/toggle

concat:
	g++ $(POWER_LIBS)/concat.cpp -o obj_dir/concat


clean:
	rm -rf obj_dir 
	rm -f $(MODULE).csv
	rm -f $(MODULE).svg
	rm -f ../results.txt
	rm -f contingency_tables.txt



