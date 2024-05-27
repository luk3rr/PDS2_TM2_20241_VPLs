#include "persona.hpp"
#include "pessoa.hpp"
#include "aluno.hpp"
#include "curso.hpp"
#include "animal.hpp"
#include "cachorro.hpp"
#include "gato.hpp"
#include "pato.hpp"
#include "ponto3d.hpp"
#include <iostream>
#include <list>
#include <memory>


int main() {
  Animal* bixo1 = new Gato();
  Animal* bixo2 = new Gato();
  bixo1->fale();
  bixo2->fale();
  delete bixo1;
  delete bixo2;

  list<Animal*> lista;
 
  // Canto da bixarada;
  for(int i=0; i<50;i++) {
    if (i % 3 == 0)
      lista.push_back(new Cachorro());
    else if (i % 3 == 1)
      lista.push_back(new Gato());
    else
      lista.push_back(new Pato());
  }
 
  for (auto a : lista)
    a->fale();

  return 0; 
}

