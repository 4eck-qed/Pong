//
// Created by baron on 22.03.22.
//

#ifndef PONG_CONVERTER_H
#define PONG_CONVERTER_H

#include <string>

namespace Converter
{
    std::wstring stringToWString(const std::string &s)
    {
        return std::wstring(s.begin(), s.end());
    }

    std::string wstringToString(const std::wstring &ws)
    {
        return std::string(ws.begin(), ws.end());
    }
}


#endif //PONG_CONVERTER_H
