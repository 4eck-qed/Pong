#pragma once

#include "Drawing.h"
#include "Ball.h"
#include <sys/types.h>
#include <string>
#include <map>

class Field
{
private:
    std::wstring field;
    int width, height;
    std::map<const ConsoleObject *, Drawing::Point> children;
public:
    Field();

    Field(int width, int height);

    // gets the width
    int getWidth() const;

    // gets the height
    int getHeight() const;

    // prints the field
    void draw();

    // updates the field
    void update();

    // places object on position
    void placeObject(const ConsoleObject &c, Drawing::Point &&position);

    // access field
    wchar_t &operator[](const Drawing::Point &position);

    // moves target by offset
    void move(const ConsoleObject &target, const Drawing::Point &offset);

    // returns if target can move by given offset
    bool canMove(const ConsoleObject &target, const Drawing::Point &offset);

    bool checkCollision(const Drawing::Point &position);

    Drawing::Point topLeftCorner{0, 0};
    Drawing::Point bottomRightCorner{0, 0};
};