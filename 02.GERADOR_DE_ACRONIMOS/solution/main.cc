/*
 * Filename: main.cc
 * Created on: April 24, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sys/types.h>

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Generate an acronym from a given phrase
 * @param phrase The phrase to generate the acronym
 * @return The acronym
 **/
std::string GenerateAcronym(const std::string& phrase)
{
    std::stringstream ss(phrase);
    std::string       word, acronym;

    while (ss >> word)
    {
        if (isupper(word[0]))
            acronym += word[0];
    }

    return acronym;
}

/**
 * @brief Check if a given phrase is a recursive acronym
 * @param phrase The phrase to check
 * @return True if the phrase is a recursive acronym, false otherwise
 **/
bool IsRecursiveAcronym(const std::string& phrase)
{
    std::stringstream ss(phrase);
    std::string       firstWorld, sanitizedFirstWorld, acronym;

    // Get the first word
    ss >> firstWorld;

    // Remove especial characters
    for (char& c : firstWorld)
    {
        if (isalpha(c))
            sanitizedFirstWorld += c;
    }

    acronym = GenerateAcronym(phrase);

    // Convert to uppercase
    for (auto& c : sanitizedFirstWorld)
        c = std::toupper(c);

    return acronym == sanitizedFirstWorld;
}

int main()
{
    std::string phrase;

    getline(std::cin, phrase);

    std::string acronym     = GenerateAcronym(phrase);
    bool        isRecursive = IsRecursiveAcronym(phrase);

    std::cout << isRecursive << " " << acronym << std::endl;

    return EXIT_SUCCESS;
}
