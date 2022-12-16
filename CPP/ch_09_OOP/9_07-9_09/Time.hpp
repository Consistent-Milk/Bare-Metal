// pragma once prevents multiplhe inclusions of the header file
#pragma once
#include <string>

class Time
{
public:
    void setTime(int hour, int minute, int second);
    std::string to24HourString() const;
    std::string to12HourString() const;

private:
    int m_hour{0};
    int m_minute{0};
    int m_second{0};
};