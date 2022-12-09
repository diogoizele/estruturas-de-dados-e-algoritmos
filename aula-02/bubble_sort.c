/**
 * Ordenar é o ato de se colocar os elementos de uma sequência, em uma dada relação
 * de ordem entre si, de acordo com um critério pre-estabelecido.
 */

#include <stdio.h>

#define TAMANHO 5

void trocar(int *px, int *py)
{
    int aux = *px;
    *px = *py;
    *py = aux;
}

void preenche_vetor(int vetor[])
{

    int t = TAMANHO;
    printf("\nPreencha um vetor com 5 inteiros:\n");
    for (int i = 0; i < t; i++)
    {
        printf("%dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void imprime_vetor(int vetor[])
{
    int t = TAMANHO;

    printf("\nVetor:\n");
    for (int i = 0; i < t; i++)
    {
        printf("%dº elemento: %d\n", i + 1, vetor[i]);
    }
}

/**
 * primeira iteração:
 * compara:
 * i - j
 * 0 - 1
 * 1 - 2
 * 2 - 3
 * 3 - 4
 *
 * segunda iteração:
 * compara:
 * i - j
 * 0 - 1
 * 1 - 2
 * 2 - 3
 *
 * terceira iteração:
 * compara:
 * i - j
 * 0 - 1
 * 1 - 2
 *
 * quarta iteração:
 * compara:
 * i - j
 * 0 - 1
 */
void ordenagem_bolha(int vetor[])
{

    int t = TAMANHO - 1;

    for (int j = t; j >= 0; j--)
    {
        for (int i = 0; i < j; i++)
        {

            if (vetor[i] > vetor[i + 1])
            {
                trocar(&vetor[i], &vetor[i + 1]);
            }
        }
    }
}

int main()
{
    int x, y;
    int vetor[TAMANHO];

    vetor[0] = 94;
    vetor[1] = 7;
    vetor[2] = 3;
    vetor[3] = 12;
    vetor[4] = 56;

    imprime_vetor(vetor);

    ordenagem_bolha(vetor);
    imprime_vetor(vetor);

    preenche_vetor(vetor);
    ordenagem_bolha(vetor);
    imprime_vetor(vetor);

    return 0;
}