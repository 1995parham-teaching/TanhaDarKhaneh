#include <stdio.h>

void sum(int a, int b, int* res) {
  *res = a + b;
}

int main() {
  int a = 10;
  int b = 12;

  printf("a: %p\n", &a);
  printf("b: %p\n", &b);

  void* pa = &a;
  printf("pa: %p\n", pa);

  int* pb = &b;
  printf("pb: %p\n", pb);
  printf("b: %d\n", *pb);
  *pb = 78;
  printf("b: %d\n", b);


  int res = 0;
  sum(a, b, &res);
  printf("res: %d\n", res);
}
