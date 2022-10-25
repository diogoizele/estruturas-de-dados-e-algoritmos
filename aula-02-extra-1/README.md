# Aula 2 extra - Arranjos

### Criando arranjos na linguagem C 🕷

```C
#include <stdio.h>
#include <stdlib.h> // contém o comando malloc

int main() {
    int x[3]; // arranjo de 3 posições para inteiros
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);

    printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);
}

```

### Função que recebe um arranjo

```C
void imprimir(int* w) {
    printf("w0: %i, w1: %i, w2: %i\n", w[0], w[1], w[2]);
    printf("&w: %p, w: %p, *w: %i\n", &w, w, *w);
}

int main() {
    int x[3]; // arranjo de 3 posições para inteiros
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);

    printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);

    imprimir(x);
}

```

### Alterando os valores do arranjo

```C
void imprimir(int* w) {
    printf("w0: %i, w1: %i, w2: %i\n", w[0], w[1], w[2]);
    printf("&w: %p, w: %p, *w: %i\n", &w, w, *w);

    w[0] = 21;
    w[1] = 23;
    w[2] = 25;
}

int main() {
    int x[3]; // arranjo de 3 posições para inteiros
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    imprimir(x);

    // Aqui já mostra os valores modificados
    printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);

    printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);
}

```

### Outra forma de criar um arranjo

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[3];
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    int* y = (int*) malloc(sizeof(int) * 3);
    y[0] = 4;
    y[1] = 5;
    y[2] = 6;

	printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);

    printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);

}

```
