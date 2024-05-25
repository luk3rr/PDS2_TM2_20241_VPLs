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

/**
 * Classe que representa um soberano.
 **/
class Soberano
{
    private:
        std::string                            m_nome;
        std::vector<std::shared_ptr<Mensagem>> m_mensagens;

    public:
        Soberano(std::string nome);

        /**
         * @return Nome do soberano
         */
        std::string GetNome() const;

        /**
         * @return Vector com todas as mensagens capturadas pelo soberano
         */
        std::vector<std::shared_ptr<Mensagem>> GetMensagens() const;

        /**
         * @brief Registra uma mensagem no histórico do soberano
         */
        void RegistrarMensagem(std::shared_ptr<Mensagem> mensagem);

        /**
         * @brief Exibe todas as mensagens capturadas pelo soberano
         */
        void ExibirMensagens() const;
};

#endif // SOBERANO_H_
