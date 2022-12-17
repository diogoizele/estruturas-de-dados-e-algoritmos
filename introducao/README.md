# Introdução às Estruturas de Dados

A unidade básica de informação é o **_bit_**, cujo valor compreende uma entre duas possibilidades mutuamente exclusivas. Por exemplo um interruptor de luz pode estar em uma das duas posições, mas não em ambas simultaneamente, e o fato de estar na posição "ligado" ou na posição "desligado" é o que chamamos de **_bit_** de informação.

Vamos supor que tivéssemos chaves de duas alternativas, mas pudéssemos usar quantas delas precisássemos. Quantas chaves seriam necessárias para representar um dia com oito posições? Evidentemente, uma chave só pode representar duas posições. Duas chaves podem representar quatro posições diferentes e são necessárias três chaves para representar oito posições diferentes. Em geral, _n_ chaves podem representar _2<sup>n</sup>_ possibilidades diferentes.

Os dígitos binários 0 e 1 são usados para representar os dois possíveis estados de determinado bit. Dado _n_ bits, umas tring de _n_ 1s e 0s é usada para representar seus valores.

Verificamos que são necessários três bits para representar oito possibilidades. As oito possíveis configurações desses três bits são: (000, 001, 010, 011, 100, 101, 110, 111) podem ser usadas para representar os inteiros de 0 a 7.

Entretanto, não há nada nas definições desses bits que implique intrinsecamente que determinada definição representa determinado inteiro. Qualquer atribuição de valores inteiros às definições de bits é válida desde que não sejam atribuídos dois inteiros à mesma definição de bits.

## Inteiros Binários e Decimais

O método mais amplamente usado para interpretar definições de bits como inteiros não-negativos é o **_sistema de numeração binário_**. Nesse sistema, cada posição de bit representa uma potência de 2. A posição da extrema direita representa 2<sup>0</sup> que equivale a 1, a próxima posição à esquerda representa 2<sup>1</sup> que é 2, a próxima posição de bit representa 2<sup>2</sup>, que equivale a 4, e assim por diante. Por exemplo, o grupo de bits 00100110 apresenta 1s nas posições 1, 2 e 5 (contando da direita pra esquerda com a posição da extrema direita considerada posição 0). Sendo assim 00100110 representa o inteiro 2<sup>1</sup> + 2<sup>2</sup> + 2<sup>5</sup> = 2 + 4 + 32 = 38. Sob esse prisma, toda string de bits de tamanho _n_ representa um inteiro não-negativo único, entre 0 e 2<sup>n - 1</sup> e todo inteiro não-negativo entre 0 e 2<sup>n - 1</sup> pode ser representado por uma string de bits de tamanho _n_.

Existem dois métodos amplamente usados para representar números binários negativos. No primeiro método, chamado **_notação de complemento um_**, um número negativo é representado mudando cada bit em seu valor absoluto para a definição do bit oposto. Por exemplo, como 00100110 representa 38 11011001 é usado para representar -38.

> Observe que, com essa representação, existem duas representações para o número 0: um 0 "positivo" consistindo em todos os 0s, e um zero "negativo" consistindo em todos os 1s.

O segundo método, chamado **_notação de complemento dois_**. Nessa notação, 1 é somado à representação de complemento de um número negativo. Por exemplo, 11011001 + 1 = 11011010, que representa -38 na notação de complemento de dois.

> Obsreve que existe apenas uma representação para o numero 0 usando _n_ bits na notação de complemento de dois. Para constatar isso, considere o 0 usando oito bits: 00000000. O complemento de um é 11111111, que é o 0 "negativo"nessa notação. Somar 1 para produzir a forma de complemento de 2 resulta em 100000000, que tem nove bits. Como somente oito bits são permitidos, o bit da extrema esquerda (ou a "sobra") é descartado, deixando 00000000 como "menos" 0.

O **sistema de numeração binário** definitivamente não é o único método pelo qual os bits podem ser usados para representar inteiros. Por exemplo, uma string de bits pode ser usada para representar inteiros no sistema numérico decimal, da seguinte forma: quatro bits podem ser usados para representar um dígito decimal entre 0 e 9 na notação binária descrita anteriormente. Uma string de bits de qualquer tamanho pode ser dividida em conjuntos consecutivos de quatro bits, **com cada conjunto representando um dígito decimal**. Dessa forma, a string representa o número formado por um dígito decimal. Dessa forma, a string representa o número formado por esses dígitos decimais na notação decimal convencional. Por exemplo. nesse sistema, a string de bits 00100110 é separada em duas strings de quatro bits cada: 0010 e 0110. A primeira string representa o dígito decimal 2 e a segunda representa o dígito decimal 6, de modo que a string inteira representa o inteiro 26. Essa representação é chamada **_decimal codificado em binário_**

Uma característica importante da representação de decimal codificado em binário de inteiros não-negativos é que nem todas as strings de bits são representações válidas de um inteiro decimal. Quatro bits podem ser usados para representar um dentre 16 possibilidades diferentes, uma vez que existem 16 estados possíveis para um conjunto de quatro bits. Entretanto, na representação de inteiro decimal codificado em binário, somente dez dessas 16 possibilidades são usadas. Ou seja, códigos como 1010 e 1100, cujos valores binário são 10 ou acima, não são válidos em números decimais codificados em binário.

## Números Reais

\<continuar na página 26\>
