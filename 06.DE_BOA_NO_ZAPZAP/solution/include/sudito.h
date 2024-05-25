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

/**
 * Classe que representa uma mensagem
 * Forward declaration devido ao problema de dependência cíclica
 */
class Mensagem;

/**
 * Classe que representa um Sudito
 */
class Sudito
{
    private:
        std::string                            m_nome;
        std::vector<std::shared_ptr<Sudito>>   m_conexoes;
        std::vector<std::shared_ptr<Mensagem>> m_mensagensRecebidas;
        std::vector<std::shared_ptr<Mensagem>> m_mensagensEnviadas;

        /**
         * @brief Verifica se um Sudito é uma conexão
         * @param sudito Ponteiro para o Sudito que será verificado
         * @return true se o Sudito é uma conexão, false caso contrário
         */
        bool VerificarConexao(std::shared_ptr<Sudito> sudito);

    public:
        Sudito(std::string nome);

        /**
         * @return Nome do Sudito
         */
        std::string GetNome();

        /**
         * @return Mensagens recebidas pelo Sudito
         */
        std::vector<std::shared_ptr<Mensagem>> GetMensagensRecebidas();

        /**
         * @return Mensagens enviadas pelo Sudito
         */
        std::vector<std::shared_ptr<Mensagem>> GetMensagensEnviadas();

        /**
         * @return Conexões do Sudito
         */
        std::vector<std::shared_ptr<Sudito>> GetConexoes();

        /**
         * @brief Adiciona uma nova conexão ao Sudito
         * @param novaConexao Ponteiro para o Sudito que será adicionado como conexão
         */
        void AdicionarConexao(std::shared_ptr<Sudito> novaConexao);

        /**
         * @brief Envia uma mensagem para um Sudito
         * @param msg Mensagem que será enviada
         * @param destinatario Ponteiro para o Sudito que receberá a mensagem
         */
        void EnviarMensagem(std::shared_ptr<Mensagem> msg,
                            std::shared_ptr<Sudito>   destinatario);

        /**
         * @brief Posta uma mensagem no mural do Sudito
         * @param msg Mensagem que será postada
         */
        void PostarMensagem(std::shared_ptr<Mensagem> msg);

        /**
         * @brief Recebe uma mensagem de outro Sudito
         * @param mensagem Mensagem que foi enviada
         */
        void ReceberMensagem(std::shared_ptr<Mensagem> mensagem);

        /**
         * @brief Exibe as mensagens enviadas pelo Sudito
         */
        void ExibirMensagensEnviadas();

        /**
         * @brief Exibe as mensagens recebidas pelo Sudito
         */
        void ExibirMensagensRecebidas();
};

#endif // SUDITO_H_
