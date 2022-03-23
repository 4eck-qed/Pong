#include <thread>
#include "Game.h"

using namespace Toolbox;

[[noreturn]]
void Game::start(std::string player1Name, std::string player2Name)
{
    field.placeObject(ball, {field.getWidth() / 2, field.getHeight() / 2});
    field.placeObject(player1, {1, field.getHeight() / 2});
    field.placeObject(player2, {field.getWidth() - 2, field.getHeight() / 2});

    auto down = Drawing::Point{0, 1};
    auto up = Drawing::Point{0, -1};
    auto left = Drawing::Point{-1, 0};
    auto right = Drawing::Point{1, 0};

    ball.State = MovingState::GoLeft;
    player1.State = MovingState::GoDown;
    player2.State = MovingState::GoDown;

    while (true)
    {
        switch (ball.State)
        {
            case GoDown:
                if (field.canMove(ball, down)) field.move(ball, down);
                else ball.State = MovingState::GoUp;
                break;
            case GoUp:
                if (field.canMove(ball, up)) field.move(ball, up);
                else ball.State = MovingState::GoDown;
                break;
            case GoLeft:
                if (field.canMove(ball, left)) field.move(ball, left);
                else ball.State = MovingState::GoRight;
                break;
            case GoRight:
                if (field.canMove(ball, right)) field.move(ball, right);
                else ball.State = MovingState::GoLeft;
                break;
        }

        switch (player1.State)
        {
            case GoDown:
                if (field.canMove(player1, down)) field.move(player1, down);
                else player1.State = MovingState::GoUp;
                break;
            case GoUp:
                if (field.canMove(player1, up)) field.move(player1, up);
                else player1.State = MovingState::GoDown;
                break;
            case GoLeft:
                if (field.canMove(player1, left)) field.move(player1, left);
                else player1.State = MovingState::GoRight;
                break;
            case GoRight:
                if (field.canMove(player1, right)) field.move(player1, right);
                else player1.State = MovingState::GoLeft;
                break;
        }

        switch (player2.State)
        {
            case GoDown:
                if (field.canMove(player2, down)) field.move(player2, down);
                else player2.State = MovingState::GoUp;
                break;
            case GoUp:
                if (field.canMove(player2, up)) field.move(player2, up);
                else player2.State = MovingState::GoDown;
                break;
            case GoLeft:
                if (field.canMove(player2, left)) field.move(player2, left);
                else player2.State = MovingState::GoRight;
                break;
            case GoRight:
                if (field.canMove(player2, right)) field.move(player2, right);
                else player2.State = MovingState::GoLeft;
                break;
        }

//      OnPlayerAction();
        system("clear");
        field.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

Game::Game() : Game(64, 16)
{

}

Game::Game(int width, int height, std::string player1Name, std::string player2Name)
{
    field = Field(width, height);
    ball = Ball();
    player1 = Player(player1Name);
    player2 = Player(player2Name);
}
