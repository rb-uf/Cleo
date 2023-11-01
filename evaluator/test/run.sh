#verilator -Wall --cc simple_adder.v --exe tb_simple_adder.cpp
verilator -Wall --cc simple_adder.v --exe tb_simple_adder_switching.cpp
cd obj_dir
make -f Vsimple_adder.mk Vsimple_adder
./Vsimple_adder