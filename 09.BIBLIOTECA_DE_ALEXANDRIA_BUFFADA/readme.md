# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento, herança, composição e polimorfismo.

Esse VPL depende das implementações feitas no VPL 'Biblioteca de Alexandria'. Se você não as fez, seja um(a) bom(boa) garoto(a) e volte lá para fazê-las.

A nossa biblioteca de Alexandria era simples demais, por isso vamos tentar deixar as coisas mais legais. Como um entusiasta da manutenção nos sistemas, você trabalhará na extensão do programa já implementado, adicionando uma classe que representará o usuário e integrar toda a lógica de empréstimos e devoluções com essa nova classe.

## O que você deve implementar
### class User
#### Atributos
- **m_name**, string: nome do usuário
- **m_email**, string: email do usuário
- **m_cpf**, string: cpf do usuário
- **m_id**, std::size_t: Da mesma forma que os IDs dos itens, esse ID deve ser um inteiro não negativo e sequencial, começando do zero.

#### Métodos
- **User(std::size_t id, std::string name, std::string email, std::string cpf)**: Construtor
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
  - Existem n formas de fazer isso, algumas mais fáceis que outras. Pense um pouco, mas como você provavelmente ainda é juninho na programação, se não tiver criatividade suficiente [pegue na mão do monitor que ele lhe mostrará um caminho](https://github.com/luk3rr/aaaaaaaaah/blob/main/SOCORRO/historico_de_emprestimos.cc).
- Assim como fez com Item, crie um método para procurar um User pelo ID.
- A assinatura dos métodos Reserve e Release precisa ser alterada, conforme abaixo:
  - **void Reserve(std::size_t item_id, std::size_t user_id);**
  - **void Reserve(std::string item_title, std::size_t user_id);**
  - **void Release(std::size_t item_id, std::size_t user_id);**
- Baseado nessa nova assinatura, a lógica da reserva e a devolução de um ID precisa considerar também o usuário.

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
1. [https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria](https://pt.wikipedia.org/wiki/Biblioteca_de_Alexandria)
2. [https://cplusplus.com/reference/utility/pair/pair/](https://cplusplus.com/reference/utility/pair/pair/)
3. [https://pt.wikipedia.org/wiki/Sobrecarga_de_fun%C3%A7%C3%A3o](https://pt.wikipedia.org/wiki/Sobrecarga_de_fun%C3%A7%C3%A3o)
4. [https://terminalroot.com.br/2021/06/o-que-significa-override-em-cpp.html](https://terminalroot.com.br/2021/06/o-que-significa-override-em-cpp.html)
5. [https://stackoverflow.com/questions/13340891/how-can-i-use-setfill-properly-in-c](https://stackoverflow.com/questions/13340891/how-can-i-use-setfill-properly-in-c)
6. [https://youtu.be/TjnE1gV42Jw?si=-3c5ry2juOWQNWaB](https://youtu.be/TjnE1gV42Jw?si=-3c5ry2juOWQNWaB)
