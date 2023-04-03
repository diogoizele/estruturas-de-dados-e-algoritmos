# If/else

A estrutura de controle _if/else_ é uma forma de ramificação condicional em que o código decide qual bloco de código executar com base em uma condição. A ideia geral é que, se uma determinada condição for verdadeira, o bloco de código dentro do if será executado; caso contrário, o bloco de código dentro do else será executado.

```cpp
int idade = 20;

if (idade >= 18) {
   cout << "Você é maior de idade." << endl;
}
else {
   cout << "Você é menor de idade." << endl;
}
```

Neste exemplo, a condição é "idade >= 18", o que significa que se a idade for maior ou igual a 18, o bloco de código dentro do if será executado, caso contrário, o bloco de código dentro do else será executado.

Você pode ter mais de uma condição em uma estrutura if/else usando a estrutura `else if` (também conhecida como elif ou else-if). Aqui está um exemplo:

```cpp
int nota = 7;

if (nota >= 9) {
   cout << "A" << endl;
}
else if (nota >= 8) {
   cout << "B" << endl;
}
else if (nota >= 7) {
   cout << "C" << endl;
}
else if (nota >= 6) {
   cout << "D" << endl;
}
else {
   cout << "F" << endl;
}
```

Neste exemplo, o código decide a nota com base nas condições. Se a nota for maior ou igual a 9, o código escreve "A"; se a nota for maior ou igual a 8, mas menor que 9, o código escreve "B"; e assim por diante.

Essa é uma estrutura muito útil na programação, pois permite que o código tome decisões com base em condições, tornando o programa mais flexível e adaptável a diferentes situações
