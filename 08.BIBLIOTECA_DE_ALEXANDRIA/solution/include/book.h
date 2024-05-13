/*
 * Filename: book.h
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "item.h"
#include <cstddef>

class Book : public Item
{
    private:
        std::string m_genre;
        std::string m_publisher;
        std::string m_isbn;
        std::size_t m_numPages;

    public:
        Book(std::size_t id,
             std::size_t availableCopies,
             std::size_t pages,
             std::string title,
             std::string author,
             std::string isbn,
             std::string date,
             std::string genre,
             std::string publisher);

        ~Book();

        std::string GetISBN() const;
        std::string GetGenre() const;
        std::string GetPublisher() const;
        std::size_t GetNumPages() const;

        void PrintInfo() override;
};

#endif // BOOK_H_
