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
		Personagem(const Personagem *copy);
		Personagem(std::string nomeInicial);
		virtual void cumprimento();
		~Personagem();
};

#endif