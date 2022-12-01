# Aula 6 - Lista ligada (implementação dinâmica)

### Lista ligada 🤝

- É uma estrutura de dados que armazena elementos em **nós**;

Na implementação dinâmica a alocação de elementos é feita sob demanda, ou seja, quando um novo elemento é inserido na lista, um novo nó é alocado dinamicamente, não havendo desperdício de memória.

### Ideia geral

- Temos um ponteiro para o primeiro nó (elemento) da lista;

![Lista ligada](https://miro.medium.com/max/1300/1*ejbj1auh_Nxg_kmuuSGUSA.jpeg)

- Cada elemento indica seu sucessor;
- O último elemento aponta para `NULL`;

> ✍️ **Exemplo**: Excluir elemento da lista.
>
> Imagine uma lista onde:
>
> - O início aponta para o endereço _2010_;
> - O endereço _2010_ guarda a chave `5` e aponta para o endereço _2310_;
> - O endereco _2310_ guarda a chave `7` e aponta para o endereço _2180_;
> - O endereço _2180_ guarda a chave `8` e aponta para _2050_;
> - O endereço _2050_ guarda a chave `9` e aponta para `NULL`.
>
> Para excluir o elemento com chave `8`, basta fazer o elemento anterior apontar para o elemento seguinte, ou seja, o elemento com chave `7` apontará para o elemento com chave `9`:
>
> - O início aponta para o endereço _2010_;
> - O endereço _2010_ guarda a chave `5` e aponta para o endereço _2310_;
> - O endereco _2310_ guarda a chave `7` e aponta para o endereço _2050_;
> - O endereço _2050_ guarda a chave `9` e aponta para `NULL`.
