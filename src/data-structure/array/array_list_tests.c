#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list.h"

int ArrayListTests() {
  int i, element;

  printf("\n");
  printf(" +--------------------------------------+\n");
  printf(" |                                      |\n");
  printf(" |              Array List              |\n");
  printf(" |                                      |\n");
  printf(" +--------------------------------------+\n");
  printf("\n");

  ArrayList *list = create(10);

  for (i = 0; i < list->size; i++) {
    element = i + 1;

    if (i % 2 == 0) element = (element * 3) - 2;

    insert(list, i, element);
  }

  print(list);

  printf("\nCode: %d\n", push(list, 11));  // 5 -> ARRAY_FULL

  for (i = 0; i < list->size; i++) {
    exclude(list, i);
  }

  print(list);

  printf("\nCode: %d\n", exclude(list, -1));    // 1 -> INVALID_POSITION
  printf("\nCode: %d\n", insert(list, -1, 1));  // 1 -> INVALID_POSITION

  for (i = 0; i < list->size; i++) {
    insert(list, i, i + 1);
  }

  erase(list);

  print(list);

  ArrayList *secondList = create(13);

  for (i = 0; i < secondList->size; i++) {
    insert(secondList, i, i + 1);
  }

  print(secondList);

  for (i = 0; i < secondList->size / 2; i++) {
    swap(secondList, i, secondList->size - i - 1);
  }

  print(secondList);

  reverse(secondList);

  print(secondList);

  srand(time(NULL));
  ArrayList *thirdList = create(20);

  for (i = 0; i < thirdList->size; i++) {
    insert(thirdList, i, rand() % 100);
  }

  ArrayList *fourthList = copy(thirdList);
  ArrayList *fifthList = copy(fourthList);

  printf("\nNot sorted list:\n");
  print(thirdList);

  printf("\nBubble sort:\n");
  clock_t begin1 = clock();
  // Timing bubble sort
  bubbleSort(thirdList);
  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
  print(thirdList);

  printf("\nSelection sort:\n");
  clock_t begin2 = clock();
  // Timing selection sort
  selectionSort(fourthList);
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
  print(fourthList);

  printf("\nInsertion sort:\n");
  clock_t begin3 = clock();
  // Timing blender sort
  insertionSort(fifthList);
  clock_t end3 = clock();
  double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
  print(fifthList);

  // Desceding order
  reverse(thirdList);
  // print(thirdList);

  // printf("\nBlender: \n");
  // blenderSort(thirdList);
  // print(thirdList);

  printf("\nTotal time spent for bubble sort: %lf seconds", time_spent1);
  printf("\nTotal time spent for selection sort: %lf seconds", time_spent2);
  printf("\nTotal time spent for insertion sort: %lf seconds", time_spent3);

  ArrayList *sixthList = create(1000);
  for (i = 0; i < sixthList->size; i++) {
    insert(sixthList, i, rand() % 100);
  }

  int j = 64;
  printf("\nOccurrences of the number %d in the array: %d", j,
         ocurrance(sixthList, j));

  printf("\nAnd its positions:\n");
  ArrayList *positions = getIndexes(sixthList, j);

  print(sixthList);
  printf("\nAll %ds", j);
  for (i = 0; i < positions->size; i++) {
    printf("\nPosition %d: %d", positions->array[i],
           sixthList->array[positions->array[i]]);
  }

  printf("\nThe list has a minimum value of %d and a maximum value of %d",
         min(sixthList), max(sixthList));
  insertionSort(sixthList);
  print(sixthList);

  free(list);
  free(secondList);
  free(thirdList);
  free(fourthList);
  free(fifthList);
  free(sixthList);
  free(positions);

  printf("\n");

  return SUCCESS;
}

int main() {
  ArrayListTests();

  return 0;
}
