# apoCalculator
Esse é um projeto para a disciplina de Análise e Projetos Orientados a Objetos do curso de Ciências da Computação da UTFPR de Campo Mourão.

## Descrição
Uma calculadora é um objeto que tem como função receber operações matemáticas, processá-las e exibir o resultado para o usuário. Dessa forma ela pode ser dividida em três partes:

### Teclado - Keyboard
É a parte da calculadora responsável por receber as entradas do usuário e chamar o processamento das operações. Conforme o usuário digita os números e as operações o resultado vai sendo calculado, armazenado na memória e exibido na tela.
Nesse contexto, as características dessa classe são:

#### Atributos
- A princípio não possuíra nenhum.

#### Métodos

##### lerNumero - readNumber:
Esse método receberá a entrada do usuário de um número real. Caso não seja uma entrada válida, retornar exceção. Se a entrada for válida retornar o valor lido.

##### lerOperacao - readOperation
Esse método receberá como entrada um número inteiro que representará uma das operações possíveis da calculadora:
- **AC = 0**
- **Adição = 1**
- **Subtração = 2**
- **Multiplicação = 3**
- **Divisão = 4**
- **Radiciação = 5**
- **Igualdade = 6**

Se o número informado não for positivo ou não estiver no intervalo considerado, assume-se que será realizado **AC**.
Caso seja informado **AC** limpar a memória.
Caso seja informado **IGUAL** calcular a operação com os valores na memória.
Caso ao armazenar na memória já haja uma operação salva ali diferente de **AC ou IGUAL**, calcular a operação usando os valores na memória e armazenar a nova operação.


### CPU
É a parte da calculadora responsável por realizar os cálculos e armazenar os valores e operações digitados na memória.

#### Atributos
- **memoria/memory:** um vetor de reais com duas posições, inicialmente zerado.
- **operacao/operation:** o valor da última operação digitada. Padrão 1 = Adição.
- **indexDeEscrita/writeIndex:** define em qual index da lista o novo número será adicionado. Padrão = 0.

#### Métodos

##### calcular - calculate
Pega o valor de `operation` e verifica qual operação vai realizar:
- Adição:
  - memory[0] + memory[1]
- Subtração:
  - memory[0] - memory[1]
- Multiplicação:
  - memory[0] x memory[1]
- Divisão:
  - memory[0] / memory[1]
- Radiciação:
  - SQRT de memory[0]
Retorna o resultado.
 
##### ac
Seta a `operation = 1` e zera `memory`.

##### write
Recebe um número inteiro e o escreve em `memory` com base no `write` index.
Se `wi` for `0`, escreve e o muda para 1.
Se `wi` for `1`, escreve e o muda para 0.


### Tela - Display
É onde são mostrados os resultados das operações.

#### Atributos
- Não possuíra.

#### Métodos

##### showMessage
Esse método recebe uma `string` e a mostra no terminal.

##### showOperations
Esse método mostra um menu contendo todas as opções que podem ser realizadas pela calculadora.

##### showResult
Recebe um número e o exibe para o usuário, seguindo precisão de 3 casas decimais.
