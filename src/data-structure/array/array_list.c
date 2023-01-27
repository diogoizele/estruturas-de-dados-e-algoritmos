#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ArrayList *create(int size) {
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));

  list->array = (int *)malloc(sizeof(int) * size);
  list->size = size;

  for (int i = 0; i < size; i++) {
    list->array[i] = 0;
  }

  return list;
}

ArrayList *copy(ArrayList *list) {
  ArrayList *newList = (ArrayList *)malloc(sizeof(ArrayList));

  newList->array = (int *)malloc(sizeof(int) * list->size);
  newList->size = list->size;

  for (int i = 0; i < list->size; i++) {
    newList->array[i] = list->array[i];
  }

  return newList;
}

int insert(ArrayList *list, int index, int value) {
  if (index >= 0 && index < list->size) {
    if (list->array[index] == 0) {
      list->array[index] = value;
      return SUCCESS;
    } else
      return POSITION_INIT;
  }
  return INVALID_POSITION;
}

int exclude(ArrayList *list, int index) {
  if (index >= 0 && index < list->size) {
    if (list->array[index] != 0) {
      list->array[index] = 0;
    } else
      return POSITION_EMPTY;
  }
  return INVALID_POSITION;
}

int push(ArrayList *list, int value) {
  int i, ok = 0;

  for (i = 0; i < list->size; i++) {
    if (list->array[i] == 0) {
      list->array[i] = value;
      ok = 1;
      break;
    }
  }

  if (ok)
    return SUCCESS;
  else
    return ARRAY_FULL;
}

int update(ArrayList *list, int index, int value) {
  if (index >= 0 && index < list->size) {
    if (list->array[index] != 0) {
      list->array[index] = value;
      return SUCCESS;
    } else
      return POSITION_NOT_INIT;
  }
  return INVALID_POSITION;
}

int erase(ArrayList *list) {
  for (int i = 0; i < list->size; i++) {
    list->array[i] = 0;
  }

  return SUCCESS;
}

int swap(ArrayList *list, int index1, int index2) {
  if (index1 >= 0 && index1 < list->size && index2 >= 0 &&
      index2 < list->size) {

    int temp = list->array[index1];
    list->array[index1] = list->array[index2];
    list->array[index2] = temp;

    return SUCCESS;
  }

  return INVALID_POSITION;
}

int reverse(ArrayList *list) {
  for (int i = 0; i < list->size / 2; i++) {
    swap(list, i, list->size - i - 1);

    return SUCCESS;
  }
}

int print(ArrayList *list) {
  printf("\nArrayList = [\n");
  for (int i = 0; i < list->size; i++) {
    printf("%d", list->array[i]);

    if (i != list->size - 1) printf(", ");
  }
  printf(" ]\n");

  return SUCCESS;
}
