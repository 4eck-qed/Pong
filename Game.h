#pragma once

#include "Field.h"
#include "Ball.h"
#include "Player.h"
#include "Scoreboard.h"

enum Action {
    MOVE,
    NONE,
    ESC
};

class Game {
public:
    Game();

    Game(int width, int height, std::string player1Name = "Player1", std::string player2Name = "Player2");

    void Start();

    Action HandlePlayerAction(char &input);

private:
    int __game_loop(char &input);

private:
    Field field;
    Ball ball;
    Player player1;
    Player player2;
    Scoreboard scoreboard;
};
