#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>

#define OK 0
#define ERROR -1
#define P1_SCORE 10
#define P2_SCORE 20

struct termios old_tio, new_tio;

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
static void __setup_console()
{
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}

static void __restore_console()
{
    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
}

#pragma endregion

void Game::Start()
{
    __setup_console();
    field.placeObject(ball, {field.getWidth() / 2, field.getHeight() / 2});
    field.placeObject(player1, {1, field.getHeight() / 2});
    field.placeObject(player2, {field.getWidth() - 2, field.getHeight() / 2});

    ball.State = MovingState::GoLeft;
    player1.State = MovingState::GoDown;
    player2.State = MovingState::GoDown;

    auto input = '-';
    auto exit = OK;
    auto io_thread = std::thread([&] {
        if (exit != OK) std::terminate();
        while (std::cin >> input);
    });

    exit = __game_loop(input);
    system("clear");
    std::cout << "asdoaksod" << std::endl;
    switch (exit)
    {
        case P1_SCORE:
            printf("%s WIN!", player1.getName().c_str());
            break;
        case P2_SCORE:
            printf("%s WIN!", player2.getName().c_str());
            break;
        case ERROR:
            printf("Game crashed (%d)\n", exit);
            break;
    }
    printf("Press any key to continue..");
    std::cin.get();
    __restore_console();
}

Action Game::HandlePlayerAction(char &input)
{
    switch (input)
    {
        case 'w': //p1 up
            if (field.canMove(player1, Up)) field.move(player1, Up);
            input = '?';
            return MOVE;
        case 's': //p1 down
            if (field.canMove(player1, Down)) field.move(player1, Down);
            input = '?';
            return MOVE;
        case '8': //p2 up
            if (field.canMove(player2, Up)) field.move(player2, Up);
            input = '?';
            return MOVE;
        case '5': //p2 down
            if (field.canMove(player2, Down)) field.move(player2, Down);
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
        if (field.IsOnLeftBoundary(ball))
            return P1_SCORE;
        if (field.IsOnRightBoundary(ball))
            return P2_SCORE;

        switch (ball.State)
        {
            case GoDown:
                if (field.canMove(ball, Down)) field.move(ball, Down);
                else ball.State = MovingState::GoUp;
                break;
            case GoUp:
                if (field.canMove(ball, Up)) field.move(ball, Up);
                else ball.State = MovingState::GoDown;
                break;
            case GoLeft:
                if (field.canMove(ball, Left)) field.move(ball, Left);
                else ball.State = MovingState::GoRight;
                break;
            case GoRight:
                if (field.canMove(ball, Right)) field.move(ball, Right);
                else ball.State = MovingState::GoLeft;
                break;
        }
        action = HandlePlayerAction(input);
        system("clear");
        field.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    } while (action != ESC);
    return OK;
}
