#pragma once

#include <string>

namespace Toolbox
{
    std::string multiplyChars(char c, int digits)
    {
        std::string result;
        for (int i = 0; i < digits; i++)
            result += c;

        return result;
    }

    std::string multiplyString(const std::string &s, int digits)
    {
        std::string result;
        for (int i = 0; i < digits; i++)
            result.append(s);

        return result;
    }

    std::wstring multiplyWString(const std::wstring &s, int digits)
    {
        std::wstring result;
        for (int i = 0; i < digits; i++)
            result.append(s);

        return result;
    }

    std::wstring multiplyWChar(const wchar_t s, int digits)
    {
        std::wstring result;
        for (int i = 0; i < digits; i++)
            result += s;

        return result;
    }

    int countChar(char c, std::string s)
    {
        int count = 0;
        for (auto character: s)
        {
            if (character == c)
                count++;
        }
        return count;
    }

    int countWChar(wchar_t term, std::wstring ws)
    {
        int count = 0;
        for (auto wc: ws)
            if (wc == term) count++;
        return count;
    }
};
