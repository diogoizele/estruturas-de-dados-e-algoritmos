#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *y = (int *)malloc(sizeof(int));

    *y = 20;

    int z = sizeof(int);

    printf("y=%p *y=%i &y=%p z=%i\n", y, *y, &y, z);
    return 0;
}