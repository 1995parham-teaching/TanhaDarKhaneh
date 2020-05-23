#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *newNode(int data) {
  struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
  new_Node->data = data;
  new_Node->next = NULL;
  return new_Node;
}

void addFront(struct Node **head, int data) {
  struct Node *new_node = newNode(data);
  new_node->next = *head;
  *head = new_node;
}

/*
 * wrong version of add front functionality.
 *
 *struct Node * addFront(struct Node *head,int data)
 *{
 *	struct Node * new_node = newNode(data);
 *	new_node->next= *head;
 *	return new_node;
 * }
 * */

void pushBack(struct Node **head, int data) {
  if (*head == NULL) {
    *head = newNode(data);
    return;
  }
  struct Node *curr = *head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = newNode(data);
}

bool deleteNode(struct Node **head, int data) {
  if (*head == NULL)
    return false;
  if ((*head)->data == data) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return true;
  }
  struct Node *current = *head;
  struct Node *last = NULL;
  while (current != NULL) {
    if (current->data == data) {
      last->next = current->next;
      free(current);
      return true;
    }
    last = current;
    current = current->next;
  }
  return false;
}

void printNodes(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;
  addFront(&head, 1);
  addFront(&head, 2);
  addFront(&head, 3);
  pushBack(&head, 0);
  deleteNode(&head, 2);
  // head = addFront(head,1);
  printNodes(head);
  deleteNode(&head, 3);
  printNodes(head);
}
