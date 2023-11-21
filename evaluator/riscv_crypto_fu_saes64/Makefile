#Update the module name for the DuT
MODULE=riscv_crypto_fu_saes64


VMODULE=V$(MODULE)
DUTPATH=../../eut/riscv-crypto/rtl/crypto-fu/$(MODULE).v
OTHERPATH='../../eut/riscv-crypto/rtl/crypto-fu/riscv_crypto_fu_sboxes.v ../../eut/riscv-crypto/rtl/crypto-fu/riscv_crypto_fu_aes_mix_columns.v'
POWER_LIBS=../power_libs

include $(POWER_LIBS)/common.mk
