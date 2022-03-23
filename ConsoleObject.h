#pragma once

#include <string>

class ConsoleObject
{
public:
    virtual std::string getName() const = 0;
    virtual char getCharacter() const = 0;
};
