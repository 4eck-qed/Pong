#pragma once

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include "Drawing.h"
#include "ConsoleObject.h"
#include "Utils/Toolbox.h"

class Ball : public ConsoleObject
{
private:
    char body = 'o';
public:
    std::string getName() const;

    char getCharacter() const;

    Toolbox::MovingState State;
};
