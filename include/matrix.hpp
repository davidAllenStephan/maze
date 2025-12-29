/**
 * @file matrix.hpp
 * @brief 2D Matrix utility class
 *
 * Provides a 2D Matrix data structure.
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <type_traits>

/**
 * @brief Generic 2D Matrix data structure
 *
 * @tparam T Type of elements
 */
template <typename T> struct matrix_t {
  T **matrix; /**< data */
  int height; /**< rows */
  int width;  /**< columns */
};

/**
 * @brief Initializes a new matrix
 *
 * @tparam T Type of elements
 * @param height
 * @param width
 * @return Pointer to new matrix
 * @retval nullptr height less than 0
 * @retval nullptr width less than 0
 * @retval nullptr Memory allocation failure
 */
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

/**
 * @brief Frees matrix
 *
 * @tparam T Type of elements
 * @param matrix
 * @param desc Deconstructor
 */
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

/**
 * @brief Sets to value at index in matrix
 *
 * @tparam T Type of elements
 * @param matrix
 * @param y Row
 * @param x Column
 * @retval 0 Success
 * @retval -1 Null pointer passed
 * @retval -2 Invalid arguments
 */
template <typename T>
int matrix_set(matrix_t<T> *matrix, int y, int x, T value) {
  if (!matrix) {
    return -1;
  }
  if (y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return -2;
  }
  matrix->matrix[y][x] = value;
  return 0;
}

/**
 * @brief Gets element at index (pointer)
 *
 * @tparam T Type of element
 * @param matrix
 * @param y Row
 * @param x Column
 * @return Element
 * @retval nullptr Null pointer passed
 * @retval nullptr Memory allocation failure
 */
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type
matrix_get(matrix_t<T> *matrix, int y, int x) {
  if (!matrix) {
    return nullptr;
  }
  if (y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return nullptr;
  }
  return matrix->matrix[y][x];
}

/**
 * @brief Gets element at index (static)
 *
 * @tparam T Type of element
 * @param matrix
 * @param y Row
 * @param x Column
 * @return Element
 * @retval INTMAX_MAX Null pointer passed
 * @retval INTMAX_MAX Memory allocation failure
 */
template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type
matrix_get(matrix_t<T> *matrix, int y, int x) {
  if (!matrix || y < 0 || x < 0 || y >= matrix->height || x >= matrix->width) {
    return static_cast<T>(INTMAX_MAX);
  }
  return matrix->matrix[y][x];
}

/**
 * @brief Prints matrix
 *
 * @tparam T Type of element
 * @param matrix
 * @param print Print function
 */
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

/**
 * @brief Checks if matrix is full
 *
 * @tparam T Type of element
 * @param matrix
 * @param print Print function
 * @retval -1 Null pointer passed
 * @retval 0 Matrix is full
 * @retval 1 Matrix is not full
 */
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
