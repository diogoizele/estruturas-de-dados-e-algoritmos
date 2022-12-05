#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

/**
 * o nome aux, para auto referenciar a estrutura
 * internamente antes de acabar a declaração - ELEMENTO
 */
typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

// definição do tipo sendo o PONTEIRO do outro tipo, ELEMENTO
typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

int tamanho(LISTA *l)
{
    PONT end = l->inicio;
    int tam = 0;

    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }

    return tam;
}

void exibirLista(LISTA *l)
{
    PONT end = l->inicio;
    printf("LISTA: \" ");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\" \n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
    PONT pos = l->inicio;
    while (pos != NULL)
    {
        if (pos->reg.chave == ch)
            return pos;
        pos = pos->prox;
    }
    return NULL;
}

// lista ordenada pelos valores das chaves dos registros
PONT buscaSeqOrd(LISTA *l, TIPOCHAVE ch)
{
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch)
        pos - pos->prox;
    if (pos != NULL && pos->reg.chave == ch)
        return pos;
    return NULL;
}