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
    int GetWidth() const;

    // gets the height
    int GetHeight() const;

    // prints the field
    void Draw();

    // places object on position
    void PlaceObject(const ConsoleObject &object, Drawing::Point &&position);

    // moves target by offset
    void Move(const ConsoleObject &object, const Drawing::Point &offset);

    // moves target in direction
    void Move(const ConsoleObject &object, Direction direction);

    // returns if target can Move by given offset
    bool CanMove(const ConsoleObject &object, const Drawing::Point &offset);

    // returns if target can Move in given direction
    bool CanMove(const ConsoleObject &object, Direction direction);

    // returns if position is colliding with something
    bool IsColliding(const Drawing::Point &position);

    // returns true if object is on any boundary
    bool IsTouchingAnyBoundary(const ConsoleObject &object);

    // returns true if position is on any boundary
    bool IsTouchingAnyBoundary(const Drawing::Point &position);

    // returns true if object is on left boundary
    bool IsTouchingTopBoundary(const ConsoleObject &object);

    // returns true if position is on left boundary
    bool IsTouchingTopBoundary(const Drawing::Point &position);

    // returns true if object is on right boundary
    bool IsTouchingBottomBoundary(const ConsoleObject &object);

    // returns true if position is on right boundary
    bool IsTouchingBottomBoundary(const Drawing::Point &position);

    // returns true if object is on left boundary
    bool IsTouchingLeftBoundary(const ConsoleObject &object);

    // returns true if position is on left boundary
    bool IsTouchingLeftBoundary(const Drawing::Point &position);

    // returns true if object is on right boundary
    bool IsTouchingRightBoundary(const ConsoleObject &object);

    // returns true if position is on right boundary
    bool IsTouchingRightBoundary(const Drawing::Point &position);

    Drawing::Point topLeftCorner{0, 0};
    Drawing::Point bottomRightCorner{0, 0};

#pragma region overloads

    // accesses the field
    wchar_t &operator[](const Drawing::Point &position);

#pragma endregion
};