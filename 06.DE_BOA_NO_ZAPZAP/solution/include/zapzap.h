/*
 * Filename: zapzap.h
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef ZAPZAP_H_
#define ZAPZAP_H_

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "mensagem.h"
#include "soberano.h"
#include "sudito.h"

/**
 * @brief Classe que representa o ZapZap, a rede social de mensagens instantâneas
 **/
class ZapZap
{
    private:
        Soberano                                                 m_soberano;
        std::unordered_map<std::string, std::shared_ptr<Sudito>> m_suditos;

        /**
         * @brief Verifica se um sudito existe na rede social
         * @param nome Nome do sudito
         * @return true se o sudito existe, false caso contrário
         **/
        bool ExisteSudito(const std::string& nome) const;

    public:
        ZapZap(std::string nomeSoberano);
        ~ZapZap();

        /**
         * @brief Cadastra um novo sudito na rede social
         * @param nome Nome do novo sudito
         **/
        void CadastrarSudito(const std::string& nome);

        /**
         * @brief Cria uma conexão entre dois suditos
         * @param nome1 Nome do primeiro sudito
         * @param nome2 Nome do segundo sudito
         **/
        void CriarConexao(const std::string& nome1, const std::string& nome2);

        /**
         * @brief Envia uma mensagem de um sudito para outro
         * @param nome1 Nome do sudito que está enviando a mensagem
         * @param nome2 Nome do sudito que está recebendo a mensagem
         * @param conteudo Conteúdo da mensagem
         **/
        void EnviarMensagem(const std::string& nome1,
                            const std::string& nome2,
                            const std::string& conteudo);

        /**
         * @brief Posta uma mensagem na rede social
         * @param nome Nome do sudito que está postando a mensagem
         * @param conteudo Conteúdo da mensagem
         **/
        void PostarMensagem(const std::string& nome, const std::string& conteudo);

        /**
         * @brief Imprime todas as mensagens capturadas pelo soberano
         **/
        void ImprimirTodasMensagens() const;

        /**
         * @brief Imprime todas as mensagens enviadas por um sudito
         * @param nomeSudito Nome do sudito
         **/
        void ImprimirMensagensEnviadas(const std::string& nomeSudito) const;

        /**
         * @brief Imprime todas as mensagens recebidas por um sudito
         * @param nomeSudito Nome do sudito
         **/
        void ImprimirMensagensRecebidas(const std::string& nomeSudito) const;

};

#endif // ZAPZAP_H_
