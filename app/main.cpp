#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../include/kruskals.hpp"
#include "SDL2/SDL_render.h"
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
  } else {
    printf("ERROR: invalid algorithm\n");
    printf("List:\nkruskal\n");
    return -1;
  }

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("ERROR: SDL_Init failed\n%s", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow(
      "My SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      (matrix->width * 20) + 80, (matrix->height * 20) + 80, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!window) {
    printf("ERROR: SDL_CreateWindow failed\n%s", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect left;
    left.x = 20;
    left.y = 20;
    left.w = 20;
    left.h = (matrix->height * 20) + 20;
    SDL_RenderFillRect(renderer, &left);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect bottom;
    bottom.x = 20;
    bottom.y = (matrix->height * 20) + 40;
    bottom.w = (matrix->width * 20) + 20;
    bottom.h = 20;
    SDL_RenderFillRect(renderer, &bottom);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect right;
    right.x = (matrix->height * 20) + 40;
    right.y = 40;
    right.w = 20;
    right.h = (matrix->height * 20) + 20;
    SDL_RenderFillRect(renderer, &right);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect top;
    top.x = 40;
    top.y = 20;
    top.w = (matrix->width * 20) + 20;
    top.h = 20;
    SDL_RenderFillRect(renderer, &top);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 0; i < matrix->height; i++) {
      for (int j = 0; j < matrix->width; j++) {
        SDL_Rect square;
        if (matrix->matrix[i][j] == 1) {
          square.x = (i * 20) + 40;
          square.y = (j * 20) + 40;
          square.w = 20;
          square.h = 20;
        }
        SDL_RenderFillRect(renderer, &square);
      }
    }

    SDL_RenderPresent(renderer);
  }

  matrix_free(matrix);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return 0;
}
