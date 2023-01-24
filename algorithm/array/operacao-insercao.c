#include <stdio.h>

#define MAX 20

int main()
{

  int arr[MAX] = {18, 30, 15, 70, 12};
  int i, new_elem, pos, size = 5;


  printf("Array elements before insertion\n");
  for (i = 0; i < size; i++)
    printf("%d, ", arr[i]);
  
  printf("\n");

  new_elem = 50;
  pos = 3;

  if (size < MAX)
  {

    for (i = size; i > pos; i--)
      arr[i] = arr[i - 1];

    arr[pos] = new_elem;

    size++;
  }

  printf("\nArray elements after insertion\n");
  for (i = 0; i < size; i++)
    printf("%d, ", arr[i]);
  
  printf("\n");

  return 0;
}