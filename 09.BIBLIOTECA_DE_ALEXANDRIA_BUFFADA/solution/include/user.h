/*
 * Filename: user.h
 * Created on: May 16, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef USER_H_
#define USER_H_

#include <cstddef>
#include <string>
#include <iostream>

class User
{
    private:
        std::string m_name;
        std::string m_email;
        std::string m_cpf;
        std::size_t m_id;

    public:
        User(std::size_t id, std::string name, std::string email, std::string cpf);
        ~User();

        std::string GetName() const;
        std::string GetEmail() const;
        std::string GetCPF() const;
        std::size_t GetID() const;

        void PrintInfo() const;
};

#endif // USER_H_
