#include "Game.h"
#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main()
{
    auto game = Game(64, 16);
    game.Start();
    std::wcout << "Game closed." << std::endl;
    std::cin.get();
}

#pragma clang diagnostic pop