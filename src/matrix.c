// matrix.c
// Created by David Marino
// Date: 12/26/25

#include "../include/matrix.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

matrix_t *matrix_init(int height, int width) {
  if (height < 0) {
    return NULL;
  }
  if (width < 0) {
    return NULL;
  }
  matrix_t *matrix = malloc(sizeof(matrix_t));
  matrix->height = height;
  matrix->width = width;
  matrix->elements = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    matrix->elements[i] = malloc(sizeof(int) * width);
  }
  if (!matrix) {
    return NULL;
  }
  return matrix;
}

void matrix_free(matrix_t *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    free(matrix->elements[i]);
  }
  free(matrix);
}

int matrix_set(matrix_t *matrix, int y, int x, int value) {
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
  matrix->elements[y][x] = value;
  return value;
}

int matrix_get(matrix_t *matrix, int y, int x) {
  if (!matrix) {
    return -1;
  }
  if (y < 0) {
    return -1;
  }
  if (x < 0) {
    return -1;
  }
  return matrix->elements[y][x];
}

int matrix_clear(matrix_t *matrix) {
  if (!matrix) {
    return -1;
  }
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      matrix->elements[i][j] = 0;
    }
  }
  return 0;
}

int matrix_reset(matrix_t *matrix, int y, int x) {
  if (!matrix) {
    return -1;
  }
  if (y < 0) {
    return -1;
  }
  if (x < 0) {
    return -1;
  }
  matrix->elements[y][x] = 0;
  return 0;
}

/**
 *   01234
 * 0 O|O|O
 * 1 -*-*-
 * 2 O|O|O
 * 3 -*-*-
 * 4 O|O|O
 */
void matrix_print(matrix_t *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          printf("  ");
        } else {
          if (matrix->elements[i][j] == 0) {
            printf("||");
          } else {
            printf("  ");
          }
        }
      } else {
        if (j % 2 == 0) {
          if (matrix->elements[i][j] == 0) {
            printf("--");
          } else {
            printf("  ");
          }
        } else {
          printf("<>");
        }
      }
    }
    printf("\n");
  }
}

int matrix_isFull(matrix_t *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      if (matrix->elements[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}
