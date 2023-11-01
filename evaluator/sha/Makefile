VERILOG_FILE = ../../eut/riscv-crypto/rtl/crypto-fu/riscv_crypto_fu_ssha512.v

all: run

run: Vriscv_crypto_fu_ssha512
	.obj_dir/Vriscv_crypto_fu_ssha512

Vriscv_crypto_fu_ssha512: obj_dir/Vriscv_crypto_fu_ssha512.mk
	make -C obj_dir -f Vriscv_crypto_fu_ssha512.mk Vriscv_crypto_fu_ssha512

obj_dir/Vriscv_crypto_fu_ssha512.mk:
	verilator -Wall --trace --cc $(VERILOG_FILE) --exe tb_riscv_crypto_fu_ssha512.cpp
	cd obj_dir

clean:
	rm -rf obj_dir