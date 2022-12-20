# O Conceito de Implementação

O conjunto de tipos de dados nativos que um computador pode suportar é determinado pelas funções incorporadas em seu hardware. Entretanto, podemos visualizar o conceito de "tipo de dado" sob uma perspectiva totalmente diferente; não em termos do que um computador pode fazer, mas em função do que o usuário quer fazer.

Por exemplo, se alguém quiser fazer a soma entre dois inteiros, esse usuário não se importará muito com o mecanismo detalhado pelo qual essa soma será obtida. O usuário está interessado em manipular o conceito matemático de "inteiro", não em manipular bits do hardware. O hardware do computador pode ser usado para representar um inteiro e só será útil para esse propósito se a representação tiver sucesso.

Quando o conceito de "tipo de dado" é dissociado dos recursos do hardware do computar, um número ilimitado de tipos de dados pode ser considerado. Um tipo de dado é conceito abstrato, definido por um conjunto de propriedades lógicas. Assim que um tipo de dado abstrato é definido e as operações válidas envolvendo esse tipo são especificadas, podemos **_implementar_** esse tipo de dado.
Uma implementação pode ser uma **_implementação de hardware_**, na qual o circuito para efetuar as operações necessárias é elaborado e construído como parte do computador; ou pode ser uma **_implementação de software_**, na qual um programa consistindo em instrucões de um hardware já existentes é criado para interpretar strings de bits na forma desejada e efetuas operacões necessárias.
