#include <stdio.h>

struct Produto
{
    int cod;
    float preco;
};

void leProd(struct Produto *q)
{
    int i;

    for (i = 0; i < 3; i++)
    {

        printf("Codigo? ");
        scanf("%d", &q->cod);
        printf("Preco? ");
        scanf("%f", &q->preco);
        q++;
    }
}

void mostraProd(struct Produto *q)
{

    int i;

    printf("Novo preco\n");
    for (i = 0; i < 3; i++)
    {

        printf("Codigo: %d - Preco: %.2f\n", q->cod, q->preco);
        q++;
    }
}

void aumenta(struct Produto *p)
{

    int i;

    // Aumentando o preco
    for (i = 0; i < 3; i++)
    {
        p->preco *= 1.15;
        p++; // Como trata-se de uma lista sequencial, com memória contígua, incrementar o ponteiro faz o acesso aos outros elementos
    }
}

void main()
{

    struct Produto prod[3];

    leProd(&prod[0]);

    aumenta(&prod[0]);

    mostraProd(&prod[0]);
}