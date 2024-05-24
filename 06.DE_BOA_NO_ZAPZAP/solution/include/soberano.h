/*
 * Filename: soberano.h
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef SOBERANO_H_
#define SOBERANO_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mensagem.h"

class Soberano
{
    public:
        Soberano(std::string nome);
        void RegistrarMensagem(std::shared_ptr<Mensagem> mensagem);
        void ExibirMensagens() const;

    private:
        std::string                            m_nome;
        std::vector<std::shared_ptr<Mensagem>> m_mensagens;
};

#endif // SOBERANO_H_
