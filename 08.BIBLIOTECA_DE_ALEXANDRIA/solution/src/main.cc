/*
 * Filename: main.cc
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "library.h"

int main()
{
    Library library;
    char    command;

    while (std::cin >> command)
    {
        if (command == 'a')
        {
            char type;

            std::cin >> type;

            if (type == 'l')
            {
                std::size_t copies, pages;
                std::string title, author, isbn, date, genre, publisher;

                std::cin >> copies >> pages >> title >> author >> isbn >> date >>
                    genre >> publisher;

                library.AddBook(copies,
                                pages,
                                title,
                                author,
                                isbn,
                                date,
                                genre,
                                publisher);
            }
            else if (type == 'j')
            {
                std::size_t copies, volume, number;
                std::string title, date, editor, topics;

                std::cin >> copies >> volume >> number >> title >> date >> editor >>
                    topics;

                library.AddPeriodic(copies,
                                    volume,
                                    number,
                                    title,
                                    date,
                                    editor,
                                    topics,
                                    "Jornal");
            }
            else if (type == 'r')
            {
                std::size_t copies, volume, number;
                std::string title, date, editor, topics;

                std::cin >> copies >> volume >> number >> title >> date >> editor >>
                    topics;

                library.AddPeriodic(copies,
                                    volume,
                                    number,
                                    title,
                                    date,
                                    editor,
                                    topics,
                                    "Revista");
            }
            else if (type == 'c')
            {
                std::size_t copies, tracks, duration;
                std::string title, artist, date;

                std::cin >> copies >> tracks >> duration >> title >> artist >> date;

                library.AddCD(copies, tracks, duration, title, artist, date);
            }
            else
            {
                std::cerr << "Comando inválido" << std::endl;
            }
        }
        else if (command == 'r') // Reserva um item
        {
            char type;
            std::cin >> type;

            if (type == 't')
            {
                std::string title;
                std::cin >> title;

                library.Reserve(title);
            }
            else if (type == 'i')
            {
                std::size_t id;
                std::cin >> id;

                library.Reserve(id);
            }
        }
        else if (command == 'd') // Devolve um livro
        {
            std::size_t id;
            std::cin >> id;

            library.Release(id);
        }
        else if (command == 's')
        {
            library.PrintCollection();
        }
        else
        {
            std::cerr << "Comando inválido: " << command << std::endl;
        }
    }

    std::cout << "Fim da execução" << std::endl;
    return EXIT_SUCCESS;
}
