#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// # STRUCT

typedef struct Array {
  int *elements;
  int size;
} Array;

// ----------------------------------

// # RETURNS ARRAY

Array *create(int size);
Array *copy(Array *target);

// ----------------------------------

// # BASIC HANDLING

int insert(Array *target, int index, int element);
int exclude(Array *target, int index);
int push(Array *target, int element);
int update(Array *target, int index, int element);

// ----------------------------------

// # FREE MEMORY

int reset(Array *target);

// ----------------------------------

// # SHOW

void print(Array *target);

// ----------------------------------

#ifdef __cplusplus
}
#endif
