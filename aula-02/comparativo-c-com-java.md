# C vs Java 📟

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
