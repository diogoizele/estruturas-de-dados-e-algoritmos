#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

int main() {

  /**
   * *ptr = ponteiro que aloca memória para o Nodo
   * *head = ponteiro para o primeiro Nodo da lista
  */

  Node *head, *ptr;

  ptr = (Node *)malloc(sizeof(Node));

  return 0;
}