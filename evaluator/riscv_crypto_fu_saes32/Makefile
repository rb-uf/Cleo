#Update the module name for the DuT
MODULE=riscv_crypto_fu_saes32


VMODULE=V$(MODULE)
DUTPATH=../../eut/riscv-crypto/rtl/crypto-fu/$(MODULE).v
POWER_LIBS=../power_libs

all: $(VMODULE) toggle concat
	./obj_dir/$(VMODULE)
	./obj_dir/toggle
	./obj_dir/concat $(MODULE).csv
	rm actual.csv
	rm toggle.csv

$(VMODULE): obj_dir/$(VMODULE).mk
	make -C obj_dir -f $(VMODULE).mk $(VMODULE)

# "riscv_crypto_fu_sboxes.v" was added below to fix a verilator error specific to this module
obj_dir/$(VMODULE).mk:
	verilator -Wall --trace --public-flat-rw --cc  -Wno-lint -CFLAGS "-DMODULENAME=$(VMODULE) -include $(VMODULE).h -include ../inputs_$(MODULE).h" $(DUTPATH) ../../eut/riscv-crypto/rtl/crypto-fu/riscv_crypto_fu_sboxes.v --top-module riscv_crypto_fu_saes32 --exe $(POWER_LIBS)/tb.cpp


toggle:
	g++ $(POWER_LIBS)/toggle.cpp -o obj_dir/toggle

concat:
	g++ $(POWER_LIBS)/concat.cpp -o obj_dir/concat

clean:
	rm -rf obj_dir 
	rm $(MODULE).csv
