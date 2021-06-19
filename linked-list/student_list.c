#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[255];
  int id;
  double avg;
};

struct node {
  struct student data;
  struct node *next;
};

struct node *node_new(struct student std) {
  struct node *nn = malloc(sizeof(struct node));
  nn->data = std;
  nn->next = NULL;

  return nn;
}

void list_push_back(struct node **head, struct student std) {
  struct node *nn = node_new(std);

  if (*head == NULL) {
    // the list is empty so we need to change its head
    // to point on created node.
    *head = nn;
  } else {
    // the list isn't empty so we only need to update the last node.
    struct node *current;

    for (current = *head; current->next != NULL; current = current->next)
      ;

    current->next = nn;
    nn->next = NULL;
  }
}

void list_push_front(struct node **head, struct student std) {
  struct node *nn = node_new(std);

  // head
  //  |
  //  n1 -> n2 -> n3 -> n4
  //
  //  head
  //   |
  //  nn -> n1 -> n2 -> n3 -> n4

  nn->next = *head;
  *head = nn;
}

void list_push_next(struct node *next_to, struct student std) {
  //  next_to
  //    |
  //    n1 -> n2
  //
  //  next_to
  //    |
  //    n1 -> nn -> n2

  struct node *nn = node_new(std);

  nn->next = next_to->next;
  next_to->next = nn;
}

void list_pop_next(struct node *next_to) {
  //  next_to
  //    |
  //    n1 -> to_delete -> n3
  //
  //  next_to
  //    |
  //    n1 -> n3

  if (next_to->next == NULL) {
    return;
  }

  struct node *to_delete = next_to->next;

  next_to->next = to_delete->next;
  free(to_delete);
}

struct node *list_find_by_id(struct node *head, int id) {
  struct node *current;

  for (current = head; current != NULL; current = current->next) {
    if (current->data.id == id) {
      return current;
    }
  }

  return NULL;
}

void list_remove_duplicate_id(struct node *head) {
  struct node *current;

  for (current = head; current != NULL; current = current->next) {
    int id = current->data.id;
    struct node *check = current;

    // [1] -> 1 -> 1 -> 2 -> 1 -> NULL
    // 1 -> x -> x -> [2] -> 1 -> NULL
    // 1 -> x -> x -> 2 -> x -> [NULL]
    while(check->next != NULL) {
      if (check->next->data.id == id) {
        list_pop_next(check);
      } else {
        check = check->next;
      }
    }
  }
}

void list_print(struct node *head) {
  struct node *current;
  int index = 0;

  for (current = head; current != NULL; current = current->next) {
    index++;

    printf("[%d]:\n", index);
    printf("\tname: %s\n", current->data.name);
    printf("\tid: %d\n", current->data.id);
    printf("\tavg: %lf\n", current->data.avg);
  }
}

int main() {
  struct node *head = NULL;

  struct student std1 = {"Parham Alvani", 9231058, 19.02};
  struct student std2 = {"Sepehr", 9231025, 20.0};

  printf("check_push_back():\n");

  list_push_back(&head, std1);
  list_print(head);

  printf("check_push_front():\n");

  list_push_front(&head, std2);
  list_print(head);

  printf("check_find_by_id():\n");

  struct node *n;

  n = list_find_by_id(head, 9231016);
  if (n == NULL) {
    printf("there is no node with id 9231016\n");
  } else {
    printf("there is a node with id 9231016\n");
  }

  printf("check_push_next():\n");

  struct student std3 = {"Saman", 9231057, 18.0};
  n = list_find_by_id(head, 9231025);
  list_push_next(n, std3);
  list_print(head);

  printf("check_pop_next():\n");

  list_pop_next(n);
  list_print(head);

  printf("check_duplicate_by_id():\n");
  list_push_back(&head, std1);
  list_push_back(&head, std2);
  list_push_back(&head, std1);
  list_push_back(&head, std3);
  list_push_back(&head, std3);
  list_push_back(&head, std1);

  printf("\t >> before:\n");
  list_print(head);

  list_remove_duplicate_id(head);

  printf("\t >> after:\n");
  list_print(head);
}
