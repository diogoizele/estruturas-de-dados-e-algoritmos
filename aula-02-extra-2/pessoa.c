#include <stdio.h>

typedef struct aux
{
    int cpf;
    int idade;
    struct aux *conjuge;
} PESSOA;

void imprimirCPF(PESSOA p)
{
    if (p.conjuge != NULL)
    {
        printf("CPF: %i x %i\n", p.cpf, p.conjuge->cpf);
    }
}

/**
 * Essa função não causa nenhuma alteração
 * na PESSOA p depois que a função termina
 * de executar.
 *
 * Isso acontece, pois o p.idade incrementado
 * nesse caso é apenas a memória interna da
 * função, que é apagada ao fim da execução.
 */
void envelhecer1(PESSOA p)
{
    p.idade++; //
}

/**
 * Na abordagem envelhecer2, ao invés de
 * receber uma variável do tipo PESSOA,
 * a função recebe um ponteiro para uma
 * variável do tipo PESSOA.
 *
 * Dessa forma, as alterações feitas por
 * p dentro da função, apontam para as
 * variáveis dos objetos criados fora
 * e não em uma memória interna durante
 * a execução da função.
 *
 * A única memória interna é a de p, que
 * será um endereço na memória, e não a
 * própria estrutura.
 */
void envelhecer2(PESSOA *p)
{
    p->idade++;
}

void envelhecer4(PESSOA *p)
{
    p->conjuge->idade++;
}

void envelhecer3(PESSOA p)
{
    p.conjuge->idade++;
}

int main()
{
    PESSOA pessoa1;
    PESSOA pessoa2;
    PESSOA solteira;

    pessoa1.cpf = 310000000;
    pessoa1.idade = 36;

    pessoa2.cpf = 290000000;
    pessoa2.idade = 25;

    solteira.cpf = 1100000000;
    solteira.idade = 19;
    solteira.conjuge = NULL;

    pessoa1.conjuge = &pessoa2;
    pessoa2.conjuge = &pessoa1;

    imprimirCPF(pessoa1);
    imprimirCPF(solteira);

    envelhecer1(pessoa1);  // não muda o valor no endereço original
    envelhecer2(&pessoa1); // muda o valor no endereço original
    envelhecer3(pessoa1);  // muda o valor da idade do conjuge
    envelhecer4(&pessoa1); // muda o valor da idade do conjuge
}