#include <stdio.h>
#include <string.h>

struct student {
  int id;
  char first_name[200];
  char last_name[200];
};

void student_print(const struct student *std) {
  printf("ID: %d\n", std->id);
  printf("Name: %s %s\n", std->first_name, std->last_name);
}

void student_set_first_name(struct student *std, const char *name) {
  strcpy(std->first_name, name);
}

void student_set_id(struct student *std, int id) { std->id = id; }

int main() {
  struct student std = {9231058, "Parham", "Alvani"};
  printf("sizeof(struct student): %lu\n", sizeof(struct student));

  student_print(&std);

  std.id = 9631025;
  student_set_first_name(&std, "PARHAM");

  student_print(&std);
}
