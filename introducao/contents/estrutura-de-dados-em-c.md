# Estrutura de Dados em C

Um programador C pode imaginar a linguagem C como definindo uma nova máquina, com capacidades, tipos de dados e operações exclusivas. O usuário pode declarar a solução de um problema em termos de construções mais úteis de C do que em termos de construções de linguagem de máquina de baixo nível. Assim, os problemas podem ser solucionados facilmente porque existe um conjunto mais abrangente de ferramentas.

Por sua vez, o estudo das estruturas de dados envolve duas metas complementares. A **primeira meta** é identificar e desenvolver entidades e operações matemáticas úteis e determinar que classes de problemas **podem ser solucionadas**, usando essas entidades e operações.

A **segunda meta** é determinar **representações** para essas entidades abstratas e implementar as operações abstratas sobre essas representações concretas.

Nas próximas seções, examinaresmo várias estruturas de dados que já existem em C: o vetor e a estrutura. Descreveremos os recursos já disponíveis em C para a utilização desses recursos.

No restante deste livro, desenvolveremos estruturas de dados mais complexas e mostraremos sua utilidade na solução de problemas. Além disso ensinaremos a implementar essas estruturas de dados usando as estruturas de dados já disponíveis em C.

Com frequência, nenhuma implementação, nenhum hardware ou software pode modelar por completo um conceito matemático. Por exemplo, é impossível representar arbitrariamente grandes inteiros num computador porque o tamanho da memória de uma máquina é finito. Sendo assim, não é o tipo de dado "inteiro" que é representado pelo hardware, mas o tipo de dado "inteiro entre _x_ e _y_", onde _x_ e _y_ são os menores e maiores inteiros representáveis por essa máquina.

Uma consideração importante em qualquer implementação é a sua eficiência. Na verdade, a razão pela qual as estruturas de dados de alto nível, que discutimos, não são construídas e, C é a significativa sobrecarga que acarretariam. Existem linguagens de nível muito mais alto que C, que possuem vários desses tipos de dados já incorporados, mas muitas delas são ineficientes, e portanto, não amplamente usadas.

Em geral, a eficiência é determinada por dois fatores: **tempo** e **espaço**. Se determinada aplicação depender intensivamente da manipulação de estruturas dedados de alto nível, a velocidade na qual essas manipulações podem ser executadas será o principal determinante da velocidade da aplicação inteira. De modo semelhante, se um programa usar uma grande quantidade destas estruturas, uma implementação que utiliza uma quantidade excessiva de espaço para representar a estrutura de dados não será prática.

> A escolha da implementação nesse caso requer uma avaliação cuidadosa dos compromissos entre asa várias possibilidades.
