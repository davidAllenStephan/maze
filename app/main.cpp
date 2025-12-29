#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../include/kruskals.hpp"
#include "../include/window.hpp"
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  if (!argv[1]) {
    printf("ERROR: include algorithm.\n");
    return -1;
  }
  if (!argv[2]) {
    printf("ERROR: include height.\n");
    return -1;
  }
  if (!argv[3]) {
    printf("ERROR: include width.\n");
    return -1;
  }

  int height = atoi(argv[2]);
  int width = atoi(argv[3]);

  if (height < 1) {
    printf("ERROR: height > 0\n");
    return -1;
  }

  if (width < 1) {
    printf("ERROR: width > 0\n");
    return -1;
  }

  matrix_t<int> *matrix;
  if (strcmp("kruskal", argv[1]) == 0) {
    matrix = kruskal_run(height, width);
    const char *title = "Kruskals";
    SDL_Window *window = window_create(matrix, "Kruskals");
    window_render_matrix(window, matrix);
    window_cleanup(window, matrix);
  } else {
    printf("ERROR: invalid algorithm\n");
    printf("List:\nkruskal\n");
    return -1;
  }

  return 0;
}
