#ifndef ALUNO_H
#define ALUNO_H

#include "ola.hpp"

//Inclusão do Aluno
class Aluno : public Personagem {
  private:
    int matricula;
  protected:
    int getMat();
		void setMat(int);
  public:
    Aluno();
    Aluno(std::string nome);
    Aluno(std::string nome, int);
    //Aluno(const Aluno *copy);
    void cumprimento() override;
    void printAluno();
    ~Aluno();
};


#endif