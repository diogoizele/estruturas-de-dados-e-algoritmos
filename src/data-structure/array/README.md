# Array

Diferente do arranjo nativo da linguagem C, podemos implementar uma estrutura linear de dados do tipo Array, que contará com um ponteiro para um arranjo de inteiros e um inteiro que representará o tamanho do arranjo.

A principal diferença entre um [arranjo nativo](../../intro-concepts/array/) de C e uma estrutura de dados `struct Array` é que o arranjo nativo é simplesmente um bloco contíguo de memória que armazena valores do mesmo tipo (por exemplo, int), enquanto a estrutura Array é um tipo de dados composto que contém, no nosso caso, um ponteiro para um arranjo (int \*array) e uma variável (int size) que armazena o tamanho do arranjo. A estrutura Array oferece mais flexibilidade e recursos para gerenciar o arranjo, enquanto o arranjo nativo é mais simples e direto.

## Estrutura

```c
typedef struct ArrayList {
  int *array;
  int size;
} ArrayList;
```

## Arquivos

- [array_list.h](array_list.h): contém a definição da estrutura Array e as assinaturas das funções que manipulam o arranjo.
- [array_list.c](array_list.c): contém a implementação das funções que manipulam o arranjo.
- [array_list_tests.c](array_list_tests.c): contém os testes unitários das funções que manipulam o arranjo.

> 👷‍♂️ **Dica**: Para executar os testes unitários, compile o arquivo `array_list_tests.c` com o arquivo `array_list.c` com o comando `gcc array_list_tests.c array_list.c ` e execute o arquivo executável gerado.
