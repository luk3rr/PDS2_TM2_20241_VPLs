# De boa no ZapZap (VPL em construção)
A Rondolândia é uma nação idílica, governada por uma dinastia de capivaras fundada por Bacon - The Great, há várias gerações.

Em um certo momento passado, as capivaras perceberam que ideia do labor é uma furada, e decidiram criar a filosofia do ZapZap, que advoga pela manutenção da tranquilidade e que essa tranquilidade só pode ser alcançada fortalecendo as relações sociais. Assim, Torresmo IV, soberano da Rondolândia, teve a brilhante ideia de criar uma rede social chamada ZapZap, onde seus súditos pudessem praticar a filosofia do ZapZap sem sair de casa, o que aumentaria a paz no reino e permitiria Torresmo IV espionar todos os súditos do reino, prevenindo possíveis rebeliões e garantindo a permanência da dinastia por mais várias gerações. Uma ideia genial, não é mesmo ?!

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao emprego de smart pointers em C++ (homens de verdade usam /new/ e /delete/, mas ok, vocês precisam aprender isso ¯\\_(ツ)_/¯).

Como um entusiasta dos sistemas de espionagem, sua tarefa é ajudar Torresmo no desenvolvimento de sua rede social.

Para que Torresmo fique satisfeito, a rede social deve permitir que as pessoas criem conexões, enviem mensagens pessoais para uma conexão e postem mensagens para todas as conexões.

Não menos importante, Torresmo precisa saber de todas as mensagens que são trocadas no reino.

## O que você deve implementar
### class Soberano
#### Atributos
- **std::string m_nome**: Nome do soberano
- **std::vector<std::shared_ptr<Mensagem>> m_mensagens**: Vetor que armazena todas as mensagens trocadas no reino

#### Métodos
- **Soberano(std::string nome)**: Construtor que inicializa o nome do soberano
  - Devo imprimir a mensagem "Soberano NOME agora está farejando todas as mensagens do reino!"
- **void RegistrarMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para registrar uma nova mensagem no vetor de mensagens
- **void ExibirMensagens() const**: Método para exibir todas as mensagens captadas pelo soberano.
  - Caso ele já tenha captado ao menos uma mensagem:
    - Soberano: NOME
    - \----------
    - Remetente: NOME\_REMETENTE
    - Destinatário: NOME\_DESTINATARIO
    - Conteúdo: CONTEUDO\_MENSAGEM
    - \----------
    - ETC
    - \----------
  - Caso contrário
    - Súdito: NOME
    - \----------
    - Nenhuma mensagem encontrada.
    - \----------

### class Sudito
#### Atributos
- **std::string m_nome**: Nome do súdito
- **std::vector<std::unique_ptr<Sudito>> m_conexoes**: Vetor de smart pointers para armazenar as conexões do súdito
- **std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas**: Vetor de smart pointers para armazenar mensagens recebidas
    
#### Métodos
- **Suditos(std::string nome)**: Construtor que inicializa o nome do súdito
- **void AdicionarConexao(std::shared_ptr<Sudito> novaConexao)**: Método para adicionar uma nova conexão
  - Deve imprimir a mensagem "Súdito <NOME> adicionou <NOME\_NOVA\_CONEXAO> como conexão!"
- **void EnviarMensagem(std::shared_ptr<Sudito> destinatario, std::string conteudo, Soberano& soberano)**: Método para enviar uma mensagem pessoal para outra conexão
  - Deve imprimir "Súdito <NOME> enviando nova mensagem para <NOME_DESTINATARIO>"
- **void PostarMensagem(std::string conteudo, Soberano& soberano)**: Método para postar uma mensagem para todas as conexões
  - Deve imprimir "Súdito <NOME> postou uma nova mensagem!"
- **void ReceberMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para receber uma mensagem
  - Deve imprimir "Súdito <NOME> recebeu uma nova mensagem!"

### class Mensagem
#### Atributos
- **std::string m_conteudo**: Conteúdo da mensagem
- **std::shared_ptr<Sudito> m_remetente**: Smart pointer para o remetente da mensagem
- **std::shared_ptr<Sudito> m_destinatario**: Smart pointer para o destinatário da mensagem

#### Métodos
- **Mensagem(std::string conteudo, std::shared_ptr<Sudito> remetente, std::shared_ptr<Sudito> destinatario)**: Construtor que inicializa o conteúdo da mensagem, o remetente e o destinatário
- **std::string GetConteudo() const**: Método para obter o conteúdo da mensagem
- **std::shared_ptr<Sudito> GetRemetente() const**: Método para obter o remetente da mensagem
- **std::shared_ptr<Sudito> GetDestinatario() const**: Método para obter o destinatario da mensagem

### class ZapZap
Essa classe é a responsável por representar a nossa rede social, gerenciando todas as demais classes.

#### Atributos
- **Soberano m_soberano**: Instância do soberano que armazena todas as mensagens trocadas no reino
- **std::unordered_map<std::string, std::shared_ptr<Sudito>> m_suditos**: Mapa que armazena os súditos cadastrados na rede social
  - Você também pode utilizar vector, mas por motivos que não entram no escopo da disciplina de PDS2, a busca é mais rápida utilizando estruturas de dados do tipo **map** do que do tipo **vector**. Na seção /links não tão inúteis/ (eles são inúteis se você não os abrir e ver o conteúdo), deixei algumas referências sobre o **map**, caso você queira aprender algo a mais. Algoritmos e estruturas de dados são a parte mais legal da computação, então divirta-se!

#### Métodos
- **void CadastrarSudito(const std::string& nome)**: Cadastra um novo súdito
- **void CriarConexao(const std::string& nome1, const std::string& nome2)**: Cria uma conexão entre dois súditos
- **void EnviarMensagem(const std::string& nome1, const std::string& nome2, const std::string& conteudo)**: Envia uma mensagem pessoal de um súdito para outro
- **void PostarMensagem(const std::string& nome, const std::string& conteudo)**: Posta uma mensagem para todas as conexões de um súdito
- **void ImprimirMensagensSúdito(const std::string& nome) const**: Imprime as mensagens recebidas por um súdito no seguinte formato:
  - Caso ele já tenha recebido ao menos uma mensagem:
    - Súdito: NOME
    - \----------
    - Remetente: NOME\_REMETENTE
    - Conteúdo: CONTEUDO\_MENSAGEM
    - \----------
    - ETC
    - \----------
  - Caso contrário
    - Súdito: NOME
    - \----------
    - Nenhuma mensagem encontrada.
    - \----------

- **void ImprimirTodasMensagens() const**: Imprime todas as mensagens registradas pelo soberano.
OBS.: Para que a saída dos métodos de impressão sejam condizentes com a saída para os casos de teste, imprima as informações na ordem que elas foram inseridas no vector.

### Dependência circular
Se você ainda não se deparou com erros de dependência circular, provavelmente vai ter que lidar com isso nessa atividade.

Esse erro ocorre quando você tem dois arquivos que se incluem mutuamente. Por exemplo, suponho que você tenha o arquivo *a.hpp* e o arquivo *b.hpp*. O erro de dependência circular ocorre se você incluir *a.hpp* em *b.hpp* e também incluir *b.hpp* em *a.hpp*. Isso deixa o compilador literalmente doidão e ele não vai conseguir compilar seu código.

Existem várias formas de lidar com erros de dependência circular, e todas sempre me pareceram sempre gambiarras. Caso você se depare com esse empecilho, os links 4, podem te ajudar.

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em inglês, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
- 's nome': comando para cadastrar um súdito
- 'c nome1 nome2': comando para criar uma conexão entre dois súditos
- 'm nome1 nome2 conteudo': comando para enviar uma mensagem pessoal de nome1 para nome2
- 'p nome conteudo': comando para postar uma mensagem de nome para todas as suas conexões
- 'i nome': comando para imprimir as mensagens recebidas por um súdito
- 'a': comando para imprimir todas as mensagens registradas pelo soberano
- 'q': comando para finalizar o programa

Você pode assumir que todos os nomes utilizados nas entradas são válidos e também que **não** ocorre de dois súditos terem o mesmo nome. Além disso, nos casos de teste sempre haverá um, e somente um, soberano.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set. Se você perceber que algum método Get ou Set não é utilizado pelo seu programa, então você não precisa implementá-lo.
2. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.
3. Separe cada especificação (hpp) de sua respectiva implementação (cpp). Não implemente tudo em um único arquivo. Seja organizado.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
**output**\

# Links não tão inúteis
1. [https://stackoverflow.com/questions/2572678/c-stl-map-vs-vector-speed](https://stackoverflow.com/questions/2572678/c-stl-map-vs-vector-speed)
1. [https://www.youtube.com/watch?v=K_v_EIIZlp4](https://www.youtube.com/watch?v=K_v_EIIZlp4)
2. [https://www.youtube.com/watch?v=7mwgA9XFIEQ](https://www.youtube.com/watch?v=7mwgA9XFIEQ)
3. [https://www.youtube.com/watch?v=FsfRsGFHuv4](https://www.youtube.com/watch?v=FsfRsGFHuv4)
4. [https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes](https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes)
5. [https://pvigier.github.io/2018/02/09/dependency-graph.html](https://pvigier.github.io/2018/02/09/dependency-graph.html)
6. [https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c](https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c)
