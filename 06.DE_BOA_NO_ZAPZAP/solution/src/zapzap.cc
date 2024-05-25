/*
 * Filename: zapzap.cc
 * Created on: May 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "zapzap.h"

ZapZap::ZapZap(std::string nomeSoberano)
    : m_soberano(nomeSoberano)
{ }

ZapZap::~ZapZap()
{ }

bool ZapZap::ExisteSudito(const std::string& nome) const
{
    return m_suditos.find(nome) != m_suditos.end();
}

void ZapZap::CadastrarSudito(const std::string& nome)
{
    m_suditos[nome] = std::make_shared<Sudito>(nome);
}

void ZapZap::CriarConexao(const std::string& nome1, const std::string& nome2)
{
    m_suditos[nome1]->AdicionarConexao(m_suditos[nome2]);
    m_suditos[nome2]->AdicionarConexao(m_suditos[nome1]);
}

void ZapZap::EnviarMensagem(const std::string& nome1,
                            const std::string& nome2,
                            const std::string& conteudo)
{
    std::shared_ptr<Mensagem> mensagem =
        make_shared<Mensagem>(conteudo, m_suditos[nome1], m_suditos[nome2]->GetNome());

    m_suditos[nome1]->EnviarMensagem(mensagem, m_suditos[nome2]);
    m_soberano.RegistrarMensagem(mensagem);
}

void ZapZap::PostarMensagem(const std::string& nome, const std::string& conteudo)
{
    std::shared_ptr<Mensagem> mensagem =
        make_shared<Mensagem>(conteudo, m_suditos[nome], "Conexões");

    m_suditos[nome]->PostarMensagem(mensagem);
    m_soberano.RegistrarMensagem(mensagem);
}

void ZapZap::ImprimirTodasMensagens() const
{
    m_soberano.ExibirMensagens();
}

void ZapZap::ImprimirMensagensEnviadas(const std::string& nomeSudito) const
{
    m_suditos.at(nomeSudito)->ExibirMensagensEnviadas();
}

void ZapZap::ImprimirMensagensRecebidas(const std::string& nomeSudito) const
{
    m_suditos.at(nomeSudito)->ExibirMensagensRecebidas();
}
