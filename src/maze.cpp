#include "../include/dyn_array.hpp"
#include "../include/matrix.hpp"
#include "../include/disjoint_set.hpp"
#include <stdlib.h>
#include <time.h>

void print_int(int value) { printf("%u", value); }

int main(int argc, char *argv[]) {
  srand(time(0));

  int height = atoi(argv[1]);
  int width = atoi(argv[2]);
  int walls_count = ((width - 1) * height) + (width * (height - 1));

  dyn_array_t<disjoint_set_t *> *cells =
      dyn_array_init<disjoint_set_t *>(width * height);
  for (int i = 0; i < cells->capacity; i++) {
    disjoint_set_t *set = disjoint_set_make_set();
    dyn_array_append(cells, set);
  }

  dyn_array_t<int> *walls = dyn_array_init<int>(walls_count);
  int even_walls = width - 1;
  int odd_walls = width;
  int count = 0;
  while (count != walls_count) {
    int z = rand() % walls_count;
    if (dyn_array_get(walls, z) == 1) {
      continue;
    }
    int a = z / (even_walls + odd_walls);
    int b = z % (even_walls + odd_walls);
    if (b < even_walls) {
      int index1 = (a * width) + b;
      int index2 = (a * width) + (b + 1);
      int res = disjoint_set_union(cells->array[index1], cells->array[index2]);
      if (res == 1) {
        walls->array[z] = 1;
      }
    } else {
      int index1 = (a * width) + (b - even_walls);
      int index2 = ((a + 1) * width) + (b - even_walls);
      int res = disjoint_set_union(cells->array[index1], cells->array[index2]);
      if (res == 1) {
        walls->array[z] = 1;
      }
    }
    count++;
  }

  matrix_t<int> *matrix = matrix_init<int>((height * 2) - 1, (width * 2) - 1);
  int walls_index = 0;
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      if (i % 2 == 1) {
        if (j % 2 == 1) {
          matrix_set(matrix, i, j, 1);
        } else {
          if (walls->array[walls_index] == 1) {
            matrix_set(matrix, i, j, 1);
          }
          walls_index++;
        }
      } else {
        if (j % 2 == 1) {
          if (walls->array[walls_index] == 1) {
            matrix_set(matrix, i, j, 1);
          }
          walls_index++;
        }
      }
    }
  }

  matrix_print(matrix, print_int);
  matrix_free(matrix);

  dyn_array_free(cells, disjoint_set_free);
  free(walls);

  return 0;
}
