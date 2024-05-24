/*
 * Filename: soberano.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "soberano.h"


Soberano::Soberano(std::string nome)
    : m_nome(nome)
{
    std::cout << "Soberano " << m_nome
              << " agora está farejando todas as mensagens do reino!" << std::endl;
}

void Soberano::RegistrarMensagem(std::shared_ptr<Mensagem> mensagem)
{
    m_mensagens.push_back(mensagem);
}

void Soberano::ExibirMensagens() const
{
    if (m_mensagens.empty())
    {
        std::cout << "Soberano: " << m_nome << std::endl;
        std::cout << "----------" << std::endl;
        std::cout << "Nenhuma mensagem encontrada." << std::endl;
        std::cout << "----------" << std::endl;
    }
    else
    {
        std::cout << "Soberano: " << m_nome << std::endl;
        std::cout << "----------" << std::endl;
        for (auto& mensagem : m_mensagens)
        {
            std::cout << "Remetente: " << mensagem->GetRemetente() << std::endl;
            std::cout << "Destinatário: " << mensagem->GetDestinatario() << std::endl;
            std::cout << "Conteúdo: " << mensagem->GetConteudo() << std::endl;
            std::cout << "----------" << std::endl;
        }
    }
}
