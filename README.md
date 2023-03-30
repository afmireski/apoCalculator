# apoCalculator
Esse é um projeto para a disciplina de Análise e Projetos Orientados a Objetos do curso de Ciências da Computação da UTFPR de Campo Mourão.

## Tutorial
```zsh
# Clone o projeto
git clone https://github.com/afmireski/apoCalculator.git

# Entre na pasta do projeto
cd apoCalculator

# Execute o makefile para compilar o projeto
make calculator

# A partir desse momento o programa estará rodando.
# Digite os números e operações que deseja realizar.
# O programa para de executar quando a operação IGUAL for escolhida

```

## Descrição
Uma calculadora é um objeto que tem como função receber operações matemáticas, processá-las e exibir o resultado para o usuário. Dessa forma ela pode ser dividida nas seguintes partes:

### Tecla - Key
É a parte da calculadora que tem como valor um `dígito` ou uma `operação`. Quando a tecla é pressionada ela devolve seu valor.

#### Atributos
- **value:** o valor da tecla, que pode ser uma `operation` ou um `digit`.

#### Métodos

##### press
Retorna o valor de `value`.

### Teclado - Keyboard
É a parte da calculadora responsável por receber as entradas do usuário e chamar o processamento das operações. Conforme o usuário digita os números e as operações o resultado vai sendo calculado, armazenado na memória e exibido na tela.
Todo `teclado` é composto por várias `teclas` que podem se referir a `dígitos` ou a `operações`. Conforme `dígitos` vão sendo digitados, seus valores vão sendo concatenados num `buffer` e exibidos na `tela`. Já quando uma `operação` é digitada o valor do `buffer` é enviado para a `CPU` e ele resetado.
Nesse contexto, as características dessa classe são:

#### Atributos
- **keys:** é a variável que armazena todas as teclas que o teclado possuí.

#### Métodos

##### envia o valor do Buffer - sendBufferValue
Pega o valor do buffer, o converte de `string` para `float` e o retorna.


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

##### setOperation
Recebe um `valor de Operation` e seta `operation` para o valor recebido

### Tela - Display
É onde são mostrados os dígitos e resultado das operações que o usuário realiza.

#### Atributos
- **buffer:** é a variável responsável por concatenar os valores digitados.



#### Métodos

##### showMessage
Esse método recebe um `número` e o mostra no terminal.


### Calculadora - Tela
É o objeto que agrupa todos os anteriores, criando algo funcional.

#### Atributos
- **display**: uma instância de Display que representa a tela da calculadora;
- **cpu**: uma instância de CPU que será responsável por realizar as operações da calculadora;
- **keyboard**: uma instância de Keyboard que representa o teclado da calculadora;

#### Métodos

##### getDisplay
Fornece acesso ao display da calculadora;

##### getCpu
Fornece acesso à CPU da calculadora;

##### getKeyboard
Fornece acesso ao keyboard da calculadora;

## Sobre a Implementação
- Primeiro serão implementadas as `interfaces`, ou `classes abstratas`, num arquivo `interfaces.hpp`, seguindo a descrição acima.
- Depois será criado um arquivo `.hpp`, `calculator.hpp`, `display.hpp`, que implementará cada `interface`.
- Por fim serão criados um `arquivo.cpp` para cada `arquivo.hpp`.
