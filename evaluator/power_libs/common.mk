all: $(VMODULE) toggle concat
	./obj_dir/$(VMODULE)
	./obj_dir/toggle
	./obj_dir/concat $(MODULE).csv
	rm actual.csv
	rm toggle.csv
	$(POWER_LIBS)/plotter $(MODULE).csv

$(VMODULE): obj_dir/$(VMODULE).mk
	make -C obj_dir -f $(VMODULE).mk $(VMODULE)

obj_dir/$(VMODULE).mk:
	verilator -Wall --trace --public-flat-rw --cc  -Wno-lint -CFLAGS "-DMODULENAME=$(VMODULE) -include $(VMODULE).h -include ../inputs_$(MODULE).h " $(DUTPATH) --exe $(POWER_LIBS)/tb.cpp


toggle:
	g++ $(POWER_LIBS)/toggle.cpp -o obj_dir/toggle

concat:
	g++ $(POWER_LIBS)/concat.cpp -o obj_dir/concat


clean:
	rm -rf obj_dir 
	rm -f $(MODULE).csv
	rm -f $(MODULE).svg
	rm -f ../results.txt
	rm contingency_tables.txt