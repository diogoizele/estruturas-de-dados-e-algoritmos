# Estrutura de Dados e Algoritmos

## Visão geral

Este repositório busca reunir, implementar e documentar toda minha tragetória num estudo minucioso em torno das mais diversas estruturas de dados e os algoritmos que as manipulam.

## Recursos

- [Estruturas de dados](src/data-structure/)
- [Algoritmos](src/algorithms/)

## Estruturas de dados

Uma estrutura de dados é uma forma específica de organizar e armazenar dados em um computador para que possam ser acessador e manipulados de forma eficiente.

## Algoritmos

Um algoritmo é um conjunto de instruções que descreve como resolver uma classe de problemas. Sendo assim, trata-se de um conjunto de regras que definem precisamente uma sequência de operações.

## Conceitos introdutórios

Na computação, a unidade básica de informação é o **bit**, cujo valor compreende uma entre duas possibilidades mutuamente exclusivas. A ideia é análoga a um interruptor que pode estar ligado ou desligado.

- [Bit](src/intro-concepts/bit-and-byte/bit.md)
- [Byte](src/intro-concepts//bit-and-byte/byte.md)

### Notação Grande O - Big O Notation

A notação Grande O é usada para descrever o comportamento de um algoritmo em termos de seu crescimento. Ela é usada para descrever o pior caso de desempenho de um algoritmo.

| Estrutura de dados      | Acesso     | Busca     | Inserção  | Remoção   |
| ----------------------- | ---------- | --------- | --------- | --------- |
| Array                   | O(1)       | O(n)      | O(n)      | O(n)      |
| Lista encadeada         | O(n)       | O(n)      | O(1)      | O(1)      |
| Pilha                   | O(n)       | O(n)      | O(1)      | O(1)      |
| Fila                    | O(n)       | O(n)      | O(1)      | O(1)      |
| Tabela Hash             | -          | O(n)      | O(n)      | O(n)      |
| Árvore de busca binária | O(n)       | O(n)      | O(n)      | O(n)      |
| Árvore binária          | O(log (n)) | O(log(n)) | O(log(n)) | O(log(n)) |
| Árvore rubro-negra      | O(log (n)) | O(log(n)) | O(log(n)) | O(log(n)) |

Fonte: [Big O Cheat Sheet](https://www.bigocheatsheet.com/).
