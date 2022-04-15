#pragma once

#include <string>

class IStorageRepository
{
public:
    virtual void Create(std::string table) = 0;

    virtual void Select(std::string table, std::string condition) = 0;

    virtual void Insert(std::string table, int player1score, int player2score) = 0;

    virtual void Delete(std::string table, std::string condition) = 0;
};
