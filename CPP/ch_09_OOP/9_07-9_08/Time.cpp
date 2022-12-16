// STL
#include <iostream>
#include <string>
#include <stdexcept>
// TPL
#include <fmt/format.h>
// CH
#include "Time.hpp"

// CH Function Definitions
void Time::setTime(int hour, int minute, int second)
{
    if ((hour < 0 || hour >= 24) || (minute < 0 || minute >= 60) || (second < 0 || second >= 60))
    {
        throw std::invalid_argument{
            "hour, minute or second was out of range"};
    }

    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

std::string Time::to24HourString() const
{
    return fmt::format("{:02d}:{:02d}:{:02d}", m_hour, m_minute, m_second);
}

std::string Time::to12HourString() const
{
    int hour = m_hour % 12;
    return fmt::format("{}:{:02d}:{:02d} {}",
                       (hour == 0 ? 12 : hour),
                       m_minute, m_second,
                       (m_hour < 12 ? "AM" : "PM"));
}