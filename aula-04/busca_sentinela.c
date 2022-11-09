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

int buscaSentinela(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while (l->A[i].chave != ch)
        i++;

    if (i == l->nroElem)
        return -1;

    else
        return i;
}