#include <stdio.h>

int is_prime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int next_prime_number(int n) {
  if (n == 2) {
    return 3;
  }
  n += 2;
  while (is_prime(n) == 0) {
    n += 2;
  }
  return n;
}

int check_goldbach(int n) {
  int i = 2;

  while (i < n) {
    if (is_prime(n - i) == 1) {
      printf("%d + %d == %d\n", i, n - i, n);
      return 1;
    }
    i = next_prime_number(i);
  }

  return 0;
}

int main() {
  int number;

  while (1) {
    scanf("%d", &number);

    if (number == 0) {
      break;
    } else if (number % 2 == 0 && number > 2) {
      if (check_goldbach(number) == 1) {
        printf("Golbach is correct for %d\n", number);
      } else {
        printf("You win the golbach price for %d\n", number);
      }
    } else {
      printf("please enter even number that is greater that 2\n");
    }
  }
}
