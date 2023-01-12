# Operações com Strings de Caracteres

Apresentaremos as funções em C que implementam algumas operações primitivas sobre strings de caracteres. Para todas essas funções, presumiremos as declarações globais:

A primeira função encontra o real tamanho da string:

```c
#define STRSIZE = 90

char string[STRSIZE];

int strlen(char string[]) {
    int count;

    for (count = 0; string[count] != '\0'; count++)

    return count;
}

```

A segunda função aceita duas strings como parâmetros. A função retorna um inteiro indicando a posição inicial da primeira ocorrência da segunda string dentro da primeira. Se a segunda string não existir dentro da primeira, será retornado _-1_.

```c
int strpos(char string[], char substring[]) {
    int index = -1;

    for (int i = 0; string[i] != '\0'; i++) {
        index = -1;
        
        for (int j = 0; substring[j] != '\0'; j++) {

            if (string[i + j] != substring[j]) {
                index = -1;
                break;
            }

            index = i;  
        }

        if (index != -1)
            break;
    }
}
```

Outra operação habitual sobre strings é a concatenação. O resultado de concatenar duas strings consiste nos caracteres da primeira seguidos pelos caracteres da segunda. A seguinte função define _s1_ com a concatenação de _s1_ e _s2_:

```c
void strcat(char s1[], char s2[]) {
    int i, j;

    i = strlen(s1);

    for (j = 0; s2[j] != '\0'; j++)
        s1[i + j] = s2[j];

    s1[i + j] = '\0';
}

```

A última operação sobre strings que apresentaremos é a opreação de substring. _substr(sl, ij, s2)_ define a string _s2_ com os _j_ caracteres, começando em _sl[i]_. A função _substr_ é definida como:

```c
void substr(char sl[], int i, int j, char s2[]) {
    int k, m;

    for (k = 0; m = 0; m < j; s2[m++] = sl[k++])

    s2[m] = '\0';
}
```