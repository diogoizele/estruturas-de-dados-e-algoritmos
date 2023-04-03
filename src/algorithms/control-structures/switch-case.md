# Switch/case

A estrutura de controle switch/case é uma estrutura de controle de fluxo que permite que o programa execute diferentes blocos de código dependendo do valor de uma variável ou expressão. É uma alternativa mais elegante do que uma sequência de estruturas if/else aninhadas para testar valores em um intervalo discreto.

> ⚠️ **Atenção**: A estrutura switch/case só funciona para comparar igualdade de valores. Não é possível comparar valores maiores ou menores. Além disso, a estrutura só funciona com valores inteiros e caracteres. Se você tentar usá-la com outros tipos de dados, o compilador irá gerar um erro.

```cpp
int dia_da_semana = 2;

switch (dia_da_semana) {
    case 1:
        cout << "Domingo" << endl;
        break;
    case 2:
        cout << "Segunda-feira" << endl;
        break;
    case 3:
        cout << "Terça-feira" << endl;
        break;
    case 4:
        cout << "Quarta-feira" << endl;
        break;
    case 5:
        cout << "Quinta-feira" << endl;
        break;
    case 6:
        cout << "Sexta-feira" << endl;
        break;
    case 7:
        cout << "Sábado" << endl;
        break;
    default:
        cout << "Dia da semana inválido." << endl;
}
```

Neste exemplo, a variável `"dia_da_semana"` tem o valor 2. A estrutura de controle switch/case testa esse valor e executa o bloco de código correspondente. Neste caso, a segunda opção é verdadeira, e o programa exibirá "Segunda-feira" na saída.

Se o valor da variável `"dia_da_semana"` não for igual a nenhum dos casos especificados, o bloco de código na cláusula `"default"` será executado. Isso é usado como uma espécie de "captura de erros" para evitar que o programa falhe se a entrada do usuário ou outra variável não esperada for recebida.

## break

O comando "break" é usado em cada case para indicar ao compilador que a execução do switch deve ser encerrada e o controle deve ser passado para a próxima instrução depois do switch. Se o comando break não for usado, a execução continuará no próximo case, e os comandos de todas as opções subsequentes serão executados até que ocorra um break ou o fim do switch seja alcançado.

A estrutura de controle switch/case é especialmente útil quando se tem um grande número de valores possíveis para uma variável ou expressão e quando se quer evitar a repetição de uma série de declarações if/else aninhadas.
