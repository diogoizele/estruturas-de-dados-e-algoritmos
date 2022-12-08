# Aula 6 - Lista ligada (implementação dinâmica)

### Lista ligada 🤝

- É uma estrutura de dados que armazena elementos em **nós**;

Na implementação dinâmica a alocação de elementos é feita sob demanda, ou seja, quando um novo elemento é inserido na lista, um novo nó é alocado dinamicamente, não havendo desperdício de memória.

### Ideia geral

- Temos um ponteiro para o primeiro nó (elemento) da lista;

![Lista ligada](https://miro.medium.com/max/1300/1*ejbj1auh_Nxg_kmuuSGUSA.jpeg)

- Cada elemento indica seu sucessor;
- O último elemento aponta para `NULL`;

> ✍️ **Exemplo**: Excluir elemento da lista.
>
> Imagine uma lista onde:
>
> - O início aponta para o endereço _2010_;
> - O endereço _2010_ guarda a chave `5` e aponta para o endereço _2310_;
> - O endereco _2310_ guarda a chave `7` e aponta para o endereço _2180_;
> - O endereço _2180_ guarda a chave `8` e aponta para _2050_;
> - O endereço _2050_ guarda a chave `9` e aponta para `NULL`.
>
> Para excluir o elemento com chave `8`, basta fazer o elemento anterior apontar para o elemento seguinte, ou seja, o elemento com chave `7` apontará para o elemento com chave `9`:
>
> - O início aponta para o endereço _2010_;
> - O endereço _2010_ guarda a chave `5` e aponta para o endereço _2310_;
> - O endereco _2310_ guarda a chave `7` e aponta para o endereço _2050_;
> - O endereço _2050_ guarda a chave `9` e aponta para `NULL`.

### Implementação

```C
#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct  {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

```

### Inicialização

Para inicializar a lista ligada, precisa-se:

- Colocar o valor _`NULL`_ na variáve; **_início_**

```C

void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

```

### Retornar o número de elementos

Já que optou-se por não criar um campo com o número de elementos na lista, precisa-se **percorrer todos os elementos** para contar quantos existem.

```C

int tamanho(LISTA* l) {
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

```

### Exibição/Impressão

Para exibir os elementos da estrutura precisaremos iterar pelos **elementos** e, por exemplo, **imprimir suas chaves**.

```C

void exibirLista(LISTA* l) {
    PONT end = l->inicio;
    printf("Lista: \" ");

    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }

    printf("\"\n");
}

```

### Buscar por elemento

A função de busca deverá:

- **Receber uma chave** do usuário;
- **Retornar o endereço** em que este elemento se encontra (caso seja encontrado);
- **Retornar _NULL_** caso não haja um registro com essa chave na lista.

```C

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    PONT pos = l->inicio;
    while (pos != NULL) {
        if (pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;
}

// lista ordenada pelos valores das chaves dos registross

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) {
    PONT pos = l->inicio;
    while (post != NULL && post->reg.chave < ch) pos = pos->prox;
    if (post != NULL && post->reg.chave == ch) return pos;
    return NULL;
}

```

### Inserção de um elemento

O usuário passa como parâmetro um registro a ser inserido na lista.

> 🚨 Será realizada a inserção **ordenada pelo valor da chave** do registro passado e não será permitida a inserção de elementos repetidos.

- Na inserção, precisa-se identificar **entre quais elementos** o elemento novo será inserido.
- **Alocação de memória** para o novo elemento.
- Precisará conhecer quem será o **predecessor do elemento**.

#### Inserção ordenada

Será desenvolvida uma **função auxiliar** para procurar por uma dada chave e nos informar:

- O **endereço desse elemento** se ele existir;
- O **endereço** de quem seria o **predecessor** desse elemento (independentemente do elemento existir ou não na lista);
- Como a função irá nos passar **dois endereços** diferentes?

#### "Passando dois resultados"

```C
#include <stdio.h>

int funcaoQuadradoCubo(int x, int* y) {
    *y = x*x*x;
    return x*x;
}

int main() {
    int a = 30;
    int cubo;
    int quadrado = funcaoQuadradoCubo(a, &cubo);
    printf("a: %i; a*a: %i; a*a*a: %i\n", a, quadrado, cubo);
}

```

> 💡 Como não podemos retornar 2 valores em uma função, ao passar como segundo parâmetro um ponteiro, o que queremos fazer é, além de retornar um valor, modificar outra variável, como se fosse um "hackzinho" para 2 retornos.

#### Busca - auxiliar

```C
PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != null) && (atual->reg.chave<ch)) {
        *ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
}

```

Após essa longa introdução, a inserçao de fato:

### Inserção ordenada

```C
bool inserirElementoListaOrd(LISTA* l, REGISTRO reg) {
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;

    i = buscaSequancialExc(1, ch, &ant);
    if (i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if (ant == NULL) {
        i->prox = i->inicio;
        i->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}
```

### Exclusão de um elemento

O usuário passa a chave do elemento que ele quer excluir:

- Se houver um elemento com esta chave na lista, **exclui este elemento** da llist, **acerta os ponteiros** envolvidos e retorna _true_;
- Caso contrário, retorna _false_;
- Para está função, precisa-se saber quem é o **predecessor** do elemento a ser excluído.

```C
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if (i == NULL) return false;
    if (ant == NULL) l->inicio = i->proximo;
    else ant->prox = i->prox;
    free(i);
    return true;
}
```

### Reinicialização da lista

Para reinicializar a estrutura, precisa-se **excluir todos os seus elementos** e atualizar o campo **_inicio_** para _NULL_.

```C
void reinicializarLista(LISTA* l) {
    PONT end = l->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

```
