/*
 * Filename: book.cc
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "book.h"
#include <cstddef>

Book::Book(std::size_t id,
           std::size_t availableCopies,
           std::size_t pages,
           std::string title,
           std::string author,
           std::string isbn,
           std::string date,
           std::string genre,
           std::string publisher)
    : Item(id, availableCopies, title, author, date, "Livro")
{
    this->m_numPages  = pages;
    this->m_genre     = genre;
    this->m_publisher = publisher;
    this->m_isbn      = isbn;
}

Book::~Book()
{
    std::cout << "Livro " << this->GetID() << " diz: Leia-me amanhã!" << std::endl;
}

std::string Book::GetISBN() const
{
    return this->m_isbn;
}

std::string Book::GetGenre() const
{
    return this->m_genre;
}

std::string Book::GetPublisher() const
{
    return this->m_publisher;
}

std::size_t Book::GetNumPages() const
{
    return this->m_numPages;
}

void Book::PrintInfo()
{
    std::cout << "ITEM: " << this->GetItemType() << std::endl;
    std::cout << "ID: " << this->GetID() << std::endl;
    std::cout << "TÍTULO: " << this->GetTitle() << std::endl;
    std::cout << "AUTOR(A): " << this->GetAuthor() << std::endl;
    std::cout << "EDITORA: " << this->GetPublisher() << std::endl;
    std::cout << "GÊNERO: " << this->GetGenre() << std::endl;
    std::cout << "NÚMERO DE PÁGINAS: " << this->GetNumPages() << std::endl;
    std::cout << "ISBN: " << this->GetISBN() << std::endl;
    std::cout << "DATA: " << this->GetDate() << std::endl;
    std::cout << "CÓPIAS DISPONÍVEIS: " << this->GetAvailableCopies() << std::endl;
    std::cout << "CÓPIAS RESERVADAS: " << this->GetLoanedCopies() << std::endl;
}
