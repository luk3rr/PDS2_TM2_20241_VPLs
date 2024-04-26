#include "aluno.hpp"

//Implementação do Aluno
float Aluno::calcularRSG() {
  cout << "O aluno ainda não tem RSG" << endl;
  return 0;
}

void criaAlunoExemplo(){
  Aluno aluno;
  aluno.nome = "Jose da Silva";
  aluno.matricula = 201812345;
  std::cout << aluno.calcularRSG() << std::endl;
}