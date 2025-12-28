// matrix.cpp
// Created by David Marino
// Date: 12/28/25

#include "../include/matrix.hpp"

template matrix_t<int *> *matrix_init<int *>(int height, int width);
template int matrix_set(matrix_t<int> *matrix, int y, int x, int value);
template int matrix_get(matrix_t<int> *matrix, int y, int x);
template int matrix_isFull(matrix_t<int> *matrix);
