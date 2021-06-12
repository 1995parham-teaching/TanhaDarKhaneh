#include <stdio.h>
#include <string.h>

int tokenizer(char *s, char *token, char result[][100]) {
  char *p;
  int res_index = 0;

  while ((p = strstr(s, token)) != NULL) {
    strncpy(result[res_index], s, p - s);
    result[res_index][p - s] = '\0';
    res_index++;

    s = p + strlen(token);
  }
  strcpy(result[res_index], s);
  res_index++;

  return res_index;
}

int main() {
  char *s[] = {
      "Hello-123-73-123-2222-Parham-Salam",
      "ABxyCD",
      "ABxyCD",
  };

  char *token[] = {
      "-",
      "yx",
      "xy",
  };

  for (int j = 0; j < sizeof(s) / sizeof(char *); j++) {
    printf("** s: %s, token: %s **\n", s[j], token[j]);

    char result[100][100];

    int len = tokenizer(s[j], token[j], result);

    for (int i = 0; i < len; i++) {
      printf("[%d]: %s\n", i + 1, result[i]);
    }
  }
}
