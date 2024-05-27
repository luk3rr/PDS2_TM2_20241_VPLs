#include <iostream>
#include <string>

using namespace std;

class Personagem {
  private:
    std::string nome;
	protected:
		std::string getNome();
		void setNome(std::string);
	public:
		Personagem();
		Personagem(std::string nomeInicial);
		//Personagem(const Personagem *per);
		void cumprimento();
		~Personagem();
};

class Aluno : public Personagem {
  private:
    int matricula;
  public:
    int getMat();
		void setMat(int);
  public:
    Aluno();
    Aluno(std::string nome, int);
    void printAluno();
    ~Aluno();
};

int main(){
	Personagem p;
	p.cumprimento();
	Personagem p2("joao");
	p2.cumprimento();
	Aluno a("adao", 1);
	a.printAluno();
	return 0;
}

Personagem::Personagem(std::string nomeInicial){
  this->nome = nomeInicial;
}
Personagem::Personagem(){
  this->nome = "";
}
std::string Personagem::getNome(){
  return this->nome;
}
void Personagem::setNome(std::string newName){
  this->nome = newName;
}
void Personagem::cumprimento(){
  std::cout << "O ola do Personagem: " << this->nome << " eh - C tah baum? Ou ta baum dimais?" << std::endl;
}
Personagem::~Personagem(){
  std::cout << "O personagem: " << this->nome << " nao fara mais parte da realidade" << std::endl;
}
Aluno::Aluno() :  Personagem(){
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
void Aluno::printAluno(){
 std::cout << "Nome do Aluno: " << this->getNome() << std::endl;
 std::cout << "Matricula: " << this->matricula << std::endl;
}
Aluno::~Aluno(){};