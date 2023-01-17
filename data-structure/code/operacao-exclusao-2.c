#include <stdio.h>

int main() {

  int arr[] = {18, 30, 15, 70, 12};
  int removed_index = 2, n = 5;
  int i, j;

  printf("Given array elements are:\n");

  for (i = 0; i < n; i++) 
    printf("arr[%d]=%d ", i, arr[i]);

  j = removed_index;

  while (j < n) {
    arr[j] = arr[j + 1];
    j++;
  }

  n--;

  printf("\nElements of array after deletion\n");

  for (i = 0; i < n; i++) 
    printf("arr[%d]=%d, ", i, arr[i]);

  return 0;
}