#include "Ball.h"
#include "Field.h"
#include "Player.h"
#include "Game.h"
#include <chrono>
#include <thread>
#include <cstring>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

#ifdef _WIN32
char Getch(){
HANDLE hdl=GetStdHandle(STD_INPUT_HANDLE);
HANDLE hdo=GetStdHandle(STD_OUTPUT_HANDLE);

DWORD oldmode; //Zuvor verwendeter Konsolenmodus
CONSOLE_CURSOR_INFO cci;

char gedrueckt;

GetConsoleMode(hdl, &oldmode);
GetConsoleCursorInfo(hdo, &cci); cci.bVisible=false; //Cursor nicht sichtbar

SetConsoleMode(hdl, oldmode&~(ENABLE_LINE_INPUT|ENABLE_ECHO_INPUT)); //Input wird nicht angezeigt, Entertaste muss nicht gedrückt werden
SetConsoleCursorInfo(hdo, &cci);

gedrueckt=getchar();

cci.bVisible=true; SetConsoleCursorInfo(hdo, &cci); //Setze Cursor wieder zurück
SetConsoleMode(hdl, oldmode); //Und den Modus wieder auf den zuvor verwendeten

return gedrueckt;
}
#else

#endif


//
//void OnPlayerAction()
//{
//    switch (ball.State)
//    {
//        case GoDown:
//            if (field.canMove(ball, down)) field.move(ball, down);
//            else ball.State = MovingState::GoUp;
//            break;
//        case GoUp:
//            if (field.canMove(ball, up)) field.move(ball, up);
//            else ball.State = MovingState::GoDown;
//            break;
//        case GoLeft:
//            if (field.canMove(ball, left)) field.move(ball, left);
//            else ball.State = MovingState::GoRight;
//            break;
//        case GoRight:
//            if (field.canMove(ball, right)) field.move(ball, right);
//            else ball.State = MovingState::GoLeft;
//            break;
//    }
//}

int main(int argc, const char **args)
{
    auto game = Game(64, 16);
    game.start("Player1", "Player2");
//    std::memset(m_keys, 0, 256 * sizeof(sKeyState));
}

#pragma clang diagnostic pop