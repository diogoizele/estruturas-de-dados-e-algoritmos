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

bool inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
    if (l->nroElem >= MAX)
        return false;
    int pos = l->nroElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave)
    {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
    return true;
}