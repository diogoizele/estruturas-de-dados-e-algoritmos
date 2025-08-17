#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

void beginsert(LinkedList *list, int item) {

  Node *ptr = (Node *)malloc(sizeof(Node));

  if (ptr == NULL) {
    printf("\nOVERFLOW");
    return;
  }

  ptr->data = item;
  ptr->next = list->head;

  list->head = ptr;

  list->size++;

  printf("Node inserted");
}

int main() {

  int choice, item;
  LinkedList l;
  Node *n;

  l.head = NULL;
  l.size = 0;

  do {
    printf("\nEnter the item which you want to insert: ");

    scanf("%d", &item);
    beginsert(&l, item);

    printf("\nPress 0 to insert more? ");
    scanf("%d", &choice);

  } while (choice == 0);

  n = l.head;

  printf("\nPrint Nodes:");
  while (n != NULL) {
    printf("\nNode: %d", n->data);
    n = n->next;
  }

  return 0;
}