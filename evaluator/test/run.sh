verilator -Wall --trace --cc simple_adder.v --exe tb_simple_adder.cpp
cd obj_dir
make -f Vsimple_adder.mk Vsimple_adder
./Vsimple_adder