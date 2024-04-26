#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>

using namespace std;

//Inclusão do Aluno
struct Aluno {
  string nome;
  int matricula;
  float calcularRSG();
};

void criaAlunoExemplo();

#endif