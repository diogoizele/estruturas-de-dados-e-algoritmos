#include <stdio.h>

#define MAX 10

void add(int *p_arr, int num, int index, int *curr_quant_elem) {
  int i, aux = p_arr[0];

  if (index < 0 || index >= MAX) {
    printf("Error: index invalid\n");
    return;
  }

  if (*curr_quant_elem >= MAX) {
    printf("Error: array not size enough to add element: %d\n", num);
    return;
  }

  for (i = *curr_quant_elem; i > index; i--)
    if (i - 1 >= 0) p_arr[i] = p_arr[i - 1];

  p_arr[index] = num;

  *curr_quant_elem = *curr_quant_elem + 1;
}

void print_array(int *p_arr) {
  printf("\nArray: \n");

  for (int i = 0; i < MAX; i++) printf("arr[%d] = %d, \n", i, p_arr[i]);
}

int main() {

  int arr[MAX] = {12, 19, 6, 50, 32};
  int curr_length = 5;

  print_array(arr);

  add(arr, 20, 0, &curr_length);

  print_array(arr);

  add(arr, 10, 3, &curr_length);
  add(arr, 647, 4, &curr_length);
  add(arr, 5, 1, &curr_length);

  print_array(arr);

  add(arr, 23, 9, &curr_length);
  add(arr, 24, 8, &curr_length);

  print_array(arr);

  return 0;
}