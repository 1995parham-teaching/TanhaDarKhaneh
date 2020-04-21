#include <stdio.h>

void display_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int arr[], int i, int j) {
  printf("swap(): Address of arr: %p\n", arr);
  printf("swap(): Address of i, j: %p, %p\n", &i, &j);

  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int main() {
  int arr[] = {73, 78, 98, 95, 99};
  const int size = sizeof(arr) / sizeof(int);

  printf("main(): Address of arr: %p\n", arr);

  display_arr(arr, size);

  int i = 0;
  int j = 3;
  printf("main(): Address of i, j: %p, %p\n", &i, &j);

  swap(arr, i, j);

  display_arr(arr, size);
}
