# Ponteiros em C

Na realidade, C permite que o programador referencie a posição de objetos bem como os próprios objetos (isto é, o conteúdo de suas posições). Por exemplo, se _x_ for declarado como um inteiro, _&x_ se referirá à posição reservada para conter _x_. _&x_ é chamado **_ponteiro_**.

É possivel declarar uma variável cujo tipo de dado seja um ponteiro e cujos possíveis valores sejam posições na memória. Por exemplo, as declaraçõesÇ

```C
int *pi;
float *pf;
char *pc;
```

Declara três variáveis ponteiro: _pi_ é ponteiro para um inteiro, _pf_ é um ponteiro para um número de ponto flutuante e _pc_ é um ponteiro para um caractere. O asterisco indica que os valores das variáveis sendo declaradas são ponteiros para valores do tipo especificado na declaração, em vez de objetos desse tipo.

Sob vários aspectos, um ponteiro é como qualquer outro tipo de dado em C. O valor de um ponteiro é uma posição de memória de mesma forma que o valor de um inteiro é um número. Os valores dos ponteiros podem ser atribuídos como quaisquer outros valores. Por exemplo, a declaração de _pi_ = _&x_ atribui um ponteiro para o inteiro _x_ à variável ponteiro _pi_.

A notação _\*pi_ em C refere-se ao inteiro na posição referenciada pelo ponteiro pi. A declaração _x_ = _\*pi_ atribui o valor deste inteiro à variável inteira _x_.

Observe que C insiste em que uma declaração de ponteiro especifique o tipo de dado para o qual o ponteiro aponta. Nas declarações anteriores, cada uma das variáveis _pi_, _pf_ e _pc_ são ponteiros para tipos de dados específicos: _int_, _float_ e _char_, respectivamente. O tipo de _pi_ não é simplesmente um "ponteiro", mas um "ponteiro para inteiro". Na verdade, os tipos de _pi_ e _pf_ são diferentes: _pi_ é um ponteiro para um inteiro, enquanto _pf_ é um ponteiro para um número de ponto flutuante. Cada tipo de dado _dt_ em C gera outro tipo de dado, _pdt_, chamado "ponteiro para _dt_". Chamamos de _dt_ o **tipo base** de _pdt_.

A conversão de _pf_ do tipo "ponteiro para um número de ponto flutuante" para o tipo "ponteiro para um inteiro" pode ser feita escrevendo-se:

```C
pi = (int *) pf;
```

Onde o operador **_{int \* )_** converte o valor de _pf_ para o tipo "ponteiro para um **_int_**" ou "**_int\*_**".

A importância da associação de cada ponteiro com determinado tipo base evidencia-se ao rever os recursos aritméticos que C oferece para os ponteiros. Se _pi_ é um ponteiro para um inteiro, então _pi_ + 1 é o ponteiro para o inteiro imediatamente seguindo ao inteiro _\*pi_, pi + 2 é o ponteiro para o segundo inteiro depois de _\*pi_, e assim por diante. Por exemplo, suponha que determinada máquina use endereçamento de bytes, que um inteiro exija quatro bytes e que o valor de _pi_ seja 100 (isto é, pi aponta para o inteiro _\*pi_ na posição 100). Sendo assim, o valor de _pi_ - 1 é 96, o valor de _pi_ + 1 é 104 e o valor de _pi_ + 2 é 108. O valor de _\*(pi_ - 1 ) é o contepudo dos quatro bytes, 96, 97, 98, 99, interpretado como um inteiro; o valor de \*(_pi_ + 1) é o conteúdo dos bytes 104, 105, 106, 107, interpretado como um inteiro; e assim por diante.

De modo semelhante, se o valor da variável _pc_ é 100 (lembre-se de que _pc_ é um ponteiro para um caractere) e um caractere tem um _byte_, _pc_ - 1 refere-se à posição 99, _pc_ + 1 refere-se à posição 101 e assim por diante. Assim, o resultado da aritmética de ponteiros em C depende do tipo base do ponteiro.

> 🚨 Observe também a diferença entre _\*pi_ + 1, que se refere a 1 somado ao inteiro _\*pi_, e \*(_pi_ + 1), que se refere ao inteiro posterior ao inteiro na posição referenciada por _pi_.

Uma área na qual os ponteiros de C desempenham um notável papel é na passagem de parâmetros para funções. Normalmente, os parâmetros são passados para uma função por C _por valor_, isto é, os valores sendo passados são copiados nos parâmetros da função chamada no momento em que a função for chamada. Se o valor de um parâmetro for alterado dentro da função, o valor no programa de chamada não será modificado. Por exemplo, examine o seguinte segmento de programa e função:

```C
x = 5;
printf("%d\n", x);
funct(x);
printf("%d\n", x);

funct(y) int y;
{
    ++y;
    printf("%d\n", y);
} /* end funct */
```

Aa linha 2 imprime 5 e, em seguida, a linha 3 chama _funct_. O valor de _x_ que é copiado em _y_ e _funct_ começa a execução. A linha 9 imprime 6 e _funct_ retorna. Entretanto, quanado a linha 8 incrementa o valor de _y_, o valor de _x_ permanece inalterado. Dessa forma, a linha 4 imprime 5. _x_ e _y_ referem-se a duas variáveis diferentes que tem o mesmo valor no início de _funct_. _y_ pode mudar independente de _x_.

Se quisermos usar _funct_ para modificar o valor de _x_, precisaremos passar o endereço de _x_ como segue:

```C
x = 5;
printf("%d\n", x);
funct(&x);
printf("%d\n", x);

funct(py) int *py;
{
    ++(*py);
    printf("%d\n", *py);
} /* end funct */
```

A linha 2 imprime novamente 5, e a linha 3 chama _funct_. Entretanto, o valor passado agora não é o valor inteiro de _x_, mas o valor do ponteiro _&x_. Esse é o endereço de _x_. O parâmetro de _funct_ não é mais _y_ de tipo int, mas _py_ de tipo **_int\*_**. (É conveniente nomear as variáveis de ponteiro começando com a letra _p_ para lembrar ao programador e ao leitor do programa que ela é um ponteiro. Entretanto, isso não é uma exigência da linguagem C e poderíamos ter chamado de _y_ o parâmetro do tipo ponteiro). Agora, a linha 8 incrementa o inteiro na posição _py_. Contudo, em si mesmo, _py_ não é alterado e mantém seu valor inicial, &x. Dessa forma, _py_ aponta para o inteiro _x_ de modo que, quando _\*py_ for incrementado, _x_ será incrementado. A linha 9 imprime 6 e _funct_ retorna, a linha 4 imprime 6 também. Os ponteiros representam o mecanismo usado em C para permitir que uma função chamada modifique variáveis numa função chamada (ou chamadora).
