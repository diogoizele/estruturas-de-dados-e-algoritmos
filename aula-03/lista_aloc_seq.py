lista = [94, 7, 3, 12, 56]

# último elemento válido
ultimo = len(lista) - 1

## Acesso aleatório - RAM (Random Access Memory)
# o uso de lista[i] permite que façamos um acesso randômico à memória.
# dessa forma, não há distinção em termos de dificuldade para acessar qualquer um dos elementos da lista.

lista[3]

## Para uma lista sequancial, os valores estão armazenados na memória de forma CONÍGUA.
# assim, cada elemento se encontra em posições de memória vizinhas, tal qual vemos no array.

# A dinamicidade do Python é alcançada pois, na lista, ao invés de armazenar os valores em si
# são armazenados os ponteiros para os valores. Por isso podemos inserir um número e uma string
# (tipos com quantidade de bytes distintas) em uma mesma lista e ainda assim ter o armazenamento contíguo.

