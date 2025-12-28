// disjoint_set.c
// Created by David Marino
// Date: 12/26/25

#include "../include/disjoint_set.h"
#include <stdio.h>
#include <stdlib.h>

disjoint_set_t *disjoint_set_make_set() {
  disjoint_set_t *set = malloc(sizeof(disjoint_set_t));
  set->parent = set;
  set->size = 1;
  return set;
}

disjoint_set_t *disjoint_set_find(disjoint_set_t *a) {
  if (a->parent != a) {
    a->parent = disjoint_set_find(a->parent);
    return a->parent;
  } else {
    return a->parent;
  }
}

int disjoint_set_union(disjoint_set_t *a, disjoint_set_t *b) {
  a = disjoint_set_find(a);
  b = disjoint_set_find(b);
  if (a == b) {
    return 0;
  }
  a->parent = b;
  b->size = b->size + a->size;
  return 1;
}

void disjoint_set_free(disjoint_set_t *set) { free(set); }

void disjoint_set_print(disjoint_set_t *set) {
  printf("%p\n", (void *)&set->parent);
}
