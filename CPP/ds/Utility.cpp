#include "Utility.hpp"

bool ds::isDigit(const std::string &s)
{
    for (char i : s)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }

    return true;
}