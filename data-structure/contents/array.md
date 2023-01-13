# Matriz (Array)

Digamos que queremos armazenar as notas de todos os alunos de uma turma, podemos usar um array para armazená-las. Isso ajuda a reduzir o uso de várias variáveis, pois não precisamos criar uma variável separada para notas de cada disciplina. Todas as marcas podem ser acessadas simplesmente percorrendo a matriz.

Uma matriz é uma estrutura de dados usada para armazenar **elementos homogêneos** em locais contíguos. O **tamanho** de uma matriz deve ser fornecido antes de armazenar os dados.

Na programação C, eles são os tipos de dados derivados que podem armazenar dados do tipo primitivo, como int, char, double, float, etc.

## Propriedades da matriz

Existem algumas das propriedades de uma matriz listada a seguir:

- Cada elemento em uma matriz é do mesmo tipo de dado e carrega o mesmo tamanho que é determinado pelo tipo de dado.
- Os elementos na matriz são armazenados em locais de memória contíguos, dos quais o primeiro elemento é armazenado no menor local de memória.
- Os elementos da matriz podem ser acessados aleatoriamente, pois podemos calcular o endereço de cada elemento da matriz com o endereço base fornecido e o tamanho do elemento.

Arrays são uteis pois podemos:

- Classificar e pesquisar um valor em uma matriz facilmente.
- Os arrays sõa os melhores para processar vários valores de forma rápida e fácil.
- **As matrizes são boas para armazenar vários valores em uma única variável** - Na programação de computadores, a maioria dos casos requer o armazenamento de um grande número de dados de um tipo semelhante. Para armazenar tal quantidade de dados, precisamos definir um grande número de variáveis. Isso torna o programa muito grande e difícil de entender. Portanto, é melhor armazenar todos os dados em uma matriz.

## Alocação de Memória

Conforme declarado acima, todos os elementos são armazenados em locais contíguos na memória principal. O nome do array representa o endereço base ou o endereço do primeiro elemento na memória principal. Cada elemento da matriz é representado pela indexação adequada.

## Acessando Elementos

Exigimos as informações fornecidas abaixo para acessar qualquer elemento aleatório na matriz:

- Endereço base da matriz
- Tamanho de um elemento em bytes
- Tipo de indexação - geralmente é 0 ou 1

A fórmula para calcular o endereço para acessar um elemento da matriz:

> Endereço de byte do elemento A[i] = Endereço base da matriz + tamanho \* (i - indexação)

Aqui, o tamanho representa a memória ocupada pelos tipos de dados primitivos. Como instância, _int_ ocupa 2 bytes, _float_ ocupa 4 bytes de espaço de memória na programação C.

## Notação O

Deixe o tamanho da matriz ser n. Então, a complexidade de tempo para as operações básicas é:

- **Tempo de acesso**: O(1) - Isto é possível pois os elementos são armazenados em locais contíguos.
- **Tempo de pesquisa**: O(n) - Para pesquisa sequencial: O(log n) para pesquisa binária (se a matriz estiver ordenada corretamente).
- **Tempo de inserção**: O(n) - O pior caso ocorre quando a inserção acontece no início de uma matriz e requer a mudança de todos os elementos.
- **Tempo de exclusão**: O(n) - O pior caso ocorre quando a exclusão acontece no início de uma matriz e requer a mudança de todos os elementos.

## Operação Transversal

Esta operação é realizada para percorrer os elementos do array. Imprime todos os elementos do array um após o outro.

```C
#include <stdio.h>

void main() {
    int arr[5] = {18, 30, 15, 70, 12};
    int i;

    printf("The arrays element are: \n");

    for (i = 0; i < 5; i++) {
        printf("Arr[%d] = %d ", i, arr[i]);
    }
}

```

## Operação de Inserção

Esta operação é realizada para inserir um ou mais elementos no array. De acordo com os requisitos, um elemento pode ser adicionado no inicio, no final ou em qualquer índice do array. Agora, vamos ver a implementação de inserir um elemento no array.

```C
#include <stdio.h>

int main() {
  int arr[20] = {18, 30, 15, 70, 12};
  int i, x, pos, n = 5;

  printf("Array's elements before insertion: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");

  x = 50; // element to be inserted
  pos = 4;
  n++;

  for (i = n - 1; i >= pos; i--)
    arr[i] = arr[i - 1]

  arr[pos - 1] = x;

  printf("Array's elements after insertion: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

```

> É importante destacar que a matriz precisará ter espaço suficiente para armazenar o novo elemento. Se a matriz estiver cheia, não podemos inserir um novo elemento.
