// disjoint_set.h
// Created by David Marino
// Date: 12/26/25

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#ifdef __cplusplus
extern "C" {
#endif

struct disjoint_set {
  struct disjoint_set *parent;
  int size;
};

typedef struct disjoint_set disjoint_set_t;

// Creates a set.
// @return new disjoint_set_t
disjoint_set_t *disjoint_set_make_set();

// Finds the set a given set belonds to.
// @param a
// @return root disjoint_set_t
disjoint_set_t *disjoint_set_find(disjoint_set_t *a);

// Combines two sets into one.
// @param a
// @param b
// @return 0 if same set, 1 if different set
int disjoint_set_union(disjoint_set_t *a, disjoint_set_t *b);

// Frees disjoint set.
// @param disjoint_set_t set
void disjoint_set_free(disjoint_set_t *set);

void disjoint_set_print(disjoint_set_t *set);

#ifdef __cplusplus
}
#endif

#endif
