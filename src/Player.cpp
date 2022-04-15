//
// Created by baron on 22.03.22.
//

#include "../include/Player.h"

Player::Player()
{

}

Player::Player(std::string name) : name(name)
{

}

std::string Player::GetName() const
{
    return name;
}

char Player::GetCharacter() const
{
    return '|';
}
