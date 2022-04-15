#include "../include/Game.h"
#include <iostream>

int main()
{
    auto game = Game(64, 16);
    game.Start();
    std::wcout << "Game closed." << std::endl;
    std::cin.get();
}
