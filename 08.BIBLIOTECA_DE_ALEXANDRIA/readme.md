# VPL em construção
Esse VPL tem o objetivo de trabalhar herança e a lógica de buscar itens em uma estrutura de dados qualquer.

# A biblioteca de Alexandria
A [Biblioteca de Alexandria](https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria) foi o local onde seres humanos colheram pela primeira vez, de maneira séria e sistemática, o conhecimento do mundo. Localizada na cidade de Alexandria, no Egito, fundada por Ptolomeu I, por volta do século III AEC, serviu como centro de aprendizado e pesquisa, agregando o conhecimento de filósofos e cientistas do mundo mediterrâneo.

Além do famoso Eratóstenes, a biblioteca também foi o lar do astrônomo Hiparco, que mapeou as constelações e fez uma estimativa da intensidade do brilho das estrelas; Euclides, que sistematizou com brilhantismo a geometria e que disse a seu rei, quando se debatia com um difícil problema matemático: "Não existe uma estrada real para a geometria"; Dionísio da Trácia, o homem que definiu as categorias gramaticais e fez para o estudo da língua o que Euclides fez para a geometria; Herófilo, o fisiologista que estabeleceu de maneira sólida que é o cérebro, e não o coração, a morada da inteligência; Heron de Alexandria, inventor de engrenagens e de motores a vapor, e autor de _Automata_, o primeiro livro sobre robôs; Apolônio de Perga, o matemático que demonstrou os formatos das seções cônicas — elipse, parábola e hipérbole —, curvas que, hoje sabemos, formam as órbitas de planetas, cometas e estrelas; Arquimedes, o maior gênio da mecânica até Leonardo da Vinci; e o astrônomo e geógrafo Ptolomeu, que compilou muito do que é hoje a pseudociência da astrologia: seu universo geocêntrico sustentou-se durante 1500 anos, um lembrete de que a capacidade intelectual não é uma garantia de que não se estará de todo errado. E entre esses grandes homens havia uma grande mulher, Hipátia, matemática e astrônoma, o último luminar da biblioteca, cujo martírio está ligado à destruição da biblioteca sete séculos após sua fundação.

(O parágrafo acima foi retirado do livro Cosmos, de Carl Sagan)

![Representação artística da Biblioteca](./img/biblioteca.jpg)

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
- **m_date**, string: Data de publicação. Não se preocupe com o formato, o que o usuário digitar deve ser armazenado.
- **m_available_quantity**, std::size_t: Indica a quantidade disponível para aluguel imediato no acervo, ou seja, os itens que ainda não foram reservados
- **m_loaned_quantity**: std::size_t: Indica quantos itens foram reservados. Inicialmente deve ser definido como zero.
- **m_itemType**, string: Deve armazenar o tipo do item
  - O tipo pode ser "Book", "Periodic" ou "CD".

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Métodos responsável por mostrar as informações do item da seguinte maneira:
  - ID: x
  - TTITLE: x
  - AUTHOR: x
  - DATE: x
  - ITEM TYPE: x
  - AVAILABLE COPIES: x
  - LOANED COPIES: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)

- **Reserve()**: Método que implementa a lógica de reservar um item.
  - Se houver itens disponíveis para empréstimo, deve imprimir "Item ID reservado com sucesso :)"
  - Se não houver, deve imprimir "Item ID não disponível para empréstimo :("

- **Release()**: Método que implementa a lógica de devolução do item e liberá-lo para um novo empréstimo.
  - Se realmente houver algum empréstimo, deve imprimir "Item ID recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)"
  - A sua lógica deve lidar com a tentativa de devolver um item que não está emprestado. Se nenhum item tiver sido emprestado, então imprima "Item ID não está emprestado o.O"

### class Book
Classe que representa um livro. Deve ser herança de Item.

#### Atributos
- **m_pages**, std::size_t: Armazena a quantidade de páginas do livro
- **m_genre**, string: Armazena o gênero do livro
- **m_publisher**, string: Armazena o nome da editora que publicou o livro
- **m_isbn**, string: Armazena o ISBN do livro

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Métodos responsável por mostrar as informações do livro da seguinte maneira:
  - ITEM: x
  - ID: x
  - TTITLE: x
  - AUTHOR: x
  - PUBLISHER: x
  - GENRE: x
  - NUMBER OF PAGES: x
  - ISBN: x
  - DATE: x
  - AVAILABLE COPIES: x
  - LOANED COPIES: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)

### class Periodic
Classe que representa um periódico (revista, jornal etc). Deve ser herança de Item.

#### Atributos
- **m_volume, m_number:** Todo periódico tem um volume e um número. O volume corresponde ao número sequencial a partir do ano de fundação do periódico. O número corresponde a edição publicada em um determinado ano. Por exemplo, se o periódico foi fundado em 2010, a primeiro edição de 2024 teria volume = 13 (em 2010 o volume é zero) e numero = 1. Aqui, como no VPL sobre CAVs, você pode decidir utilizar uma variável do tipo pair (veja o link 4) para representar os dois valores ou duas variáveis do tipo std::size_t separadas.
- **m_topics**, string: Deve armazena os tópicos abordados pelo periódico.

(Não precisa se preocupar com o ano de fundação do periódico, a explicação é mais para você saber para que os atributos servem. Nos casos de teste seu programa já receberá o volume e o número diretamente, sem precisar fazer cálculos com anos)

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Métodos responsável por mostrar as informações do jornal da seguinte maneira:
  - ITEM: x
  - ID: x
  - TITLE: x
  - EDITOR: x
  - TOPICS: x
  - DATE: x
  - AVAILABLE COPIES: x
  - LOANED COPIES: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)
  - (EDITOR no caso é o atributo author de Item. Não cheguei na idade de ler jornal, mas acredito que cada seção tenha um autor, então EDITOR aqui seria o nome da editora, considerando ela como autora)

### class CD
Classe que representa um /compact disc/. Deve ser herança de Item.

#### Atributos
- **m_tracks**, std::size_t: Indica a quantidade de faixas de áudio existem no CD.
- **m_duration**, std::size_t: Duração em segundos do CD.

#### Métodos
- Construtor e destrutor
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Métodos responsável por mostrar as informações do CD da seguinte maneira:
  - ITEM: x
  - ID: x
  - TITLE: x
  - ARTIST: x
  - TRACKS: x
  - DURATION:
  - DATE: x
  - AVAILABLE COPIES: x
  - LOANED COPIES: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)
  - (ARTIST no caso é o atributo author de Item.)
  - (DURATION foi dada em segundos, mas você deve imprimir no seguinte formato HH:MM:SS (hora, minuto e segundo, com dois digitados cada um)

### class Library
É aqui que a brincadeira começa. A classe Library é a responsável por:
1. Buscar items
2. Registrar items
3. Reservar items, caso estejam disponíveis
4. Imprimir o catalogo completo

#### Atributos
- **m_item**, vector: Vetor que armazena **ponteiros** para os itens do acervo.

#### Métodos
- Construtor e destrutor
- **AddBook(copies, pages, title, author, isbn, date, genre, publisher)**
- **AddPeriodic(copies, volume, number, title, date, editor, topics, type)**: Type já é recebido aqui, pois você pode ter periódicos de diferentes tipos.
- **AddCD(copies, tracks, duration, title, artist, date)**
- **Item\* Search(id)**: Método para procurar um item pelo ID. Caso o item exista, deve retornar um ponteiro ele, caso contrário retorne _nullptr_
- **Item\* Search(title)**: Método para procurar um item pelo título.
  - Tenha atenção:
  - Não é garantido que todos os itens terão nomes diferentes. Ou seja, dois autores (ou editores ou artistas) diferentes podem ter obras com o mesmo nome.
  - Dito isso, se for encontrado mais de um item com o mesmo nome, imprima:
    - Itens encontrados:
    - \----------
    - Informações do primeiro item encontrado
    - \----------
    - Informações do segundo item encontrado
    - \----------
    - etc etc
    - \----------
    - (Retorne nullptr)
  - Se existe apenas um item com o título pesquisado, retorne um ponteiro para ele.
- **Reserve(id)**: Aqui você basicamente vai chamar o método Reserve de Item
- **Release(id)**: Aqui você basicamente vai chamar o método Release de Item
- **Show()**: Imprime todo o catalogo da biblioteca na ordem dos IDs dos itens (item 1, item 2, item 3 etc)
  - Se não houver itens, imprima apenas "Estamos sem itens, mas você pode fazer uma doação ;-;"

Coloquei não coloquei o tipo dos parâmetros recebidos pelos métodos acima, você certamente conseguirá inferi-los. Sua função deve ter exatamente os mesmo parâmetros como descrito acima, mas você pode mudar a ordem ou o nome deles.

A respeito da lógica de criar IDs para cada veículo:
- Cada ID deve ser um inteiro não negativo
- Os IDs devem ser sequenciais começando do zero
- O usuário não fornece o ID, a sua função Library que deve gerenciá-los
  - Pense sobre a melhor maneira de fazer isso

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
Por fim, você deve implementar o **main.cpp** do seu programa e toda a lógica de entrada/saída que será responsável por manipular os seguintes comandos:
+ a l 'copies pages title author isbn date genre publisher': Comando para adicionar (**a**) um livro (**l**)
+ a j 'copies volume number title date editor topics': Comando para adicionar (**a**) um jornal (**j**) (é um periódico)
+ a r 'copies volume number title date editor topics': Comando para adicionar (**a**) uma revista (**r**) (é um periódico)
+ s: Imprime o catalogo da biblioteca

O último comando da sua função main antes do 'return 0;' deve ser 'std::cout << "Fim da execução" << std::endl;'.

Observe que diferentemente do VPLs sobre Pokémons, aqui o comando **a** sempre é seguido por outro comando. Como você pode implementar isso no seu main?

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set. Se você perceber que algum método Get ou Set não é utilizado pelo seu programa, então você não precisa implementá-lo.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.
4. Separe cada especificação (hpp) de sua respectiva implementação (cpp). Não implemente tudo em um único arquivo. Seja organizado.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
**output**\

# Links não tão inúteis
1. https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria
2. https://learn.microsoft.com/pt-br/cpp/cpp/enumerations-cpp?view=msvc-170
3. https://cplusplus.com/reference/utility/pair/pair/
