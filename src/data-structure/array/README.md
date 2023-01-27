# Array

Diferente do arranjo nativo da linguagem C, podemos implementar uma estrutura linear de dados do tipo Array, que contará com um ponteiro para um arranjo de inteiros e um inteiro que representará o tamanho do arranjo.

## Estrutura

```c
typedef struct ArrayList {
  int *array;
  int size;
} ArrayList;
```
