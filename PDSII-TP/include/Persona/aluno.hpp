#ifndef ALUNO_H
#define ALUNO_H

#include "ola.hpp"

//Inclusão do Aluno
class Aluno : Personagem {
  private:
    int matricula;
  protected:
    int getNome();
		void setNome(int);
  public:
    Aluno();
    void criaAlunoExemplo();
    ~Aluno();
};


#endif