#pragma once

#include "ConsoleObject.h"
#include "Utils/Toolbox.h"

class Player : public ConsoleObject
{
private:
    std::string name;
public:
    Player();
    Player(std::string name);
    std::string getName() const;
    char getCharacter() const;
    Toolbox::MovingState State;
};
