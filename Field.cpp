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

    { // Generate field
        field.append(L'┌' + Toolbox::multiplyWChar(L'─', width - 2) + L'┐' + L'\n');
        auto line = L'│' + Toolbox::multiplyWChar(L' ', width - 2) + L'│';
        field.append(Toolbox::multiplyWString(line + L'\n', height));
        field.append(L'└' + Toolbox::multiplyWChar(L'─', width - 2) + L'┘' + L'\n');
    }
}

void Field::draw()
{
    std::wcout << field << std::endl;
}

void Field::placeObject(const ConsoleObject &object, Drawing::Point &&position)
{
    if (position >> Point{width - 2, height} || position << Point{1, 1})
    {
        std::cout << "Can't place on border or outside of the field!" << std::endl;
        return;
    }

    (*this)[position] = object.getCharacter();
    children[&object] = position;
}

void Field::move(const ConsoleObject &target, const Drawing::Point &offset)
{
    auto targetPosition = children[&target];
    auto newPosition = targetPosition + offset;

    if (!canMove(target, offset))
    {
        std::cout << "Can't move out of boundaries!" << std::endl;
        return;
    }

    (*this)[targetPosition] = ' ';
    (*this)[newPosition] = target.getCharacter();
    children[&target] = newPosition;
}

void Field::move(const ConsoleObject &target, Direction direction)
{
    move(target, direction_vectors[direction]);
}

bool Field::canMove(const ConsoleObject &target, const Point &offset)
{
    auto newPosition = children[&target] + offset;
    return not IsColliding(newPosition);
}

bool Field::canMove(const ConsoleObject &target, Direction direction)
{
    auto newPosition = children[&target] + direction_vectors[direction];
    return not IsColliding(newPosition);
}

bool Field::IsColliding(const Point &position)
{
    if (IsOnLeftBoundary(position) || IsOnRightBoundary(position))
        return true;

    for (const auto &child: children)
        if (child.second == position)
            return true;

    return false;
}

bool Field::IsOnLeftBoundary(const ConsoleObject &target)
{
    return children[&target].X == 1;
}

bool Field::IsOnLeftBoundary(const Point &position)
{
    return position.X == 1;
}

bool Field::IsOnRightBoundary(const ConsoleObject &target)
{
    return children[&target].X == width - 2;
}

bool Field::IsOnRightBoundary(const Point &position)
{
    return position.X == width - 2;
}

#pragma region overloads

wchar_t &Field::operator[](const Drawing::Point &position)
{
    auto row = position.X;
    auto column = width * position.Y;
    auto newLineChars = Toolbox::countWChar(L'\n', field.substr(0, column)) + 1;
    column += newLineChars;

    return field[row + column];
}

#pragma endregion

#pragma region Getters and Setters

int Field::getWidth() const
{
    return width;
}

int Field::getHeight() const
{
    return height;
}

#pragma endregion