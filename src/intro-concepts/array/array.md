# Array (Arranjo / Vetor)

> A ideia de um array é representar muitas instâncias em uma variável .

Imagine que queremos armazenar as notas de todos os alunos de uma turma, podemos usar um array para armazená-las. Isso ajuda a reduzir o uso de várias variáveis, pois não precisamos criar uma variável separada para notas de cada disciplina. Todas as notas podem ser acessadas simplesmente percorrendo o arranjo.

Um array é uma **estrutura de dados linear** usada para armazenar **elementos homogêneos** em locais contíguos. O **tamanho** do array deve ser fornecido antes de armazenar os dados.

Na programação C, eles são os tipos de dados derivados que podem armazenar dados do tipo primitivo, como int, char, double, float, etc.

## Vantagens

- Arrays fornecem o nome único para o grupo de variaveis do mesmo tipo.
- Percorrer um array é um processo muito simples, pois os elementos são armazenados em locais contíguos.
- Qualquer elemento pode ser acessado diretamente usando o nome do array e o índice do elemento.
- Os arrays são os melhores para processar vários valores de forma rápida e fácil.

## Desvantagens

- Os vetores são homogêneos, ou seja, todos os elementos devem ser do mesmo tipo.
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

  int i = 2; // index of the element to be accessed

  int *addressOfElement = (int*) baseAddress + (i - indexing);

  printf("The address of element %d is %p\n\n", i, addressOfElement);
  printf("The element of address %p is %d\n\n", addressOfElement,
         *(baseAddress + 2));

  return 0;
}
```

Quando você trabalha com ponteiros em C, a soma de um ponteiro com um inteiro é interpretada como avançar o ponteiro pelo número de bytes correspondente ao tipo apontado pelo ponteiro.

Por exemplo, se você tem um ponteiro para int (int \*), e você soma 1 a ele, o ponteiro será avançado em 4 bytes (tamanho de um inteiro em muitas arquiteturas). Já se você tem um ponteiro para char (char \*), e você soma 1 a ele, o ponteiro será avançado em 1 byte (tamanho de um char).

Os tamanhos de bytes dos tipos primitivos em C podem variar de acordo com a arquitetura da máquina e com a implementação do compilador. Mas, geralmente, os tamanhos são os seguintes:

- char: 1 byte
- short: 2 bytes
- int: 4 bytes
- long: 4 bytes (em algumas arquiteturas pode ser 8 bytes)
- long long: 8 bytes
- float: 4 bytes
- double: 8 bytes

## Notação O - Big O Notation

Em um array de tamanho n, sendo n o número de elementos desse array, a complexidade de tempo para as operações básicas é:

- **Tempo de acesso**: O(1) - Isto é possível pois os elementos são armazenados em locais contíguos, sendo possível acessar aleatoriamente através do índice.
- **Tempo de pesquisa**: O(n) - Para pesquisa sequencial e O(log n) para pesquisa binária (se a matriz estiver ordenada corretamente).
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

## Aplicações da Estrutura de Dados Array

- Arrays são usados para implementar listas, pilhas, filas, etc.
- Arrays são usados para matrizes e outras implementações matemáticas.
- Arrays são usados em tabelas de pesquisa de computadores.
- Arrays podem ser usados para escalonamento de CPU.

## Aplicações em Tempo Real

- Listas de contatos em telefones celulares.
- Arrays são usados em portais de reserva de passagens online.
- Páginas de livro.
- Arrays são usados em sistemas de gerenciamento de banco de dados.
