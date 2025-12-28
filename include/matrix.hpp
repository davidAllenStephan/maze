// matrix.hpp
// Created by David Marino
// Date: 12/26/25

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdio>
#include <cstdlib>
#include <type_traits>

template <typename T> struct matrix_t {
  T **matrix;
  int height;
  int width;
};

template <typename T> matrix_t<T> *matrix_init(int height, int width) {
  if (height < 0 || width < 0) {
    return nullptr;
  }
  matrix_t<T> *matrix = static_cast<matrix_t<T> *>(malloc(sizeof(matrix_t<T>)));
  if (!matrix) {
    return nullptr;
  }
  matrix->height = height;
  matrix->width = width;
  matrix->matrix = static_cast<T **>(malloc(sizeof(T *) * height));
  if (!matrix->matrix) {
    free(matrix);
    return nullptr;
  }
  for (int i = 0; i < height; i++) {
    matrix->matrix[i] = static_cast<T *>(malloc(sizeof(T) * width));
    if (!matrix->matrix[i]) {
      for (int j = 0; j < i; j++) {
        free(matrix->matrix[j]);
      }
      free(matrix->matrix);
      free(matrix);
      return nullptr;
    }
  }

  return matrix;
}

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

template <typename T>
int matrix_set(matrix_t<T> *matrix, int y, int x, T value) {
  if (!matrix || y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return -1;
  }
  matrix->matrix[y][x] = value;
  return 0;
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type
matrix_get(matrix_t<T> *matrix, int y, int x) {
  if (!matrix || y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return nullptr;
  }
  return matrix->matrix[y][x];
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type
matrix_get(matrix_t<T> *matrix, int y, int x) {
  if (!matrix || y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return static_cast<T>(-1);
  }
  return matrix->matrix[y][x];
}

template <typename T> void matrix_print(matrix_t<T> *matrix, void (*print)(T)) {
  if (!matrix || !print) {
    return;
  }
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      print(matrix->matrix[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}

template <typename T> int matrix_isFull(matrix_t<T> *matrix) {
  if (!matrix) {
    return 0;
  }
  for (int i = 0; i < matrix->height; i++)
    for (int j = 0; j < matrix->width; j++)
      if (!matrix->matrix[i][j])
        return -1;
  return 0;
}

#endif
