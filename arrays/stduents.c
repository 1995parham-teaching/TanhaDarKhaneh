/*
 * In The Name of God
 * =======================================
 * [] File Name : stduents.c
 *
 * [] Creation Date : 17-04-2020
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2020 Parham Alvani.
 */
#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 100

void read_data(char names[][MAX_NAME_SIZE], double grades[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter name: ");
    scanf("%s", names[i]);

    printf("Enter grade: ");
    scanf("%lf", &(grades[i]));
  }
}

double get_average(double grades[], int size) {
  int i;
  double res = 0;
  for (i = 0; i < size; i++)
    res += grades[i];
  return (res / size);
}

void print_names(char names[][MAX_NAME_SIZE], double grades[], int size,
                 double average) {
  int i;
  printf("Average = %lf \n", average);
  printf("List of students whose grade is above the average: \n");

  for (i = 0; i < size; i++)
    if (grades[i] > average)
      printf("%s\n", names[i]);
}

int main(void) {
  int num;
  printf("Enter number of students: ");
  scanf("%d", &num);

  double grades[num];

  char names[num][MAX_NAME_SIZE];

  read_data(names, grades, num);

  double average = get_average(grades, num);

  print_names(names, grades, num, average);

  return 0;
}
