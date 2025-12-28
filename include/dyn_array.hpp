// dyn_array.hpp
// Created by David Marino
// Date: 12/26/25

#ifndef DYN_ARRAY_HPP
#define DYN_ARRAY_HPP

#include <cstdio>
#include <cstdlib>

template <typename T> struct dyn_array_t {
  T *array;
  int size;
  int capacity;
};

// Initializes a new dynamic array.
// @param arr
// @param size
template <typename T> dyn_array_t<T> *dyn_array_init(int capacity) {
  dyn_array_t<T> *array =
      static_cast<dyn_array_t<T> *>(malloc(sizeof(dyn_array_t<T>)));
  array->array = static_cast<T *>(malloc(sizeof(T) * capacity));
  array->size = 0;
  array->capacity = capacity;
  return array;
}

// Appends element at the end of the array.
// @param array
// @param element
// @return error < 0 <= success
template <typename T> int dyn_array_append(dyn_array_t<T> *array, T element) {
  if (!array) {
    return -1;
  }
  if (!element) {
    return -1;
  }
  if (array->size == array->capacity) {
    array->capacity = array->capacity * 2;
    array->array =
        static_cast<T *>(realloc(array->array, sizeof(T) * array->capacity));
    array->array[array->size] = element;
    array->size += 1;
  } else {
    array->array[array->size] = element;
    array->size += 1;
  }
  return 0;
}

// Removes element at index.
// @param array
// @param index
// @return error < 0 <= success
template <typename T> int dyn_array_remove(dyn_array_t<T> *array, int index) {
  if (!array) {
    return -1;
  }
  if (index < 0) {
    return -1;
  }
  for (int i = index; i < array->size; i++) {
    array->array[i] = array->array[i + 1];
  }
  array->size -= 1;
  return 0;
}

// Gets element at index in array.
// @param array
// @param index
// @return T, NULL on error.
template <typename T> T dyn_array_get(dyn_array_t<T> *array, int index) {
  if (!array) {
    return -1;
  }
  if (index < 0) {
    return -1;
  }
  return array->array[index];
}

// Prints array.
// @param array
template <typename T> void dyn_array_print(dyn_array_t<T> *array) {
  for (int i = 0; i < array->size; i++) {
    printf("%p ", (void *)&array->array[i]);
  }
  printf("\n");
}

// Free dyn_array.
// @param array
// @param desc deconstructor
template <typename T>
void dyn_array_free(dyn_array_t<T> *array, void (*desc)(T)) {
  for (int i = 0; i < array->size; i++) {
    desc(array->array[i]);
  }
  free(array->array);
  free(array);
}

#endif
