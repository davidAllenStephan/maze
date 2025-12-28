// dyn_array.cpp
// Created by David Marino
// Date: 12/26/25

#include "../include/dyn_array.hpp"
#include "../include/disjoint_set.hpp"

template dyn_array_t<int> *dyn_array_init<int>(int capacity);
template int dyn_array_append(dyn_array_t<int> *array, int element);
template int dyn_array_remove(dyn_array_t<int> *array, int index);
template int dyn_array_get(dyn_array_t<int> *array, int index);

template dyn_array_t<disjoint_set_t *> *
dyn_array_init<disjoint_set_t *>(int capacity);
template int dyn_array_append(dyn_array_t<disjoint_set_t *> *array,
                              disjoint_set_t *element);
template int dyn_array_remove(dyn_array_t<disjoint_set_t *> *array, int index);
template disjoint_set_t *dyn_array_get(dyn_array_t<disjoint_set_t *> *array,
                                       int index);
