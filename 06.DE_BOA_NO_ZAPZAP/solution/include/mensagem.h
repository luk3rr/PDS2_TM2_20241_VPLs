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

/**
 * @brief Classe que representa uma mensagem enviada por um Sudito
 **/
class Mensagem
{
    private:
        std::string             m_conteudo;
        std::string             m_destinatario;
        std::shared_ptr<Sudito> m_remetente;

    public:
        Mensagem(std::string             conteudo,
                 std::shared_ptr<Sudito> remetente,
                 std::string             destinatario);

        /**
         * @return Retorna o conteúdo da mensagem
         */
        std::string GetConteudo() const;

        /**
         * @return Retorna o destinatário da mensagem
         */
        std::string GetDestinatario() const;

        /**
         * @return Retorna o remetente da mensagem
         */
        std::shared_ptr<Sudito> GetRemetente() const;
};

#endif // MENSAGEM_H_
