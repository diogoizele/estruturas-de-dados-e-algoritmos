#include <stdio.h>

int main()
{

    int arr[] = {18, 30, 15, 70, 12};
    int removed_item_index = 1, arr_length = 5;

    printf("\nFirst array elements:\n");
    for (int i = 0; i < arr_length; i++)
        printf("arr[%d] = %d ", i, arr[i]);

    for (int i = removed_item_index; i < arr_length; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr_length--;

    printf("\nSecond array elements:\n");

    for (int i = 0; i < arr_length; i++)
        printf("arr[%d] = %d ", i, arr[i]);

    printf("\nEnd program!\n");

    return 0;
}