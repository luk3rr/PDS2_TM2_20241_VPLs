#include "Banco.hpp"

Banco::Banco(){
    _qtdc = 0;

    for(int i = 0; i < 20; i++){
        p[i] = nullptr;
    }
}


ContaBancaria* Banco::CriaConta(int id, std::string nome){

    for(int i = 0; i < _qtdc; i++){

        if(p[i]->_id == id){

            std::cout << "ERRO: conta repetida" << std::endl;

            return nullptr;
        }
    }

    p[_qtdc] = new ContaBancaria(id, nome);

    _qtdc += 1;

    std::cout << "conta criada" <<std::endl;

    return p[_qtdc];

}

ContaBancaria* Banco::Pesquisa(int id){

    for(int i = 0; i < _qtdc; i++){

        if(p[i]->_id == id){
            return p[i];
        }
    }

    return nullptr;

}

void Banco::ListaContas(){
    for(int i = 0; i < _qtdc; i++){

        std::cout << p[i]-> _id << " " << p[i]->_cliente << " " << std::fixed << std::setprecision(2) << p[i] -> _saldo << std::endl;

    }
}
