# Rinha de Pokémon
Esse VPL depende das implementações feitas no VPL ‘Rinha de Pokémon’. Se você não as fez, seja um(a) bom(boa) garoto(a) e volte lá para fazê-las.

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento e utilização de exceções personalizadas em C++.

Em geral, a melhor maneira de testar um sistema é disponibilizando-o para um usuário, pois estes vão tentar fazer com o seu sistema coisas que você nem imaginaria e que ocasionalmente vão quebrar o seu programa :')

Pensando nisso, como um entusiasta dos sistemas inquebráveis de rinhas (novamente, as lícitas), sua tarefa é implementar exceções personalizadas que lidam com os diversos erros que podem ocorrer durante o campeonato.

## O que você deve implementar
### rinhaExcept.hpp
No VPL, existe um arquivo vazio chamado *rinhaExcept.{hpp, cpp}*. Você deve fazer a definição e implementação de suas exceções personalizadas nestes arquivos.

Os casos de exceção que devem ser tratados são os seguintes:
1. Tentativa de adicionar um treinador com nome repetido
   - Deve implementar o método **what()** que retorna a mensagem "Treinador NOME já existe (-_-)"

1. Tentativa de adicionar um Pokémon com nome repetido a um mesmo treinador
   - Deve implementar o método **what()** que retorna a mensagem "Pokémon NOME\_POKEMON já pertence ao treinador NOME\_TREINADOR (-_-)"

2. Tentativa de usar um Pokémon que não está no time de um determinado treinador
   - Deve implementar o método **what()** que retorna a mensagem "Pokémon NOME\_POKEMON não encontrado no time do treinador NOME\_TREINADOR o.O"

3. Tentativa de usar um treinador que não está na rinha
   - Deve implementar o método **what()** que retornar a mensagem "Treinador NOME não encontrado o.O"

4. Poder do ataque não pode ser negativo
   - Deve implementar o método **what()** que retorna a mensagem "Poder do ataque não pode ser negativo '-'"

5. Potência do ataque não pode ser negativa
   - Deve implementar o método **what()** que retorna a mensagem "Potência do ataque não pode ser negativa '-'"

### Onde você deve lançar exceções
O melhor local para lançar exceções depende fortemente de como você implementou o seu programa. Você deve decidir qual o local mais apropriado para lançar suas exceções. No entanto, tente achar pelo menos um caso de lançamento de cada uma das 5 exceções citadas acima.

### Onde devo capturar ?
Para facilitar a correção deste pobre monitor, você deve tratar todas as exceções que forem lançadas no main do seu programa.

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.

Além disso, você pode estar se perguntando por que diabos eu pedi para você imprimir mensagens nos destrutores. Bom, além de tentar fazer com que você os implemente, também gostaria que você visualizasse a ordem que os destrutores são chamados quando há heranças envolvidas.

### Main
O main deve tratar as mesmas entradas do VPL 'Rinha de Pokémon', mas você deve alterá-lo para capturar as exceções que são lançadas pelo seu programa.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set.
2. Você deve lançar cada uma das cinco exceções citadas pelo menos uma vez.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
t Ash\
t Xerosic\
t Xerosic\
i Xerosic\
i Trolei\
e Ash Pikachu 42 0.7\
x Xerosic Cheirosinho 33 0.99\
x Xerosic Cheirosinho 33 0.99\
x Xerosic Cheirosin -33 0.99\
r Ash Pikachu Xerosic Cheirosin\
r Ash Pikachu Xerosic Cheirosinho\
r Ash Pikachu Xerosic Cheirosin\
q

**output**\
Treinador Xerosic já existe (-\_-)\
Treinador: Xerosic\
\----------\
Nenhum pokémon encontrado :(\
\----------\
Treinador Trolei não encontrado o.O\
Pokémon Cheirosinho já existe no time do treinador Xerosic (-\_-)\
Poder do ataque não pode ser negativo '-'\
Pokémon Cheirosin não encontrado no time do treinador Xerosic o.O
\### RINHA ###
Ash (Pikachu) vs. Xerosic (Cheirosinho)\
Pokémon: Pikachu\
Tipo de ataque: Elétrico! Bzzzz!\
Potência do ataque: 0.7\
HP: 100\
Dano: 29.4\
Pokémon: Cheirosinho\
Tipo de ataque: Explosivo! Booom!\
Potência do ataque: 0.99\
HP: 70.6\
\#############\
Pokémon Cheirosin não encontrado no time do treinador Xerosic o.O\
Fim da execução\
Classe derivada : Pokémon elétrico Pikachu diz: Adeus!\
Classe base : Pokémon Pikachu foi destruído!\
Treinador Ash foi destruído!\
Classe derivada : Pokémon explosivo Cheirosinho diz: Adeus!\
Classe base : Pokémon Cheirosinho foi destruído!\
Treinador Xerosic foi destruído!\
Rinha destruída pela Polícia Federal!

# Links não tão inúteis
1. [https://cplusplus.com/doc/tutorial/exceptions/](https://cplusplus.com/doc/tutorial/exceptions/)
2. [https://www.geeksforgeeks.org/exception-handling-c/]()https://www.geeksforgeeks.org/exception-handling-c/
3. [Exemplo de como implementar exceções customizadas em C++](https://github.com/luk3rr/PERSONAL_FINANCE/blob/main/include/CartaoDeCreditoExcp.hpp)
