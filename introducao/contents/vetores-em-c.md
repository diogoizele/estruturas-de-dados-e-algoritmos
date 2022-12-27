# Vetores em C

Nesta e na próxima seção, examinaremos várias estruturas de dados que representam uma parte inestimável da linguagem C. Veremos também como usar essas estruturas e como elas podem ser implementadas. Essas estruturas são tipos de dados **_compostos_** ou **_estruturados_**, ou seja, elas são formadas de estruturas de dados mais simples que existem na linguagem.

O estudo dessas estruturas de dados envolve uma análise de como as estruturas simples se combinam de modo a formar uma composição e como extrair um componente específico da composição.

O primeiro desses tipos de dados é o **_vetor_**. A forma mais simples de vetor é um **_vetor unidimensional_**, que pode ser definido abstratamente como um conjunto finito e ordenado de elementos homogêneos. Por "finito" entendemos que existe um número **específico** de elementos no vetor. Esse número pode ser grande ou pequeno, mas ele precisa existir. Por "ordenado" entendemos que os elementos do vetor são organizados de tal forma que exista um elemento zero, um primeiro elemento, um segundo elemento, um terceiro elemento e assim por diante. Por "homogêneo" entendemos que todos os elementos no vetor precisam ser do **mesmo tipo**. Por exemplo, um vetor pode conter inteiro ou caracteres, mas não pode conter ambos.

Precisamos também especificar como a estrutura é acessada. Por exemplo, a declaração C:

```c
int a[100];
```

Especifica um vetor de 100 inteiros. As duas operações básicas que acessam um vetor são a **_extração_** e o **_armazenament_**.

- **Extração**: é uma função que aceita um vetor, _a_, e um índice _i_, e retorna um elemento do vetor. Em C, o resultado dessa operação é indicado pela expressão _a[i]_.
- **Armazenamento**: aceita um vetor, _a_, um índice _i_, e um elemento, _x_. Em C, esta operação é indicado pelo comando de atribuição _a[i] = x_.

> 🚨 Antes da atribuição de um valor a um elemento do vetor, seu valor é indefinido e uma referência a ele numa expressão será inválida.

O menor elemento do índice de um vetor é chamado **_limite mínimo_** e, em C, é sempre 0, e o maior elemento é chamado **_limite máximo_**. Se _lower_ é o limite mínimo de um vetor e _upper_, o limite máximo, o número de elementos no vetor, chamado _faixa_ é dado por _upper_ - _lower_ + 1. Por exemplo, no vetor _a_, declarado anteriormente, o limite mínimo é 0, o limite máximo é 99 e a faixa é 100.

Uma característica importante de um vetor em C é que nem o limite máximo nem o mínimo (e consequentemente a faixa também) podem ser alterados durante a execução de um programa. O limite mínimo é sempre fixado em 0, e o limite máximo é fixado quando o programa é escrito.

Uma técnica muito útil é declarar um limite como um identificador de **constante** a fim de que o trabalho necessário para modificar o tamanho de um vetor seja minimizado. Por exemplo, examine o seguinte segmento de programa para declara e inicializar um vetor:

```c
int a[100];
for (i = 0; i < 100; a[i++] = 0);
```

Para mudar o vetor para um tamanho maior (ou menor), a constante 100 deve ser alterada em dois locais: uma vez nas declarações e uma vez no comando **_for_**. Examine a seguinte alternativa equivalente:

```c
#define NUMELTS 100
int a[NUMELTS];
for (i = 0; i < NUMELTS; a[i++] = 0);
```

Agora, só é necessária uma mudança na definição da constante para alterar o limite máximo.
