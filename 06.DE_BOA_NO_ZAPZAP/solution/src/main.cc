/*
 * Filename: main.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "zapzap.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

int main()
{
    ZapZap      zapZap("Torresmo IV");
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::string        comando;
        iss >> comando;

        switch (comando[0])
        {
            case 's': {
                std::string nome;
                iss >> nome;
                zapZap.CadastrarSudito(nome);
                break;
            }
            case 'c': {
                std::string nome1, nome2;
                iss >> nome1 >> nome2;
                zapZap.CriarConexao(nome1, nome2);
                break;
            }
            case 'm': {
                std::string nome1, nome2, conteudo;
                iss >> nome1 >> nome2;
                std::getline(iss, conteudo);

                if (not conteudo.empty() and conteudo[0] == ' ')
                {
                    conteudo.erase(0, 1);
                }
                zapZap.EnviarMensagem(nome1, nome2, conteudo);
                break;
            }
            case 'p': {
                std::string nome, conteudo;
                iss >> nome;
                std::getline(iss, conteudo);
                if (not conteudo.empty() and conteudo[0] == ' ')
                {
                    conteudo.erase(0, 1);
                }
                zapZap.PostarMensagem(nome, conteudo);
                break;
            }
            case 'i': {
                std::string nome, tipoCmd;
                iss >> tipoCmd >> nome;

                if (tipoCmd == "r")
                {
                    zapZap.ImprimirMensagensRecebidas(nome);
                }
                else if (tipoCmd == "e")
                {
                    zapZap.ImprimirMensagensEnviadas(nome);
                }
                else
                {
                    std::cout << "Comando desconhecido." << std::endl;
                }

                break;
            }
            case 'a': {
                zapZap.ImprimirTodasMensagens();
                break;
            }
            case 'q': {
                std::cout << "E as capivaras viveram felizes para sempre..."
                          << std::endl;
                return EXIT_SUCCESS;
            }
            default: {
                std::cout << "Comando desconhecido." << std::endl;
                break;
            }
        }
    }

    return 0;
}
