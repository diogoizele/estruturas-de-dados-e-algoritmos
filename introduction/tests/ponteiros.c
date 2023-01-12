#include <stdio.h>

int main()
{
    int x = 20;
    int *pi = &x;
    printf("inicialmente:\n");
    printf("int x = 20\n");
    printf("int *pi = &x\n");

    printf("\nx guarda o inteiro %d\n", x);
    printf("o valor que *pi recebe é = %p, mas ele em si é = %d\n", &x, *pi);

    printf("\nacessando apenas pi, tem a posição de memória, ou seja &x = %p\n", pi);
    printf("pi == &x :  %s", pi == &x ? "true\n" : "false\n");

    printf("\nacessando *pi, não trabalhamos mais com o ponteiro (posição de memória), mas sim com o próprio valor que o ponteiro aponta = %d\n", *pi);
}