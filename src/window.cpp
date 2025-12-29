#include "../include/window.hpp"

SDL_Window *window_create(matrix_t<int> *matrix, const char *title) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow(
      title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      (matrix->width * 20) + 80, (matrix->height * 20) + 80, SDL_WINDOW_SHOWN);
  return window;
}

void window_render_matrix(SDL_Window *window, matrix_t<int> *matrix) {
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!window) {
    printf("ERROR: SDL_CreateWindow failed\n%s", SDL_GetError());
    SDL_Quit();
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

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect left;
    left.x = 20;
    left.y = 20;
    left.w = 20;
    left.h = (matrix->height * 20) + 20;
    SDL_RenderFillRect(renderer, &left);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect bottom;
    bottom.x = 20;
    bottom.y = (matrix->height * 20) + 40;
    bottom.w = (matrix->width * 20) + 20;
    bottom.h = 20;
    SDL_RenderFillRect(renderer, &bottom);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect right;
    right.x = (matrix->height * 20) + 40;
    right.y = 40;
    right.w = 20;
    right.h = (matrix->height * 20) + 20;
    SDL_RenderFillRect(renderer, &right);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
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
  SDL_DestroyRenderer(renderer);
}

void window_cleanup(SDL_Window *window, matrix_t<int> *matrix) {
  matrix_free(matrix);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
