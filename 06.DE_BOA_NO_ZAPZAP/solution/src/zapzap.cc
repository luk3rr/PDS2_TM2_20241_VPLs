/*
 * Filename: zapzap.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "zapzap.h"

ZapZap::ZapZap(std::string nomeSoberano)
    : m_soberano(nomeSoberano)
{ }

void ZapZap::CadastrarSudito(const std::string& nome)
{
    m_suditos[nome] = std::make_shared<Sudito>(nome);
}

void ZapZap::CriarConexao(const std::string& nome1, const std::string& nome2)
{
    m_suditos[nome1]->AdicionarConexao(m_suditos[nome2]);
    m_suditos[nome2]->AdicionarConexao(m_suditos[nome1]);
}

void ZapZap::EnviarMensagem(const std::string& nome1,
                            const std::string& nome2,
                            const std::string& conteudo)
{
    std::shared_ptr<Mensagem> mensagem =
        make_shared<Mensagem>(m_suditos[nome1], m_suditos[nome2], conteudo);

    m_soberano.RegistrarMensagem(mensagem);

    m_suditos[nome1]->EnviarMensagem(mensagem);
}

void ZapZap::PostarMensagem(const std::string& nome, const std::string& conteudo)
{
    m_soberano.
}

void ZapZap::ImprimirMensagensSúdito(const std::string& nome) const
{
    std::cout << "Súdito: " << nome << std::endl;
    std::cout << "----------" << std::endl;
    if (m_suditos.at(nome)->MensagensRecebidas().size() == 0)
    {
        std::cout << "Nenhuma mensagem encontrada." << std::endl;
        std::cout << "----------" << std::endl;
    }
    else
    {
        for (auto& mensagem : m_suditos.at(nome)->MensagensRecebidas())
        {
            std::cout << "Remetente: " << mensagem->Remetente()->Nome() << std::endl;
            std::cout << "Conteúdo: " << mensagem->Conteudo() << std::endl;
            std::cout << "----------" << std::endl;
        }
    }
}
