# Strings e Caracteres

Como sabemos, nem sempre a informação é interpretada em termos numéricos. Itens como nomes, títulos de cargos e endereços precisam também ser representados de alguma maneira dentro de um computador.

Para permitir a representação desses objetos não-numéricos, é necessário outro método de **interpretação de strings de bits**. Geralmente tais informações são representadas da forma de strings de caracteres. Por exemplo, em alguns computadores, os 8 bits 00100110 são usados para representar o caractere '_&_'. Um padrão de oito bits diferentes é usado para representar o caractere '_A_', outro para representar o caractere '_B_', e mais para cada caractere que tenha uma representação em determinada máquina.

> Se são usados [**8 bits**](../bit-and-byte/byte.md) para representar um caractere, podem ser representados até **256 caracteres** diferentes, uma vez que existem 256 padrões de vits diferentes. Se a string 11000000 é usada para representar o caractere '_A_'e 11000001 é usada para representar o caractere '_B_', a string de caracteres 'AB' seria representada pela string de bits 1100000011000001.

Como no caso dos inteiros, não há nada em determinada string de bits que a torne intrinsecamente adequada para representar um caractere específico. Essa atribuição de strings de bits a caracteres pode ser totalmente aleatória, mas precisa ser adotada com coerência.
**Os próprios computadores variam o número de bits usados para representar caractere**. Alguns computadores usam 7 bits (e, portanto, só permitem até 128 caracteres possíveis), alguns usam 8 (até 256 caracteres) e outros usam 10 (até 1024 caracteres possíveis). O número de bits necessário para representar um caractere em determinado computador é chamado **_tamanho do byte_** e um grupo de bits com esse número se chama **[_byte_](../bit-and-byte/byte.md)**.

Sendo assim, verificamos que a própria informação não tem significado. Qualquer significado pode ser atribuído a determinado padrão de bits, desde que seja feito com coerência. É a interpretação de um padrão de bits que dá significado. Por exemplo, a string de bits 00100110 pode ser interpretada como o número 38 (binário), o número 26 (decimal codificado em binário) ou o caractere '&'. Um método de interpretar um padrão de bits é frequentemente chamado **_tipo de dado_**.

## Strings em C

A linguagem C não possui um tipo de dado específico para representar strings de caracteres. Em vez disso, uma string é definida como um vetor de caracteres. Cada string é encerrada com um caractere _NULL_, que indica o final da string. Uma **constante** string é indicada por qualquer conjunto de caracteres entre aspas. O caractere _NULL_ é automaticamente incluído no final dos caracteres dentro de uma constante string, quando eles são armazenados. Dentro de um programa, o caractere _NULL_ é indicado pela _sequência de escape_ \\0. Outras sequências de escape que podem ser usadas são: \\n, para nova linha, \\t, para tabulação, \\b, para retrocesso, \\r, para retorno de cursor, \\f, para avanço de página, \\', para aspas simples, \\", para aspas duplas, \\\, para barra invertida, \\?, para interrogação, \\a, para alerta, \\v, para tabulação vertical, \\ooo, para o caractere com o código octal ooo, \\xhh, para o caractere com o código hexadecimal hh.

Uma constante string representa um valor cujo limite mínimo é 0 e o limite máximo é o número de caracteres na string. Por exemplo, a string "HELLO THERE" é um vetor de 12 elementos (o espaço em branco e o \\0 **contam** como um caractere cada).

```C
int main() {

  char str1[] = "HELLO THERE";
  char str2[] = {'H', 'E', 'L', 'L', 'O', ' ', 'T', 'H', 'E', 'R', 'E', '\0'};
  char *str3 = "Hello There - In pointer";

  return 0;
}
```
