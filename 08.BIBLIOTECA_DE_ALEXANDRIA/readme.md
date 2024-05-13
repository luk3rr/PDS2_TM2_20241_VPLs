# A biblioteca de Alexandria
A [Biblioteca de Alexandria](https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria) foi o local onde seres humanos colheram pela primeira vez, de maneira séria e sistemática, o conhecimento do mundo. Localizada na cidade de Alexandria, no Egito, fundada por Ptolomeu I, por volta do século III AEC, serviu como centro de aprendizado e pesquisa, agregando o conhecimento de filósofos e cientistas do mundo mediterrâneo.

Além do famoso Eratóstenes, a biblioteca também foi o lar do astrônomo Hiparco, que mapeou as constelações e fez uma estimativa da intensidade do brilho das estrelas; Euclides, que sistematizou com brilhantismo a geometria e que disse a seu rei, quando se debatia com um difícil problema matemático: "Não existe uma estrada real para a geometria"; Dionísio da Trácia, o homem que definiu as categorias gramaticais e fez para o estudo da língua o que Euclides fez para a geometria; Herófilo, o fisiologista que estabeleceu de maneira sólida que é o cérebro, e não o coração, a morada da inteligência; Heron de Alexandria, inventor de engrenagens e de motores a vapor, e autor de _Automata_, o primeiro livro sobre robôs; Apolônio de Perga, o matemático que demonstrou os formatos das seções cônicas — elipse, parábola e hipérbole —, curvas que, hoje sabemos, formam as órbitas de planetas, cometas e estrelas; Arquimedes, o maior gênio da mecânica até Leonardo da Vinci; e o astrônomo e geógrafo Ptolomeu, que compilou muito do que é hoje a pseudociência da astrologia: seu universo geocêntrico sustentou-se durante 1500 anos, um lembrete de que a capacidade intelectual não é uma garantia de que não se estará de todo errado. E entre esses grandes homens havia uma grande mulher, Hipátia, matemática e astrônoma, o último luminar da biblioteca, cujo martírio está ligado à destruição da biblioteca sete séculos após sua fundação.

(O parágrafo acima foi retirado do livro Cosmos, de Carl Sagan)

![Representação artística da Biblioteca](./img/biblioteca.jpg)

Infelizmente a maior parte do conhecimento desenvolvido e armazenado entre as paredes da biblioteca foi sucessivamente destruído por incêndios, invasões persas e também pelo já citado Júlio César (sim, o mesmo da Cifra de César), que destruiu boa parte da biblioteca durante um conflito com os egípcios.

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e polimorfismo.

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
- **m_availableCopies**, std::size_t: Indica a quantidade disponível para aluguel imediato no acervo, ou seja, os itens que ainda não foram reservados
- **m_loanedCopies**: std::size_t: Indica quantos itens foram reservados. Inicialmente deve ser definido como zero.
- **m_itemType**, string: Deve armazenar o tipo do item
  - O tipo pode ser "Livro", "Jornal", "Revista" ou "CD".

#### Métodos
- Construtor e destrutor
  - O destrutor deve imprimir a mensagem "Item ID liberado da memória!"
  - (Acredito que dizer "Item ID destruído!" não pega muito bem no contexto de itens de uma biblioteca, ainda mais depois do que foi citado no texto de introdução deste VPL)
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Método **virtual** responsável por mostrar as informações do item da seguinte maneira:
  - ID: x
  - TÍTULO: x
  - AUTOR(A): x
  - DATA: x
  - TIPO: x
  - CÓPIAS DISPONÍVEIS: x
  - CÓPIAS RESERVADAS: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)

- **Reserve()**: Método que implementa a lógica de reservar um item.
  - Se houver itens disponíveis para empréstimo, deve imprimir "Item ID reservado com sucesso :)"
  - Se não houver, deve imprimir "Item ID não disponível para empréstimo :("

- **Release()**: Método que implementa a lógica de devolução do item e liberá-lo para um novo empréstimo.
  - Se realmente houver algum empréstimo, deve imprimir "Item ID recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)"
  - A sua lógica deve lidar com a tentativa de devolver um item que não está emprestado. Se nenhum item tiver sido emprestado, então imprima "Nenhuma cópia do item ID está emprestado o.O".
    - Isso é mais simples do que você inicialmente pode imaginar. Se m_loanedCopies for igual a zero para um determinado item, então nenhuma cópia dele foi emprestada. Se não...

### class Book
Classe que representa um livro. Deve ser herança de Item.

#### Atributos
- **m_numPages**, std::size_t: Armazena a quantidade de páginas do livro
- **m_genre**, string: Armazena o gênero do livro
- **m_publisher**, string: Armazena o nome da editora que publicou o livro
- **m_isbn**, string: Armazena o ISBN do livro

#### Métodos
- Construtor e destrutor
  - O destrutor deve imprimir a mensagem "Livro ID diz: Leia-me amanhã!"
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Sobrescrita do método virtual da classe base responsável por mostrar as informações do livro da seguinte maneira:
  - ITEM: x
  - ID: x
  - TÍTULO: x
  - AUTOR(A): x
  - EDITORA: x
  - GÊNERO: x
  - NÚMERO DE PÁGINAS: x
  - ISBN: x
  - DATA: x
  - CÓPIAS DISPONÍVEIS: x
  - CÓPIAS RESERVADAS: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)

### class Periodic
Classe que representa um periódico (revista, jornal etc). Deve ser herança de Item.

#### Atributos
- **m_volume, m_number:** Todo periódico tem um volume e um número. O volume corresponde ao número sequencial a partir do ano de fundação do periódico. O número corresponde a edição publicada em um determinado ano. Por exemplo, se o periódico foi fundado em 2010, a primeiro edição de 2024 teria volume = 13 (em 2010 o volume é zero) e numero = 1. Aqui, como no VPL sobre CAVs, você pode decidir utilizar uma variável do tipo pair (veja o link 2) para representar os dois valores ou duas variáveis do tipo std::size_t separadas.
- **m_topics**, string: Deve armazena os tópicos abordados pelo periódico.

(Não precisa se preocupar com o ano de fundação do periódico, a explicação é mais para você saber para que os atributos servem. Nos casos de teste seu programa já receberá o volume e o número diretamente, sem precisar fazer cálculos com anos)

#### Métodos
- Construtor e destrutor
  - O destrutor deve imprimir a mensagem "TIPO ID liberado da memória!"
  - Nessa tarefa, o TIPO de um periódico pode ser jornal ou revista.
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Sobrescrita do método virtual da classe base responsável por mostrar as informações do jornal da seguinte maneira:
  - ITEM: x
  - ID: x
  - TÍTULO: x
  - EDITORA: x
  - TÓPICOS: x
  - DATA: x
  - CÓPIAS DISPONÍVEIS: x
  - CÓPIAS RESERVADAS: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)
  - (EDITORA no caso é o atributo autor de Item. Não cheguei na idade de ler jornal ou revista, mas acredito que cada seção tenha um autor, então utilizamos EDITORA para simplificar)

Se você estiver se perguntando o motivo de eu não ter separado a classe periódico em duas classes diferentes (revista e jornal), a resposta é uma das duas opções abaixo:
1. O monitor não teve criatividade suficiente para elaborar atributos ou métodos que fossem específicos das duas classes
2. O monitor estava com pena dos alunos e decidiu diminuir o tamanho do VPL agregando revista e jornal em apenas uma classe

Qual opção você acha que é ? O.O

### class CD
Classe que representa um /compact disc/. Deve ser herança de Item.

#### Atributos
- **m_tracks**, std::size_t: Indica a quantidade de faixas de áudio existem no CD.
- **m_duration**, std::size_t: Duração em segundos do CD.

#### Métodos
- Construtor e destrutor
  - O destrutor deve imprimir a mensagem "CD ID liberado da memória!"
- Métodos Get e Set para obter e definir os valores dos atributos
- **PrintInfo():** Sobrescrita do método virtual da classe base responsável por mostrar as informações do CD da seguinte maneira:
  - ITEM: x
  - ID: x
  - TÍTULO: x
  - ARTISTA: x
  - FAIXAS: x
  - DURAÇÃO: x
  - DATA: x
  - CÓPIAS DISPONÍVEIS: x
  - CÓPIAS RESERVADAS: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)
  - (ARTISTA no caso é o atributo author de Item.)
  - (DURAÇÃO foi dada em segundos, mas você deve imprimir no seguinte formato HH:MM:SS (hora, minuto e segundo, com dois digitados cada um)

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
  - Se você criou os objetos do tipo Item no heap (você provavelmente fez isso), então você deve liberar a memória.
  - Após liberar a memória, imprima "Bye!"
- **AddBook(copies, pages, title, author, isbn, date, genre, publisher)**
- **AddPeriodic(copies, volume, number, title, date, editor, topics, type)**: type já é recebido aqui, pois você pode ter periódicos de diferentes tipos.
- **AddCD(copies, tracks, duration, title, artist, date)**
- **Item\* Search(id)**: Método para procurar um item pelo ID. Caso o item exista, deve retornar um ponteiro para ele, caso contrário retorne _nullptr_
- **Item\* Search(title)**: Método para procurar um item pelo título.
  - Tenha atenção:
  - Não é garantido que todos os itens terão nomes diferentes. Ou seja, dois autores (ou editoras ou artistas) diferentes podem ter obras com o mesmo nome. No entanto, um mesmo autor/editora/artista nunca terá duas obras com o mesmo nome.
  - Dito isso, se for encontrado mais de um item com o mesmo nome, imprima:
    - Vários itens com o mesmo título encontrados:
    - \----------
    - Informações do primeiro item encontrado
    - \----------
    - Informações do segundo item encontrado
    - \----------
    - etc etc
    - \----------
    - (Retorne nullptr)
  - Se existir apenas um item com o título pesquisado, retorne um ponteiro para ele.
  - Se não existir nenhum item com o título pesquisado, retorne _nullptr_
- **Reserve(id)**: Implementa a lógica de encontrar um item pelo ID e chamar o método Reserve da classe Item para ele, caso o item exista. Se o item não existir, imprima "Item ID não encontrado o.O"
- **Reserve(title)**: Implementa a lógica de encontrar um item pelo título e chamar o método Reserve da classe Item para ele, caso o item exista. Se o item não existir, imprima "Item TITLE não encontrado o.O"
- **Release(id)**: Implementa a lógica de encontrar um item e chamar o método Release da classe Item. Se o item não existir, imprima "Item ID não encontrado o.O"
- **PrintCollection()**: Imprime todo o catalogo da biblioteca na ordem dos IDs dos itens (item 1, item 2, item 3 etc)
  - Se você fez o VPL como espero que faça, apenas chame PrintInfo de cada Item, de forma que a impressão seja formata da seguinte maneira:
    - \----------
    - Informações do primeiro item
    - \----------
    - Informações do segundo item
    - \----------
    -  etc etc
    - \----------
  - Se não houver itens, imprima apenas "Estamos sem itens, mas você pode fazer uma doação ;-;"

Coloquei não coloquei o tipo dos parâmetros recebidos pelos métodos acima, você certamente conseguirá inferi-los. Sua função deve ter exatamente os mesmo parâmetros como descrito acima, mas você pode mudar a ordem ou o nome deles.

A respeito da lógica de criar IDs para cada item:
- Cada ID deve ser um inteiro não negativo
- Os IDs devem ser sequenciais começando do zero
- O usuário não fornece o ID, a sua função Library que deve gerenciá-los
  - Pense sobre a melhor maneira de fazer isso

Existe polimorfismo na forma como implementamos os métodos **Search** e **Reserve**. Você sabe qual o tipo desse polimorfismo (talvez isso caia na prova, cof cof).

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
Por fim, você deve implementar o **main.cpp** do seu programa e toda a lógica de entrada/saída que será responsável por manipular os seguintes comandos:
- a l 'copies pages title author isbn date genre publisher': Comando para adicionar (**a**) um livro (**l**)
- a j 'copies volume number title date editor topics': Comando para adicionar (**a**) um jornal (**j**) (é um periódico)
- a r 'copies volume number title date editor topics': Comando para adicionar (**a**) uma revista (**r**) (é um periódico)
- a c 'copies tracks duration title artist date': Comando para adicionar (**a**) um CD
- r t 'title': Comando para reservar (**r**) um item buscando-o pelo título (**t**)
- r i 'id: Comando para reservar (**r**) um item buscando-o pelo ID (**i**)
- d 'id': Comando para devolver (**d**) um item. Diferentemente da reserva, a devolução só é possível indicando o ID do item
- s: Imprime o catalogo da biblioteca

O último comando da sua função main antes do 'return 0;' deve ser 'std::cout << "Fim da execução" << std::endl;'.

Observe que diferentemente do VPLs sobre Pokémons, aqui alguns comandos são seguidos por outros até que os parâmetros para a criação do objeto sejam dados. Como você pode implementar isso no seu main?

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set. Se você perceber que algum método Get ou Set não é utilizado pelo seu programa, então você não precisa implementá-lo.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.
4. Separe cada especificação (hpp) de sua respectiva implementação (cpp). Não implemente tudo em um único arquivo. Seja organizado.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
a l 1 500 Sapiens YuvalNoahHarari 123456789-00 2011 História CompanhiaDasLetras\
a l 1 500 Sapiens VamoVerSeSeuProgramaEhBãoMesmo 123456789-00 2011 História CompanhiaDasLetras\
a l 1 220 ORomanceDasEquaçõesAlgébricas GilbertoGeraldoGarbi 123456789-00 1997 Matemática EditoraLivrariaDaFísica\
a r 2 6 4 ExtraExtraUmGatoBotouUmOvo:EntendaOCaso May2014 Anônimo PiadaRuim\
a j 3 10 5 FolhaDeSãoPaulo 01/05/2019 FolhaDeSãoPaulo Política,Economia,Esportes\
a c 1 13 4227 SobrevivendoNoInferno RacionaisMC's 27/10/1997\
a c 1 11 3789 Reanimation LinkinPark 30/07/2002\
r t Sapiens\
r i 0\
r i 1\
d 0\
r 3\
s\
d 3

**output**\
Vários itens com o mesmo título encontrados:\
\----------\
ITEM: Livro\
ID: 0\
TÍTULO: Sapiens\
AUTOR(A): YuvalNoahHarari\
EDITORA: CompanhiaDasLetras\
GÊNERO: História\
NÚMERO DE PÁGINAS: 500\
ISBN: 123456789-00\
DATA: 2011\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: Livro\
ID: 1\
TÍTULO: Sapiens\
AUTOR(A): VamoVerSeSeuProgramaEhBãoMesmo\
EDITORA: CompanhiaDasLetras\
GÊNERO: História\
NÚMERO DE PÁGINAS: 500\
ISBN: 123456789-00\
DATA: 2011\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
Item Sapiens não encontrado o.O\
Item 0 reservado com sucesso :)\
Item 1 reservado com sucesso :)\
Item 0 recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)\
\----------\
ITEM: Livro\
ID: 0\
TÍTULO: Sapiens\
AUTOR(A): YuvalNoahHarari\
EDITORA: CompanhiaDasLetras\
GÊNERO: História\
NÚMERO DE PÁGINAS: 500\
ISBN: 123456789-00\
DATA: 2011\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: Livro\
ID: 1\
TÍTULO: Sapiens\
AUTOR(A): VamoVerSeSeuProgramaEhBãoMesmo\
EDITORA: CompanhiaDasLetras\
GÊNERO: História\
NÚMERO DE PÁGINAS: 500\
ISBN: 123456789-00\
DATA: 2011\
CÓPIAS DISPONÍVEIS: 0\
CÓPIAS RESERVADAS: 1\
\----------\
ITEM: Livro\
ID: 2\
TÍTULO: ORomanceDasEquaçõesAlgébricas\
AUTOR(A): GilbertoGeraldoGarbi\
EDITORA: EditoraLivrariaDaFísica\
GÊNERO: Matemática\
NÚMERO DE PÁGINAS: 220\
ISBN: 123456789-00\
DATA: 1997\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: Revista\
ID: 3\
TÍTULO: ExtraExtraUmGatoBotouUmOvo:EntendaOCaso\
EDITORA: Anônimo\
TÓPICOS: PiadaRuim\
DATA: May2014\
CÓPIAS DISPONÍVEIS: 2\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: Jornal\
ID: 4\
TÍTULO: FolhaDeSãoPaulo\
EDITORA: FolhaDeSãoPaulo\
TÓPICOS: Política,Economia,Esportes\
DATA: 01/05/2019\
CÓPIAS DISPONÍVEIS: 3\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: CD\
ID: 5\
TÍTULO: SobrevivendoNoInferno\
ARTISTA: RacionaisMC's\
FAIXAS: 13\
DURAÇÃO: 01:10:27\
DATA: 27/10/1997\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: CD\
ID: 6\
TÍTULO: Reanimation\
ARTISTA: LinkinPark\
FAIXAS: 11\
DURAÇÃO: 01:03:09\
DATA: 30/07/2002\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 0\
\----------\
Nenhuma cópia do item 3 está emprestado o.O\
Fim da execução\
Livro 0 diz: Leia-me amanhã!\
Item 0 liberado da memória!\
Livro 1 diz: Leia-me amanhã!\
Item 1 liberado da memória!\
Livro 2 diz: Leia-me amanhã!\
Item 2 liberado da memória!\
Revista 3 diz: Leia-me amanhã!\
Item 3 liberado da memória!\
Jornal 4 diz: Leia-me amanhã!\
Item 4 liberado da memória!\
CD 5 diz: Ouça-me amanhã!\
Item 5 liberado da memória!\
CD 6 diz: Ouça-me amanhã!\
Item 6 liberado da memória!\
Bye!


# Links não tão inúteis
1. [https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria](https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria)
2. [https://cplusplus.com/reference/utility/pair/pair/](https://cplusplus.com/reference/utility/pair/pair/)
3. [https://pt.wikipedia.org/wiki/Sobrecarga_de_fun%C3%A7%C3%A3o](https://pt.wikipedia.org/wiki/Sobrecarga_de_fun%C3%A7%C3%A3o)
4. [https://terminalroot.com.br/2021/06/o-que-significa-override-em-cpp.html](https://terminalroot.com.br/2021/06/o-que-significa-override-em-cpp.html)
5. [https://stackoverflow.com/questions/13340891/how-can-i-use-setfill-properly-in-c](https://stackoverflow.com/questions/13340891/how-can-i-use-setfill-properly-in-c)
6. [https://youtu.be/TjnE1gV42Jw?si=-3c5ry2juOWQNWaB](https://youtu.be/TjnE1gV42Jw?si=-3c5ry2juOWQNWaB)
