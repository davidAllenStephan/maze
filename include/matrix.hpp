// matrix.h
// Created by David Marino
// Date: 12/26/25

#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

template <typename T> struct matrix_t {
  T **matrix;
  int height;
  int width;
};

// Initilizes matrix.
// @param height
// @param width
// @return pointer to matrix on success, NULL on fail.
template <typename T> matrix_t<T> *matrix_init(int height, int width) {
  if (height < 0) {
    return NULL;
  }
  if (width < 0) {
    return NULL;
  }
  matrix_t<T> *matrix = static_cast<matrix_t<T> *>(malloc(sizeof(matrix_t<T>)));
  matrix->height = height;
  matrix->width = width;
  matrix->matrix = static_cast<T **>(malloc(sizeof(T **) * height));
  for (int i = 0; i < width; i++) {
    matrix->matrix[i] = static_cast<T *>(malloc(sizeof(T *) * width));
  }
  if (!matrix) {
    return NULL;
  }
  return matrix;
}

// Frees matrix.
// @param matrix
// @param desc

template <typename T>
void matrix_free(matrix_t<T> *matrix, void (*desc)(T) = nullptr) {
  if (!matrix) {
    return;
  }

  if (desc) {
    for (int i = 0; i < matrix->height; i++) {
      for (int j = 0; j < matrix->width; j++) {
        if (matrix->matrix[i][j]) {
          desc(matrix->matrix[i][j]);
        }
      }
    }
  }

  for (int i = 0; i < matrix->height; i++) {
    free(matrix->matrix[i]);
  }

  free(matrix->matrix);
  free(matrix);
}

// Sets value at index in matrix.
// @param matrix
// @param y
// @param x
// @param value
// @return fail < 0 <= success
template <typename T>
int matrix_set(matrix_t<T> *matrix, int y, int x, int value) {
  if (!matrix) {
    return -1;
  }
  if (value < 0) {
    return -1;
  }
  if (y < 0) {
    return -1;
  }
  if (x < 0) {
    return -1;
  }
  matrix->matrix[y][x] = value;
  return value;
}

// Gets value at index in matrix.
// @param matrix
// @param y
// @param x
// @return T, NULL on error
template <typename T> T matrix_get(matrix_t<T> *matrix, int y, int x) {
  if (!matrix) {
    return NULL;
  }
  if (y < 0) {
    return NULL;
  }
  if (x < 0) {
    return NULL;
  }
  return matrix->matrix[y][x];
}

// Prints matrix to stdout.
// @param matrix
// @param height
// @param width
template <typename T> void matrix_print(matrix_t<T> *matrix, void (*print)(T)) {
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      print(matrix->matrix[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}

// Checks if each element is set in matrix.
// @param matrix
// @return not full < 0 <= full
template <typename T> int matrix_isFull(matrix_t<T> *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      if (matrix->matrix[i][j] == NULL) {
        return 0;
      }
    }
  }
  return 1;
}

#endif
