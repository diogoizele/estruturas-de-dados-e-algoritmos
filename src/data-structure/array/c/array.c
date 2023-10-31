#include <stdio.h>
#include <stdlib.h>

#define MEMORY_CLEANED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define ARRAY_FULL 2
#define INITIALIZED 3
#define EMPTY 4

typedef struct Array {
  int *elements;
  int size;
} Array;

Array *create(int size);
Array *copy(Array *target);

int insert(Array *target, int index, int element);
int exclude(Array *target, int index);
int push(Array *target, int element);
int update(Array *target, int index, int element);

int reset(Array *target);

void print(Array *target);

Array *create(int size) {

  Array *array = (Array *)malloc(sizeof(Array));

  array->elements = (int *)malloc(sizeof(int) * size);
  array->size = size;

  for (int i = 0; i < size; i++) array->elements[i] = 0;

  return array;
}

Array *copy(Array *target) {

  Array *newArray = (Array *)malloc(sizeof(Array));
  int size = target->size;

  newArray->elements = (int *)malloc(sizeof(int) * size);
  newArray->size = size;

  for (int i = 0; i < size; i++) newArray->elements[i] = target->elements[i];

  return newArray;
}

int insert(Array *target, int index, int element) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  if (target->elements[index] != 0) return INITIALIZED;

  target->elements[index] = element;

  return SUCCESS;
}

int exclude(Array *target, int index) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  if (target->elements[index] == 0) return EMPTY;

  target->elements[index] = 0;

  return SUCCESS;
}

int push(Array *target, int element) {
  for (int i = 0; i < target->size; i++) {

    if (target->elements[i] == 0) {
      target->elements[i] = element;

      return SUCCESS;
    }
  }

  return ARRAY_FULL;
}

int update(Array *target, int index, int element) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  target->elements[index] = element;

  return SUCCESS;
}

int reset(Array *target) {

  for (int i = 0; i < target->size; i++) {
    target->elements[i] = 0;
  }

  return SUCCESS;
}

void print(Array *target) {

  printf("\n[");

  for (int i = 0; i < target->size; i++) {
    printf(" %d", target->elements[i]);

    if (i < target->size - 1) printf(", ");
  }

  printf(" ]\n");
}
