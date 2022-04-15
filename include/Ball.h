#pragma once

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include "Drawing.h"
#include "ConsoleObject.h"
#include "../Utils/Toolbox.h"

class Ball : public ConsoleObject
{
private:
    char body = 'o';
public:
    std::string GetName() const;

    char GetCharacter() const;

    Toolbox::MovingState State;
};
