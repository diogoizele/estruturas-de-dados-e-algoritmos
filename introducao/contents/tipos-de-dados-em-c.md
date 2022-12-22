# Tipos de Dados em C

A linguagem C contém quatro tipos básicos de dados: _int_, _float_, _char_ e _double_. Na maioria dos computadores, esses quatro tipos são os nativos no hardware da máquina. Já vimos como os inteiros, os reais e os caracteres podem ser implementados no hardware. Uma variável _double_ é um número de ponto flutuante de dupla precisão.
Existem três qualificadores que podem ser aplicados aos _ints_: _short_, _long_ e _unsigned_. Uma variável de inteiro _short_ ou _long_ refere-se ao tamanho máximo do valor da variável. Os verdadeiros tamanhos máximos implicados por _short int_, _long int_ ou _int_ variam de uma máquina para outra. Um inteiro _unsigned_ é um sempre inteiro positivo, que segue as leis aritiméticas do módulo _l-_, onde _n_ é o número de bits inteiros.

Uma declaração de variável em C especifica dois itens. Primeiro, a quantidade de armazenamento que deve ser reservada para os objetos declarados com esse tipo. Por exemplo, uma variável do tipo _int_ precisa ter espaço suficiente para armazenar o maior valor inteiro possível. Segundo, ela especifica como os dados representados por strings de bits devem ser interpretados como um inteiro ou número de ponto flutuante, resultando em dois valores numéricos totalmente diferentes.

Uma declaração de variável especifica que deve ser reservado armazenamento para um objeto do tipo especificado e que o objeto nessa posição de armazenamento pode ser referenciado com o identificador de variável especificado.
