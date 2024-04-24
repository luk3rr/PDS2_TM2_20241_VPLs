/*
 * Filename: main.cc
 * Created on: April 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

constexpr uint16_t ALPHABET_SIZE = 26;

/**
 * @brief Verifica se um caractere é válido
 *
 * Para os propósitos deste programa, um caractere é válido se for uma letra
 * do alfabeto inglês, maiúscula ou minúscula
 *
 * @param ch Caractere a ser verificado
 * @return True se o caractere é válido, False caso contrário
 **/
bool ValidChar(char ch)
{
    return (ch >= 'A' and ch <= 'Z') or (ch >= 'a' and ch <= 'z');
}

/**
 * @brief Cifra ou decifra uma string usando a cifra de César
 * @param operation 'c' para cifrar e 'd' para decifrar
 * @param c Valor do deslocamento
 * @param text Texto a ser cifrado ou decifrado
 * @return Texto cifrado ou decifrado
 **/
std::string CaesarCipher(char operation, int c, std::string text)
{
    std::string result = "";

    for (char ch : text)
    {
        // Caracteres especiais não são cifrados
        if (ValidChar(ch))
        {
            // Se for maiúscula, base = 'A' = 65
            // Se for minúscula, base = 'a' = 97
            char base = isupper(ch) ? 'A' : 'a';

            // Calcula o deslocamento do caractere
            int shift = c % ALPHABET_SIZE;

            if (shift < 0) // Garante que o deslocamento seja positivo
                shift += ALPHABET_SIZE;

            if (operation == 'c')
                result += (char)(((ch - base + shift) % ALPHABET_SIZE) + base);

            else
                result += (char)(((ch - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + base);

        }
        else
        {
            result += ch;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <operation> <shift> <text>\n";
        return EXIT_FAILURE;
    }

    char        operation = argv[1][0];
    int         c         = std::stoi(argv[2]);
    std::string text      = argv[3];

    std::string result = CaesarCipher(operation, c, text);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
