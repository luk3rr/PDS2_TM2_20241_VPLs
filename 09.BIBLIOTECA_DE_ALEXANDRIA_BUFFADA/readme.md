# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e polimorfismo.

Esse VPL depende das implementações feitas no VPL 'Biblioteca de Alexandria'. Se você não as fez, seja um(a) bom(boa) garoto(a) e volte lá para fazê-las.

A nossa biblioteca de Alexandria era simples demais, por isso vamos buffar ela tentar deixar as coisas mais legais. Como um entusiasta da manutenção nos sistemas, você trabalhará na extensão do programa já implementado, adicionando uma classe que representará o usuário e integrar toda a lógica de empréstimos e devoluções com essa nova classe.

## O que você deve implementar
### class User
#### Atributos
- **m_name**, string: nome do usuário
- **m_email**, string: email do usuário
- **m_cpf**, string: cpf do usuário
- **m_id**, std::size_t: Da mesma forma que os IDs dos itens, esse ID deve ser um inteiro não negativo e sequencial, começando do zero.

#### Métodos
- **User(std::size_t id, std::string name, std::string email, std::string cpf)**: Construtor
- Destrutor
  - Deve imprimir a mensagem "Usuário ID foi para o beleléu!"
  - (Beleléu é um eufemismo, mas por algum motivo existe um [livro](https://www.amazon.com.br/Belel%C3%A9u-Patr%C3%ADcio-Dugnani/dp/8535631003) de capa engraçada com o mesmo nome)
- Métodos Get e Set
- **PrintInfo**: Método que deve imprimir as informações do usuário no seguinte formato
  - ID: x
  - NOME: x
  - EMAIL: x
  - CPF: x
  - (Considere que "x" é o valor armazenado na variável do dado em questão)

### class Item, CD, Library, Periodic, Book
As classes implementadas no último VPL devem ser mantidas. A única classe que necessita de alterações será a Library, então se você está mudando alguma coisas nas outras classes você com certeza não está seguindo o caminho das pedras ._.

Atributos que você deve adicionar em Library:
- Crie um vector de **ponteiros** para objetos do tipo **User**.
- Precisamos de um registro de empréstimos, de forma que seja possível armazenar os histórico de empréstimos, seja de itens já devolvidos ou não.
  - Existem $n$ formas de fazer isso, algumas mais fáceis que outras. Pense um pouco, mas como você provavelmente ainda é juninho na programação, se não tiver criatividade suficiente [pegue na mão do monitor que ele lhe mostrará um caminho](https://github.com/luk3rr/aaaaaaaaah/blob/main/SOCORRO/historico_de_emprestimos.cc).

Métodos que você deve adicionar ou alterar em Library:
- Assim como fez com Item, crie um método para procurar um User pelo ID.
- A assinatura dos métodos Reserve e Release precisa ser alterada, conforme abaixo:
  - **void Reserve(std::size_t item_id, std::size_t user_id);**
  - **void Reserve(std::string item_title, std::size_t user_id);**
  - **void Release(std::size_t item_id, std::size_t user_id);**
  - Para que a saída do seu programa seja condizente com o que é esperado nos casos de teste, você deve:
    - Procurar um **item** e caso não o encontre imprima a mensagem "Item ID não encontrado o.O" (você já faz isso no VPL anterior) e termine a função (veja o link 1).
    - Caso o item exista, procure pelo usuário. Se não encontrá-lo, imprima "Usuário ID não encontrado o.O" e termine a função.
    - Se o item e o usuário foram encontrados, então implemente a lógica da reserva ou devolução.
      - A lógica de reserva usa a função **Reserve** da classe **Item**. Lembra quando eu disse que você só alteraria a classe Library, então, [eu menti](https://pbs.twimg.com/media/FYDl1MlX0AEvcIm?format=png&name=900x900). A solução fica mais fácil se Item::Reserve retornar um booleano que indica que o item pode ser reservado ou não. As mensagens que Item::Reserve já mostra devem ser mantidas e devem ser impressas antes das mensagens citadas abaixo:
        - Se o item for reservado com sucesso, então mostre a mensagem "Usuário NOME\_USUARIO reservou o item TITULO\_ITEM com sucesso!"
      - A lógica de devolução usa a função **Release** da classe **Item**, mas também depende de se o usuário realmente tem uma reserva daquele item e se a devolução dessa reserva ainda está pendente. As mensagem que Item::Release já mostra devem ser mantidas e devem ser impressas antes das mensagens citadas abaixo:
        - Se a devolução for feita com sucesso, então imprima "Usuário NOME\_USUARIO devolveu o item TITULO\_ITEM" com sucesso!
        - Se não, imprima "Usuário NOME\_USUARIO não reservou o item TITULO\_ITEM o.O"
- Crie o método **AddUser(nome, email, cpf)**
- Crie um método chamado **PrintUsers** para mostrar as informações de todos os usuários registrados
  - Se não existe usuário cadastrado, imprima apenas "Não há usuários cadastrados. Acho que estão todos no TikTok -.-"
  - Se não, imprima as informações de cada usuário no seguinte formato:
    - \----------
    - (Infos do usuário 0)
    - \----------
    - (etc etc)
    - \----------
- Crie um método chamado **PrintReservations** para mostrar todo o histórico de empréstimos
  - Se não existe reservas no histórico, imprima apenas "Não há reservas no momento. Hoje em dia as pessoas so'pensam em TikTok -.-"
  - Se não, imprima as informações de cada reserva:
    - \----------
    - Item: x
    - Usuário: x
    - Status: (O status da reserva pode ser 'Devolvido' [XOR](https://en.wikipedia.org/wiki/Exclusive_or) 'Reservado')
    - \----------
    - (etc etc)
    - \----------
- Por último, mas mais **importante** que tudo: se você criou os **users** no heap, não maltrate o servidor do VPL e libere a memória.
  - Atualmente o seu destrutor já apaga os **itens** que foram criados. Logo abaixo, apague os **usuários** e por último imprima a mensagem "Bye!".

Considere que a impressão das informações dos usuários e reservas serão feitas na ordem em que elas foram cadastradas no sistema.

OBS.: Um usuário certamente pode reserva mais de uma cópia de um mesmo item. O que provocará várias entradas iguais no histórico. Você deve realizar a devolução para o primeiro item não devolvido encontrado no histórico.

### Freedom
Como ainda vivemos em um país livre, você pode adicionar novos atributos às classes, ou implementar outros métodos ou classes que achar necessário para a sua solução. Além disso, você não precisa seguir a nomenclatura de atributos, métodos e classes utilizada. Você poderia, por exemplo, colocar tudo em português, mas o seu programa deve implementar a lógica e comportamento solicitados.

### Main
Por fim, você deve implementar o **main.cpp** do seu programa e toda a lógica de entrada/saída que será responsável por manipular os seguintes comandos:
- a l 'copies pages title author isbn date genre publisher': Comando para adicionar (**a**) um livro (**l**)
- a j 'copies volume number title date editor topics': Comando para adicionar (**a**) um jornal (**j**) (é um periódico)
- a r 'copies volume number title date editor topics': Comando para adicionar (**a**) uma revista (**r**) (é um periódico)
- a c 'copies tracks duration title artist date': Comando para adicionar (**a**) um CD
- a u 'name email cpf': Comando para adicionar (**a**) um usuário (**u**)
- r t 'title userID': Comando para reservar (**r**) um item buscando-o pelo título (**t**) para um usuário com determinado ID
- r i 'itemID userID': Comando para reservar (**r**) um item buscando-o pelo ID (**i**) para um usuário com determinado ID
- d 'itemID userID': Comando para devolver (**d**) um item. Diferentemente da reserva, a devolução só é possível indicando o ID do item e o ID do usuário que fez a reserva.
- s c: Imprime o catalogo da biblioteca
- s u: Imprime as informações de todos os usuários cadastrados
- s r: Imprime as informações de todas as reservas registradas

O último comando da sua função main antes do 'return 0;' deve ser 'std::cout << "Fim da execução" << std::endl;'.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e acessados somente através de métodos Get e Set. Se você perceber que algum método Get ou Set não é utilizado pelo seu programa, então você não precisa implementá-lo.
2. Você deve fazer todas as heranças e sobrescrita de métodos solicitadas.
3. Respeita o formato das mensagens que são impressas. O moodle verifica se seu programa funciona corretamente comparando a sua saída com a esperada para cada caso de teste. Se houver alguma coisa fora de lugar, os testes vão falhar.
4. Separe cada especificação (hpp) de sua respectiva implementação (cpp). Não implemente tudo em um único arquivo. Seja organizado.

# Exemplos de entrada e saída
## Exemplo 1
**input**\
a l 5 300 DomCasmurro MachadoDeAssis 9788532803186 01/01/1899 Romance EditoraNovaFronteira\
a u Lucaaassss alo@lucas.me 0111001001100101011000010110110001101101011001010110111001110100011001010010000001110110011000110010000011000011101010010010000001100011011101010111001001101001011011110111001101101111\
a j 3 10 5 FolhaDeSãoPaulo 01/05/2019 FolhaDeSãoPaulo Política,Economia,Esportes\
a r 2 7 12 Veja 15/04/2024 EditoraAbril Política,Cultura,Tecnologia\
a u voceeeeeee alo@vc.me 011011010111010101101001011101000110111101101111001000000110001101110101011100100110100101101111011100110110111100100000011011010111001101101101\
a u outrapessoa alo@op.me 011011100010000001100011011000010111001001100001001000000110010101110101001000000110111000100000011000110110111101101100011011110111000101110101011001010110100100100000011101010110110100100000011000110111000001100110001000000110010101101101001000000110001001101001011011100110000101110010011010010110111100100000001001110010110100100111\
a c 4 12 8230 RaçaNegra-AoVivo RaçaNegra 20/03/2024\
s r\
r t DomCasmurro 0\
r i 1 10\
r i 1 0\
r i 1 1\
r i 1 2\
r i 1 0\
r i 1 0\
d 2 0\
d 2 1\
d 2 0\
d 3 1\
d 1 3\
r t DomCasmurro 99\
d 1 2\
d 0 0\
s c\
s u\
s r

**output**\
Não há reservas no momento. Hoje em dia as pessoas só pensam em TikTok -.-\
Item 0 reservado com sucesso :)\
Usuário Lucaaassss reservou o item DomCasmurro com sucesso!\
Usuário 10 não encontrado o.O\
Item 1 reservado com sucesso :)\
Usuário Lucaaassss reservou o item FolhaDeSãoPaulo com sucesso!\
Item 1 reservado com sucesso :)\
Usuário voceeeeeee reservou o item FolhaDeSãoPaulo com sucesso!\
Item 1 reservado com sucesso :)\
Usuário outrapessoa reservou o item FolhaDeSãoPaulo com sucesso!\
Item 1 não disponível para empréstimo :(\
Item 1 não disponível para empréstimo :(\
Usuário Lucaaassss não reservou o item Veja o.O\
Usuário voceeeeeee não reservou o item Veja o.O\
Usuário Lucaaassss não reservou o item Veja o.O\
Usuário voceeeeeee não reservou o item RaçaNegra-AoVivo o.O\
Usuário 3 não encontrado o.O\
Usuário 99 não encontrado o.O\
Item 1 recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)\
Usuário outrapessoa devolveu o item FolhaDeSãoPaulo com sucesso!\
Item 0 recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)\
Usuário Lucaaassss devolveu o item DomCasmurro com sucesso!\
\\----------\
ITEM: Livro\
ID: 0\
TÍTULO: DomCasmurro\
AUTOR(A): MachadoDeAssis\
EDITORA: EditoraNovaFronteira\
GÊNERO: Romance\
NÚMERO DE PÁGINAS: 300\
ISBN: 9788532803186\
DATA: 01/01/1899\
CÓPIAS DISPONÍVEIS: 5\
CÓPIAS RESERVADAS: 0\
\\----------\
ITEM: Jornal\
ID: 1\
TÍTULO: FolhaDeSãoPaulo\
EDITORA: FolhaDeSãoPaulo\
TÓPICOS: Política,Economia,Esportes\
DATA: 01/05/2019\
CÓPIAS DISPONÍVEIS: 1\
CÓPIAS RESERVADAS: 2\
\\----------\
ITEM: Revista\
ID: 2\
TÍTULO: Veja\
EDITORA: EditoraAbril\
TÓPICOS: Política,Cultura,Tecnologia\
DATA: 15/04/2024\
CÓPIAS DISPONÍVEIS: 2\
CÓPIAS RESERVADAS: 0\
\----------\
ITEM: CD\
ID: 3\
TÍTULO: RaçaNegra-AoVivo\
ARTISTA: RaçaNegra\
FAIXAS: 12\
DURAÇÃO: 02:17:10\
DATA: 20/03/2024\
CÓPIAS DISPONÍVEIS: 4\
CÓPIAS RESERVADAS: 0\
\----------\
\----------\
ID: 0\
NOME: Lucaaassss\
EMAIL: alo@lucas.me\
CPF: 0111001001100101011000010110110001101101011001010110111001110100011001010010000001110110011000110010000011000011101010010010000001100011011101010111001001101001011011110111001101101111\
\----------\
ID: 1\
NOME: voceeeeeee\
EMAIL: alo@vc.me\
CPF: 011011010111010101101001011101000110111101101111001000000110001101110101011100100110100101101111011100110110111100100000011011010111001101101101\
\----------\
ID: 2\
NOME: outrapessoa\
EMAIL: alo@op.me\
CPF: 011011100010000001100011011000010111001001100001001000000110010101110101001000000110111000100000011000110110111101101100011011110111000101110101011001010110100100100000011101010110110100100000011000110111000001100110001000000110010101101101001000000110001001101001011011100110000101110010011010010110111100100000001001110010110100100111\
\----------\
\----------\
Item: DomCasmurro\
Usuário: Lucaaassss\
Status: Devolvido\
\----------\
Item: FolhaDeSãoPaulo\
Usuário: Lucaaassss\
Status: Reservado\
\----------\
Item: FolhaDeSãoPaulo\
Usuário: voceeeeeee\
Status: Reservado\
\----------\
Item: FolhaDeSãoPaulo\
Usuário: outrapessoa\
Status: Devolvido\
\----------\
Fim da execução\
Livro 0 diz: Leia-me amanhã!\
Item 0 liberado da memória!\
Jornal 1 diz: Leia-me amanhã!\
Item 1 liberado da memória!\
Revista 2 diz: Leia-me amanhã!\
Item 2 liberado da memória!\
CD 3 diz: Ouça-me amanhã!\
Item 3 liberado da memória!\
Usuário 0 foi para o beleléu!\
Usuário 1 foi para o beleléu!\
Usuário 2 foi para o beleléu!\
Bye!

# Links não tão inúteis
1. [https://stackoverflow.com/questions/346613/how-do-you-exit-from-a-void-function-in-c](https://stackoverflow.com/questions/346613/how-do-you-exit-from-a-void-function-in-c)
2. [https://cplusplus.com/reference/utility/pair/pair/](https://cplusplus.com/reference/utility/pair/pair/)
