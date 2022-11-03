#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

int tamanho(LISTA *l)
{
    return l->nroElem;
}


int main()
{
    /**
     * Cria uma variável do tipo de estrutura lista.
     */
    LISTA lista;

    printf("Valor inicial de nroElem: %i <- (valor do endereço de memória)\n", lista.nroElem);

    /**
     * Inicializa a lista utilizando a função e passando
     * o endereço da lista recém declarada como parâmetro.
     *
     * A inicialização consiste em definir o nroElem da
     * LISTA para 0.
     */
    inicializarLista(&lista);

    printf("Valor de nroElem depois de inicializar a lista: %i\n\n", lista.nroElem);

    /**
     * Exibe o tamanho da lista utilizando a função e passando
     * o endereço da lista recém declarada como parâmetro.
     *
     * O tamanho da lista é o valor do nroElem da LISTA.
     */

    int t = tamanho(&lista);

    printf("Tamanho atual da lista: %i \n", t);

    return 0;
}