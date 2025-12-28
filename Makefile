all: build/maze

build/maze: src/maze.cpp build/matrix.o build/disjoint_set.o
	g++ -o build/maze src/maze.cpp build/matrix.o build/disjoint_set.o

build/matrix.o: src/matrix.c
	gcc -c src/matrix.c -I include -o build/matrix.o

build/disjoint_set.o: src/disjoint_set.c
	gcc -c src/disjoint_set.c -I include -o build/disjoint_set.o

clean:
	rm -rf build
	mkdir build

