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

class ZapZap
{
    public:
        ZapZap(std::string nomeSoberano);
        ~ZapZap();

        void CadastrarSudito(const std::string& nome);
        void CriarConexao(const std::string& nome1, const std::string& nome2);
        void EnviarMensagem(const std::string& nome1,
                            const std::string& nome2,
                            const std::string& conteudo);
        void PostarMensagem(const std::string& nome, const std::string& conteudo);
        void ImprimirMensagensSudito(const std::string& nome) const;
        void ImprimirTodasMensagens() const;

    private:
        Soberano                                                 m_soberano;
        std::unordered_map<std::string, std::shared_ptr<Sudito>> m_suditos;
};

#endif // ZAPZAP_H_
