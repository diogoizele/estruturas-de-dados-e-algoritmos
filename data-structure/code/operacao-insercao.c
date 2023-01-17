#include <stdio.h>

int main()
{

  // Array with 20 length
  int arr[20] = {18, 30, 15, 70, 12};
  int i, new_elem, pos, current_position = 5;

  int _ex_index = 10;

  printf("Array elements before insertion\n");
  for (i = 0; i < current_position; i++)
    printf("%d, ", arr[i]);
  printf("\n");

  new_elem = 50;
  pos = 3; // on place of element 12
  current_position++;

  printf("Accessing a random element from the array: arr[%d] = %d\n", _ex_index, arr[_ex_index]);

  // iterator starts in last position with element
  // in line 17 the position was incremented, so in the for below it is decreased
  for (i = current_position - 1; i > pos; i--)
  {
    printf("Replace element: arr[%d] = arr[%d]\n", i, i - 1);
    printf("Element: arr[%d] = %d\n", i, arr[i - 1]);
    arr[i] = arr[i - 1];
  }
  arr[pos] = new_elem;

  printf("\nArray elements after insertion\n");
  for (i = 0; i < current_position; i++)
    printf("%d, ", arr[i]);
  printf("\n");

  return 0;
}