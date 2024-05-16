/*
 * Filename: user.cc
 * Created on: May 16, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "user.h"

User::User(std::size_t id, std::string name, std::string email, std::string cpf)
{
    this->m_name  = name;
    this->m_email = email;
    this->m_cpf   = cpf;
    this->m_id    = id;
}

User::~User()
{
    std::cout << "Usuário " << this->m_id << " foi para o beleléu!" << std::endl;
}

std::string User::GetName() const
{
    return this->m_name;
}

std::string User::GetEmail() const
{
    return this->m_email;
}

std::string User::GetCPF() const
{
    return this->m_cpf;
}

std::size_t User::GetID() const
{
    return this->m_id;
}

void User::PrintInfo() const
{
    std::cout << "ID: " << this->m_id << std::endl;
    std::cout << "NAME: " << this->m_name << std::endl;
    std::cout << "EMAIL: " << this->m_email << std::endl;
    std::cout << "CPF: " << this->m_cpf << std::endl;
}
