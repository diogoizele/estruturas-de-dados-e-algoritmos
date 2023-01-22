#include <stdio.h>

int main()
{
    int arr[] = {18, 30, 16, 72, 20};

    printf("The array's elements are: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Arr[%d] = %d, ", i, arr[i]);
    }

    return 0;
}