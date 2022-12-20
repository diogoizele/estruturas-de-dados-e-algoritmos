# Hardware e Software

A memória (conhecida também como **_armazenamento_** ou **_núcleo_**) de um computador é apenas um grupo de bits (chaves). Em qualquer momento da operação de um computador, determinado bit na memória é 0 ou 1 (desativado ou ativado). A definição de um bit é chamada seu **_valor_** ou seu **_conteúdo_**.

Os bits na memória de um computador são agrupados em unidades maiores, como bytes. Em alguns computadores, vários bytes são agrupados em unidade chamada **_palavras_**. Cada unidade desse tipo (byte ou palavra, dependendo da máquina) recebe a atribuição de um **_endereço_**, isto é, um nome que identifica determinada unidade entre todas as unidades na memória. Em geral, esse endereço é numérico, de modo que podemos falar do byte 746 ou da palavra 937. Um endereço é frequentemente chamado **_posição_**, e o conteúdo de uma posição são os valores dos bits que formam a unidade nessa posição.

Todo computador tem um conjunto de tipos de dados "nativos". Isso significa que ele é construído com um mecanismo para **manipular padrões de bits coerentes com os objetos que eles representam**. Por exemplo, vamos supor que um computador contenha uma instrução para somar dois inteiros binários e introduzir sua soma em determinada posição na memória para uso posterior. Sendo assim deve existir um mecanismo incorporado no computador para:

1. extrair os padrões de bits dos operandos de duas posições determinadas;
2. produzir um terceiro padrão de bits representando o inteiro binário que seja a soma dos dois inteiros binários representados pelos dois operandos;
3. e armazenar o padrão de bits resultante em determinada posição.

O computador "sabe" interpretar os padrões de bits nas posições específicas como inteiros binários porque **o hardware** que executa a instrução **foi projetado para fazer isso**. Essa operação é parecida com uma lâmpada que "sabe" que está acesa quando o interruptor está em determinada posição.

Se a mesma máquina tiver também uma instrução para somar dois números reais, deverá existir um mecanismo embutido separado para interpretar operando como números reais. São necessárias duas instruções distintas para as duas operações, e cada instrução carrega em si mesma uma identificação implícita dos tipos de seus operandos, além de suas posições explícitas. Portanto, cabe ao programador saber que tipo de dado está contido em cada posição usada, e escolher entre usar uma instrução de soma de inteiros ou reais para obter a soma de dois números.

Uma linguagem de programação de alto nível ajuda consideravelmente nessa tarefa. Por exemplo, se um programador C declarar

```C
int x, y;
float a, b;
```

Será reservado espaço em quatro posições para quatro números diferentes. Essas quatro posições podem ser referenciadas pelos **_identificadores_** _x_, _y_, _a_ e _b_. Um identificador é usado no lugar de um endereço numérico para citar determinada posição de memória porque é conveniente para o programador.

é importante reconhecer o papel-chave desempenhado pelas delcaracões numa linguagem de alto nível. É por meio das declarações que o programador especifica como o conteúdo da memória do computador deve ser interpretado pelo programa. Fazendo isso, a declaração determina a quantidade de memória necessária para certa entidade e para outros detalhes fundamentais.
