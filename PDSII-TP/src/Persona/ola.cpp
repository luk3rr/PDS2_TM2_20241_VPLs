#include "ola.hpp"

Personagem::Personagem(){
  this->nome = "";
}

Personagem::Personagem(std::string nomeInicial){
  this->nome = nomeInicial;
}

Personagem::Personagem(const Personagem *copy){
  this->nome = copy->nome;
}

std::string Personagem::getNome(){
  return this->nome;
}

void Personagem::setNome(std::string newName){
  this->nome = newName;
}

//Implementação do cumprimento
void Personagem::cumprimento(){
  std::cout << "O ola do Personagem: " << this->nome << "é - C tah baum? Ou ta baum dimais?" << std::endl;
}

Personagem::~Personagem(){
  std::cout << "O personagem: " << this->nome << " naum fara mais parte da realidade" << std::endl;
}