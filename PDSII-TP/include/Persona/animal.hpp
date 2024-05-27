#ifndef ANIMAL_H
#define ANIMAL_H

#include "ola.hpp"

//Inclusão do Animal
class Animal : public Personagem {
  private:
    std::string especie;
  protected:
    std::string getEspecie();
	void setEspecie(std::string);
  public:
    Animal();
    Animal(std::string nome);
    Animal(std::string nome, std::string especie);
    //Animal(const Animal *copy);
    virtual void cumprimento() override;
    void printAnimal();
    ~Animal();
};


#endif