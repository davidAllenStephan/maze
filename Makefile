all: build/maze

build/maze: src/maze.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp
	g++ -o build/maze src/maze.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp -Iinclude

clean:
	rm -rf build
	mkdir build

