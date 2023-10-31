# Arrays

Em Ciência da Computação, um **array**, também conhecido como **vetor** ou **arranjo**, é uma **estrutura de dados** fundamental que permite armazenar uma coleção de elementos do mesmo tipo sob um único nome ou identificador. Esses elementos são acessados por meio de um **índice** que especifica a posição de cada elemento no array.

## Declaração

A declaração de um array envolve a especificação de:

- **Tipo** - tipo de dados dos elementos do array.
- **Identificador** - nome do array.
- **Tamanho** - número de elementos que o array pode armazenar.

```java
int[] numeros = new int[5];
```

```c
int numeros[5] = {0, 1, 2, 3, 4};
```

## Acesso aos Elementos

Os elementos de um array são acessados usando um índice. O índice é um número inteiro que indica a **posição do elemento** no array. É importante notar que a indexação de arrays geralmente **começa em 0**, ou seja, o primeiro elemento tem o índice 0, o segundo tem o índice 1 e assim por diante até o último elemento, que tem o índice `tamanho - 1`.

Para acessar um elemento em um array, você usa a seguinte notação:

```java
int[] numeros = {0, 1, 2, 3, 4};

int primeiroElemento = numeros[0];

int ultimoElemento = numeros[length - 1];
```

## Tamanho

O tamanho de um array (ou seja, o número de elementos que ele pode conter) é geralmente fixo após a sua criação. Se você precisar armazenar mais elementos do que o tamanho do array, será necessário criar um novo array com um tamanho maior e copiar os elementos do array original para o novo array.

## Lista Sequencial

Um **array** é uma estrutura de dados que representa uma lista sequencial de elementos armazenados em locais contíguos na memória. Assim, podemos dizer que um array é uma forma de implementar uma **lista sequencial**. Em outras palavras, uma lista sequencial é uma abstração de dados que descreve uma coleção de elementos onde a ordem dos elementos é importante e acessada por meio de índices. Os arrays fornecem uma implementação direta dessa abstração.

Em relação a uma lista sequencial, sua abstração descreveria as operações comuns que você pode realizar, como:

- **Inserir**: Adicionar um elemento à lista em uma posição específica.
- **Remover**: Retirar um elemento da lista em uma posição específica.
- **Acessar**: Obter um elemento em uma posição específica.
- **Tamanho**: Saber o número de elementos na lista.
