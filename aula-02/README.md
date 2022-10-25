# Aula 2 - Criação de uma primeira estrutura

### Criando uma estrutura simples

Será visto que uma estrutura serve para guardar algumas informações

Pelo fato da linguagem `Java` ter o paradigma de Orientação a Objetos, tudo trata-se de classes e objetos.

Dessa forma, ao criar a estrutura [PesoAltura](./PesoAltura.java), estamos criando na verdade uma classe `PesoAltura` que poderá ser instanciada.

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
