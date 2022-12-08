# Aula 2 - Criação de uma primeira estrutura

## Criando uma estrutura simples

_Struct_ - Estrutura de dados heterogênea, usada para representr o que em outras linguagens é chamado de **registro**. Em outras palavras, é uma coleção de variáveis referenciadas por um nome, sendo conveninente para manter informacões relacionadas agrupadas.

- Cada uma das variáveis que compoem a _struct_ é chamada de membro (ou campo) da _struct_.

```C
struct Produto {
    int codigo;
    float preco;
}

struct Dt_dma {
    int dia, mes, ano;
}
```

Quando se declara a _struct_, um tipo de dado novo é criado, logo, deve-se declarar a variável do tipo _struct_.

```C
struct Produto p1;
struct Dt_dma hoje;
```

## Criando uma estrutura com typedef

O comando `typedef` permite criar um novo tipo de dado, que pode ser usado em qualquer lugar onde um tipo de dado seja permitido.

```C
typedef struct {
    int codigo;
    float preco;
} Produto;

typedef struct {
    int dia, mes, ano;
} Dt_dma;
```

- O comando `typedef` cria um novo tipo de dado chamado `Produto` que é uma estrutura com os campos `codigo` e `preco`.

```C
Produto p1;
Dt_dma dt1;
```

Dessa forma, pode-se usar apenas o tipo criado na estrutura, e não _struct_ para declarar a variável.

> 💡 Em resumo, o comando `struct` cria a estrutura e o `typedef` define um novo tipo.

### Atribuição

```C
p1.codigo = 104;
dt1.ano = 2002;
```

## Ponteiros e alocação de memória ✒

Em **C** há uma distinção bastante explícita entre um tipo (ou uma estrutura) e um endereço:

- `int x;` significa que _x_ é uma variável do tipo **inteiro**.
- `int* y;` significa que _y_ é uma variável do tipo **endereço para inteiro**

O asterisco - \* - após a palavra _int_ indica que estamos falando de um endereço inteiro e não mais de um inteiro.

Veja um [exemplo de ponteiro](ponteiros.c)

- A variável x é inicializada com o valor 25.
- A variável y recebe o endereço onde está a variável x.
- Coloca-se o valor 30 na posição de memória referenciada (apontada) pelo endereço armazenado em y.

| posição de memória | variável | valor |
| ------------------ | -------- | ----- |
| 0940               | x        | 30    |
| 0936               | y        | 0940  |

Nesse caso:

- `int*` indica que será armazenado um ponteiro para uma variável do tipo **inteiro**;
- `&x` pega a posição de memória ou referência (ponteiro) da variável _x_;
- `*y` pega o valor na memória referenciada por _y_

### Struct e Ponteiro

```C
struct Dt_dma *p; // p é um ponteiro para registros de tipo Dt_dma
struct Dt_dma dt1; // dt1 é uma variável do tipo Dt_dma
p = &dt1; // p aponta para dt1
p->ano = 2002; // atribui o valor 2002 ao campo ano da variável dt1
(*p).ano = 2002; // atribui o valor 2002 ao campo ano da variável dt1
```

- O acesso ao membro de uma _struct_ pode ser feito de duas formas:
  - `p->ano` - operador de acesso ao membro;
  - `(*p).ano` - operador de acesso ao membro.

### malloc

Em _C_ há uma função para alocação de memória: **malloc** (_memory allocation_)

- recebe como parâmetro o **número de bytes** (quantidade de bytes) que se deseja alocar.
- retorna o endereço inicial do bloco de bytes que foi alocado, porém esse retorno tem o tipo void\* (ponteiro para void).
- há um operador chamado **sizeof** que recebe como parâmetro um tipo (simples ou composto) e retorna a quantidade de bytes ocupada por esse tipo.

- [Refatoração](PesoAltura.c) do código usando `malloc`.
- [Veja aqui](comparativo-c-com-java.md) uma comparação entre as linguagens C e Java.
