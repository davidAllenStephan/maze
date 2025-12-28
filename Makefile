all: build/kruskals

build/kruskals: src/kruskals.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp
	g++ -o build/kruskals src/kruskals.cpp src/disjoint_set.cpp src/matrix.cpp src/dyn_array.cpp -Iinclude

clean:
	rm -rf build
	mkdir build

