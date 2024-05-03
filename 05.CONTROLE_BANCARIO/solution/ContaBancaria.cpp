#include "ContaBancaria.hpp"

ContaBancaria::ContaBancaria(int id, std::string cliente){
    _id = id;
    _cliente = cliente;
    _saldo = 0;

}

void ContaBancaria::Deposito(float valor){
    _saldo += valor;
}

void ContaBancaria::Saque(float valor){
    _saldo -= valor;
}

void ContaBancaria::Pix(ContaBancaria *p, float valor){
    _saldo -= valor;
    p->_saldo += valor;
}

void ContaBancaria::imprime(){

    std::cout << _id <<" "<< _cliente <<" "<< std::fixed << std::setprecision(2) << _saldo << std::endl;

}
