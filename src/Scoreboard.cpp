#include "../include/Scoreboard.h"
#include "../Utils/Toolbox.h"
#include "../Utils/Converter.h"

#include <iostream>

Scoreboard::Scoreboard(int width, int height) : width(width), height(height)
{

}

void Scoreboard::AddEntry(std::string label, int count)
{
    entries.insert({label, count});
}

void Scoreboard::IncreaseCount(std::string label)
{
    entries.at(label)++;
}

void Scoreboard::Draw()
{
    std::wcout << L'┌' << Toolbox::MultiplyWChars(L'─', width - 2) << L'┐' << std::endl;
    for (auto entry: entries)
        std::wcout << L'│' << Converter::StringToWString(entry.first) << " : " << entry.second << std::endl;
    std::wcout << L'└' << Toolbox::MultiplyWChars(L'─', width - 2) << L'┘' << std::endl;
}


