# While

A estrutura de controle while é usada para executar um bloco de código repetidamente, enquanto uma condição específica for verdadeira. A estrutura é composta por uma expressão booleana que é avaliada a cada iteração do loop, e o loop continuará a ser executado enquanto a expressão for **verdadeira**.

```c++
int contador = 0;
while (contador < 10) {
  cout << contador << endl;
  contador++;
}
```

Neste exemplo, o loop continuará a ser executado enquanto a variável "contador" for menor que 10. A cada iteração do loop, o programa exibirá o valor atual do contador e, em seguida, incrementará o contador em 1.

A expressão booleana na estrutura while pode ser tão complexa quanto necessário, desde que possa ser avaliada como verdadeira ou falsa. Aqui está um exemplo mais complexo que usa a estrutura while para ler entrada do usuário até que um valor específico seja inserido:

```c++
int valor;
while (true) {
  cout << "Insira um valor (0 para sair): ";
  cin >> valor;

  if (valor == 0) {
    break;
}
cout << "Valor inserido: " << valor << endl;
}
```

Neste exemplo, o loop é iniciado com uma expressão booleana `"true"`, o que significa que ele continuará a ser executado indefinidamente. Dentro do loop, o programa solicita que o usuário insira um valor e lê a entrada do usuário com o comando `cin`. Se o valor inserido for igual a 0, o loop é interrompido com o comando `"break"`. Caso contrário, o programa exibe o valor inserido e continua solicitando entradas do usuário.

> ⚠️ É importante tomar cuidado com a **condição de saída** ou **condição de parada** do loop para evitar loops infinitos. Se a expressão booleana nunca for avaliada como falsa, o loop continuará a ser executado indefinidamente, o que pode causar falhas no programa.
