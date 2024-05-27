#include "aluno.hpp"

Aluno::Aluno() :  Personagem(){
  this->matricula = 0;
}

Aluno::Aluno(std::string nomeInicial) : Personagem(nomeInicial){
  this->matricula = 0;
}

Aluno::Aluno(std::string nomeInicial, int matInicial) : Personagem(nomeInicial){
  this->matricula = matInicial;
}

int Aluno::getMat(){
  return this->matricula;
}
void Aluno::setMat(int newMat){
  this->matricula = newMat;
}

void Aluno::cumprimento(){
  std::cout << "Sou aluno,  " << this->getNome() << std::endl;
  std::cout << "Matricula: " << this->getMat() << " como c tah?" << std::endl;
}

void Aluno::printAluno(){
  std::cout << "O " << this->getNome() << " de matricula: " << this->getMat() << " eh um aluno da realidade." << std::endl;
}

Aluno::~Aluno(){};