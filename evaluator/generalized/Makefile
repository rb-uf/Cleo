MODULE=riscv_crypto_fu_ssha512
VMODULE=V$(MODULE)
DUTPATH=../../eut/riscv-crypto/rtl/crypto-fu/$(MODULE).v

all: $(VMODULE) toggle concat
	./obj_dir/$(VMODULE)
	./obj_dir/toggle
	./obj_dir/concat $(MODULE).csv
	rm actual.csv
	rm toggle.csv

$(VMODULE): obj_dir/$(VMODULE).mk
	make -C obj_dir -f $(VMODULE).mk $(VMODULE)

obj_dir/$(VMODULE).mk:
	verilator -Wall --trace --public-flat-rw --cc  -Wno-lint -CFLAGS "-DMODULENAME=$(VMODULE) -include $(VMODULE).h" $(DUTPATH) --exe tb_$(MODULE).cpp


toggle:
	g++ ../power_libs/toggle.cpp -o obj_dir/toggle

concat:
	g++ ../power_libs/concat.cpp -o obj_dir/concat

clean:
	rm -rf obj_dir 
	rm $(MODULE).csv
