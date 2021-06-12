#include <stdio.h>

int max_index(int arr[], int size) {
  int index = 0;

  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[index]) {
      index = i;
    }
  }

  return index;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  printf("siezof(arr): %lu\n", sizeof(arr));

  const int size = sizeof(arr) / sizeof(int);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int index = max_index(arr, size);

  printf("Index: %d, Value: %d\n", index, arr[index]);
}
