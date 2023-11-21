all: generator genplot

generator: gen.cpp
	g++ gen.cpp -o generator

genplot: generator
	./generator
	./genplot generator.csv

clean:
	rm -f generator
	rm -f generator.csv
	rm -f generator.svg