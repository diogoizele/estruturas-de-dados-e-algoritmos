# Sequências como Definições de Valores

Ao desenvolver as especificações para vários tipos de dados, usamos frequentemente a notação da **teoria dos conjuntos** para especificar os valores de um TDA. Em particular, é util usar a notação de sequências matemáticas que apresentamos agora.

Uma **sequência** é apenas um conjunto ordenado de elementos. Ocasionalmente, uma sequência _S_ é escrita como enumeração de seus elementos, como em:

**_S_ = \<S0, S1, ..., S<sub>n-1</sub>\>**

Se _S_ contem _n_ elementos, diz-se que _S_ é de tamanho _n_. Pressupomos a existência de uma função de tamanho, _len_, de modo que _len(S)_ seja o tamanho da sequência S. Presumimos também a existência das funções _first(S)_, que retorna o valor do primeiro elemento de S (**S0**, no exemplo anterior), e _last(S)_, que retorna o valor do último elemento de _S_ (**S<sub>n-1</sub>**, no exemplo anterior). Existe uma sequência especial de tamanho 0, chamada _nilseq_, que não contém elementos, _first(nilseq)_ e _last(nilseq)_ são indefinidos, e _len(nilseq)_ é 0.

Por exemplo, poderíamos definir os seguintes tiposÇ

```C
/* sequencia de inteiros de qualquer tamanho */
abstract typedef <<int>> intseq;

/* sequencia de tamanho 3 consistindo em um inteiro, um caractere e um numero de ponto flutuante */
abstract typedef <int, char, float> myseq;

/* sequencia de 10 inteiros*/
abstract typedef <<int, 10>> intseq;

/* sequencia arbitraria de tamanho 2 */
abstract typedef <<, 2>> pair;
```

Duas sequências são _iguais_ quando cada elemento da primeira é igual ao elemento correspondente da segunda. Uma **_subsequência_** é uma parte contígua de uma sequência. Se S é uma sequência, a função _sub(S, i , j)_ refere-se à subsequência de _S_ começando na posição _i_ em _S_ e consistindo em _j_ elementos consecutivos.

