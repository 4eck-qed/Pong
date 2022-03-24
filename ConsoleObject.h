#pragma once

#include <string>

class ConsoleObject
{
public:
    virtual std::string GetName() const = 0;
    virtual char GetCharacter() const = 0;
};
