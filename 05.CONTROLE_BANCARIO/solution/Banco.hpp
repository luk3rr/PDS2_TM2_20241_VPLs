
#ifndef BANCO_H
#define BANCO_H
#include "ContaBancaria.hpp"

struct Banco {
    int _qtdc = 0;

    ContaBancaria* p[20];

    Banco();

    ContaBancaria* CriaConta(int, std::string);
    ContaBancaria* Pesquisa(int);
    void ListaContas();

};

#endif
