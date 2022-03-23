#include "Field.h"
#include "Ball.h"
#include "Utils/Toolbox.h"
#include "Utils/Converter.h"

#include <string>
#include <iostream>

using namespace Drawing;

Field::Field(int width, int height)
{
    this->width = width;
    this->height = height;
    topLeftCorner = {0, 0};
    bottomRightCorner = {width, height};

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

void Field::update()
{
    draw();
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
    update();
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

bool Field::canMove(const ConsoleObject &target, const Point &offset)
{
    auto newPosition = children[&target] + offset;
    return not checkCollision(newPosition);
}

bool Field::checkCollision(const Point &position)
{
    if (position >> Point{width - 2, height} || position << Point{1, 1})
        return true;

    for (const auto &child: children)
        if (child.second == position)
            return true;
    return false;
}

Field::Field() : Field(64, 16)
{

}

#pragma endregion