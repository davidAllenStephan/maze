all: build/kruskals

build/kruskals: src/kruskals.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp src/window.cpp
	g++ src/window.cpp src/kruskals.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp -o build/kruskals -Iinclude -lSDL2

clean:
	rm -rf build
	mkdir build

