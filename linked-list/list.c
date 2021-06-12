#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
};

struct node *node_construct(int id) {
  struct node *nn = NULL;

  nn = malloc(sizeof(struct node));
  if (nn == NULL) {
    return NULL;
  }

  nn->info = id;
  nn->next = NULL;

  return nn;
}

void list_print(struct node *list) {
  struct node *current = NULL;
  int i = 0;

  for (i = 0, current = list; current != NULL; current = current->next, i++) {
    printf("%d) %d\n", i, current->info);
  }
}

void list_push_back(struct node *list, struct node *nn) {
  struct node *current = NULL;

  for (current = list; current->next != NULL; current = current->next) {
  }

  current->next = nn;
  nn->next = NULL;
}

void list_pop_back(struct node *list) {
  struct node *current = list;

  while (current->next->next != NULL) {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
}

void list_push_front(struct node **plist, struct node *nn) {
  nn->next = *plist;
  *plist = nn;
}

void list_pop_next(struct node *adjacent_to_delete_node) {
  struct node *to_delete = adjacent_to_delete_node->next;
  adjacent_to_delete_node->next = to_delete->next;
  free(to_delete);
}

void list_pop_by_info(struct node *list, int v) {
  // find a node before the node that contains v
  struct node *current = list;
  for (current = list; current->next != NULL && current->next->info != v;
       current = current->next)
    ;

  // there is no node that conaints v
  if (current->next == NULL) {
    return;
  }

  list_pop_next(current);
}

// +--+    +--+    +--+
// |01| -> |02| -> |03| ...
// +--+    +--+    +--+
//  ^
//  |
// list

int main() {
  struct node *list = NULL;

  list = node_construct(10);             // node 01 = (10)
  list->next = node_construct(12);       // node 02 = (12)
  list->next->next = node_construct(13); // node 03 = (13)

  list_print(list);
  printf("\n");

  list_push_back(list, node_construct(15));
  list_push_back(list, node_construct(78));

  list_print(list);
  printf("\n");

  list_pop_by_info(list, 15);

  list_print(list);
  printf("\n");
}
