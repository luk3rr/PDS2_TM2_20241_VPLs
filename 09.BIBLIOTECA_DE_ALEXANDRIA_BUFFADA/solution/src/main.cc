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
            else if (type == 'u') // Adiciona um usuário
            {
                std::string name, email, cpf;

                std::cin >> name >> email >> cpf;

                library.AddUser(name, email, cpf);
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
                std::size_t user_id;
                std::string title;
                std::cin >> title >> user_id;

                library.Reserve(title, user_id);
            }
            else if (type == 'i')
            {
                std::size_t item_id, user_id;
                std::cin >> item_id >> user_id;

                library.Reserve(item_id, user_id);
            }
        }
        else if (command == 'd') // Devolve um livro
        {
            std::size_t item_id, user_id;
            std::cin >> item_id >> user_id;

            library.Release(item_id, user_id);
        }
        else if (command == 's')
        {
            char type;
            std::cin >> type;

            if (type == 'c')
                library.PrintCollection();

            else if (type == 'u')
                library.PrintUsers();

            else if (type == 'r')
                library.PrintReservations();
        }
        else
        {
            std::cerr << "Comando inválido: " << command << std::endl;
        }
    }

    std::cout << "Fim da execução" << std::endl;
    return EXIT_SUCCESS;
}
