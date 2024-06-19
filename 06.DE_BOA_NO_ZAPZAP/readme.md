# De boa no ZapZap
A Rondolândia é uma nação idílica, governada por uma dinastia de capivaras fundada por Bacon - The Great, há várias gerações.

Em um certo momento passado, as capivaras perceberam que ideia do labor é uma furada, e decidiram criar a filosofia do ZapZap, que advoga pela manutenção da tranquilidade e que essa tranquilidade só pode ser alcançada fortalecendo as relações sociais. Assim, Torresmo IV, soberano da Rondolândia, teve a brilhante ideia de criar uma rede social chamada ZapZap, onde seus súditos pudessem praticar a filosofia do ZapZap sem sair de casa, o que aumentaria a paz no reino e permitiria Torresmo IV espionar todos os súditos do reino, prevenindo possíveis rebeliões e garantindo a permanência da dinastia por mais várias gerações. Uma ideia genial, não é mesmo ?!

<img src="img/capivara.png" alt="Dia da Capivara: por que espécie some da Lagoa da Pampulha? | Minas Gerais  | G1" width="400" height="225" role="presentation" class="img-fluid atto_image_button_text-bottom"></p>

De boa na Lagoa da Pampulha ( ‾ʖ̫‾)

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao emprego de smart pointers em C++ (homens de verdade usam *new* e *delete*, mas okay, vocês precisam aprender isso ¯\\_(ツ)_/¯).

Como um entusiasta dos sistemas de espionagem, sua tarefa é ajudar Torresmo no desenvolvimento de sua rede social.

Para que Torresmo fique satisfeito, a rede social deve permitir que as pessoas criem conexões, enviem mensagens pessoais para uma conexão e postem mensagens para todas as conexões. Não menos importante, Torresmo precisa saber de todas as fofocas que são trocadas no reino.

## O que você deve implementar
### class Soberano
#### Atributos
- **std::string m_nome**: Nome do soberano

- **std::vector<std::shared_ptr<Mensagem>> m_mensagens**: Vetor que armazena todas as mensagens trocadas no reino

#### Métodos
- **Soberano(std::string nome)**: Construtor que inicializa o nome do soberano
  - Devo imprimir a mensagem "Soberano <NOME> agora está farejando todas as mensagens do reino!"

- **void RegistrarMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para registrar uma nova mensagem no vetor de mensagens

- **void ExibirMensagens() const**: Método para exibir todas as mensagens captadas pelo soberano.
  - Caso ele já tenha captado ao menos uma mensagem:
    - Soberano: <NOME>
    - \----------
    - Remetente: <NOME\_REMETENTE>
    - Destinatário: <NOME\_DESTINATARIO>
    - Conteúdo: <CONTEUDO\_MENSAGEM>
    - \----------
    - ETC
    - \----------
  - Caso contrário
    - Soberano: <NOME>
    - \----------
    - Nenhuma mensagem encontrada.
    - \----------

### class Sudito
#### Atributos
- **std::string m_nome**: Nome do súdito

- **std::vector<std::shared_ptr<Sudito>> m_conexoes**: Vetor de smart pointers para armazenar as conexões do súdito

- **std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas**: Vetor de smart pointers para armazenar mensagens recebidas

- **std::vector<std::shared_ptr<Mensagem>> m_mensagensEnviadas**: Vetor de smart pointers para armazenar mensagens enviadas
    
#### Métodos
- **Suditos(std::string nome)**: Construtor que inicializa o nome do súdito

- **void AdicionarConexao(std::shared_ptr<Sudito> novaConexao)**: Método para adicionar uma nova conexão
  - Deve imprimir a mensagem "Súdito <NOME> adicionou <NOME\_NOVA\_CONEXAO> como conexão!"

- **void EnviarMensagem(std::shared_ptr<Mensagem> msg, std::shared_ptr<Sudito> destinatario)**: Método para enviar uma mensagem pessoal para outra conexão
  - Se o destinatário não for conexão do Súdito atual, então imprima "Súdito <NOME> não pode enviar mensagem para <NOME\_DESTINATARIO>" pois não são conexões!" e finalize a função.
  - Caso contrário, deve imprimir "Súdito <NOME> enviando nova mensagem para <NOME\_DESTINATARIO>" e enviar a mensagem.

- **void PostarMensagem(std::shared_ptr<Mensagem> msg)**: Método para postar uma mensagem para todas as conexões
  - Deve imprimir "Súdito <NOME> postou uma nova mensagem!" e implementar toda a lógica de distribuir as mensagens entre as conexões

- **void ReceberMensagem(std::shared_ptr<Mensagem> msg)**: Método para receber uma mensagem
  - Deve imprimir "Súdito <NOME> recebeu uma nova mensagem de <NOME\_REMETENTE"

- **void ExibirMensagensEnviadas()**: Método para imprimir todas as mensagens enviadas pelo súdito
  - Se nenhuma mensagem foi enviada, imprima no seguinte formato:
    - \---------
    - Nenhuma mensagem enviada por <NOME>
    - \---------
  - Caso contrário, imprima:
    - \---------
    - Mensagens enviadas por <NOME>:
    - \---------
    - Destinatário: <NOME\_DESTINATARIO>
    - Conteúdo: <CONTEUDO\_MSG>
    - \---------
    - etc etc
    - \---------

- **void ExibirMensagensRecebidas()**: Método para imprimir todas as mensagens recebidas pelo súdito
  - Se nenhuma mensagem foi recebida, imprima no seguinte formato:
    - \---------
    - Nenhuma mensagem recebida por <NOME>
    - \---------
  - Caso contrário, imprima:
    - \---------
    - Mensagens recebidas por <NOME>:
    - \---------
    - Remetente: <NOME\_REMETENTE>
    - Conteúdo: <CONTEUDO\_MSG>
    - \---------
    - etc etc
    - \---------

### class Mensagem
#### Atributos
- **std::string m_conteudo**: Conteúdo da mensagem

- **std::string m_destinatario**: Nome do destinatário (acho que talvez aqui possa ser smart pointer, mas não lembro o motivo de ter colocado string '-')

- **std::shared_ptr<Sudito> m_remetente**: Smart pointer para o remetente da mensagem

#### Métodos
- **Mensagem(std::string conteudo, std::shared_ptr<Sudito> remetente, std::string destinatario)**: Construtor que inicializa o conteúdo da mensagem, o remetente e o destinatário

- Os métodos Gets e Sets que forem necessários

### class ZapZap
Essa classe é a responsável por representar a nossa rede social, gerenciando todas as demais classes.

#### Atributos
- **Soberano m_soberano**: Instância do soberano que armazena todas as mensagens trocadas no reino

- **std::unordered_map<std::string, std::shared_ptr<Sudito>> m_suditos**: Map que armazena os súditos cadastrados na rede social
  - Você também pode utilizar vector, mas por motivos que não entram no escopo da disciplina de PDS2, a busca é mais rápida utilizando estruturas de dados do tipo **map** do que do tipo **vector**. Na seção /links não tão inúteis/ (eles são inúteis se você não os abrir e ver o conteúdo), deixei algumas referências sobre o **map**, caso você queira aprender algo a mais. Algoritmos e estruturas de dados são a parte mais legal da computação, então divirta-se!

#### Métodos
- **void CadastrarSudito(const std::string& nome)**: Cadastra um novo súdito

- **void CriarConexao(const std::string& nome1, const std::string& nome2)**: Cria uma conexão entre dois súditos

- **void EnviarMensagem(const std::string& nome1, const std::string& nome2, const std::string& conteudo)**: Envia uma mensagem pessoal de um súdito para outro. Nesse caso, nome1 envia para nome2

- **void PostarMensagem(const std::string& nome, const std::string& conteudo)**: Posta uma mensagem para todas as conexões de um súdito. O nome do destinatário desse post deve ser "Conexões".

- **void ImprimirTodasMensagens() const**: Imprime todas as mensagens capturadas pelo soberano

- **void ImprimirMensagensEnviadas(const std::string& nome) const**: Imprime todas as mensagens enviadas por um súdito

- **void ImprimirMensagensRecebidas(const std::string& nome) const**: Imprime todas as mensagens recebidas por um súdito

OBS.: Para que a saída dos métodos de impressão sejam condizentes com a saída para os casos de teste, imprima as informações na ordem que elas foram inseridas no vector.

### Dependência circular
Se você ainda não se deparou com erros de dependência circular, provavelmente vai ter que lidar com isso nessa atividade.

Esse erro ocorre quando você tem dois arquivos que se incluem mutuamente. Por exemplo, suponho que você tenha o arquivo *a.hpp* e o arquivo *b.hpp*. O erro de dependência circular ocorre se você incluir *a.hpp* em *b.hpp* e também incluir *b.hpp* em *a.hpp*. Isso deixa o compilador literalmente doidão e ele não vai conseguir compilar seu código.

Existem várias formas de lidar com erros de dependência circular, e todas sempre me pareceram sempre gambiarras. Caso você se depare com esse empecilho, os links 5, 6 e 7 podem te ajudar.

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em inglês, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
Antes da execução o seu programa já deve instânciar um Soberano com o nome "Torresmo IV".

- 's nome': comando para cadastrar um súdito

- 'c nome1 nome2': comando para criar uma conexão entre dois súditos

- 'm nome1 nome2 conteudo': comando para enviar uma mensagem pessoal de nome1 para nome2

- 'p nome conteudo': comando para postar uma mensagem de nome para todas as suas conexões

- 'i r nome': comando para imprimir as mensagens recebidas por um súdito

- 'i e nome': comando para imprimir as mensagens enviadas por um súdito

- 'a': comando para imprimir todas as mensagens registradas pelo soberano

- 'q': comando para finalizar o programa

Você pode assumir que **não** ocorre de dois súditos terem o mesmo nome e que todos os nomes são válidos, ou seja, não vou tentar trollar o seu programa. Além disso, nos casos de teste sempre haverá um, e somente um, soberano.

A última mensagem impressa pelo seu programa deve ser "E as capivaras viveram felizes para sempre..."

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set. Se você perceber que algum método Get ou Set não é utilizado pelo seu programa, então você não precisa implementá-lo.
2. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.
3. Separe cada especificação (hpp) de sua respectiva implementação (cpp). Não implemente tudo em um único arquivo. Seja organizado.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
s Capivarinhas\
s CapyMcCapyface\
s SrPelos\
s DonaCapivara\
s BigCapy\
s CapitãoCapivara\
s CapyGato\
c Capivarinhas CapyMcCapyface\
c Capivarinhas SrPelos\
c CapyMcCapyface DonaCapivara\
c SrPelos BigCapy\
c DonaCapivara CapitãoCapivara\
c BigCapy CapyGato\
m Capivarinhas CapyMcCapyface E aí, CapyMcCapyface! Vamos dar um rolê na lagoa?\
m CapyMcCapyface DonaCapivara Alô, DonaCapivara! Tem pão de queijo aí?\
m SrPelos BigCapy CapyPower! Vamos dominar o mundo?\
m DonaCapivara CapitãoCapivara Capitão, meu Capitão! Preparado para a missão?\
m BigCapy CapyGato CapyGato, para de roubar minhas cenouras!\
p Capivarinhas Hora de relaxar na sombra!\
p SrPelos Alguém viu minha boia de patinho?\
p DonaCapivara Festa na lagoa hoje à noite!\
p CapitãoCapivara De boa na lagoa rsrs!\
i r CapyMcCapyface\
i r BigCapy\
i e Capivarinhas\
i e SrPelos\
a\
q

**output**\
Soberano Torresmo IV agora está farejando todas as mensagens do reino!\
Súdito Capivarinhas adicionou CapyMcCapyface como conexão!\
Súdito CapyMcCapyface adicionou Capivarinhas como conexão!\
Súdito Capivarinhas adicionou SrPelos como conexão!\
Súdito SrPelos adicionou Capivarinhas como conexão!\
Súdito CapyMcCapyface adicionou DonaCapivara como conexão!\
Súdito DonaCapivara adicionou CapyMcCapyface como conexão!\
Súdito SrPelos adicionou BigCapy como conexão!\
Súdito BigCapy adicionou SrPelos como conexão!\
Súdito DonaCapivara adicionou CapitãoCapivara como conexão!\
Súdito CapitãoCapivara adicionou DonaCapivara como conexão!\
Súdito BigCapy adicionou CapyGato como conexão!\
Súdito CapyGato adicionou BigCapy como conexão!\
Súdito Capivarinhas enviando nova mensagem para CapyMcCapyface\
Súdito CapyMcCapyface recebeu uma nova mensagem de Capivarinhas\
Súdito CapyMcCapyface enviando nova mensagem para DonaCapivara\
Súdito DonaCapivara recebeu uma nova mensagem de CapyMcCapyface\
Súdito SrPelos enviando nova mensagem para BigCapy\
Súdito BigCapy recebeu uma nova mensagem de SrPelos\
Súdito DonaCapivara enviando nova mensagem para CapitãoCapivara\
Súdito CapitãoCapivara recebeu uma nova mensagem de DonaCapivara\
Súdito BigCapy enviando nova mensagem para CapyGato\
Súdito CapyGato recebeu uma nova mensagem de BigCapy\
Súdito Capivarinhas postou uma nova mensagem!\
Súdito CapyMcCapyface recebeu uma nova mensagem de Capivarinhas\
Súdito SrPelos recebeu uma nova mensagem de Capivarinhas\
Súdito SrPelos postou uma nova mensagem!\
Súdito Capivarinhas recebeu uma nova mensagem de SrPelos\
Súdito BigCapy recebeu uma nova mensagem de SrPelos\
Súdito DonaCapivara postou uma nova mensagem!\
Súdito CapyMcCapyface recebeu uma nova mensagem de DonaCapivara\
Súdito CapitãoCapivara recebeu uma nova mensagem de DonaCapivara\
Súdito CapitãoCapivara postou uma nova mensagem!\
Súdito DonaCapivara recebeu uma nova mensagem de CapitãoCapivara\
\----------\
Mensagens recebidas por CapyMcCapyface:\
\----------\
Remetente: Capivarinhas\
Conteúdo: E aí, CapyMcCapyface! Vamos dar um rolê na lagoa?\
\----------\
Remetente: Capivarinhas\
Conteúdo: Hora de relaxar na sombra!\
\----------\
Remetente: DonaCapivara\
Conteúdo: Festa na lagoa hoje à noite!\
\----------\
\----------\
Mensagens recebidas por BigCapy:\
\----------\
Remetente: SrPelos\
Conteúdo: CapyPower! Vamos dominar o mundo?\
\----------\
Remetente: SrPelos\
Conteúdo: Alguém viu minha boia de patinho?\
\----------\
\----------\
Mensagens enviadas por Capivarinhas:\
\----------\
Destinatário: CapyMcCapyface\
Conteúdo: E aí, CapyMcCapyface! Vamos dar um rolê na lagoa?\
\----------\
\----------\
Mensagens enviadas por SrPelos:\
\----------\
Destinatário: BigCapy\
Conteúdo: CapyPower! Vamos dominar o mundo?\
\----------\
Soberano: Torresmo IV\
\----------\
Remetente: Capivarinhas\
Destinatário: CapyMcCapyface\
Conteúdo: E aí, CapyMcCapyface! Vamos dar um rolê na lagoa?\
\----------\
Remetente: CapyMcCapyface\
Destinatário: DonaCapivara\
Conteúdo: Alô, DonaCapivara! Tem pão de queijo aí?\
\----------\
Remetente: SrPelos\
Destinatário: BigCapy\
Conteúdo: CapyPower! Vamos dominar o mundo?\
\----------\
Remetente: DonaCapivara\
Destinatário: CapitãoCapivara\
Conteúdo: Capitão, meu Capitão! Preparado para a missão?\
\----------\
Remetente: BigCapy\
Destinatário: CapyGato\
Conteúdo: CapyGato, para de roubar minhas cenouras!\
\----------\
Remetente: Capivarinhas\
Destinatário: Conexões\
Conteúdo: Hora de relaxar na sombra!\
\----------\
Remetente: SrPelos\
Destinatário: Conexões\
Conteúdo: Alguém viu minha boia de patinho?\
\----------\
Remetente: DonaCapivara\
Destinatário: Conexões\
Conteúdo: Festa na lagoa hoje à noite!\
\----------\
Remetente: CapitãoCapivara\
Destinatário: Conexões\
Conteúdo: De boa na lagoa rsrs!\
\----------\
E as capivaras viveram felizes para sempre...

# Links não tão inúteis
1. [https://stackoverflow.com/questions/2572678/c-stl-map-vs-vector-speed](https://stackoverflow.com/questions/2572678/c-stl-map-vs-vector-speed)
2. [https://www.youtube.com/watch?v=K_v_EIIZlp4](https://www.youtube.com/watch?v=K_v_EIIZlp4)
3. [https://www.youtube.com/watch?v=7mwgA9XFIEQ](https://www.youtube.com/watch?v=7mwgA9XFIEQ)
4. [https://www.youtube.com/watch?v=FsfRsGFHuv4](https://www.youtube.com/watch?v=FsfRsGFHuv4)
5. [https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes](https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes)
6. [https://pvigier.github.io/2018/02/09/dependency-graph.html](https://pvigier.github.io/2018/02/09/dependency-graph.html)
7. [https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c](https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c)
8. [https://www.geeksforgeeks.org/smart-pointers-cpp/](https://www.geeksforgeeks.org/smart-pointers-cpp/)
9. [https://medium.com/@victorgsampaio/entendendo-c-smart-pointers-d0ca51a87886](https://medium.com/@victorgsampaio/entendendo-c-smart-pointers-d0ca51a87886)
