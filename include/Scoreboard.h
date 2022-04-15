#pragma once

#include <map>
#include <string>

class Scoreboard
{
public:
    Scoreboard(int width, int height);
    void AddEntry(std::string label, int count);
    void IncreaseCount(std::string label);
    void Draw();
private:
    int width, height;
    std::map<std::string, int> entries;
};
