#include "ContaBancaria.hpp"
#include "Banco.hpp"


int main(){

    char op;
    int id;
    int iddest;
    float valor;
    std::string nome;

    Banco q;

    ContaBancaria *cb;
    ContaBancaria *dt;


    while (1){

        std::cin >> op;

        if(op == 'T'){
            break;
        }

        if(op == 'C'){

            std::cin >> id;
            std::cin >> nome;
            cb = q.CriaConta(id, nome);

        }

        if( op == 'D'){

            std::cin >> id;

            std::cin >> valor;

            cb = q.Pesquisa(id);


            if(cb == nullptr){

                std::cout << "ERRO: conta inexistente" << std::endl;

            }else{
                cb->Deposito(valor);

                std::cout << "deposito efetuado" << std::endl;
            }
        }

        if( op == 'S'){

            std::cin >> id;
            std::cin >> valor;

            cb = q.Pesquisa(id);

            if(cb == nullptr){

                std::cout << "ERRO: conta inexistente" << std::endl;

            }else{
                cb->Saque(valor);
                std::cout << "saque efetuado" << std::endl;
            }
        }


        if(op == 'P'){

            std::cin >>id;
            std::cin >> iddest;
            std::cin >> valor;

            cb = q.Pesquisa(id);

            dt = q.Pesquisa(iddest);


            if(cb == nullptr || dt == nullptr){
                std::cout << "ERRO: conta inexistente" << std::endl;
            }else{

                cb->Pix(dt, valor);
                std::cout << "pix efetuado" << std::endl;
            }
        }

        if( op == 'I'){

            q.ListaContas();

        }

    }



    return 0;
}
