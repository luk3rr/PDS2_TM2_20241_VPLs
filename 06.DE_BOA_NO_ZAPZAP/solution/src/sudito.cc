/*
 * Filename: sudito.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "sudito.h"

/*
*### class Sudito
#### Atributos
- **std::string m_nome**: Nome do súdito
- **std::vector<std::unique_ptr<Sudito>> m_conexoes**: Vetor de smart pointers para
armazenar as conexões do súdito
- **std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas**: Vetor de smart
pointers para armazenar mensagens recebidas

#### Métodos
- **Suditos(std::string nome)**: Construtor que inicializa o nome do súdito
- **void AdicionarConexao(std::shared_ptr<Sudito> novaConexao)**: Método para adicionar
uma nova conexão
  - Deve imprimir a mensagem "Súdito <NOME> adicionou <NOME\_NOVA\_CONEXAO> como
conexão!"
- **void EnviarMensagem(std::shared_ptr<Sudito> destinatario, std::string conteudo,
Soberano& soberano)**: Método para enviar uma mensagem pessoal para outra conexão
  - Deve imprimir "Súdito <NOME> enviando nova mensagem para <NOME_DESTINATARIO>"
- **void PostarMensagem(std::string conteudo, Soberano& soberano)**: Método para postar
uma mensagem para todas as conexões
  - Deve imprimir "Súdito <NOME> postou uma nova mensagem!"
- **void ReceberMensagem(std::shared_ptr<Mensagem> mensagem)**: Método para receber uma
mensagem
  - Deve imprimir "Súdito <NOME> recebeu uma nova mensagem!"
* */

Sudito::Sudito(std::string nome)
    : m_nome(nome)
{ }

void Sudito::AdicionarConexao(std::shared_ptr<Sudito> novaConexao)
{
    m_conexoes.push_back(novaConexao);
    std::cout << "Súdito " << m_nome << " adicionou " << novaConexao->m_nome
              << " como conexão!" << std::endl;
}

void Sudito::EnviarMensagem(std::shared_ptr<Sudito> destinatario,
                            std::string             conteudo,
                            Soberano&               soberano)
{
    std::cout << "Súdito " << m_nome << " enviando nova mensagem para "
              << destinatario->m_nome << std::endl;
    std::shared_ptr<Mensagem> mensagem =
        std::make_shared<Mensagem>(m_nome, destinatario->m_nome, conteudo);
    destinatario->ReceberMensagem(mensagem);
    soberano.ReceberMensagem(mensagem);
}

void Sudito::PostarMensagem(std::string conteudo, Soberano& soberano)
{
    std::cout << "Súdito " << m_nome << " postou uma nova mensagem!" << std::endl;
    std::shared_ptr<Mensagem> mensagem =
        std::make_shared<Mensagem>(m_nome, "Todos", conteudo);
    for (auto& conexao : m_conexoes)
    {
        conexao->ReceberMensagem(mensagem);
    }
    soberano.ReceberMensagem(mensagem);
}

void Sudito::ReceberMensagem(std::shared_ptr<Mensagem> mensagem)
{
    m_mensagensRecebidas.push_back(mensagem);
    std::cout << "Súdito " << m_nome << " recebeu uma nova mensagem!" << std::endl;
}
