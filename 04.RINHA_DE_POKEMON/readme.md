# WARNING: This VPL is under construction
# Rinha de Pokémon
Segundo a legislação brasileira, é crime realizar ou promover "brigas de galo" ou quaisquer outras lutas entre animais. No entanto, no mundo de Pokémon
aparentemente ainda não há legislações que garantam os direitos dos monstros (Pokémon vem de **Poke**tto **Mon**sutā, que é Pocket Monster em inglês). Além disso, pelo que eu entendi, monstros não são animais, então é lícito realizar rinhas de Pokémons em território brasileiro.

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e o temido polimorfismo.

Como um entusiasta das rinhas (lícitas), sua tarefa é implementar um campeonato de batalhas de Pokémons, onde diferentes treinadores podem se desafiar.

OBS.: Se o objetivo fosse ficar milionário, poderíamos incluir e gerenciar um sistema de apostas. No entanto, como o objetivo é apenas aprender C++ e POO, não teremos um sistema de apostas.

## O que você deve implementar
### class Pokemon
Classe base que representa um Pokémon genérico.

#### Atributos
1. **m_name**, **m_attackType** do tipo string, que armazena o nome do Pokémon e o tipo do ataque que ele faz (elétrico, aquático, explosivo etc);

2. **m_hp** do tipo double, que indica a vida atual do Pokémon; O HP é definido inicialmente como 100 para todos os Pokémons.

3. **m_attackStrength** do tipo double no intervalo [0,1], que indica a potência do ataque do Pokémon.

#### Métodos
1. **Pokemon(string name, string attackType, double m_attackStrength):** Método construtor para a inicialização dos atributos;

2. **virtual ~Pokemon()**: Destrutor que deve ser implementado.
    + Deve imprimir a mensagem: "Classe base : Pokémon NOME foi destruído!"

3. **virtual double CalculateDamage() = 0:** Método virtual puro que deve ser implementado por todas as classes derivadas (veja o link 2 e 3). Deve ser responsável por calcular o dano que o Pokémon causa.
   + O cálculo do dano é feito multiplicando a potência do ataque pelo poder de ataque.

4. **Attack(Pokemon\* target):** Método que implementa o comportamento de atacar outro Pokémon (target).
   + Se o Pokémon atacante estiver com HP iguala a zero, então ele não pode atacar e a função deve apenas imprimir a mensagem "NOME já partiu dessa pra melhor e não pode atacar!"
   + Caso contrário:
     + Imprima as informações do Pokémon atacante (use a função PrintInfo)
     + Calcule o dano que ele causa
     + Imprima o dano calculado no formato "Dano: X"
     + Aplique o dano sobre o Pokémon alvo
     + Imprima as informações sobre o Pokémon alvo

4. **ReceiveAttack(double)**: Método que implementa o comportamento de quando um Pokémon recebe uma pancada (ou lapada, no bom português). O valor recebido como parâmetro deve ser debitado do hp do Pokémon. O hp nunca deve ficar negativo, sendo o menor valor válido zero, que indica que o Pokémon já morreu (que deus o tenha).
   + Caso o Pokémon já esteja morto, a função deve apenas imprimir a mensagem "NOME já morreu. Não chute Pokémon morto!"
   + Caso contrário, implemente a lógica de debitar o HP de acordo com o dano recebido.
     + Caso o hp chegue a zero, deve-se imprimir a mensagem "NOME Faliceu! ;-;"

5. **virtual SayAttackType()**: Método que imprime o tipo do ataque.

6. **PrintInfo**: Imprime as informações do Pokémon no formato:
   + Pokémon: NOME
   + Tipo ataque: TIPO
   + Potência do ataque: X
   + HP: Y

### class ElectricPokemon
Herda de Pokémon.

#### Atributos
1. **m_electricPower** do tipo double, que indica quanto de dano elétrico o Pokémon pode dar.

#### Métodos
1. **ElectricPokemon(string name, string attackType, double electricPower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **virtual ~ElectricPokemon()**: Destrutor que deve ser implementado.
    + Deve imprimir a mensagem: "Classe derivada : Pokémon elétrico NOME diz: Adeus!"

3. **virtual double CalculateDamage()**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Bzzzz!
   + (Imagine que "Bzzzz" é um barulho de choque e não de uma abelha ._. )

### class AquaticPokemon
Herda de Pokémon.

#### Atributos
1. **m_aquaticPower** do tipo double, que indica quanto de dano aquático o Pokémon pode dar.

#### Métodos
1. **AquaticPokemon(string name, string attackType, double aquaticPower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **virtual ~AquaticPokemon()**: Destrutor que deve ser implementado.
    + Deve imprimir a mensagem: "Classe derivada : Pokémon aquático NOME diz: Adeus!"

3. **virtual double CalculateDamage()**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Splash!

### class ExplosivePokemon
Herda de Pokémon.

#### Atributos
1. **m_explosivePower** do tipo double, que indica quanto de dano explosivo o Pokémon pode dar.

#### Métodos
1. **PokemonExplosive(string name, string attackType, double explosivePower, double attackStrength)**: Método construtor para a inicialização dos atributos;

2. **virtual ~Explosive()**: Destrutor que deve ser implementado.
    + Deve imprimir a mensagem: "Classe derivada : Pokémon explosivo NOME diz: Adeus!"

3. **virtual double CalculateDamage()**: Sobrescrita do método virtual da superclasse.

3. **SayAttackType()**: Sobrescrita do método da superclasse. Imprime o tipo do ataque no seguinte formato:
   + TIPO! Booom!

### Trainer
#### Atributos
1. **m_name**, do tipo string, que armazena o nome do treinador;
2. **m_pokemons**, um vector que armazenar uma lista de ponteiros para objetivos do tipo **Pokémon**.

#### Métodos
1. **Trainer(string)**: Construtor que inicializa o atributo 'name' do treinador.
2. **~Trainer()**: Se você criou Pokémons no heap (utilizou new), então você deve liberar a memória (isso é importante!). Além disso, o destrutor deve imprimir a mensagem: "Treinador NOME foi destruído!"

1. Métodos para criar Pokémons específicos:
   + **AddElectricPokemon(string name, string attackType, double electricPower, double attackStrength);**
   + **AddAquaticPokemon(string name, string attackType, double aquaticPower, double attackStrength);**
   + **AddExplosivePokemon(string name, string attackType, double explosivePower, double attackStrength);**

3. **UsePokemon(string name):** Busca pelo Pokémon com o nome informado e retorna um ponteiro para ele;

4. **PrintInfo():** Imprime as informações do treinador no seguinte formato:
   + Se nenhum Pokémon foi cadastrado
     + Treinador: NOME
     + \----------
     + Nenhum Pokémon encontrado :(
     + \---------
   + Caso contrário:
     + Treinador: NOME
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
1. **Rinha()**: Construtor default.
2. **~Rinha()**: Se você criou treinadores no heap (utilizou new), então você deve liberar a memória (isso é importante!). Além disso, você deve imprimir a mensagem "Rinha destruída pela Polícia Federal!"

1. **AddTrainer(string name)**: Método para criar treinadores com um nome específico.

2. Métodos para cadastro de Pokémons específicos:
   + **AddElectricPokemon(string nameTrainer, string namePokemon, string attackType, double electricPower, double attackStrength);**
   + **AddAquaticPokemon(string nameTrainer, string namePokemon, string attackType, double aquaticPower, double attackStrength);**
   + **AddExplosivePokemon(string nameTrainer, string namePokemon, string attackType, double explosivePower, double attackStrength);**

3. **Fight(string nameTrainer1, string namePokemon1, string nameTrainer2, string namePokemon2):** Executa a batalha considerando o nome dos treinadores e Pokémons informados. Deve imprimir as seguintes informações:
   + \### RINHA \###
   + NOME\_TREINADOR\_1 (NOME\_POKEMON\_1) vs. NOME\_TREINADOR\_2 (NOME\_POKEMON\_2)
   + Chamar método **Attack** (nesse caso, pokemon1 ataca pokemon2)
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
+ 'q': comando para finalizar o programa.

O último comando da sua função main antes do 'return 0;' deve ser 'std::cout << "Fim da execução" << std::endl;'.

Você pode assumir que todos os nomes utilizados nas entradas são válidos. Ou seja, não ocorre nos casos de teste a tentativa de realizar uma batalha com um treinador ou Pokémon que ainda não foi registrado.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver algum coisa fora de lugar, os testes vão falhar.

# Exemplos de entrada e saída
## Exemplo 1
**input**
t Ash\
t Xerosic\
e Ash Pikachu Elétrico 42 0.7\
x Xerosic Cheirosinho Explosivo 33 0.99\
r Ash Pikachu Xerosic Cheirosinho\
q

**output**
\### RINHA ###
Ash (Pikachu) vs. Xerosic (Cheirosinho)\
Pokémon: Pikachu\
Tipo de ataque: Elétrico\
Potência do ataque: 0.7\
HP: 100\
Dano: 29.4\
Pokémon: Cheirosinho\
Tipo de ataque: Explosivo\
Potência do ataque: 0.99\
HP: 70.6\
#############\
Fim da execução\
Classe derivada : Pokémon elétrico Pikachu diz: Adeus!\
Classe base : Pokémon Pikachu foi destruído!\
Treinador Ash foi destruído!\
Classe derivada : Pokémon explosivo Cheirosinho diz: Adeus!\
Classe base : Pokémon Cheirosinho foi destruído!\
Treinador Xerosic foi destruído!\
Rinha destruída pela Polícia Federal!

## Exemplo 1
**input**
t DrZager\
t OMonitorDePDS2\
a OMonitorDePDS2 Shellder Aquático 83 0.66\
x DrZager Dinamite Explosivo 33 1\
r OMonitorDePDS2 Shellder DrZager Dinamite\
r DrZager Dinamite OMonitorDePDS2 Shellder\
r OMonitorDePDS2 Shellder DrZager Dinamite\
r DrZager Dinamite OMonitorDePDS2 Shellder\
r OMonitorDePDS2 Shellder DrZager Dinamite\
q

**output**
\### RINHA ###\
OMonitorDePDS2 (Shellder) vs. DrZager (Dinamite)\
Pokémon: Shellder\
Tipo de ataque: Aquático\
Potência do ataque: 0.66\
HP: 100\
Dano: 54.78\
Pokémon: Dinamite\
Tipo de ataque: Explosivo\
Potência do ataque: 1\
HP: 45.22\
#############\
\### RINHA ###\
DrZager (Dinamite) vs. OMonitorDePDS2 (Shellder)\
Pokémon: Dinamite\
Tipo de ataque: Explosivo\
Potência do ataque: 1\
HP: 45.22\
Dano: 33\
Pokémon: Shellder\
Tipo de ataque: Aquático\
Potência do ataque: 0.66\
HP: 67\
#############\
\### RINHA ###\
OMonitorDePDS2 (Shellder) vs. DrZager (Dinamite)\
Pokémon: Shellder\
Tipo de ataque: Aquático\
Potência do ataque: 0.66\
HP: 67\
Dano: 54.78\
Dinamite Faliceu! ;-;\
Pokémon: Dinamite\
Tipo de ataque: Explosivo\
Potência do ataque: 1\
HP: 0\
#############\
\### RINHA ###\
DrZager (Dinamite) vs. OMonitorDePDS2 (Shellder)\
Dinamite já partiu dessa pra melhor e não pode atacar!\
#############\
\### RINHA ###
OMonitorDePDS2 (Shellder) vs. DrZager (Dinamite)\
Pokémon: Shellder\
Tipo de ataque: Aquático\
Potência do ataque: 0.66\
HP: 67\
Dano: 54.78\
Dinamite já morreu. Não chute Pokémon morto!\
Pokémon: Dinamite\
Tipo de ataque: Explosivo\
Potência do ataque: 1\
HP: 0\
#############\
Fim da execução\
Classe derivada : Pokémon explosivo Dinamite diz: Adeus!\
Classe base : Pokémon Dinamite foi destruído!\
Treinador DrZager foi destruído!\
Classe derivada : Pokémon aquático Shellder diz: Adeus!\
Classe base : Pokémon Shellder foi destruído!\
Treinador OMonitorDePDS2 foi destruído!\
Rinha destruída pela Polícia Federal!

# Links não tão inúteis
1. https://www2.camara.leg.br/legin/fed/decret/1960-1969/decreto-50620-18-maio-1961-390463-publicacaooriginal-1-pe.html
2. https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
3. https://stackoverflow.com/questions/1306778/virtual-pure-virtual-explained
4. https://stackoverflow.com/questions/18198314/what-is-the-override-keyword-in-c-used-for
5. https://www.naukri.com/code360/library/new-and-delete-operator-in-c
