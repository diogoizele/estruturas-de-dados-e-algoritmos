# O Vetor com um TDA

Podemos representar um vetor como um tipo de dado abstrato com uma pequena extenção das convenções e notações discutidas anteriormente. Pressupomos a função _type(arg)_, que retorna o tipo de seu argumento, _arg_. Evidentemente, uma função como essa não pode existir em C porque C não pode determinar dinamicamente o tipo de uma variável. Entretanto, como não estamos preocupados com a implementação aqui, mas com a especificação, o uso de uma função como essa é válido.

Deixemos que _ARRTYPE(ub, eltype)_ indique o TDA correspondente ao tipo de vetor em C _eltype vetor[ub]_. Este é o nosso primeiro exemplo de um TDA parametrizado, no qual o exato TDA é detemrinado pelos valores de um ou mais parâmetros. Nesse caso _ub_ e _eltype_ são os parâmetros; observe que _eltype_ é um indicador de tipo, não um valor. Agora, podemos visualizar qualquer vetor unidimensional como uma entidade de tipo _ARRTYPE_. Por exemplo, _ARRTYPE(10, int)_ representaria o tipo do vetor _x_ na declaração _int x[10]_. Podemos então visualizar qualquer vetor unidimensional como uma entidade do tipo _ARRTYPE_. Veja a seguir a especificação.

```C
abstract typedef <<eltype, ub>> ARRTYPE(ub, eltype);
condition type(ub) == int}
abstract eltype extract(a, i)     /* written a[i] = elt */
ARRTYPE (ub, eltype) a;
int i;
precondition 0 <= i < ub;
postcondition extract == ai
abstract store(a, 1, elt)        /* written a[i] = elt */
ARRTYPE (ub, eltype) a;
int i;
eltype elt;
precondition 0 <= i < ub;
postcondition a[i] == elt;
```

A operação _store_ é nosso primeiro exemplo de uma opreação que modifica um de seus parâmetros; nesse caso, o vetor _a_. Isso é indicado na pós-condição, especificando-se o valor do elemento do vetor ao qual _elt_ está sendo atribuído. A menos que um valor modificado seja especificado numa pós-condição, presumimos que todos os parâmetros mantêm o mesmo valor anterior, depois que a operação é aplicada numa pós-condição. Não é necessário especificar que tais valores permanecem inalterados. Sendo assim, nesse exemplo, todos os elementos do vetor, com exceção daquele ao qual _elt_ é atribuído, mantêm os mesmos valores.

\<Continua na pagina 57\>
