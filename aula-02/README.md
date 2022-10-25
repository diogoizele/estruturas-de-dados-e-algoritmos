# Aula 2 - Criação de uma primeira estrutura

### Criando uma estrutura simples

Será visto que uma estrutura serve para guardar algumas informações

Pelo fato da linguagem `Java` ter o paradigma de Orientação a Objetos, tudo trata-se de classes e objetos.

Dessa forma, ao criar a estrutura [PesoAltura](./PesoAltura.java), estamos criando na verdade uma classe `PesoAltura` que poderá ser instanciada.

```Java
public class PesoAltura {
    int peso; // peso em quilogramas
    int altura; // altura em centimetros
}
```

Sendo assim, para possamos executar essa estrutura, necessitaremos instanciá-la dentro de alguma outra classe que possua o método `public static void main(String[] args)`.

Já em `C`, como não se trata de uma linguagem orientada a objetos, não será criada uma classe, e sim uma `struct`. Criando então a estrutura [PesoAltura](./PesoAltura.c) em `C` teremos:

```C

typedef struct {
    int peso; // peso em quilogramas
    int altura; // altura em centimetros
} PesoAltura;

```

- A sintaxe `struct {...}` define uma estrutura com campos definidos dentro das chaves.
- A sintaxe `typedef ... PesoAltura` defined o nome _PesoAltura_ para o que foi definido nas reticências.

> 🌞 Em resumo, o comando `struct` cria a estrutura e o `typedef` dá nome a um novo tipo.

Onde em `Java` teremos uma classe com **Atributos**, em `C` teremos uma estrutura com vários **campos**.

## Constantes 🗒

**Em Java**

```Java
    public static final int ALTURA_MAXIMA = 255;
```

**Em C**

```C
    #define ALTURA_MAXIMA 255
```

## Função main 🍕

A função main é o local de início (_entry point_) da execução de um programa em C ou em Java. A mesma pode possuir alguns parâmetros que permitem a comunicação entre o programa em e o `shell`, através do sistema operacional.

**Em Java**

```Java
public static void main(String[] args) {}
```

**Em C**

```C
int main() {
    //...
    return 0;
}
```

> 🚨 Diferente de Java, a função _main_ em C retorna um inteiro, geralmente sendo este o número 0, quando o código em questão executa corretamente.

## Instanciação 🗡

**Em Java**

```Java
PesoAltura pessoa1 = new PesoAltura();
pessoa1.peso = 80;
pessoa1.altura = 169;
```

**Em C**

```C
PesoAltura pessoa1;
pessoa1.peso = 80;
pessoa1.altura = 169;
```

Em _C_, ao declarar a variável _pessoa1_ do tipo PesoAltura, a linguagem já cria a estrutura, não criando um ponteiro para outro lugar da memória como é feito ao instanciar uma classe em Java.

## Saída

**Em Java**

```Java
System.out.print("Peso: " + pessoa1.peso + ", Altura: " + pessoa1.altura + ". ");
```

**Em C**

```C
printf("Peso: %i, Altura: %i. ", pessoa1.peso, pessoa1.altura);
```

> 💡 `%i`nesse caso significa que a variável a ser impressa é do tipo inteiro.

## Uso de memória 🦵

**Em Java**

| variável     | valor |
| ------------ | ----- |
| alturaMaxima | 225   |
| args         | 9742  |
| pessoa1      | 3408  |

| posições na memória | valor                 |
| ------------------- | --------------------- |
| 9742                |                       |
| 3408                | peso: 80; altura: 169 |

Como a linguagem _Java_ trabalha com ponteiros apontando para a memória, tanto a variável _args_, proveniente do método _main_ (que ao não possuir parâmetro na execução, não possui valor na memória), quanto a variável do tipo PesoAltura _pessoa1_ possuem o valor como sendo o endereço na memória onde de fato seus valores se encontram.

**Em C**

| variável | valor                 |
| -------- | --------------------- |
| pessoa1  | peso: 80; altura: 169 |

Um dos motivos de porque o uso de memória é tão diferente nos nas duas soluções é que a implementação em C não corresponde totalmente à implementação em Java.

Veja abaixo a forma para fazer uma implementação em _C_, semelhante a usada na linguagem _Java_.

## Ponteiros e alocação de memória ✒

Em **C** há uma distinção bastante explícita entre um tipo (ou uma estrutura) e um endereço:

- `int x;` significa que _x_ é uma variável do tipo **inteiro**.
- `int* y;` significa que _y_ é uma variável do tipo **endereço para inteiro**

O asterisco - \* - após a palavra _int_ indica que estamos falando de um endereço inteiro e não mais de um inteiro.

Veja um [exemplo de ponteiro](ponteiros.c) onde:

```C
#include <stdio.h>
int main() {
    int x = 25;
    int* y = &x;
    *y = 30;
    printf("Valor atual de X: %i\n", x); // O valor atual de X é 30
    return 0;
}
```

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

### malloc

Em _C_ há uma função para alocação de memória: **malloc** (_memory allocation_)

- recebe como parâmetro o **número de bytes** (quantidade de bytes) que se deseja alocar.
- retorna o endereço inicial do bloco de bytes que foi alocado, porém esse retorno tem o tipo void\* (ponteiro para void).
- há um operador chamado **sizeof** que recebe como parâmetro um tipo (simples ou composto) e retorna a quantidade de bytes ocupada por esse tipo.

- [Refatoração](PesoAltura.c) do código usando `malloc`.
