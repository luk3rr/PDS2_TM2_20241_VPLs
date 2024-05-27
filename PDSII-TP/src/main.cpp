#include "ola.hpp"
#include "ponto3d.hpp"
#include "aluno.hpp"
#include <iostream>

void iniciaRealidade();
void criaPersonagemAlunoExemplo();

int main () {
  iniciaRealidade();

  return 0;
}

void iniciaRealidade(){
  bool realidadeVirtual = true;
  while (realidadeVirtual){
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "--    Bem vindo a nossa realidade virtual                     --" << std::endl;
    std::cout << "--    O que desejas?                                          --" << std::endl;
    std::cout << "--    1 - Criar o personagem                                  --" << std::endl;
    std::cout << "--    2 - Dar boas vindas                                     --" << std::endl;
    std::cout << "--    3 - Calcular o local da proxima missao                  --" << std::endl;
    std::cout << "--    0 - Voltar a realidade                                  --" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    int escolha;
    std::cin >> escolha;
    switch(escolha) {
      case 1:
        std::cout << "Historia 03" << std::endl;
        criaPersonagemAlunoExemplo(); //Historia 03
        break;
      case 2:
        std::cout << "Historia 01" << std::endl;
        //cumprimento(); //Historia 01
        break;
      case 3:
        calculaOrigemAoPontoUnico(5); //Historia 02
        break;
      case 0:
        realidadeVirtual = false; //Historia 02
        break;
      default:
        std::cout << "Alternativa inexistente!" << std::endl;
        break;
    }
  }
}

void criaPersonagemAlunoExemplo(){
  Aluno a("Adao", 1);
  a.printAluno();
}