/*
 * Filename: sudito.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "sudito.h"
#include "mensagem.h"
#include <memory>

Sudito::Sudito(std::string nome)
    : m_nome(nome)
{ }

bool Sudito::VerificarConexao(std::shared_ptr<Sudito> outro)
{
    for (auto& conexao : m_conexoes)
    {
        if (conexao == outro)
        {
            return true;
        }
    }
    return false;
}

std::string Sudito::GetNome()
{
    return m_nome;
}

std::vector<std::shared_ptr<Mensagem>> Sudito::GetMensagensRecebidas()
{
    return m_mensagensRecebidas;
}

std::vector<std::shared_ptr<Mensagem>> Sudito::GetMensagensEnviadas()
{
    return m_mensagensEnviadas;
}

std::vector<std::shared_ptr<Sudito>> Sudito::GetConexoes()
{
    return m_conexoes;
}

void Sudito::AdicionarConexao(std::shared_ptr<Sudito> novaConexao)
{
    this->m_conexoes.push_back(novaConexao);
    std::cout << "Súdito " << m_nome << " adicionou " << novaConexao->GetNome()
              << " como conexão!" << std::endl;
}

void Sudito::EnviarMensagem(std::shared_ptr<Mensagem> msg, std::shared_ptr<Sudito> dest)
{
    if (VerificarConexao(dest))
    {
        std::cout << "Súdito " << m_nome << " enviando nova mensagem para "
                  << dest->GetNome() << std::endl;

        dest->ReceberMensagem(msg);
        m_mensagensEnviadas.push_back(msg);
    }
    else
    {
        std::cout << "Súdito " << m_nome << " não pode enviar mensagem para "
                  << dest->GetNome() << " pois não são conexões!" << std::endl;
    }
}

void Sudito::PostarMensagem(std::shared_ptr<Mensagem> mensagem)
{
    std::cout << "Súdito " << m_nome << " postou uma nova mensagem!" << std::endl;

    for (auto& conexao : m_conexoes)
    {
        conexao->ReceberMensagem(mensagem);
    }
}

void Sudito::ReceberMensagem(std::shared_ptr<Mensagem> mensagem)
{
    m_mensagensRecebidas.push_back(mensagem);

    std::cout << "Súdito " << m_nome << " recebeu uma nova mensagem de "
              << mensagem->GetRemetente()->GetNome() << std::endl;
}

void Sudito::ExibirMensagensEnviadas()
{
    if (m_mensagensEnviadas.empty())
    {
        std::cout << "----------" << std::endl;
        std::cout << "Nenhuma mensagem enviada por " << m_nome << std::endl;
        std::cout << "----------" << std::endl;
        return;
    }

    std::cout << "----------" << std::endl;
    std::cout << "Mensagens enviadas por " << m_nome << ":" << std::endl;
    for (auto& msg : m_mensagensEnviadas)
    {
        std::cout << "----------" << std::endl;
        std::cout << "Destinatário: " << msg->GetDestinatario() << std::endl;
        std::cout << "Conteúdo: " << msg->GetConteudo() << std::endl;
        std::cout << "----------" << std::endl;
    }
}

void Sudito::ExibirMensagensRecebidas()
{
    if (m_mensagensRecebidas.empty())
    {
        std::cout << "----------" << std::endl;
        std::cout << "Nenhuma mensagem recebida por " << m_nome << std::endl;
        std::cout << "----------" << std::endl;
        return;
    }

    std::cout << "----------" << std::endl;
    std::cout << "Mensagens recebidas por " << m_nome << ":" << std::endl;
    for (auto& msg : m_mensagensRecebidas)
    {
        std::cout << "----------" << std::endl;
        std::cout << "Remetente: " << msg->GetRemetente()->GetNome() << std::endl;
        std::cout << "Conteúdo: " << msg->GetConteudo() << std::endl;
    }
    std::cout << "----------" << std::endl;
}
