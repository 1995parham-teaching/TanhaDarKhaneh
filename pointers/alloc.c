#include <stdio.h>
#include <stdlib.h>

//   address of [ address of [0,0] ] (arr)
//         |
//        \/
// [ address of [ 0,0 ] ] -> [ 0,0 ] [ 0,1 ] [ 0,2 ]
// [ address of [ 1,0 ] ] -> [ 1,0 ] [ 1,1 ] [ 1,2 ]
int main() {
  int n;
  int m;

  scanf("%d %d", &n, &m);

  int **arr;

  arr = malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    arr[i] = malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr[i][j] = i * j;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("arr[%d][%d]: %d\n", i, j, arr[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
}
