# VPL em construção
Esse VPL tem o objetivo de trabalhar herança e a lógica de buscar itens em uma estrutura de dados qualquer.

# A biblioteca de Alexandria
A [Biblioteca de Alexandria](https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria) foi o local onde seres humanos colheram pela primeira vez, de maneira séria e sistemática, o conhecimento do mundo. Localizada na cidade de Alexandria, no Egito, fundada por Ptolomeu I, por volta do século III AEC, serviu como centro de aprendizado e pesquisa, agregando o conhecimento de filósofos e cientistas do mundo mediterrâneo.

Além do famoso Eratóstenes, a biblioteca também foi o lar do astrônomo Hiparco, que mapeou as constelações e fez uma estimativa da intensidade do brilho das estrelas; Euclides, que sistematizou com brilhantismo a geometria e que disse a seu rei, quando se debatia com um difícil problema matemático: "Não existe uma estrada real para a geometria"; Dionísio da Trácia, o homem que definiu as categorias gramaticais e fez para o estudo da língua o que Euclides fez para a geometria; Herófilo, o fisiologista que estabeleceu de maneira sólida que é o cérebro, e não o coração, a morada da inteligência; Heron de Alexandria, inventor de engrenagens e de motores a vapor, e autor de /Automata/, o primeiro livro sobre robôs; Apolônio de Perga, o matemático que demonstrou os formatos das seções cônicas — elipse, parábola e hipérbole —, curvas que, hoje sabemos, formam as órbitas de planetas, cometas e estrelas; Arquimedes, o maior gênio da mecânica até Leonardo da Vinci; e o astrônomo e geógrafo Ptolomeu, que compilou muito do que é hoje a pseudociência da astrologia: seu universo geocêntrico sustentou-se durante 1500 anos, um lembrete de que a capacidade intelectual não é uma garantia de que não se estará de todo errado. E entre esses grandes homens havia uma grande mulher, Hipátia, matemática e astrônoma, o último luminar da biblioteca, cujo martírio está ligado à destruição da biblioteca sete séculos após sua fundação.

(O parágrafo acima foi retirado do livro Cosmos, de Carl Sagan)

Infelizmente a maior parte do conhecimento desenvolvido e armazenado entre as paredes da biblioteca foi sucessivamente destruído por incêndios, invasões persas e também pelo já citado Júlio César (sim, o mesmo da Cifra de César), que destruiu boa parte da biblioteca durante um conflito com os egípcios.

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição.

Na época da biblioteca de Alexandria, utilizavam-se rolos de [papiro](https://pt.wikipedia.org/wiki/Papiro) para armazenar todo o conhecimento produzido, mas no mundo contemporâneo podemos utilizar os meios digitais, que são mais fáceis de manipular e não sofrem tanto com as ações do tempo, como os papiros.

Pensando nisso, como um entusiasta da preservação da sabedoria, sua tarefa é implementar um sistema de biblioteca, de forma que seja possível registrar, catalogar e buscar livros, revistas, jornais etc.

## O que você deve implementar
### class Item
Classe responsável por representar um item genérico do acervo da biblioteca.

#### Atributos
- **m_id**, std::size_t: Todo item da biblioteca deve ter um ID
- **m_title**, string: Título do item
- **m_author**, string: Nome do autor ou autores.
- **m_date**, string: Data de publicação no formato "DD/MM/AAAA"
- **m_available_quantity**, std::size_t: Indica a quantidade disponível para aluguel imediato no acervo, ou seja, os itens que ainda não foram reservados
- **m_loaned_quantity**: std::size_t: Indica quantos itens foram reservados
- **m_itemType**, string: Deve armazenar o tipo do item
  - O tipo pode ser "Livro", "Jornal", "Revista", ou "CD".

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Métodos responsável por mostrar as informações do item da seguinte maneira:
  - ID: x
  - TITLE: x
  - AUTOR(ES): x
  - DATA: x
  - QTD DISPONÍVEL: x
  - QTD RESERVADOS: x
  - TIPO: x

Considere que "x" é o valor armazenado na variável do dado em questão.

### class Book
Classe que representa um livro. Deve ser herança de Item.

#### Atributos
- **m_genre**: Aqui eu deixo você escolher como gostaria de representar os gêneros. Vejo duas possibilidades: /string/ ou, se você quer aprender algo novo, /enum/ (veja os links 2 e 3). Os gêneros possíveis são:
  - "FiccaoCientifica"
  - "Fantasia"
  - "Poesia"
  - "Quadrinhos"
  - "Infantil"

(Acho a opção do enum mais difícil, mas deixo a oportunidade para aprender algo novo)

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos

### class Newspaper
Classe que representa um jornal. Deve ser herança de Item.

#### Atributos
#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos

### class Magazine
Classe que representa uma revista. Deve ser herança de Item.

#### Atributos
- **m_volume, m_number:** Toda revista tem um volume e um número. O volume corresponde ao número sequencial a partir do ano de fundação da revista. O número corresponde a edição publicada em um determinado ano. Por exemplo, se a revista foi fundada em 2010, a primeiro edição de 2024 teria volume = 13 (em 2010 o volume é zero) e numero = 1. Aqui, como no VPL sobre CAVs, você pode decidir utilizar uma variável do tipo pair (veja o link 4) para representar os dois valores ou duas variáveis do tipo std::size_t separadas.

(Não precisa se preocupar com o ano de fundação da revista, a explicação é mais para você saber para que os atributos servem. Nos casos de teste seu programa já receberá o volume e o número diretamente, sem precisar fazer cálculos com anos)

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos

### class CD
Classe que representa um /compact disc/. Deve ser herança de Item.

#### Atributos
- **m_duration**, std::size_t: Duração em segundos do CD.

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos

### class Library
É aqui que a brincadeira começa. A classe Library é a responsável por:
1. Buscar items
   - Por tipo (livros, jornais, revistas ou cd)
   - Por atributo
2. Registrar items
3. Reservar items, caso estejam disponíveis
4. Imprimir o catalogo completo

#### Atributos
- **m_item**, vector: Vetor que armazena todos os itens do acervo.

#### Métodos
- **SearchBook()**
- **SearchMagazine()**
- **SearchNewspaper()**
- **SearchCD()**

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
1. https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria
2. https://learn.microsoft.com/pt-br/cpp/cpp/enumerations-cpp?view=msvc-170
3. https://murilo.wordpress.com/2009/05/29/o-que-sao-enums-e-como-utiliza-los-melhor-em-c/
4. https://cplusplus.com/reference/utility/pair/pair/
