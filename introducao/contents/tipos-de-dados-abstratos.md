# Tipos de Dados Abstratos

Uma ferramenta útil para especificar as propriedades lógicas de um tipo de dado é o **_tipo de dado abstrato_**, ou **_TDA_**. Fundalmentalmente, um tipo de dado significa um conjunto de valores e uma sequência de operações sobre estes valores.

Ao definir um tipo de dado abstrato como um conceito matemático, não nos preocupamos com a eficiência de tempo e espaço. Estas são questões de implementação. É possível até que não se consiga implementar determinado TDA num determinado hardware ou usando determinado sistema de software.

Existem vários métodos para especificar um TDA. O método que usamos é semiformal e faz uso intensivo da notação de C.

```C
/* definição de valor */
abstract typedef <integer, integer> RATIONAL;
condition RATIONAL[1] <> 0;

/* definição de operador */
abstract RATIONAL makerational(a, b);
int a,b;
precondition b<>0;
postcondition makerational[0] == a;
              makerational[1] == b;

abstract RATIONAL add(a, b);
RATIONAL a,b;
postcondition add[1] == a[1] * b[1];
              add[0] == a[0] * b[1] + b[0] * a[1];

abstract RATIONAL mult(a, b);
RATIONAL a,b;
postcondition mult[1] == a[1] * b[1];
              mult[0] == a[0] * b[0];

abstract equal (a, b);
RATIONAL a,b;
postcondition equal == (a[0] * b[1] == b[0] * a[1]);

```

Um TDA consistem em duas partes: a definição de valores e a definição de operadores. A definição de valores determina o conjunto de valores para o TDA e consiste em duas partes: uma cláusula de definição e uma cláusula de condição.

Por exemplo, a definição de valor para o TDA _RACIONAL_ declara que o valor de _RACIONAL_ consiste em dois inteiros, sendo o segundo deles diferente de 0. Evidentemente, os dois inteiros que formam um número racional são o numerador e o denominador. Usamos notação de vetor (colchetes) para indicar as partes de um tipo abstrato.

As palavras-chave **_abstract typedef_** introduzem uma definição de valor, e a palavra-chave **_condition_** é usada para especificar quaisquer condições (ou critérios) impostas sobre o ripo recém-definido.

Imediatamente depois da definição do valor, vem a definição dos operadores. Cada operador é definido como uma função abstrata com três partes um cabeçalho, as precondições e as pós-condições. Por exemplo, a definição do operador TDA RACIONAL inclui as operações de criação (makerational), de adição (add) e multiplicação (mult), além de um teste de igualdade (equal).

Examinaremos primeiro a especificação para multiplicação, por ser a mais simples. Ela contém um cabeçalho e pós-condições, mas nenhuma pré-condição.

```C
abstract RATIONAL mult(a, b) /* written a*b */
RATIONAL a,b;
postcondition mult[0] == a[0] * b[0];
              mult[1] == a[1] * b[1];
```

O cabeçalho desta definição são as duas primeiras linhas, parecido com o cabeçalho da função de C. A palavra-chave **_abstract_** indica que esta não é uma função de C, mas uma definição do operador de TDA. O comentário iniciado com a nova palavra-chave **_written_** indica uma forma alternativa de escrever a função.

A pós-condição especifica o que a operação faz. Numa pós-condição, o nome da função (neste caso, _mult_) é usado para indicar o resultado da operação. Sendo assim, _mult[0]_ representa o numerador do resultado, e _mult[1]_ representa o denominador. Ou seja, ele especifica quais condições serão verdadeiras depois da execução da operação.

A especificação de igualdade (_equal_) é a amais significativa e mais complexa em termos de conceito. Em geral, quaisquer dois valores num TDA são "iguai" se e somente se os valores de seus componentes forem iguais.

Entretanto, para alguns tipos de dados, dois valores com componentes desiguais podem ser considerados iguais. Na verdade, este é o caso dos números racionais; por exemplo, os números racionais 1/2, 2/4, 3/6, 4/8, etc. são todos iguais, a despeito da desigualdade de seus componentes. Dois números racionais são considerados iguais se seus componentes forem iguais, quando os números forem reduzidos aos mínimos termos (ou seja, quando seus numeradores e denominadores forem ambos divididos por seu maior divisor comum - simplificação na matemática). Uma forma de testar a igualdade dos racionais é reduzir os dois números a seus mínimos termos e depois testar a igualdade dos numeradores e denominadores. Outra forma de testar a igualdade de racionais é verificar se os produtos cruzados (isto é, o numerador de um multiplicado pelo denominador de outro) são iguais. Este é o método que usamos ao especificar a operação de igualdade abstrata.
