# Merge

O termo _merge_, em algoritmos, refere-se fundamentalmente à operação de **combinar duas ou mais sequências** de elementos **em uma única sequência** ordenada ou consolidada.

> No contexto clássico, o _merge_ aparece principalmente no **Merge Sort**, onde dois sub-arrays previamente ordenados são combinados para formar um array final também ordenado.

**O princípio é simples:** se você tem duas listas ordenadas, comparar seus elementos iniciais e ir adicionando o menor à sequência final garante que o resultado permaneça ordenado. A eficiência desse processo deriva justamente da ordenação prévia dos subconjuntos.

Em termos de implementação, o _merge_ exige duas coisas: a habilidade de **acessar os elementos** das estruturas de origem e um **critério de comparação** ou combinação. No caso de arrays, a operação é direta porque os elementos são indexáveis, para listas encadeadas, é necessário percorrer nós, para strings, pode-se combinar caracteres ou substrings.

A generalização do conceito permite pensar em _merge_ como a **combinação controlada de coleções**. Por exemplo, duas strings podem ser _merged_ caracter a caracter para formar uma nova string ordenada, ou duas filas podem ser combinadas preservando a ordem temporal de chegada dos elementos.

Para criarmos uma função de _Merge_ na pseudo-linguagem _Portugol_, primeiro declaramos o ponteiro para o array destino, depois as referências para os 2 arrays que serão mesclados e o tamanho do primeiro e tamanho do segundo:

```js
funcao merge(inteiro &destino[], inteiro arr1[], inteiro arr2[], inteiro tam1, inteiro tam2) {
  inteiro i = 0, j = 0, k = 0

  enquanto (i < tam1 e j < tam2) {
    se (arr1[i] < arr2[j]) {
      destino[k++] = arr1[i++]
    } senao {
      destino[k++] = arr2[j++]
    }
  }

  enquanto (j < tam2) destino[k++] = arr2[j++]
  enquanto (i < tam1) destino[k++] = arr1[i++]
}
```

Internamente, definimos 3 índices iniciando em `0`. Um para cada sub-array e um terceiro para controlar o array destino. O nosso critério de comparação aqui é **ordem crescente**, ou seja, adicionamos do menor para o maior elemento.

**Quando** `i` **ou** `j` **se tornam maiores que o tamanho do respectivo array que elas controlam, significa que um dos arrays foi totalmente transferido**. O que resta, portanto, é verificar se o índice do outro array ainda é menor que o tamanho do array, e completar o array de destino com os elementos faltantes.

A seguir, temos um exemplo de implementação da função **merge** em _Kotlin_:

```kotlin
fun merge(arr1: IntArray, arr2: IntArray, tam1: Int, tam2: Int): IntArray {
  var i = 0
  var j = 0
  var k = 0
  val result = IntArray(tam1 + tam2)

  while (i < tam1 && j < tam2) {
    if (arr1[i] < arr2[j]) {
      result[k++] = arr1[i++]
    } else {
      result[k++] = arr2[j++]
    }
  }

  while (j < tam2) result[k++] = arr2[j++]
  while (i < tam1) result[k++] = arr1[i++]

  return result
}
```

Note que, nesse caso, não alteramos um array existente, mas criamos um **novo array** e o retornamos diretamente pela função. A decisão entre retornar um novo array ou modificar um array já existente (_in place_) depende do contexto e dos requisitos do problema.

## Merge em Sub-listas

Os exemplos anteriores mostram o merge entre dois arrays armazenados em posições distintas da memória. Porém, também é possível realizar o merge sobre **sub-listas** de um mesmo array.

> 🔍 Uma **sub-lista** (ou _sub-array_) corresponde a um segmento contíguo de elementos retirado de uma lista ou array original.

Entender o conceito de sub-lista é especialmente importante em algoritmos como o **Merge Sort**, porque a ideia central é trabalhar sempre com "porções" do array original, e **não criar listas independentes em memória** a cada divisão.

Entendemos a sub-lista como uma **visão restrita** de um trecho contíguo da lista original. Em vez de copiar os elementos para um novo array, podemos simplesmente trabalhar com os índices que delimitam o intervalo de interesse, economizando tanto memória quanto operações desnecessárias de cópia.

Para visualizar isso, imagine que temos um array `O[0..n-1]`. Quando queremos dividi-la em duas partes, não precisamos criar dois novos arrays com os elementos já copiados. Basta calcular o índice do meio: `meio = (0 + n-1) / 2`.

Assim, podemos dizer que a sublista **A** corresponde ao intervalo `O[0..meio]`, enquanto a sub-lista **B** corresponde a `O[meio+1..n-1]`. Perceba que não houve nova alocação de memória: apenas estamos delimitando, por meio de índices, os "pedaços" da lista com os quais vamos trabalhar.

Ao tratar sub-listas como **faixas indexadas dentro do array original**, podemos reduzir o problema sem estourar o consumo de recursos. Isso também ajuda a manter a ordem original dos elementos, pois estamos sempre olhando para partes do mesmo bloco de memória contínua.

Portanto, compreender sub-listas é aprender a manipular **referências a trechos do array original**, sem a necessidade de recriar estruturas. É esse mecanismo que permite ao Merge Sort alcançar sua eficiência `O(n log n)`: ele **divide** o problema em sub-listas, **ordena** cada uma delas, e depois os **combina** de forma ordenada, sempre trabalhando dentro da estrutura original de dados.

Perceba que, diferente da abordagem anterior (que recebia dois arrays distintos e seus tamanhos), aqui trabalhamos diretamente sobre um único array, especificando **início**, **meio** (não necessariamente a metade exata) e **fim** da sub-lista a ser mesclada.

```js
funcao merge(inteiro &destino[], inteiro inicio, inteiro meio, inteiro fim) {
  const inteiro tamanho = fim - inicio
  const inteiro auxiliar[tamanho]
  inteiro i = inicio, j = meio + 1, k = 0

  enquanto (i <= meio e j <= fim) {
    se (destino[i] < destino[j]) {
      auxiliar[k++] = destino[i++]
    } senao {
      auxiliar[k++] = destino[j++]
    }
  }

  enquanto(i < meio) auxiliar[k++] = destino[i++]
  enquanto(j < fim) auxiliar[k++] = destino[j++]

  k = 0
  para (inteiro l = inicio; l < fim; l++) {
    destino[l] = auxiliar[k++]
  }
}
```

Primeiro, calculamos o tamanho da sub-lista como `fim - inicio`. Isso é necessário porque não assumimos que a sub-lista começa em `0` ou termina em `n-1`.

Em seguida, criamos um array auxiliar desse tamanho. Os ponteiros `i` e `j` são inicializados em `inicio` e `meio + 1`, respectivamente, enquanto `k` inicia em `0`.

A lógica consiste em comparar diretamente os elementos no `destino` (nosso array principal). A cada iteração, o menor valor entre `destino[i]` e `destino[j]` é colocado no array auxiliar. Quando um dos lados se esgota, copiamos o restante do outro lado diretamente para o auxiliar.

Por fim, reaproveitamos `k`, resetando-o para zero, e usamos um laço que vai de `inicio` até `fim`, sobrescrevendo o trecho correspondente do `destino` com os valores ordenados que estavam no auxiliar.

Respectiva função escrita em **Kotlin**:

```kotlin
fun mergeSubArray(array: IntArray, p: Int, q: Int, r: Int) {
  val size = r - p
  val aux = IntArray(size)

  var i = p
  var j = q + 1
  var k = 0

  while (i <= q && j <= r) {
    if (array[i] < array[j]) {
      aux[k++] = array[i++]
    } else {
      aux[k++] = array[j++]
    }
  }

  while (i < q) aux[k++] = array[i++]
  while (j < r) aux[k++] = array[j++]

  k = 0
  for (l in p until r) {
    array[l] = aux[k++]
  }
}
```
