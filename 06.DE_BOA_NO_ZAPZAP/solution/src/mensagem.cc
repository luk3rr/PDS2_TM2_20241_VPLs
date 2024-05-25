/*
 * Filename: mensagem.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "mensagem.h"

Mensagem::Mensagem(std::string             conteudo,
                   std::shared_ptr<Sudito> remetente,
                   std::string             destinatario)
{
    m_conteudo     = conteudo;
    m_remetente    = remetente;
    m_destinatario = destinatario;
}

std::string Mensagem::GetConteudo() const
{
    return m_conteudo;
}

std::shared_ptr<Sudito> Mensagem::GetRemetente() const
{
    return m_remetente;
}

std::string Mensagem::GetDestinatario() const
{
    return m_destinatario;
}
