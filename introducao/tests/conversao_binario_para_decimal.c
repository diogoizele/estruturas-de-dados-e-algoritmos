#include <stdio.h>

#define tamanho 8
#define ZERO 48
#define UM 49

int potencia(int base, int expoente)
{

    int resultado = base;

    for (int i = 0; i < (expoente - 1); i++)
    {
        resultado = resultado * base;
    }

    return resultado;
}

int main()
{

    char exemplo[tamanho] = {"00100110"};
    int aux, inteiro = 0;

    printf("bit: %s \n", exemplo);

    char copia[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        copia[i] = exemplo[i];
    }

    for (int i = 0; i < tamanho; i++)
    {
        aux = tamanho - (i + 1);
        exemplo[i] = copia[aux];
    }

    printf("\nInverte Bit: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", exemplo[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (exemplo[i] == UM)
        {

            inteiro += potencia(2, i);
        }
    }

    printf("\nResultado final: %d\n", inteiro);

    return 0;
}