#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list.h"

int ArrayListTests() {
  int i;

  printf("\n");
  printf(" +--------------------------------------+\n");
  printf(" |                                      |\n");
  printf(" |              Array List              |\n");
  printf(" |                                      |\n");
  printf(" +--------------------------------------+\n");
  printf("\n");

  ArrayList *list = create(10);

  // for (i = 0; i < list->size; i++) {
  //   insert(list, i, i + 1);
  // }

  // print(list);

  return SUCCESS;
}

int main() {
  ArrayListTests();

  return 0;
}
