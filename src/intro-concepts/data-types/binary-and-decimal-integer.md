# Inteiros binários e decimais

O método mais amplamente usado para interpretar definições de bits como inteiros não-negativos é o **sistema de numeração binário**. Nesse sistema, cada posição de [bit](../bit-and-byte/bit.md) representa uma potência de 2. A posição da extrema direita representa A posição da extrema direita representa 2<sup>0</sup> que equivale a 1, a próxima posição à esquerda representa 2<sup>1</sup> que é 2, e assim por diante. Por exemplo o [byte](../bit-and-byte/byte.md) `00100110` representa:

| 2<sup>7</sup> | 2<sup>6</sup> | 2<sup>5</sup> | 2<sup>4</sup> | 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup> |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| 0             | 0             | 1             | 0             | 0             | 1             | 1             | 0             |
| 0             | 0             | 32            | 0             | 0             | 4             | 2             | 0             |

Sendo assim `00100110` representa o inteiro 2<sup>1</sup> + 2<sup>2</sup> + 2<sup>5</sup> = 2 + 4 + 32 = 38. Sob esse prisma, toda string de bits de tamanho _n_ representa um inteiro não-negativo único entre 0 e 2<sup>n</sup> - 1.

Existem dois métodos amplamente usados para representar números binários negativos. No primeiro método, chamado **notação de complemento um**, um número negativo representado mudando cada bit em seu valor absoluto para a definição do bit oposto. Por exemplo, como `00100110` representa 38, `11011001` é usado para representar -38.

> 👀 **Observe** que, com essa representação, existem duas representacões para o número 0: um 0 "positivo" consistindo em todos os 0s, e um zero "negativo" consistindo em todos os 1s.

No segundo método, chamado **notação de complemento dois**, 1 é somado à representação de **complemento de um número negativo**. Por exemplo, como `00100110` representa 38, a notação de complemento um, somado a 1, resultará na notação de complemento dois: `11011001` + 1 = `11011010` que representa -38.

## Codificação binária decimal

O **sistema de numeração binário** definitivamente não é o único método pelo qual os bits podem ser usados para representar inteiros. Por exemplo, uma string de bits pode ser usada para representar inteiros no sistema numérico decimal da seguinte forma: quatro bits podem ser usados para representar um dígito decimal entre 0 e 9 na notação binária descrita anteriormente:

| Decimal | Binário |
| ------- | ------- |
| 0       | 0000    |
| 1       | 0001    |
| 2       | 0010    |
| 3       | 0011    |
| 4       | 0100    |
| 5       | 0101    |
| 6       | 0110    |
| 7       | 0111    |
| 8       | 1000    |
| 9       | 1001    |

Uma string de bits de qualquer tamanho pode ser dividida em conjuntos consecutivos de quatro bits, **com cada conjunto representando um dígito decimal**. Dessa forma, a string representa o número formado por esses dígitos decimais na notação decimal convencional. Por exemplo nesse sistema, a string de bits `00100110` é separada em duas strings de quatro bits cada: `0010` `0110`. A primeira string representa o dígito decimal 2 e a segunda o dígito decimal 6, de modo que a string inteira representa o inteiro 26. Essa representação é chamada **decimal codificado em binário**.

> ⚠️ **Atenção**: Uma característica importante da representação de **decimal codificado em binário de inteiros não-negativos** é que nem todas as strings de bits são representações válidas de um inteiro decimal. Quatro bits podem ser usados para representar um dentre 16 possibilidades diferentes, uma vez que existem 16 estados possíveis para um conjunto de quatro bits. Entretanto, na representação de inteiro decimal codificado em binário, somente 10 dessas 16 possibilidades são usadas (0 - 9). Ou seja, códigos como 1010 (10) e 1100 (12), cujos valores binário são acima de 10, não são válidos em números decimais codificados em binário.
