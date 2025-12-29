# maze

## Structure
``` text
.
├── Makefile
├── app
│   └── main.cpp
├── src
│   ├── disjoint_set.cpp
│   ├── dyn_array.cpp
│   ├── kruskals.cpp
│   └── matrix.cpp
└── include
    ├── disjoint_set.hpp
    ├── dyn_array.hpp
    ├── kruskals.hpp
    └── matrix.hpp
```

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

```bash
mkdir build && cd build
cmake ..
make
./main
make doc       # Generate html documentation.
```
