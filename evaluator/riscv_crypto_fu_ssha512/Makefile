MODULE=riscv_crypto_fu_ssha512
VMODULE=V$(MODULE)
DUTPATH=../../eut/riscv-crypto/rtl/crypto-fu/$(MODULE).v

all: $(VMODULE) toggle
	./obj_dir/$(VMODULE)
	./obj_dir/toggle

$(VMODULE): obj_dir/$(VMODULE).mk
	make -C obj_dir -f $(VMODULE).mk $(VMODULE)

obj_dir/$(VMODULE).mk:
	verilator -Wall --trace --public-flat-rw --cc -CFLAGS "-DMODULENAME=$(VMODULE) -include $(VMODULE).h" $(DUTPATH) --exe tb_$(MODULE).cpp


toggle:
	g++ toggle.cpp -o obj_dir/toggle

clean:
	rm -rf obj_dir 
	rm actual.csv 
	rm toggle.csv
