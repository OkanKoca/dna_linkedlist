all: compile run

compile:
	g++ -I ./include/ -o ./lib/Dna.o -c ./src/Dna.cpp
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Dna.o ./lib/Gen.o ./lib/Kromozom.o ./src/main.cpp
run:
	./bin/Test
