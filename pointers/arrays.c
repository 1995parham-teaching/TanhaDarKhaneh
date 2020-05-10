#include <stdio.h>

int main() {
  int arr[20] = {0};

  printf("arr: %p\n", arr);
  printf("&arr[0]: %p\n", &arr[0]);
  printf("&arr: %p\n", &arr);

  int *pi;

  pi = &arr[7];

  arr[7] = 10;
  arr[8] = 20;
  arr[9] = 30;

  printf("*pi: %d\n", *pi); // 10

  printf("*pi + 1: %d\n", *pi + 1); // 10 + 1 = 11
  // *(pi + 1) == pi[1]
  printf("*(pi + 1): %d\n", *(pi + 1)); // 20
  printf("pi[1]: %d\n", pi[1]); // 20

  printf("pi[2]: %d\n", pi[2]); // 30
}
