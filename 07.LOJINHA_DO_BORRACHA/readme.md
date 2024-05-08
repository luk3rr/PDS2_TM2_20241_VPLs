# VPL em construção
Esse VPL parece bom para trabalhar conceitos de herança com os vários itens da loja.

# Lojinha do Borracha
A Rondolândia é uma nação idílica, governada por uma dinastia de capivaras fundada por Bacon - The Great, há várias gerações.

Em um certo momento passado, as capivaras perceberam que ideia o labor é uma furada, e decidiram criar a filosofia do ZapZap, que advoga pela manutenção da tranquilidade e que essa tranquilidade só pode ser alcançada fortalecendo as relações sociais. Assim, Torresmo IV, soberano da Rondolândia, teve a brilhante ideia de criar uma rede social chamada ZapZap, onde seus súditos pudessem praticar a filosofia do ZapZap sem sair de casa, o que aumentaria a paz no reino e permitiria Torresmo IV espionar todos os súditos do reino, prevenindo possíveis rebeliões e garantindo a permanência da dinastia por mais várias gerações. Uma ideia genial, não é mesmo ?!

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e o temido polimorfismo.

Como um entusiasta dos sistemas de espionagem, sua tarefa é ajudar Torresmo no desenvolvimento de sua rede social.

Para que Torresmo fique satisfeito, a rede social deve permitir que as pessoas criem conexões, enviem mensagens pessoais para uma conexão e postem mensagens para todas as conexões.

Não menos importante, Torresmo precisa saber de todas as mensagens que são trocadas no reino.

## O que você deve implementar
###

### class Capirava

### class Soberano

#### Atributos

#### Métodos

### class Suditos

### class Mensagem

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.


### Main
Por fim, você deve implementar o **main.cpp** do seu programa e toda a lógica de entrada/saída que será responsável por manipular os seguintes comandos:
+ 't nome': comando para cadastrar um treinador na rinha;
+ 'i nome': comando para imprimir as informações de um treinador;
+ 'e nomeTreinador nomePokemon forcaAtaque potenciaAtaque': comando para adicionar um Pokémon elétrico ao treinador informado;
+ 'a nomeTreinador nomePokemon forcaAtaque potenciaAtaque': comando para adicionar um Pokémon aquático ao treinador informado;
+ 'x nomeTreinador nomePokemon forcaAtaque potenciaAtaque': comando para adicionar um Pokémon explosivo ao treinador informado;
+ 'r nomeTreinador1 nomePokemon1 nomeTreinador2 nomePokemon2': comando para realizar uma batalha de acordo com os nomes informados.
+ 'q': comando para finalizar o programa.

O último comando da sua função main antes do 'return 0;' deve ser 'std::cout << "Fim da execução" << std::endl;'.

Você pode assumir que todos os nomes utilizados nas entradas são válidos. Ou seja, não ocorre nos casos de teste a tentativa de realizar uma batalha com um treinador ou Pokémon que ainda não foi registrado.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
**output**\

# Links não tão inúteis
