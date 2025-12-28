// dyn_array.cpp
// Created by David Marino
// Date: 12/26/25

#include "../include/dyn_array.hpp"
#include "../include/disjoint_set.hpp"

template dyn_array_t<int> *dyn_array_init<int>(int capacity);
template dyn_array_t<disjoint_set_t *> *
dyn_array_init<disjoint_set_t *>(int capacity);
