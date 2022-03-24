#pragma once

#include <string>

namespace Converter
{
    std::wstring StringToWString(const std::string &s);

    std::string WStringToString(const std::wstring &ws);
}
