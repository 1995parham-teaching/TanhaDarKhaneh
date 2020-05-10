#include <stdio.h>

// A = {1, 2, 3, 4}
// B = {4, 5, 6}
// A - B = {1, 2, 3}


// int search(int target, int arr[], int size)
// is the same as
// int search(int target, int *arr, int size)

// check the existance of target in given array
int search(int target, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return 1;
    }
  }
  return 0;
}

int diff_set(int *a, int size_a, int *b, int size_b, int *res) {
  int res_index = 0;

  for (int i = 0; i < size_a; i++) {
    if (search(a[i], b, size_b) == 0) {
      res[res_index] = a[i];
      res_index++;
    }
  }

  return res_index;
}

int main() {
  int A[] = {1, 2, 3, 4};
  int B[] = {4, 5, 6};

  int res[100];

  int res_size = diff_set(A, sizeof(A) / sizeof(int), B, sizeof(B) / sizeof(int), res);

  for (int i = 0; i < res_size; i++) {
    printf("%d\n", res[i]);
  }
}
