#pragma once

#include "ConsoleObject.h"

class Player : public ConsoleObject
{
private:
    std::string name;
public:
    Player();
    Player(std::string name);
    std::string getName() const;
    char getCharacter() const;
};
