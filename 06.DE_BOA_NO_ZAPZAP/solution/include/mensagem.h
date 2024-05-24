/*
 * Filename: mensagem.h
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef MENSAGEM_H_
#define MENSAGEM_H_

#include "sudito.h"
#include <memory>
#include <string>

class Mensagem
{
    public:
        Mensagem(std::string             conteudo,
                 std::shared_ptr<Sudito> remetente,
                 std::shared_ptr<Sudito> destinatario);

        std::string             GetConteudo() const;
        std::shared_ptr<Sudito> GetRemetente() const;
        std::shared_ptr<Sudito> GetDestinatario() const;

    private:
        std::string             m_conteudo;
        std::shared_ptr<Sudito> m_remetente;
        std::shared_ptr<Sudito> m_destinatario;
};

#endif // MENSAGEM_H_
