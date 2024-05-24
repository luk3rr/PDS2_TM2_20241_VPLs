/*
 * Filename: sudito.h
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef SUDITO_H_
#define SUDITO_H_

#include <iostream>
#include <memory>
#include <vector>

class Mensagem;
class Soberano;

class Sudito
{
    public:
        Sudito(std::string nome);
        void AdicionarConexao(std::shared_ptr<Sudito> novaConexao);
        void EnviarMensagem(std::shared_ptr<Mensagem> msg);
        void PostarMensagem(std::shared_ptr<Mensagem> msg);
        void ReceberMensagem(std::shared_ptr<Mensagem> mensagem);

    private:
        std::string                            m_nome;
        std::vector<std::shared_ptr<Sudito>>   m_conexoes;
        std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas;
};

#endif // SUDITO_H_
