# Um Exemplo

Ilustraremos esses conceitos com um exemplo. Vamos suport que o hardware de um computador contenha uma instrução:

```
MOVE (origem, dest, compr)
```

que copia uma string de caracteres de bytes com o tamanho representado por _compr_ a partir de um endereço especificado por _origem_ para um endereço especificado por _dest_. (Apresentamos instruções do hardware com letras maiúsculas. O tamanho deve ser especificado por um inteiro e, por essa razão, nós o indicamos com letras minúsculas, _origem_ e _dest_ podem ser especificados por indentificadores que representam posições de armazenamento). Um exemplo dessa instrução é `MOVE(a,b,3)`, que copia os três bytes a partir da posição de armazenamento _a_ para a posição de armazenamento _b_.

> Observe os papéis distintos desempenhados pelos identificadores _a_ e _b_ nessa operação. O primeiro operando da instrução `MOVE` é o **conteúdo** da posição especificada pelo identificador _a_. O segundo operando, entretanto, não é o conteúdo da posição _b_, uma vez que esse conteúdo é irrelevante para a execução da instrução. Em substituição, a própria posição é o operando porque ela especifica o desitno da string de caracteres. Embora um identificador sempre represente uma posição, é comum o uso de um identificador como referência ao conteúdo dessa posição. Sempre ficará evidente pelo contexto se um identificador está referenciando uma posição (ponteiro) ou o seu conteúdo. O identificador que aparece como primeiro operando de uma instrução `MOVE` refere-se ao conteúdo na memória, enquanto o identificador que aparece como segundo operando indica uma posição.

<\continua na página 33\>
