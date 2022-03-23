#pragma once

#include "Drawing.h"
#include "Ball.h"
#include <sys/types.h>
#include <string>
#include <map>

enum Direction
{
    Up,
    Down,
    Left,
    Right
};

class Field
{
private:
    std::wstring field;
    int width, height;
    std::map<const ConsoleObject *, Drawing::Point> children;
    std::map<Direction, Drawing::Point> direction_vectors;
public:
    Field();

    Field(int width, int height);

    // gets the width
    int getWidth() const;

    // gets the height
    int getHeight() const;

    // prints the field
    void draw();

    // places object on position
    void placeObject(const ConsoleObject &c, Drawing::Point &&position);

    // access field
    wchar_t &operator[](const Drawing::Point &position);

    // moves target by offset
    void move(const ConsoleObject &object, const Drawing::Point &offset);

    // moves target in direction
    void move(const ConsoleObject &object, Direction direction);

    // returns if target can move by given offset
    bool canMove(const ConsoleObject &object, const Drawing::Point &offset);

    // returns if target can move in given direction
    bool canMove(const ConsoleObject &object, Direction direction);

    // returns if position is colliding with something
    bool IsColliding(const Drawing::Point &position);

    // returns true if object is on left boundary
    bool IsOnLeftBoundary(const ConsoleObject &object);

    // returns true if position is on left boundary
    bool IsOnLeftBoundary(const Drawing::Point &position);

    // returns true if object is on right boundary
    bool IsOnRightBoundary(const ConsoleObject &object);

    // returns true if position is on right boundary
    bool IsOnRightBoundary(const Drawing::Point &position);

    Drawing::Point topLeftCorner{0, 0};
    Drawing::Point bottomRightCorner{0, 0};
};