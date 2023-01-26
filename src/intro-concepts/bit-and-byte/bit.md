# Bit - digito binário

Um bit é a menor unidade de dados que um computador pode processar e armazenar. Um bit está sempre em um, e apenas um, dos dois estados físicos, ligado ou desligado. Os bits são armazenados na memória através do uso de capacitores que retêm cargas elétricas, que por sua vez, determinam o valor do bit.

Embora um computador possa testar e manipular dados no nível de bit, a maioria dos sistemas processa e armazena dados em blocos de bits chamados [bytes](byte.md). Um byte é um grupo de oito bits, que podem ser usados para representar um caractere de texto ou um número inteiro.

Por exemplo, um dispositivo de armazenamento pode armazenar 1 terabyte (TB) de dados, o que equivale a 1.000.00 megabytes (MB). Para colocar isso em perspectiva, 1 MB é igual a 1 milhão de bytes, que por sua vez é igual a 8 milhões de bits.

## Como um bit funciona

Cada bit em um byte é atribuído a um valor específico, chamado de _valor de posição_. Os valores de posição são usados para determinar o significado do byte como um todo, em outras palavras, os valores de byte indicam qual caractere está associado esse byte.

Um valor de posição é atribuído a cada bit em um padrão da direita para a esquerda, começando em 1 e aumentando o valor dobrando-o para cada bit:

| Posição do bit (da direita para a esquerda) | Valor de posição |
| ------------------------------------------- | ---------------- |
| Bit 1                                       | 1                |
| Bit 2                                       | 2                |
| Bit 3                                       | 4                |
| Bit 4                                       | 8                |
| Bit 5                                       | 16               |
| Bit 6                                       | 32               |
| Bit 7                                       | 64               |
| Bit 8                                       | 128              |

Os valores de posição são usados em conjunto com os valores de bit para chegar ao significado do byte. Para calcular esse valor, os valores de cada bit são somados. Portanto, um único único byte pode suportar até 256 caracteres únicos, começando com o byte `00000000` (0) e terminando com o byte `11111111` (255).
