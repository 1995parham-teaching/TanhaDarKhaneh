#include <stdio.h>

// do not return i's address
int *return_pointer(int *p, int i) {
  // static int s = 10; // you can return its address
  // int a = 20; do not return its address

  return p;
}

int main() {
  int i = 78;

  int *a = return_pointer(&i, i);

  int j = 120;
  j++;
  printf("j: %d\n", j);

  printf("a: %d\n", *a);
}
