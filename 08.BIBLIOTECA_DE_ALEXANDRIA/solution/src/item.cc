/*
 * Filename: item.cc
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "item.h"
#include <cstddef>

Item::Item(std::size_t id,
           std::size_t availableCopies,
           std::string title,
           std::string author,
           std::string date,
           std::string itemType)
{
    this->m_id                = id;
    this->m_availableCopies = availableCopies;
    this->m_title             = title;
    this->m_author            = author;
    this->m_date              = date;
    this->m_itemType          = itemType;
    this->m_loanedCopies    = 0;
}

Item::~Item()
{
    std::cout << "Item " << this->m_id << " liberado da memória!" << std::endl;
}

std::size_t Item::GetID() const
{
    return this->m_id;
}

std::size_t Item::GetAvailableCopies() const
{
    return this->m_availableCopies;
}

std::size_t Item::GetLoanedCopies() const
{
    return this->m_loanedCopies;
}

std::string Item::GetTitle() const
{
    return this->m_title;
}

std::string Item::GetAuthor() const
{
    return this->m_author;
}

std::string Item::GetDate() const
{
    return this->m_date;
}

std::string Item::GetItemType() const
{
    return this->m_itemType;
}

void Item::Reserve()
{
    if (this->m_availableCopies > 0)
    {
        this->m_availableCopies--;
        this->m_loanedCopies++;

        std::cout << "Item " << this->m_id << " reservado com sucesso :)" << std::endl;
    }
    else
    {
        std::cout << "Item " << this->m_id << " não disponível para empréstimo :("
                  << std::endl;
    }
}

void Item::Release()
{
    if (this->m_loanedCopies > 0)
    {
        this->m_availableCopies++;
        this->m_loanedCopies--;

        std::cout << "Item " << this->m_id
                  << " recebido. Obrigado pelo seu compromisso em nos devolvê-lo :=)"
                  << std::endl;
    }
    else
    {
        std::cout << "Nenhuma cópia do item " << this->m_id << " está emprestada o.O" << std::endl;
    }
}

void Item::PrintInfo()
{
    std::cout << "TIPO: " << this->m_itemType << std::endl;
    std::cout << "ID: " << this->m_id << std::endl;
    std::cout << "TÍTULO: " << this->m_title << std::endl;
    std::cout << "AUTOR(A): " << this->m_author << std::endl;
    std::cout << "DATA: " << this->m_date << std::endl;
    std::cout << "CÓPIAS DISPONÍVEIS: " << this->m_availableCopies << std::endl;
    std::cout << "CÓPIAS RESERVADAS: " << this->m_loanedCopies << std::endl;
}
