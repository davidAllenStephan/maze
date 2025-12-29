#include "../include/disjoint_set.hpp"

disjoint_set_t *disjoint_set_make_set() {
  disjoint_set_t *set = (disjoint_set_t *)malloc(sizeof(disjoint_set_t));
  if (!set) {
    return nullptr;
  }
  set->parent = set;
  set->size = 1;
  return set;
}

disjoint_set_t *disjoint_set_find(disjoint_set_t *a) {
  if (!a) {
    return nullptr;
  }
  if (a->parent != a) {
    a->parent = disjoint_set_find(a->parent);
    return a->parent;
  } else {
    return a->parent;
  }
}

int disjoint_set_union(disjoint_set_t *a, disjoint_set_t *b) {
  if (!a || !b) {
    return -1;
  }
  a = disjoint_set_find(a);
  b = disjoint_set_find(b);
  if (a == b) {
    return 1;
  }
  a->parent = b;
  b->size = b->size + a->size;
  return 0;
}

void disjoint_set_free(disjoint_set_t *set) { free(set); }

void disjoint_set_print(disjoint_set_t *set) {
  printf("%p\n", (void *)&set->parent);
}
