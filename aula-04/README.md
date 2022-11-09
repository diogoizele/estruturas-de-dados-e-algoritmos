# Aula 4 - Lista linear sequencial (continuação)

### Recaptulando 🤔

Na última aula aprendemos listas lineares sequenciais:

- Utilizamos um **arranjo** para armazenar nossos registros;
- A **inserção** de registros era feita na posição indicada pelo usuário.

### Nessa Aula ⛳️

Na aula de hoje abordaremos dois aspectos:

- **Otimização da busca** por elementos;
- Mudança na **ordem de inserção** dos elementos.

### Busca por elementos 🔥

O usuário diz qual elemento é buscado e a função retorna a posição desse elemento:

- As chaves dos elementos **não** estão em ordem crescente;
- Se o elemento não existir a função retorna -1.

#### Versão inicial

```C
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while (i < l->nroElem) {
        if (ch == l->A[i].chave) return i;
        else i++;
    }

    return -1;
}
```

### Otimização

**Ideia**: Ao invés de fazer duas comparações por iteração, seria possível fazer só uma?

- Precisamos sempre **comparar a chave do elemento atual** com a chave do elemento buscado;
- Mas como garantir que não iremos **passar do último elemento?**
- Garantindo que **a chave buscada será encontrada!**

Para isso será criado um elemento **sentinela**:

- **Elemento extra** (um registro) adicionado á lista para auxiliar alguma operação;
- Será **inserido no final da lista** (após o último elemento válido) durante as buscas;
- Conterá a **chave do elemento buscado**.

### Sentinela

> Busca por elementos sentinela 🔥

```C
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while (l->A[i].chave != ch) i++;
    if (i == l->nroElem) return -1;
    else return i;
}
```

-Há apenas um **problema** - Se a lista já estiver **cheia**, não haverá espaço para criar o sentinela;

**Para solucionar**

- Criamos uma lista com uma posição extra (**um registro a mais**) para garantir que haverá espaço para o sentinela;
- Essa posição extra **não** será utilizada para armazenar elementos válidos.

Para essa mudança, a modelagem da estrutura irá alterar um pouco:

```C
#define MAX 50

//...

typedef struct {
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;
```

A otimização da busca por elementos se dá pois antes, havia **2 testes condicionais por iteração**:

- O primeiro testava se o elemento buscado já havia sido encontrado;
- O segundo testava se o elemento buscado não existia na lista;

Com a inserção do sentinela, apenas um teste condicional é necessário, e não a cada iteração:

- O teste condicional testa se o elemento buscado já foi encontrado;

### Busca binária 0️⃣1️⃣

A **busca binária** é mais eficiente, porém ela necessita que as chaves dos elementos estejam **ordenadas**.

- Para aplicar essa busca, necessita-se mudar a nossa antiga função de **inserção de elementos.**
- A função por inserção seguirá a lógica do _insertion sort_.

Para implementar a inserção de elementos ordenada:

```C
bool inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    if (l->nroElem >= MAX) return false;
    int pos = l->nroElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave) {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
}
```

Com a lista ordenada, podemos fazer a função de busca binária:

```C
int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;

    while(esq <= dir) {
        meio = ((esq + dir) / 2);
        if (l->A[meio].chave == ch) return meio;
        else {
            if (l->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
    }
    return -1;
}
```

**Vantagens** geradas com a ordenação dos elementos pela chave:

- A busca binária é mais eficiente;
- Não é necessário o uso de sentinela;
- O que acontece com a **exclusão**? fica mais eficiente

```C
bool excluirElemLista(TIPOCHAVE ch, LISTA *l) {
    int pos, j;
    pos = buscaBinaria(l, ch);
    if (pos == -1)
        return false;
    for (j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j + 1];
    l->nroElem--;
    return true;
}
```
