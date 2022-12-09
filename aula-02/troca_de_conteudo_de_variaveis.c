#include <stdio.h>

void trocar(int *px, int *py)
{
    int aux = *px;
    *px = *py;
    *py = aux;
}

int main()
{
    int x, y;

    printf("\nValor para x? ");
    scanf("%d", &x);

    printf("\nValor para y? ");
    scanf("%d", &y);

    // mostrando os conteúdos de x e y
    printf("\nX = %d\nY = %d\n", x, y);

    printf("\nTrocando...\n");

    trocar(&x, &y);

    printf("\nX = %d\nY = %d\n", x, y);

    return 0;
}