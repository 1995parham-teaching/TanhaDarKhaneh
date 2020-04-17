#include <stdio.h>

int gcd(int a, int b) {
  printf("Start with %d, %d\n", a, b);
  // gcd(b, a % b) = gcd(a, b)

  if (b == 0) {
    return a;
  }

  int result = gcd(b, a % b);

  printf("Finish with %d, %d\n", a, b);

  return result;
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  printf("%d\n", gcd(a, b));
}
