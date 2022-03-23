#include <thread>
#include "Game.h"

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

    system("clear");
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

//      OnPlayerAction();
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
