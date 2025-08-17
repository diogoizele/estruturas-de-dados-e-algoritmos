#include <stdio.h>

int main() {
  int arr[] = {18, 30, 16, 72, 20};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("The array's elements are: \n");
  for (int i = 0; i < size; i++) {
    printf("Arr[%d] = %d, ", i, arr[i]);
  }

  return 0;
}