#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include "array.constants.h"

// *-------------------------------*

Array *create(int size) {

  // Allocate memory for the struct array.
  Array *array = (Array *)malloc(sizeof(Array));

  // Allocate memory for the vector that will be used to store the elements.
  array->elements = (int *)malloc(sizeof(int) * size);
  array->size = size;

  // Initialize all elements with 0.
  for (int i = 0; i < size; i++) {

    // use -> to access a variable inside a pointer.
    array->elements[i] = 0;
  }

  return array;
}

// *-------------------------------*

Array *copy(Array *target) {

  // Allocate memory for the target array
  Array *newArray = (Array *)malloc(sizeof(Array));
  int size = target->size;

  newArray->elements = (int *)malloc(sizeof(int) * size);
  newArray->size = size;

  for (int i = 0; i < size; i++) {
    newArray->elements[i] = target->elements[i];
  }

  return newArray;
}

// *-------------------------------*

int insert(Array *target, int index, int element) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  // if position was already has a value
  if (target->elements[index] != 0) return INITIALIZED;

  target->elements[index] = element;

  return SUCCESS;
}

// *-------------------------------*

int exclude(Array *target, int index) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  if (target->elements[index] == 0) return EMPTY;

  target->elements[index] = 0;

  return SUCCESS;
}

// *-------------------------------*

int push(Array *target, int element) {
  for (int i = 0; i < target->size; i++) {

    if (target->elements[i] == 0) {
      target->elements[i] = element;

      return SUCCESS;
    }
  }

  return ARRAY_FULL;
}

// *-------------------------------*

int update(Array *target, int index, int element) {

  if (index >= target->size || index < 0) return INVALID_POSITION;

  target->elements[index] = element;

  return SUCCESS;
}

// *-------------------------------*

int reset(Array *target) {

  for (int i = 0; i < target->size; i++) {
    target->elements[i] = 0;
  }

  return SUCCESS;
}

// *-------------------------------*

void print(Array *target) {

  printf("\n[");

  for (int i = 0; i < target->size; i++) {
    printf(" %d", target->elements[i]);

    if (i < target->size - 1) printf(", ");
  }

  printf(" ]\n");
}

// *-------------------------------*
