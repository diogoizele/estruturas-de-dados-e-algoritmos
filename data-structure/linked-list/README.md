# Lista Encadeada

> Uma lista vinculada é uma estrutura linear, na qual os elementos **não** são armazenados em locais de memória contíguos. Os elementos em uma lista vinculada são vinculados usando **ponteiros**.

![Lista encadeada](/data-structure/images/linked-list.png)
![Lista encadeada](/data-structure/images/LLdrawio.png)

- A lista encadeada pode ser definida como uma coleção de objetos chamados **nós** que são armazenados aleatoriamente na memória.
- Um nó contém dois campos, ou seja, dados armazenados naquele endereço específico e o ponteiro que contém o endereço do próximo nó na memória.
- O último nó da lista contém o ponteiro para nulo.

## Por que usar lista encadeada em vez de array?

Até agora, estávamos usando a estrutura de dados array para organizar o grupo de elementos que devem ser armazenados individualmente na memória. Entretanto, Array possui diversas vantagens e desvantagens que devem ser conhecidas para decidir a estrutura de dados que será utilizada ao longo do programa.

O array contém as seguintes limitações:

1. O tamanho do array deve ser conhecido com antecedência antes de usá-lo no programa.
2. Aumentar o tamanho do array é um processo demorado. É quase impossível expandir o tamanho do array em tempo de execução.
3. Todos os elementos do array precisam ser armazenados de forma contínua na memória. Inserir elementos do array requer o deslocamento de todos os predecessores.

Lista encadeada é a estrutura de dados que pode superar as limitações de um array. O uso de lista encadeada é útil porque:

1. Ele aloca a memória dinamicamente. Todos os nós da lista vinculada são armazenados de forma não contígua na memória e vinculados com a ajuda de ponteiros.
2. O dimensionamento não é mais um problema, pois não precisamos definir seu tamanho no momento da declaração. A lista cresce de acordo com a demanda do programa e limitada ao espaço de memória disponível.

## Tipos de Listas Encadeadasa

- **Lista encadeada simples** - Neste tipo de lista encadeada, pode-se mover ou percorrer a lista encadeada em apenas uma direção, onde o ponteiro `next` aponta para o próximo nó e o último nó aponta para `NULL`.
- **Lista duplamente encadeada** - Neste tipo, pode-se mover ou percorrer a lista em ambas as direções, pois, além de um ponteiro para `next`, cada nó possui um ponteiro para o nó anterior, `prev`.
- **Lista encadeada circular** - Neste tipo de lista, o último nó aponta para o primeiro nó, formando um ciclo.
- **Lista encadeada duplamente circular** - É um tipo mais complexo de lista encadeada que contém um ponteiro para o próximo nó, bem como para o nó anterior na sequência.
- **Lista vinculada de cabeçalho** - Uma lista vinculada de cabeçalho é um tipo especial de lista vinculada que contém um nó de cabeçalho no início da lista.

## Complexidade

| Operação | Complexidade |
| -------- | ------------ |
| Inserção | O(1)         |
| Exclusão | O(1)         |
| Busca    | O(n)         |

- Busca é O(n) porque na lista encadeada os dados não são armazenados em locais contíguos de memória, por isso temos que percorrê-los um por um.
- Inserção ou exclusão é O(1) porque temos apenas que vincular novos nós para inserção com o nó anterior e o próximo e desvincular os nós existentes para exclusão.

## Criação de Nós

```C
struct Node {
    int data;
    struct Node *next;
}
```

# Algoritmos

| Nome              | Código                                              |
| ----------------- | --------------------------------------------------- |
| Operação Inserção | [Clique aqui](../../algorithm/operacao-insercao.md) |
