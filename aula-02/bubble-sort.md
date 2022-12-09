# Bubble Sorte - Ordenação

Ordenar é o ato de se colocar os elementos de uma sequência, em uma dada relação de ordem entre si, de acordo com um critério pré-estabelecido.

> 💡 Os elementos do vetor devem ser trocados entre si para que fiquem na ordem desejada.

### Troca de conteúdo entre variáveis

```C
#include <stdio.h>

void trocar(int *px, int *py) {
    int aux = *px;
    *px = *py;
    *py = aux;
}

int main() {
    int x, y;

    printf("\nValor para x? ");
    scanf("%d", &x);

    printf("\nValor para y? ");
    scanf("%d", &y);

    // mostrando os conteúdos de x e y
    printf("\nX = %d\nY = %d\n", x, y);

    printf("\nTrocando...\n");

    trocar(&x, &y);

    printf("\nX = %d\nY = %d\n", x, y);

    return 0;
}
```

## Método de Ordenação Bolha (Bubble Sort)

Algoritmo: Percorre várias vezes o vetor de maneira sequencial (passos). Em cada passo, compara cada elemento do vetor com o seu sucessor (p[i] com p[i + 1]) e troca o conteúdo das posicões em análise, caso não estejam na desejada.

Exemplo:

- O elemento da posição 0 é maior que o da posição 1? Sim, troca.
- Em seguida, o elemento da posição 1 é maior que o da posição 2? Sim, troca.
- até o final do vetor.
