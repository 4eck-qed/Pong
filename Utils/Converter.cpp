#include "Converter.h"

namespace Converter
{
    std::wstring StringToWString(const std::string &s)
    {
        return std::wstring(s.begin(), s.end());
    }

    std::string WStringToString(const std::wstring &ws)
    {
        return std::string(ws.begin(), ws.end());
    }
}
