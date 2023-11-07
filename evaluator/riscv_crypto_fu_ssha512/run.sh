#!/bin/bash

MODULE=riscv_crypto_fu_ssha512
VMODULE=V$MODULE


verilator -Wall --trace --public-flat-rw --cc -CFLAGS "-DMODULENAME=$VMODULE -include $VMODULE.h" ../../eut/riscv-crypto/rtl/crypto-fu/$MODULE.v --exe tb_$MODULE.cpp
cd obj_dir
make -f $VMODULE.mk $VMODULE
./$VMODULE


g++ ../toggle.cpp -o toggle
./toggle