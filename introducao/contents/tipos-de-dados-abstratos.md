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

Imediatamente depois da definição do valor, vem a definição dos operadores. Cada operador é definido como uma função abstrata com três partesÇ um cabeçalho, as precondições e as pós-condições. Por exemplo, a definição do operador TDA RACIONAL inclui as operações de criação (makerational), de adição (add) e multiplicação (mult), além de um teste de igualdade (equal).

\<continua na pagina 40\>
