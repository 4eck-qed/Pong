#include "Game.h"
#include "Utils/Converter.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <condition_variable>
#include <mutex>

#define OK 0
#define ERROR -1
#define P1_SCORE 10
#define P2_SCORE 20

using namespace Toolbox;

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

#pragma region static functions

struct termios old_tio, new_tio;

static void __setup_console()
{
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO, &old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio = old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &= (~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

static void __restore_console()
{
    /* restore the former settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

#pragma endregion

void Game::Start()
{
    __setup_console();
    field.PlaceObject(ball, {field.GetWidth() / 2, field.GetHeight() / 2});
    field.PlaceObject(player1, {1, field.GetHeight() / 2});
    field.PlaceObject(player2, {field.GetWidth() - 2, field.GetHeight() / 2});

    ball.State = MovingState::GoLeft;
    player1.State = MovingState::GoDown;
    player2.State = MovingState::GoDown;

    auto input = '-';
    auto exit = OK;
    auto io_thread = std::thread([&] {
        while (exit == OK && std::cin >> input);
    });

    exit = __game_loop(input);
    system("clear");
    switch (exit)
    {
        case P1_SCORE:
            std::wcout << Converter::stringToWString(player1.getName()) << " WIN!" << std::endl;
            break;
        case P2_SCORE:
            std::wcout << Converter::stringToWString(player2.getName()) << " WIN!" << std::endl;
            break;
        case ERROR:
            std::wcout << L"Game crashed (" << exit << ")" << std::endl;
            break;
    }
    io_thread.detach();
    __restore_console();
}

Action Game::HandlePlayerAction(char &input)
{
    switch (input)
    {
        case 'w': //p1 up
            if (field.CanMove(player1, Up)) field.Move(player1, Up);
            input = '?';
            return MOVE;
        case 's': //p1 down
            if (field.CanMove(player1, Down)) field.Move(player1, Down);
            input = '?';
            return MOVE;
        case '8': //p2 up
            if (field.CanMove(player2, Up)) field.Move(player2, Up);
            input = '?';
            return MOVE;
        case '5': //p2 down
            if (field.CanMove(player2, Down)) field.Move(player2, Down);
            input = '?';
            return MOVE;
        case 'q':
            input = 'q';
            return ESC;
    }
    return NONE;
}

int Game::__game_loop(char &input)
{
    auto action = NONE;
    do
    {
        switch (ball.State)
        {
            case GoDown:
                if (field.CanMove(ball, Down))
                    field.Move(ball, Down);
                else
                    ball.State = MovingState::GoUp;
                break;
            case GoUp:
                if (field.CanMove(ball, Up))
                    field.Move(ball, Up);
                else
                    ball.State = MovingState::GoDown;
                break;
            case GoLeft:
                if (field.CanMove(ball, Left))
                    field.Move(ball, Left);
                else
                    ball.State = MovingState::GoRight;
                break;
            case GoRight:
                if (field.CanMove(ball, Right))
                    field.Move(ball, Right);
                else
                    ball.State = MovingState::GoLeft;
                break;
        }

        if (field.IsTouchingLeftBoundary(ball))
            return P2_SCORE;
        if (field.IsTouchingRightBoundary(ball))
            return P1_SCORE;

        action = HandlePlayerAction(input);
        system("clear");
        field.Draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    } while (action != ESC);
    return OK;
}
