# Aula 3 - Lista linear sequencial

Uma lista linear é uma lista na qual a **ordem lógica** dos elementos (a ordem "vista"pelo usuário) é a mesma ordem física (em memória principal) dos elementos. Isto é, elementos vizinhos na lista estarão em posições vizinhas de memória.

### Modelagem ⛳️

Modelaremos usando um **arranjo** de registros.
**Registros** conterão as informações de interesse do usuário.
Nosso arranjo terá um **tamanho fixo** e controlaremos o número de elementos com uma **variável adicional**.

```C
#define MAX 50 // definindo tamanho máximo do arranjo

/**
 * Usado para dar um "novo nome" ao tipo inteiro,
 * nesse caso, sendo específico para chave.
 */
typedef int TIPOCHAVE;

/**
 * O registro trata-se do "objeto" em questão que
 * será de interesse do usuário, o armazenamento de
 * informações.
 *
 * Nesse exemplo, será usado apenas um campo, sendo este
 * a chave (id) do registro, porém, os demais campos
 * dependem do problema e da implementação.
 */
typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;


/**
 * A lista, nada mais é que um arranjo com o tamanho
 * MAX já pre-definido, e o número de elementos que
 * estão armazenados no arranjo.
 */
typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;
```

## Funções de Gerenciamento 🖲

Funções de gerenciamento que serão implementadas:

- Inicializar a estrutura;
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura;
- Buscar por um elemento na estrutura;
- Inserir elementos na estrutura;
- Excluir elementos da estrutura;
- Reinicializar a estrutura.

### Inicialização 👒

Para inicializar uma estrutura qualquer, precisamos pensar nos valores adequados para cada um dos campos de nossa estrutura.

- Para inicializar uma lista sequencial já criada pelo usuário, só precisa colocar o valor 0 (zero) no número de elementos válidos.

```C
void inicialiarLista(LISTA l) {
    l.nroElem = 0;
}
```

- há algum problema com este código?

Qual a diferença entre os códigos?

```C
void inicialiarLista(LISTA* l) {
    l->nroElem = 0;
}
```

**A diferença** entre a primeira e a segunda abordagem, é que na **primeira**, é criado uma nova lista, relacionada ao parâmetro `l`. Portanto, a atribuicão de `nroElem` é feita nessa nova lista interna da função.
Já na **segunda** abordagem, como faz-se o uso de ponteiros, onde o parâmetro `l` é um ponteiro, a atribuicão de `nroElem` é feita diretamente na lista passada como parâmetro.

### Retornar número de elementos 👒

Para esta estrutura basta retornar o valor do campo `nroElem`.

```C
int tamanho(LISTA* l) {
    return l->nroElem;
}
```

### Exibição ou impreção 👒

Para exibir os elementos da estrutura, necessita-se _iterar_ pelos **elementos** válidos e, por exemplo, imprimir suas chaves.

```C
void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++) {
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}
```

### Buscar por elemento 👒

A função de busca deverá:

- **Receber uma chave** do usuário;
- **Retornar a posição** em que este elemento se encontra na lista (caso seja encontrado);
- **Retornar -1** caso não haja um registro com essa chave na lista.

```C
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while(i < l->nroElem) {
        if (ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;
}
```

### Inserção de um elemento 👒

O usuário passa como parâmetro um registro a ser inserido na lista.
Há diferentes possibilidades de inserção:

- No início;
- No fim;
- Ordenada pela chave;
- **Numa posição indicada pelo usuário**.

> 💡 Num _arranjo_ de `MAX`posições, as posições válidas vão de `0` até `MAX - 1`.

Como inserir?
Se a lista **não estiver cheia** e **índice** passado pelo usuário for válido:

- **desloca** todos os elementos posteriores uma posição para a direita;
- **insere** o elemento na posição desejada;
- **soma um** no campo `nroElem` e **retorna _true_**;
- caso contrário **retorna _false_**.

```C
bool inserirElemLista(LISTA* l, REGISTR reg, int i) {
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}
```

### Exclusão de um elemento 👒

O usuário passa a chave do elemento que quer excluir.

- Se houver um elemento com esta chave na lista, **exclui este elemento**;
- **desloca** todos os elementos posteriores uma posição para a esquerda;
- **diminui** em um campo o `nroElem` e **retorna _true_**;
- Caso contrário, **retorna _false_**;

```C
    bool excluirElemLista(TIPOCHAVE ch, LISTA* l) {
        int pos, j;
        pos = buscaSequencial(l, ch);
        if (pos == -1) return false;
        for (j = pos; j < l->nroElem - 1; j++)
            l->A[j] = l->A[j+ 1];
        l->nroElem--;
        return true;
    }
```

### Reinicialização da lista 👒

Para esta estrutura, para reinicializar a lista basta colocar 0 (zero) no campo `nroElem`.

```C
void reinicializar(LISTA* l) {
    l->nroElem = 0;
}
```
