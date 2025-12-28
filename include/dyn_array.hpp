// dyn_array.hpp
// Created by David Marino
// Date: 12/26/25

#ifndef DYN_ARRAY_HPP
#define DYN_ARRAY_HPP

#include <cstdio>
#include <cstdlib>
#include <type_traits>

template <typename T> struct dyn_array_t {
  T *array;
  int size;
  int capacity;
};

// Initializes a new dynamic array.
// @param arr
// @param size
template <typename T> dyn_array_t<T> *dyn_array_init(int capacity) {
  if (capacity < 0) {
    return nullptr;
  }
  dyn_array_t<T> *array =
      static_cast<dyn_array_t<T> *>(malloc(sizeof(dyn_array_t<T>)));
  if (!array) {
    return nullptr;
  }
  array->array = static_cast<T *>(malloc(sizeof(T *) * capacity));
  if (!array->array) {
    return nullptr;
  }
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

// Gets element at index in array (pointer).
// @param array
// @param index
// @return T, NULL or -1 on error.
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type
dyn_array_get(dyn_array_t<T> *array, int index) {
  if (!array) {
    return nullptr;
  }
  if (index < 0) {
    return nullptr;
  }
  return array->array[index];
}

// Gets element at index in array (static).
// @param array
// @param index
// @return T, NULL or -1 on error.
template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type
dyn_array_get(dyn_array_t<T> *array, int index) {
  if (!array) {
    return static_cast<T>(-1);
  }
  if (index < 0) {
    return static_cast<T>(-1);
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
void dyn_array_free(dyn_array_t<T> *array, void (*desc)(T) = nullptr) {
  if (desc) {
    for (int i = 0; i < array->size; i++) {
      desc(array->array[i]);
    }
  }
  free(array->array);
  free(array);
}

#endif
