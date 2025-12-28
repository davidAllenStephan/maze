// matrix.h
// Created by David Marino
// Date: 12/26/25

#ifndef MATRIX_H
#define MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct matrix {
  int **elements;
  int height;
  int width;
};

typedef struct matrix matrix_t;

// Initilizes matrix.
// @param height
// @param width
// @return pointer to matrix on success, NULL on fail.
matrix_t *matrix_init(int height, int width);

// Frees matrix.
// @param matrix
void matrix_free(matrix_t *matrix);

// Sets value at index in matrix.
// @param matrix
// @param y
// @param x
// @param value
// @return value on success, -1 on fail.
int matrix_set(matrix_t *matrix, int y, int x, int value);

// Gets value at index in matrix.
// @param matrix
// @param y
// @param x
// @return value on success, -1 on fail.
int matrix_get(matrix_t *matrix, int y, int x);

// Sets all values to 0 in matrix.
// @param matrix
// @return 0 on success, -1 on fail.
int matrix_clear(matrix_t *matrix);

// Sets value at index to 0.
// @param matrix
// @param y
// @param x
// @return 0 on success, -1 on fail.
int matrix_reset(matrix_t *matrix, int y, int x);

// Prints matrix to stdout.
// @param matrix
// @param height
// @param width
void matrix_print(matrix_t *matrix);

// Checks if each element is set in matrix.
// @param matrix
// @return 0 if false, 1 if true.
int matrix_isFull(matrix_t *matrix);

#ifdef __cplusplus
}
#endif
#endif
