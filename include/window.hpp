/**
 * @file window.hpp
 * @brief Abstraction of SDL window for rendering matrix
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL2/SDL.h"
#include "matrix.hpp"

/**
 * @brief Creates window
 *
 * @note Matrix must be type int
 *
 * @param matrix
 * @param title
 * @return Pointer to SDL_Window
 *
 * @warning No error checking
 */
SDL_Window *window_create(matrix_t<int> *matrix, const char *title);

/**
 * @brief Renders matrix
 *
 * @note Matrix must be type int
 *
 * @param window
 * @param matrix
 *
 * @warning No error checking
 */
void window_render_matrix(SDL_Window *window, matrix_t<int> *matrix);

/**
 * @brief Window and matrix cleanup
 *
 * @note Matrix must be type int
 *
 * @param window
 * @param matrix
 *
 * @warning No error checking
 */
void window_cleanup(SDL_Window *window, matrix_t<int> *matrix);

#endif
