#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

int buscaBinaria(LISTA *l, TIPOCHAVE ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;
    while (esq <= dir)
    {
        meio = ((esq + dir) / 2);
        if (l->A[meio].chave == ch)
            return meio;
        else
        {
            if (l->A[meio].chave < ch)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
    }
    return -1;
}