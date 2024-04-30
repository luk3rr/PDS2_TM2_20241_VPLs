#include "ola.hpp"
#include "ponto3d.hpp"
#include "aluno.hpp"
#include <iostream>

int main () {
  bool realidadeVirtual = true;
  while (realidadeVirtual){
    std::cout << "----------------------------------------------------------------" << endl;
    std::cout << "--    Bem vindo a nossa realidade virtual                     --" << endl;
    std::cout << "--    O que desejas?                                          --" << endl;
    std::cout << "--    1 - Criar o personagem                                  --" << endl;
    std::cout << "--    2 - Dar boas vindas                                     --" << endl;
    std::cout << "--    3 - Calcular o local da proxima missao                  --" << endl;
    std::cout << "--    0 - Voltar a realidade                                 --" << endl;
    std::cout << "----------------------------------------------------------------" << endl;
    int escolha;
    std::cin >> escolha;
    switch(escolha) {
      case 1:
        criaAlunoExemplo(); //Historia 03
        break;
      case 2:
        cumprimento(); //Historia 01
        break;
      case 3:
        calculaOrigemAoPontoUnico(5); //Historia 02
        break;
      case 0:
        realidadeVirtual = false; //Historia 02
        break;
      default:
        std::cout << "Alternativa inexistente!" << endl;
        break;
    }
  }
  return 0;
}
