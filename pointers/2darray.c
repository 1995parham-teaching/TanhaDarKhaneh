#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;

  printf("please enter n and m: ");
  scanf("%dx%d", &n, &m);

  int **pointer_arr = malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    pointer_arr[i] = malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pointer_arr[i][j] = i * j;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", pointer_arr[i][j]);
    }
    printf("\n");
  }

  int *static_arr = calloc(n * m, sizeof(int));

  static_arr[3 * m + 2] = 10;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", static_arr[i * m + j]);
    }
    printf("\n");
  }
}
