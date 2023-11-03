#verilator -Wall --trace --cc simple_adder.v --exe tb_simple_adder.cpp



verilator -Wall --trace --public-flat-rw --cc ../../eut/riscv-crypto/rtl/crypto-fu/riscv_crypto_fu_ssha512.v --exe tb_internal.cpp
cd obj_dir
make -f Vriscv_crypto_fu_ssha512.mk Vriscv_crypto_fu_ssha512
./Vriscv_crypto_fu_ssha512