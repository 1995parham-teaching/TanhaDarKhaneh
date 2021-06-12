#include <stdio.h>
#include <stdlib.h>

int cmp_func(const void *a, const void *b) {
  int *ap = (int *) a;
  int *bp = (int *) b;

  // a > b positive
  if (*ap > *bp) {
    return 1;
  }

  // a < b negative
  if (*ap < *bp) {
    return -1;
  }

  // a == b zero
  if (*ap == *bp) {
    return 0;
  }

  return 0;
}

int main() {
  int arr[] = {-1, 78, 73, 1, 2, 3, -10};

  qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), cmp_func);

  for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
}
