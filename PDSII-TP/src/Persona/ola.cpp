#include "ola.hpp"

Personagem::Personagem(){
  this->nome = "";
}

std::string Personagem::getNome(){
  return this->getNome();
}

void Personagem::setNome(std::string newName){
  this->nome = newName;
}

//Implementação do cumprimento
void Personagem::cumprimento(){
  std::cout << "O ola do Personagem: " << this->nome << "é - C tah baum? Ou ta baum dimais?" << std::endl;
}

Personagem::~Personagem(){
  std::cout << "O personagem: " << this->nome << "Nao fara mais parte da realidade" << std::endl;
}