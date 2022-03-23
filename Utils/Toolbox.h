#pragma once

#include <string>

namespace Toolbox
{
    enum MovingState
    {
        GoDown,
        GoUp,
        GoLeft,
        GoRight,
    };

    std::string multiplyChars(char c, int digits);

    std::string multiplyString(const std::string &s, int digits);

    std::wstring multiplyWString(const std::wstring &s, int digits);

    std::wstring multiplyWChar(const wchar_t s, int digits);

    int countChar(char c, std::string s);

    int countWChar(wchar_t term, std::wstring ws);
}
