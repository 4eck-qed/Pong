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

    std::string MultiplyChars(char c, int digits);

    std::string MultiplyString(const std::string &s, int digits);

    std::wstring MultiplyWString(const std::wstring &s, int digits);

    std::wstring MultiplyWChars(const wchar_t s, int digits);

    int CountChar(char c, std::string s);

    int CountWChar(wchar_t term, std::wstring ws);
}
