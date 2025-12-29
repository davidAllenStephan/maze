/**
 * @file dyn_array.hpp
 * @brief Dynamic Array utility class
 *
 * Provides a Dynamic Array data structure.
 * Based on:
 * @see https://en.wikipedia.org/wiki/Dynamic_array
 */

#ifndef DYN_ARRAY_HPP
#define DYN_ARRAY_HPP

#include <cstdio>
#include <cstdlib>
#include <type_traits>

/**
 * @brief Generic Dynamic Array data structure
 *
 * Doubles in size when size equals capacity.
 *
 * @tparam T Type of elements
 */
template <typename T> struct dyn_array_t {
  T *array;     /**< data */
  int size;     /**< elements in array */
  int capacity; /**< capcity of array */
};

/**
 * @brief Initializes a new dynamic array
 *
 * @tparam T Type of elements
 * @param capacity
 * @return Pointer to new dynamic array
 * @retval nullptr Capacity less than 0
 * @retval nullptr Memory allocation failure
 */
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

/**
 * @brief Appends element to end of array
 *
 * Doubles in capacity when size is equal to capcity.
 *
 * @tparam T Type of element
 * @param array
 * @param element
 * @retval 0 Success
 * @retval -1 Null pointer passed
 * @retval -2 Memory allocation failure
 */
template <typename T> int dyn_array_append(dyn_array_t<T> *array, T element) {
  if (!array) {
    return -1;
  }
  if (array->size == array->capacity) {
    array->capacity = array->capacity * 2;
    array->array =
        static_cast<T *>(realloc(array->array, sizeof(T) * array->capacity));
    if (!array->array) {
      return -2;
    }
    array->array[array->size] = element;
    array->size += 1;
  } else {
    array->array[array->size] = element;
    array->size += 1;
  }
  return 0;
}

/**
 * @brief Removes element at index
 *
 * @tparam T Type of element
 * @param array
 * @param index
 * @retval 0 Success
 * @retval -1 Null pointer passed
 * @retval -2 Invalid arguments
 *
 * @warning Does not free memory when removed
 */
template <typename T> int dyn_array_remove(dyn_array_t<T> *array, int index) {
  if (!array) {
    return -1;
  }
  if (index < 0 || index >= array->size) {
    return -2;
  }
  for (int i = index; i < array->size; i++) {
    array->array[i] = array->array[i + 1];
  }
  array->size -= 1;
  return 0;
}

/**
 * @brief Gets element at index (pointer)
 *
 * @tparam T Type of element
 * @param array
 * @param index
 * @retval Pointer to element
 * @retval nullptr Null pointer passed
 * @retval nullptr Invalid arguments
 */
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, T>::type
dyn_array_get(dyn_array_t<T> *array, int index) {
  if (!array) {
    return nullptr;
  }
  if (index < 0 || index >= array->size) {
    return nullptr;
  }
  return array->array[index];
}

/**
 * @brief Gets element at index (static)
 *
 * @tparam T Type of element
 * @param array
 * @param index
 * @retval Element
 * @retval INTMAX_MAX Null pointer passed
 * @retval INTMAX_MAX Invalid arguments
 */
template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, T>::type
dyn_array_get(dyn_array_t<T> *array, int index) {
  if (!array) {
    return static_cast<T>(INTMAX_MAX);
  }
  if (index < 0 || index >= array->size) {
    return static_cast<T>(INTMAX_MAX);
  }
  return array->array[index];
}

/**
 * @brief Prints array
 *
 * @tparam T Type of element
 * @param array
 */
template <typename T> void dyn_array_print(dyn_array_t<T> *array) {
  for (int i = 0; i < array->size; i++) {
    printf("%p ", (void *)&array->array[i]);
  }
  printf("\n");
}

/**
 * @brief Free dynamic array
 *
 * @tparam T Type of element
 * @param array
 * @param desc Deconstructor for elements
 */
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

/**
 * @brief Checks if element is contained in array
 *
 * @tparam T Type of element
 * @param array
 * @param desc Deconstructor for elements
 * @param element
 * @param cmp Comparison function
 * @retval 0 Element contained in array
 * @retval 1 Element not contained in array
 * @retval -1 Null pointer passed
 */
template <typename T>
int dyn_array_contains(dyn_array_t<T> *array, T element,
                       void (*cmp)(T, T) = nullptr) {
  if (!array) {
    return -1;
  }
  if (!cmp) {
    return -1;
  }
  for (int i = 0; i < array->size; i++) {
    if (cmp(element, array->array[i])) {
      return 0;
    }
  }
  return 1;
}

#endif
