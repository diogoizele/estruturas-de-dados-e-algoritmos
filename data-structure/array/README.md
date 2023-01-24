# Array (Arranjo)

> A ideia de um array é representar muitas instâncias em uma variável .

Imagine que queremos armazenar as notas de todos os alunos de uma turma, podemos usar um array para armazená-las. Isso ajuda a reduzir o uso de várias variáveis, pois não precisamos criar uma variável separada para notas de cada disciplina. Todas as marcas podem ser acessadas simplesmente percorrendo o arranjo.

Um array é uma **estrutura de dados linear** usada para armazenar **elementos homogêneos** em locais contíguos. O **tamanho** do array deve ser fornecido antes de armazenar os dados.

Na programação C, eles são os tipos de dados derivados que podem armazenar dados do tipo primitivo, como int, char, double, float, etc.

## Vantagens

- Arrays fornecem o nome único para o grupo de variaveis do mesmo tipo.
- Percorrer um array é um processo muito simples, pois os elementos são armazenados em locais contíguos.
- Qualquer elemento pode ser acessado diretamente usando o nome do array e o índice do elemento.
- Os arrays são os melhores para processar vários valores de forma rápida e fácil.

## Desvantagens

- O arranjo é homogêneo, ou seja, todos os elementos devem ser do mesmo tipo.
- No array, há alocações de memória estáticas, o que significa que o tamanho deve ser fornecido antes de armazenar os dados e não pode ser alterado.
- Haverá desperdício de memória se armazenarmos menos elementos do que o tamanho declarado.

## Alocação de Memória

Conforme declarado acima, todos os elementos são armazenados em locais contíguos (vizinhos) na memória principal. O nome do array representa o endereço base ou o **endereço do primeiro elemento na memória** principal.

## Acessando Elementos

Para acessar qualquer elemento aleatório na matriz, necessita-se saber:

- Endereço base da matriz (ou endereço do primeiro elemento)
- Tamanho de um elemento em bytes (`sizeof()`)
- Tipo de indexação - geralmente é 0 ou 1

A fórmula para calcular o endereço para acessar um elemento da matriz:

> Endereço de byte do elemento A[i] = Endereço base da matriz + tamanho \* (i - indexação)

Por exemplo:

```C
#include <stdio.h>

int main(void) {
  int arr[5] = {18, 30, 15, 70, 12};

  int *baseAddress = &arr[0];
  int indexing = 0;
  int elementSize = sizeof(int);

  int i = 2; // index of the element to be accessed

  int *addressOfElement = (int*)((char*)baseAddress + (elementSize * (i - indexing)));

  printf("The address of element %d is %p\n\n", i, addressOfElement);
  printf("The element of address %p is %d\n\n", addressOfElement,
         *(baseAddress + 2));

  return 0;
}
```

Quando você trabalha com ponteiros em C, a soma de um ponteiro com um inteiro é interpretada como avançar o ponteiro pelo número de bytes correspondente ao tipo apontado pelo ponteiro.

Por exemplo, se você tem um ponteiro para int (int \*), e você soma 1 a ele, o ponteiro será avançado em 4 bytes (tamanho de um inteiro em muitas arquiteturas). Já se você tem um ponteiro para char (char \*), e você soma 1 a ele, o ponteiro será avançado em 1 byte (tamanho de um char).

Então, para poder acessar uma posição específica de uma string por exemplo, é necessário usar um ponteiro para char, para poder avançar uma posição na memória a cada incremento. Dessa forma, você pode acessar cada caractere da string individualmente.

Os tamanhos de bytes dos tipos primitivos em C podem variar de acordo com a arquitetura da máquina e com a implementação do compilador. Mas, geralmente, os tamanhos são os seguintes:

- char: 1 byte
- short: 2 bytes
- int: 4 bytes
- long: 4 bytes (em algumas arquiteturas pode ser 8 bytes)
- long long: 8 bytes
- float: 4 bytes
- double: 8 bytes

É importante lembrar que esses tamanhos são apenas uma convenção e podem variar dependendo da arquitetura da máquina e do compilador utilizado. A função sizeof() pode ser usada para verificar o tamanho de bytes de um tipo específico em uma determinada plataforma.

## Notação O - Big O Notation

Em um array de tamanho n, sendo n o número de elementos desse array, a complexidade de tempo para as operações básicas é:

- **Tempo de acesso**: O(1) - Isto é possível pois os elementos são armazenados em locais contíguos.
- **Tempo de pesquisa**: O(n) - Para pesquisa sequencial: O(log n) para pesquisa binária (se a matriz estiver ordenada corretamente).
- **Tempo de inserção**: O(n) - O pior caso ocorre quando a inserção acontece no início de uma matriz e requer a mudança de todos os elementos.
- **Tempo de exclusão**: O(n) - O pior caso ocorre quando a exclusão acontece no início de uma matriz e requer a mudança de todos os elementos.

## Complexidade de tempo

| Operação    | Caso médio | Pior caso |
| ----------- | ---------- | --------- |
| Acesso      | O(1)       | O(1)      |
| Pesquisa    | O(n)       | O(n)      |
| Inserção    | O(n)       | O(n)      |
| Exclusão    | O(n)       | O(n)      |
| Atualização | O(1)       | O(1)      |

## Complexidade de espaço

No arranjo, a complexidade de espaço para o pior caso é O(n), onde n é o número de elementos na matriz.

# Algoritmos

| Nome               | Código                                               |
| ------------------ | ---------------------------------------------------- |
| Operação Traversal | [Clique aqui](../../algorithm/operacao-traversal.md) |
| Operação Inserção  | [Clique aqui](../../algorithm/operacao-insercao.md)  |
| Operação Exclusão  | [Clique aqui](../../algorithm/operacao-exclusao.md)  |
| Operação Pesquisa  | [Clique aqui](../../algorithm/operacao-pesquisa.md)  |

## Aplicações da Estrutura de Dados Array

- Arrays são usados para implementar listas, pilhas, filas, etc.
- Arrays são usados para matrizes e outras implementações matemáticas.
- Arrays são usados em tabelas de pesquisa de computadores.
- Arrays podem ser usados para escalonamento de CPU.

## Aplicações em Tempo Real

- Listas de contatos em telefones celulares.
- Arrays são usados em portais de reserva de passagens online.
- Páginas de livro.

## Array Dinâmico em C

Aqui está um exemplo de como redimensionar um array dinâmico em C:

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *p;

    printf("Insira o tamanho inicial do array: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int)); // alocando memória para o array dinâmico

    if (p == NULL) { // verificando se a alocação foi bem-sucedida
        printf("Memória insuficiente!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Insira o valor %d: ", i+1);
        scanf("%d", &p[i]);
    }

    printf("Valores do array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    int new_n;
    printf("Insira o novo tamanho do array: ");
    scanf("%d", &new_n);

    p = (int *)realloc(p, new_n * sizeof(int)); // redimensionando o array

    if (p == NULL) { // verificando se a alocação foi bem-sucedida
        printf("Memória insuficiente!\n");
        return 1;
    }

    if (new_n > n) {
        for (i = n; i < new_n; i++) {
            printf("Insira o valor %d: ", i+1);
            scanf("%d", &p[i]);
        }
    }

    printf("Valores do array redimensionado: ");
    for (i = 0; i < new_n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p); // liberando a memória alocada dinamicamente

    return 0;
}
```

O código acima solicita ao usuário para inserir o tamanho inicial do array, aloca a memória necessária usando malloc(), armazena valores inseridos pelo usuário no array, depois ele solicita o novo tamanho para o array, redimensionando o array com a função realloc() e, por fim, libera a memória usando free().

Note que ao usar realloc, os valores anteriores são copiados para o novo endereço de memória alocado, caso o novo tamanho seja menor que o anterior alguns valores poderam ser perdidos.
