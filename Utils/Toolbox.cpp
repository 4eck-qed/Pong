#include "Toolbox.h"

namespace Toolbox
{
    std::string MultiplyChars(char c, int digits)
    {
        std::string result;
        for (int i = 0; i < digits; i++)
            result += c;

        return result;
    }

    std::string MultiplyString(const std::string &s, int digits)
    {
        std::string result;
        for (int i = 0; i < digits; i++)
            result.append(s);

        return result;
    }

    std::wstring MultiplyWString(const std::wstring &s, int digits)
    {
        std::wstring result;
        for (int i = 0; i < digits; i++)
            result.append(s);

        return result;
    }

    std::wstring MultiplyWChars(const wchar_t s, int digits)
    {
        std::wstring result;
        for (int i = 0; i < digits; i++)
            result += s;

        return result;
    }

    int CountChar(char c, std::string s)
    {
        int count = 0;
        for (auto character: s)
        {
            if (character == c)
                count++;
        }
        return count;
    }

    int CountWChar(wchar_t term, std::wstring ws)
    {
        int count = 0;
        for (auto wc: ws)
            if (wc == term) count++;
        return count;
    }
}
