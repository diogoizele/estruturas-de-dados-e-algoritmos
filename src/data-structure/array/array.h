#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// # CONSTANTS

#define MEMORY_CLEANED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define ARRAY_FULL 2
#define INITIALIZED 3
#define EMPTY 4

// ----------------------------------

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
