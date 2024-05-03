#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
#include <iomanip>
#include <iostream>

struct ContaBancaria {
    int _id;
    std::string _cliente;
    float _saldo;

    ContaBancaria(int, std::string);

    void Deposito (float);
    void Saque (float);
    void Pix (ContaBancaria *p, float _valor);

    void imprime();



};

#endif
