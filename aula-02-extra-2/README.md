# Aula 2 extra - Estruturas um pouco mais complexas

### Queremos criar uma estrutura para armazenar informações de pessoas

- CPF
- Idade
- Referência ao seu cônjuge

> 💡 Em Java, pode-se imaginar que existiria uma classe Pessoa, e o atributo relacionado ao cônjuge seria do tipo _Pessoa_. Logo, o atributo na verdade guardaria uma referência na memória de onde estaria o objeto Pessoa referente ao cônjuge.

Para fazer isso em _C_, primeiramente cria-se a seguinte estrutura:

```C
typedef struct aux {
    int cpf;
    int idade;
    struct aux* conjuge;
} PESSOA;
```

> 🚨 **Importante** - como a definição do conjuge está interna à estrutura PESSOA, PESSOA ainda não passou para o compilador para que este a reconhecesse. Neste caso, usa-se uma variável auxiliar `aux` para se referir a estrutura que será criada.
