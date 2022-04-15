#pragma once

#include "ConsoleObject.h"
#include "../Utils/Toolbox.h"

class Player : public ConsoleObject
{
private:
    std::string name;
public:
    Player();
    Player(std::string name);
    std::string GetName() const;
    char GetCharacter() const;
};
