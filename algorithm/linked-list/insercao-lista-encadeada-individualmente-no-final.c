#include <stdio.h>
#include <stdlib.h>

typedef struct _ {
  int data;
  struct _ *next;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

void endinsert(LinkedList *list, int item) {

  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL) {
    printf("\nOVERFLOW");
    return;
  }

  node->data = item;

  if (list->head == NULL) {
    list->head = node;
  } else {
    Node *temp = list->head;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = node;
  }

  printf("\nNode inserted");
};

int main() {
  int choice, item;
  LinkedList l;
  Node *n;

  l.head = NULL;
  l.size = 0;

  do {
    printf("\nEnter the item which you want to insert: ");

    scanf("%d", &item);
    endinsert(&l, item);

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