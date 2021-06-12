#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
  char fname[255];
  char lname[255];
  int age;
  int grade;
};

int main() {
  FILE *fp = fopen("persons.txt", "r");
  if (fp == NULL) {
    printf("cannot open the given file");
    return -1;
  }

  struct person *persons = NULL;
  int count = 0;

  while (1) {
    struct person p;

    if (fgets(p.fname, sizeof(p.fname)/sizeof(char), fp) == NULL) {
      break;
    }
    p.fname[strlen(p.fname) - 1] = '\0';
    if (fgets(p.lname, sizeof(p.lname)/sizeof(char), fp) == NULL) {
      break;
    }
    p.lname[strlen(p.lname) - 1] = '\0';
    if (fscanf(fp, "%d %d", &p.age, &p.grade) < 2) {
      break;
    }
    fgetc(fp);
    count += 1;

    persons = realloc(persons, count * sizeof(struct person));
    persons[count - 1] = p;
  }

  for (int i = 0; i < count; i++) {
    printf("[%d]\n", i);
    printf("\tfname: %s\n", persons[i].fname);
    printf("\tlname: %s\n", persons[i].lname);
    printf("\tage: %d\n", persons[i].age);
    printf("\tgrade: %d\n", persons[i].grade);
  }
}
