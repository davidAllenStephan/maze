# maze

## Structure
``` text
.
├── Makefile
├── src
│   ├── disjoint_set.cpp
│   ├── dyn_array.cpp
│   ├── kruskals.cpp
│   ├── matrix.cpp
│   └── window.cpp
└── include
    ├── disjoint_set.hpp
    ├── dyn_array.hpp
    ├── kruskals.hpp
    └── matrix.hpp
```

Sources go in [src/](src/), header files in [include/](include/)

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
