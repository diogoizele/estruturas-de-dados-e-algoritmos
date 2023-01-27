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
  }
  return SUCCESS;
}

int print(ArrayList *list) {
  printf("\nArrayList = [ ");
  for (int i = 0; i < list->size; i++) {
    printf("%d", list->array[i]);

    if (i != list->size - 1) printf(", ");
  }
  printf(" ]\n");

  return SUCCESS;
}

int blenderSort(ArrayList *list) {
  srand(time(NULL) * list->size);
  int total = list->size * 100;

  for (int i = 0; i < total; i++) {
    swap(list, rand() % list->size, rand() % list->size);
  }

  return SUCCESS;
}

int bubbleSort(ArrayList *list) {
  int i, j;

  for (i = 0; i < list->size - 1; i++) {
    for (j = 0; j < list->size - i - 1; j++) {
      if (list->array[j] > list->array[j + 1]) swap(list, j, j + 1);
    }
  }

  return SUCCESS;
}

int selectionSort(ArrayList *list) {
  int i, j, min;

  for (i = 0; i < list->size - 1; i++) {
    min = i;
    for (j = i + 1; j < list->size; j++) {
      if (list->array[j] < list->array[min]) min = j;

      swap(list, min, i);
    }
  }

  return SUCCESS;
}

int insertionSort(ArrayList *list) {
  int i, j, num;

  for (i = 1; i < list->size; i++) {
    num = list->array[i];

    j = i - 1;

    while (j >= 0 && list->array[j] > num) {
      list->array[j + 1] = list->array[j];
      j--;
    }

    list->array[j + 1] = num;
  }

  return SUCCESS;
}

int ocurrance(ArrayList *list, int value) {
  int i, total = 0;

  for (i = 0; i < list->size; i++) {
    if (list->array[i] == value) total++;
  }

  return total;
}

ArrayList *getIndexes(ArrayList *list, int value) {
  int i, j = 0;
  int total = ocurrance(list, value);
  ArrayList *result = create(total);

  for (i = 0; i < list->size; i++) {
    if (list->array[i] == value) {
      result->array[j] = i;
      j++;
    }
  }

  return result;
}

int min(ArrayList *list) {
  int i, min = list->array[0];

  for (i = 0; i < list->size; i++) {
    if (list->array[i] < min) min = list->array[i];
  }

  return min;
}

int max(ArrayList *list) {
  int i, max = list->array[0];

  for (i = 0; i < list->size; i++) {
    if (list->array[i] > max) max = list->array[i];
  }

  return max;
}
