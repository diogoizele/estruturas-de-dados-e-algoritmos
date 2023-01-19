# Matriz (Array)

> A ideia de um array é representar muitas instâncias em uma variável .

Digamos que queremos armazenar as notas de todos os alunos de uma turma, podemos usar um array para armazená-las. Isso ajuda a reduzir o uso de várias variáveis, pois não precisamos criar uma variável separada para notas de cada disciplina. Todas as marcas podem ser acessadas simplesmente percorrendo a matriz.

Uma matriz é uma **estrutura de dados linear** usada para armazenar **elementos homogêneos** em locais contíguos. O **tamanho** de uma matriz deve ser fornecido antes de armazenar os dados.

Na programação C, eles são os tipos de dados derivados que podem armazenar dados do tipo primitivo, como int, char, double, float, etc.

## Vantagens

- Arrays fornecem o nome único para o grupo de variaveis do mesmo tipo.
- Percorrer um array é um processo muito simples, pois os elementos são armazenados em locais contíguos.
- Qualquer elemento na matriz pode ser acessado diretamente usando o nome do array e o índice do elemento.

## Desvantagens

- A matriz é homogênea, ou seja, todos os elementos devem ser do mesmo tipo.
- Na matriz, há alocações de memória estáticas, o que significa que o tamanho da matriz deve ser fornecido antes de armazenar os dados e não pode ser alterado.
- Haverá desperdício de memória se armazenarmos menos elementos do que o tamanho declarado.

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

  for (i = n - 1; i > pos; i--)
    arr[i] = arr[i - 1]

  arr[pos] = x;

  printf("Array's elements after insertion: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

```

> É importante destacar que a matriz precisará ter espaço suficiente para armazenar o novo elemento. Se a matriz estiver cheia, não podemos inserir um novo elemento.

## Operação de Exclusão

Como o nome indica, esta operação remove um elemento da matriz e reorganizando os elementos restantes:

```C
#include <stdio.h>

int main() {

  int arr[] = {18, 30, 15, 70, 12};
  int removed_index = 2, n = 5;
  int i, j;

  printf("Given array elements are:\n");

  for (i = 0; i < n; i++)
    printf("arr[%d]=%d ", i, arr[i]);

  j = removed_index;

  while (j < n) {
    arr[j] = arr[j + 1];
    j++;
  }

  n--;

  printf("\nElements of array after deletion\n");

  for (i = 0; i < n; i++)
    printf("arr[%d]=%d, ", i, arr[i]);

  return 0;
}
```

## Operação de Pesquisa

Esta operação é realizada para pesquisar um elemento na matriz com base no valor ou índice.

```C
#include <stdio.h>

int main() {
  int arr[] = {18, 30, 15, 70, 12};
  int item = 70, i, j = 0, arr_length = 5;

  printf("Given array elements are: \n");

  for (i = 0; i < arr_length; i++)
    printf("arr[%d]=%d ", i, arr[i]);

  printf("\nElement to be searched = %d", item);

  while (j < arr_length) {
    if (arr[j] == item)
      break;

    j++;
  }

  printf("\nEnlement %d is found at %d position", item, j);

  return 0;
}
```

## Operação de Atualização

Esta operação é realizada para atualizar um elemento na matriz com base no valor ou índice.

```C
#include <stdio.h>

int main() {

  int arr[5] = {18, 30, 15, 70, 12};
  int item = 50, i, pos = 3;

  printf("Given array elements are: \n");

  for (i = 0; i < 5; i++)
    printf("arr[%d]=%d ", i, arr[i]);

  arr[pos] = item;

  printf("\nElements of array after updation\n");

  for (i = 0; i < 5; i++)
    printf("arr[%d]=%d, ", i, arr[i]);

  return 0;
}
```

## Complexidade de tempo

| Operação    | Caso médio | Pior caso |
| ----------- | ---------- | --------- |
| Acesso      | O(1)       | O(1)      |
| Pesquisa    | O(n)       | O(n)      |
| Inserção    | O(n)       | O(n)      |
| Exclusão    | O(n)       | O(n)      |
| Atualização | O(1)       | O(1)      |

## Complexidade de espaço

Na matrix/array, a complexidade de espaço para o pior caso é O(n), onde n é o número de elementos na matriz.

## Aplicações da Estrutura de Dados Array

- Arrays são usados para implementar listas, pilhas, filas, etc.
- Arrays são usados para matrizes e outras implementações matemáticas.
- Arrays são usados em tabelas de pesquisa de computadores.
- Arrays podem ser usados para escalonamento de CPU.

## Aplicações em Tempo Real

- Listas de contatos em telefones celulares.
- As matrizes são usadas em diferentes campos, como processamento de imagem, computação gráfica e muito mais.
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

