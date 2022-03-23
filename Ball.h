#pragma once

#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include "Drawing.h"
#include "ConsoleObject.h"

enum MovingState
{
    GoDown,
    GoUp,
    GoLeft,
    GoRight,
};

class Ball : public ConsoleObject
{
private:
    char body = 'o';
public:
    std::string getName() const;

    char getCharacter() const;

    MovingState State;
};
