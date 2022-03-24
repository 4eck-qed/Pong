#include "Field.h"
#include "Ball.h"
#include "Utils/Toolbox.h"

#include <string>
#include <iostream>

using namespace Drawing;

Field::Field() : Field(64, 16)
{

}

Field::Field(int width, int height)
{
    this->width = width;
    this->height = height;
    topLeftCorner = {0, 0};
    bottomRightCorner = {width, height};

    direction_vectors[Up] = {0, -1};
    direction_vectors[Down] = {0, 1};
    direction_vectors[Left] = {-1, 0};
    direction_vectors[Right] = {1, 0};

    // Generate field
    field.append(L'┌' + Toolbox::MultiplyWChars(L'─', width - 2) + L'┐' + L'\n');
    auto line = L'│' + Toolbox::MultiplyWChars(L' ', width - 2) + L'│';
    field.append(Toolbox::MultiplyWString(line + L'\n', height));
    field.append(L'└' + Toolbox::MultiplyWChars(L'─', width - 2) + L'┘' + L'\n');
}

void Field::Draw()
{
    std::wcout << field << std::endl;
}

void Field::PlaceObject(const ConsoleObject &object, Point &&position)
{
    if (position >> Point{width - 2, height} || position << Point{1, 1})
    {
        std::cout << "Can't place on border or outside of the field!" << std::endl;
        return;
    }

    (*this)[position] = object.GetCharacter();
    children[&object] = position;
}

void Field::Move(const ConsoleObject &object, const Point &offset)
{
    auto objectPosition = children[&object];
    auto newPosition = objectPosition + offset;

    (*this)[objectPosition] = ' ';
    (*this)[newPosition] = object.GetCharacter();
    children[&object] = newPosition;
}

void Field::Move(const ConsoleObject &object, Direction direction)
{
    Move(object, direction_vectors[direction]);
}

#pragma region checks

bool Field::CanMove(const ConsoleObject &object, const Point &offset)
{
    auto newPosition = children[&object] + offset;
    return not IsColliding(newPosition);
}

bool Field::CanMove(const ConsoleObject &object, Direction direction)
{
    return CanMove(object, direction_vectors[direction]);
}

bool Field::IsColliding(const Point &position)
{
    return (*this)[position] != ' ';
}

bool Field::IsTouchingAnyBoundary(const ConsoleObject &object)
{
    return IsTouchingLeftBoundary(children[&object]);
}

bool Field::IsTouchingAnyBoundary(const Point &position)
{
    return IsTouchingTopBoundary(position) ||
           IsTouchingBottomBoundary(position) ||
           IsTouchingLeftBoundary(position) ||
           IsTouchingRightBoundary(position);
}

bool Field::IsTouchingTopBoundary(const ConsoleObject &object)
{
    return IsTouchingTopBoundary(children[&object]);
}

bool Field::IsTouchingTopBoundary(const Point &position)
{
    return position.Y <= 1;
}

bool Field::IsTouchingBottomBoundary(const ConsoleObject &object)
{
    return IsTouchingBottomBoundary(children[&object]);
}

bool Field::IsTouchingBottomBoundary(const Point &position)
{
    return position.Y >= height - 1;
}

bool Field::IsTouchingLeftBoundary(const ConsoleObject &object)
{
    return IsTouchingLeftBoundary(children[&object]);
}

bool Field::IsTouchingLeftBoundary(const Point &position)
{
    return position.X <= 1;
}

bool Field::IsTouchingRightBoundary(const ConsoleObject &object)
{
    return IsTouchingRightBoundary(children[&object]);
}

bool Field::IsTouchingRightBoundary(const Point &position)
{
    return position.X >= width - 2;
}

#pragma endregion

#pragma region overloads

wchar_t &Field::operator[](const Point &position)
{
    auto row = position.X;
    auto column = width * position.Y;
    auto newLineChars = Toolbox::CountWChar(L'\n', field.substr(0, column)) + 1;
    column += newLineChars;

    return field[row + column];
}

#pragma endregion

#pragma region Getters and Setters

int Field::GetWidth() const
{
    return width;
}

int Field::GetHeight() const
{
    return height;
}

#pragma endregion