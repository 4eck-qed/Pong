#pragma once

#include "Field.h"
#include "Ball.h"
#include "Player.h"

class Game
{
public:
    Game();

    Game(int width, int height, std::string player1Name = "Player1", std::string player2Name = "Player2");

    [[noreturn]]
    void start(std::string player1Name = "Player1", std::string player2Name = "Player2");

private:
    Field field;
    Ball ball;
    Player player1;
    Player player2;
    struct sKeyState
    {
        bool bPressed;
        bool bReleased;
        bool bHeld;
    } m_keys[256], m_mouse[5];
};
