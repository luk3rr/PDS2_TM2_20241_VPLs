#ifndef OLA_H
#define OLA_H

#include <iostream>

class Personagem {
  private:
    std::string nome;
	protected:
		std::string getNome();
		void setNome(std::string);
	public:
		Personagem();
		void cumprimento();
		~Personagem();
};

#endif