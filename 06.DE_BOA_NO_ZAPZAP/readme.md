# De boa no ZapZap (VPL em construção)
A Rondolândia é uma nação idílica, governada por uma dinastia de capivaras fundada por Bacon - The Great, há várias gerações.

Em um certo momento passado, as capivaras perceberam que ideia do labor é uma furada, e decidiram criar a filosofia do ZapZap, que advoga pela manutenção da tranquilidade e que essa tranquilidade só pode ser alcançada fortalecendo as relações sociais. Assim, Torresmo IV, soberano da Rondolândia, teve a brilhante ideia de criar uma rede social chamada ZapZap, onde seus súditos pudessem praticar a filosofia do ZapZap sem sair de casa, o que aumentaria a paz no reino e permitiria Torresmo IV espionar todos os súditos do reino, prevenindo possíveis rebeliões e garantindo a permanência da dinastia por mais várias gerações. Uma ideia genial, não é mesmo ?!

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao emprego de smart pointers em C++ (homens de verdade usam /new/ e /delete/, mas ok, vocês precisam aprender isso).

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
- **void RegistrarMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para registrar uma nova mensagem no vetor de mensagens
- **void ExibirMensagens() const**: Método para exibir todas as mensagens registradas

### class Suditos
#### Atributos
- **std::string m_nome**: Nome do súdito
- **std::vector<std::unique_ptr<Suditos>> m_conexoes**: Vetor de smart pointers para armazenar as conexões do súdito
- **std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas**: Vetor de smart pointers para armazenar mensagens recebidas
    
#### Métodos
- **Suditos(std::string nome)**: Construtor que inicializa o nome do súdito
- **void AdicionarConexao(std::shared_ptr<Suditos> sudito)**: Método para adicionar uma nova conexão
- **void EnviarMensagem(std::shared_ptr<Suditos> destinatario, std::string conteudo, Soberano& soberano)**: Método para enviar uma mensagem pessoal para outra conexão
- **void PostarMensagem(std::string conteudo, Soberano& soberano)**: Método para postar uma mensagem para todas as conexões
- **void ReceberMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para receber uma mensagem

### class Mensagem
#### Atributos
- **std::string m_conteudo**: Conteúdo da mensagem
- **std::shared_ptr<Suditos> remetente**: Smart pointer para o remetente da mensagem

#### Métodos
- **Mensagem(std::string conteudo, std::shared_ptr<Suditos> remetente)**: Construtor que inicializa o conteúdo da mensagem e o remetente
- **std::string getConteudo() const**: Método para obter o conteúdo da mensagem
- **std::shared_ptr<Suditos> GetRemetente() const**: Método para obter o remetente da mensagem

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
