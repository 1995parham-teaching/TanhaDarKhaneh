#include <stdio.h>
#include <string.h>

int main() {
  char greeting[100] = "Hello ";

  char name[] = "Parham";

  printf("%lu\n", sizeof(name));

  strcat(greeting, name);

  printf("greeting: %s\n", greeting);
  printf("name: %s\n", name);
}
