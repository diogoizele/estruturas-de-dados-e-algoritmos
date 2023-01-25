#include <stdio.h>

int main() {

  int arr[] = {18, 12, 15, 20, 70};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int i, j = 0, searched_item = 15;

  printf("The array's elements are: \n");

  for (i = 0; i < arr_size; i++) printf("arr[%d]=%d, ", i, arr[i]);

  while (j < arr_size) {
    if (arr[j] == searched_item) break;

    j++;
  }

  printf("\nElement found in %d positions\n", j);

  return 0;
}