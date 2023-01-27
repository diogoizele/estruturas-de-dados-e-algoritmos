#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define ARRAY_DESTROYED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define POSITION_INIT 2
#define POSITION_NOT_INIT 3
#define POSITION_EMPTY 4
#define ARRAY_FULL 5

typedef struct ArrayList {
  int *array;
  int size;
} ArrayList;

// *-------------------------------*
// |         Returns array.        |
// *-------------------------------*

ArrayList *create(int size);
ArrayList *copy(ArrayList *list);

// *-------------------------------*

// *-------------------------------*
// |         Handles array.        |
// *-------------------------------*

int insert(ArrayList *list, int index, int value);
int exclude(ArrayList *list, int index);
int push(ArrayList *list, int value);
int update(ArrayList *list, int index, int value);

// *-------------------------------*

// *-------------------------------*
// |          Free memory.         |
// *-------------------------------*

int erase(ArrayList *list);

// *-------------------------------*

// *-------------------------------*
// |          Switch array.        |
// *-------------------------------*

int swap(ArrayList *list, int index1, int index2);
int reverse(ArrayList *list);

// *-------------------------------*

// *-------------------------------*
// |          Sort array.          |
// *-------------------------------*

int bubbleSort(ArrayList *list);
int selectionSort(ArrayList *list);
int insertionSort(ArrayList *list);
int blenderSort(ArrayList *list);

// *-------------------------------*

// *-------------------------------*
// |          Search array.        |
// *-------------------------------*

int ocurrance(ArrayList *list, int value);
ArrayList *getIndexes(ArrayList *list, int value);
int min(ArrayList *list);
int max(ArrayList *list);

// *-------------------------------*

// *-------------------------------*
// |          Print array.         |
// *-------------------------------*

int print(ArrayList *list);

#ifdef __cplusplus
}
#endif
