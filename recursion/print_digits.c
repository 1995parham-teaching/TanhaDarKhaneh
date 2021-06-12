#include <stdio.h>

void print_digits_left_to_right(int n) {
  printf("Start with %d\n", n);

  if (n < 10) {
    printf("%d\n", n);
    return;
  }

  print_digits_left_to_right(n / 10);
  printf("%d\n", n % 10);

  printf("Finish with %d\n", n);
}

void print_digits_right_to_left(int n) {
  printf("Start with %d\n", n);

  if (n < 10) {
    printf("%d\n", n);
    return;
  }

  printf("%d\n", n % 10);
  print_digits_right_to_left(n / 10);

  printf("Finish with %d\n", n);
}

int main() {
  int n;

  scanf("%d", &n);

  print_digits_left_to_right(n);
}
