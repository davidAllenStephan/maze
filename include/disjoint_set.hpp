/**
 * @file disjoint_set.hpp
 * @brief Disjoint Set utility class
 *
 * Provides a Disjoint Set data structure.
 * Based on:
 * @see https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 */

#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Disjoint set node
 *
 * Represents one element in the union–find structure.
 */
struct disjoint_set {
  struct disjoint_set *parent; /**< parent of node */
  int size;                    /**< number children including itself */
};

typedef struct disjoint_set disjoint_set_t;

/**
 * @brief Initializes a new disjoint set node
 * @warning Does not check if node is already in forest
 * @return Pointer to new disjoint set node
 * @retval nullptr Memory allocation failure
 */
disjoint_set_t *disjoint_set_make_set();

/**
 * @brief Finds root of given set
 *
 * Uses path compression.
 *
 * @param set
 * @return Pointer to root set
 * @retval nullptr Null pointer passed
 */
disjoint_set_t *disjoint_set_find(disjoint_set_t *set);

/**
 * @brief Union of two sets
 *
 * Finds root of both sets, set_a always becomes child of set_b.
 *
 * @param set_a
 * @param set_b
 * @retval 0 Success
 * @retval 1 Already belong to same set
 * @retval -1 Null pointer passed
 */
int disjoint_set_union(disjoint_set_t *set_a, disjoint_set_t *set_b);

/**
 * @brief Frees set node
 *
 * @param set
 */
void disjoint_set_free(disjoint_set_t *set);

/**
 * @brief Prints set
 *
 * Prints the parent pointer of a set
 *
 * @param set
 */
void disjoint_set_print(disjoint_set_t *set);

#endif
