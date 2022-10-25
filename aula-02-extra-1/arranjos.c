#include <stdio.h>
#include <stdlib.h>

void imprimir(int *w)
{
    printf("w0: %i, w1: %i, w2: %i\n", w[0], w[1], w[2]);
    printf("&w: %p, w: %p, *w: %i\n", &w, w, *w);
}

int main()
{
    int x[3];

    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);
    printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);

    imprimir(x);
}