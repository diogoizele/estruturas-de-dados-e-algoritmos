# Usando Vetores Unidimensionais

Um vetor unidimensional é usado quando necessário para manter uma grande quantidade de itens na memória e para referenciar todos os itens de uma maneira uniforme. Por exemplo, suponha que precisemos ler 100 inteiros, encontrar sua média e determinar o quanto cada inteiro se desvia dessa média. O seguinte programa fará isto:

```C
#define NUMELTS 100
aver()
{
    int num[NUMELTS];
    int i;
    int total;
    float avg;
    float diff;

    total = 0ç

    for (i = 0; i < NUMELTS; i++) {
        /* le os numeros no vetor e os soma*/
        scanf("%d", &num[i]);
        total += num[i];
    } /* fim do for*/
    avg = total / NUMELTS;
    printf("Diferença dos números");

    for (i = 0; i < NUMELTS; i++) {
        diff = num[i] - avg;
        printf("\n %d %d", num[i], diff);
        printf("\nA media: %d", avg);
    }
} /* fim do aver */
```

Esse programa usa dois grupos de 100 números. O primeiro grupo é o conjunto de inteiros de entrada e é representado pelo vetor _num_. O segundo grupo é o conjunto de diferenças que são valores sucessivos atribuídos à variável _diff_ na segunda repetição. Surge então a pergunta: por que usar um vetor para armazenar todos os valores do primeiro grupo simultaneamente, enquanto uma única variável é utilizada para guardar um valor do segundo grupo por vez?

A resposta é simples. Cada diferença é calculada, impressa e nunca é necessária novamente. Sendo assim, a variável _diff_ pode ser utilizada para a diferença do próximo inteiro e a média. Entretanto, os inteiros originais, que são os valores do vetor _num_, precisam todos ser mantidos na memória. Embora cada um possa ser somado ao total quando entra, precisa ser mantido até que a média seja calculada para que o programa compute a diferença entre ele e a média. Para tanto, usa-se um vetor.

> 💡 Evidentemente, poderiam ser usadas 100 variáveis separada para armazenar os inteiros. Entretanto, a vantagem de um vetor é que ele permite que o programador declare somente um identificador e obtenha mesmo assim uma grande quantidade de espaço. Além disso, em conjunto com a repetição FOR, ele também permite que o programador referencie cada elemento do grupo de forma uniforme - `num[i]`.
