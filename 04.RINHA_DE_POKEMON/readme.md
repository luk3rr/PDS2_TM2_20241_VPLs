# WARNING: This VPL is under construction
# Rinha de Pokémon
Segundo a legislação brasileira, é crime realizar ou promover "brigas de galo" ou quaisquer outras lutas entre animais. No entanto, no mundo de Pokémon
aparentemente ainda não há legislações que garantam os direitos dos monstros (Pokémon vem de **Poke**tto **Mon**sutā, que é Pocket Monster em inglês). Além disso, pelo que eu entendi, monstros não são animais, então é lícito realizar rinhas de Pokémons em território brasileiro.

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e o temido polimorfismo.

Como um entusiasta das rinhas (lícitas), sua tarefa é implementar um campeonato de batalhas de Pokémons, onde diferentes treinados podem se desafiar.

OBS.: Se o objetivo fosse ficar milionário, poderíamos incluir e gerenciar um sistema de apostas. No entanto, como o objetivo é apenas aprender C++ e POO, não teremos um sistema de apostas.

## O que você deve implementar
### class Pokemon
Classe base que representa um Pokémon genérico.

#### Atributos
1. **m_name**, **m_attackType** do tipo string, que armazena o nome do Pokémon e o tipo do ataque que ele faz (elétrico, aquático, explosivo etc);

2. **m_hp** do tipo double, que indica a vida atual do Pokemon; O HP é definido como 100 para todos os Pokémons.

3. **m_attackStrength** do tipo double no intervalo [0,1], que indica a potência do ataque do Pokémon.

#### Métodos
1. **Pokemon(string name, string attackType, double m_attackStrength):** Método construtor para a inicialização dos atributos;

==talvez==
2. **virtual ~Pokemon()**: Destrutor que deve ser implementado
==talvez==

3. **virtual void Attack(Pokemon\* other) = 0:** Método virtual puro que deve ser implementado por todas as classes derivadas (veja o link 2 e 3). Esse método deve implementar a ação de aplicar dano em outro Pokémon, de acordo com a seguinte lógica
   + Fala o próprio nome
   + Fala o tipo do ataque
   + Calcula o dano e imprime: "Dano: X"
     + O cálculo do dano é feito multiplicando a potência do ataque pela quantidade de dano que ele inflige.
   + Aplica o dano sobre outro Pokémon

4. **ReceiveAttack(double)**: Método que recebe um double que indica quando um Pokémon recebe uma pancada (ou lapada, no bom português). O valor recebido como parâmetro deve ser debitado do hp do Pokémon. O hp nunca deve ficar negativo, sendo o menor valor válido zero. Caso o hp chegue a zero, deve-se imprimir a mensagem "NOME Faliceu! ;-;", seguido de uma quebra de linha;

5. **virtual SayAttackType()**: Método que imprime o tipo do ataque no seguinte formato:
   + TIPO!
   + Seguido de uma quebra de linha

6. **PrintInfo**: Imprime as informações do Pokémon no formato:
   + Pokémon: NOME
   + Tipo ataque: TIPO
   + Potência do ataque: X
   + HP: Y

### class ElectricPokemon
Herda de Pokemon.

#### Atributos
1. **m_electricPower** do tipo double, que indica quanto de dano elétrico o Pokémon pode dar.

#### Métodos
1. **ElectricPokemon(string name, string attackType, double electricPower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **Attack(Pokemon\* other)**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Bzzzz!
   + Seguido de uma quebra de linha
   + (Imagine que "Bzzzz" é um barulho de choque e não de uma abelha ._. )

### class AquaticPokemon
Herda de Pokemon.

#### Atributos
1. **m_aquaticPower** do tipo double, que indica quanto de dano aquático o Pokémon pode dar.

#### Métodos
1. **AquaticPokemon(string name, string attackType, double aquaticPower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **Attack(Pokemon\* other)**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Splash!
   + Seguido de uma quebra de linha

### class PokemonExplosive
Herda de Pokemon.

#### Atributos
1. **m_explosivePower** do tipo double, que indica quanto de dano explosivo o Pokémon pode dar.

#### Métodos
1. **PokemonExplosive(string name, string attackType, double explosivePower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **Attack(Pokemon\* other)**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Booom!
   + Seguido de uma quebra de linha

### Trainer
#### Atributos
1. **m_name**, do tipo string, que armazena o nome do treinador;
2. **m_pokemons**, um vector que armazenar uma lista de ponteiros para objetivos do tipo **Pokémon**.

#### Métodos
1. Métodos para cadastro de Pokémons específicos (devem ser inseridos sequencialmente no vetor):
   + **RegisterElectricPokemon(string name, string attackType, double electricPower, double attackStrength);**
   + **RegisterAquaticPokemon(string name, string attackType, double aquaticPower, double attackStrength);**
   + **RegisterExplosivePokemon(string name, string attackType, double explosivePower, double attackStrength);**

3. **UsePokemon(string name):** Busca pelo Pokémon com o nome informado e retorna um ponteiro para ele;
4. **PrintInfo():** Imprime as informações do treinador no seguinte formato:
   + Se nenhum Pokémon foi cadastrado
     + Nome: NOME
     + \----------
     + Nenhum Pokemon encontrado :(
     + \---------
   + Caso contrário:
     + Nome: NOME
     + \----------
     + (Informações sobre o pokemon 0)
     + \----------
     + (Informações sobre o pokemon 1)
     + \----------
     + (etc etc etc)
     + \----------

### Rinha
#### Atributos
2. **m_trainers**, um vector que armazenar uma lista de ponteiros para objetivos do tipo **Trainer**.

#### Métodos
1. **RegisterTrainer(string name)**: Método para cadastrar treinadores. Os treinadores devem ser inseridos sequencialmente no vetor;

2. Métodos para cadastro de Pokémons específicos (devem ser inseridos sequencialmente no vetor):
   + **RegisterElectricPokemon(string nameTrainer, string namePokemon, string attackType, double electricPower, double attackStrength);**
   + **RegisterAquaticPokemon(string nameTrainer, string namePokemon, string attackType, double aquaticPower, double attackStrength);**
   + **RegisterExplosivePokemon(string nameTrainer, string namePokemon, string attackType, double explosivePower, double attackStrength);**

3. **Fight(string nameTrainer1, string namePokemon1, string nameTrainer2, string namePokemon2):** Executa a batalha considerando o nome dos treinadores e Pokémons informados. Deve imprimir as seguintes informações:
   + \### RINHA \###
   + NOME\_TREINADOR\_1 (NOME\_POKEMON\_1) vs. NOME\_TREINADOR\_2 (NOME\_POKEMON\_2)
   + Chamar método **Attack** (nesse caso, pokemon1 ataca pokemon2)
   + Imprimir o status do pokemon atacado (nesse caso, pokemon2)
   + #############

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
Por fim, você deve implementar o **main.cpp** do seu programa e toda a lógica de entrada/saída que será responsável por manipular os seguintes comandos:
+ 't nome': comando para cadastrar um treinador na rinha;
+ 'i nome': comando para imprimir as informações de um treinador;
+ 'e nomeTreinador nomePokemon tipoAtaque forcaAtaque potenciaAtaque': comando para adicionar um Pokémon elétrico ao treinador informado;
+ 'a nomeTreinador nomePokemon tipoAtaque forcaAtaque potenciaAtaque': comando para adicionar um Pokémon aquático ao treinador informado;
+ 'x nomeTreinador nomePokemon tipoAtaque forcaAtaque potenciaAtaque': comando para adicionar um Pokémon explosivo ao treinador informado;
+ 'r nomeTreinador1 nomePokemon1 nomeTreinador2 nomePokemon2': comando para realizar uma batalha de acordo com os nomes informados.

Você pode assumir que todos os nomes utilizados nas entradas são válidos. Ou seja, não ocorre nos casos de teste a tentativa de realizar uma batalha com um treinador ou Pokémon que ainda não foi registrado.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.

# Exemplos de entrada e saída
## Entrada

## Saída

## Exemplo 1
**input**

**output**


# Links não tão inúteis
1. https://www2.camara.leg.br/legin/fed/decret/1960-1969/decreto-50620-18-maio-1961-390463-publicacaooriginal-1-pe.html
2. https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
3. https://stackoverflow.com/questions/1306778/virtual-pure-virtual-explained
