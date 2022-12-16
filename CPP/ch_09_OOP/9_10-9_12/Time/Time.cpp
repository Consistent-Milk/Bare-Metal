// Member-function definitions for class Time
// STL
#include <iostream>
#include <stdexcept>
#include <string>
// TPL
#include <fmt/format.h>
// CH
#include "Time.hpp"

// Constructor
Time::Time(int hour, int minute, int second)
{ // Calls setter for validation
    setTime(hour, minute, second);
}

// Setters
// -------
void Time::setTime(int hour, int minute, int second)
{
    // Seperate validators have been set in this implementation
    // of the time class
    if (hour < 0 || hour >= 24)
    {
        throw std::invalid_argument{"hour was out of range"};
    }

    if (minute < 0 || minute >= 60)
    {
        throw std::invalid_argument{"minute was out of range"};
    }

    if (second < 0 || second >= 60)
    {
        throw std::invalid_argument{"second was out of range"};
    }

    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

// Set hour value through setTime
void Time::setHour(int hour)
{
    setTime(hour, m_minute, m_second);
}

// Set minute value through setTime
void Time::setMinute(int minute)
{
    setTime(m_hour, minute, m_second);
}

// Set second value through setTime
void Time::setSecond(int second)
{
    setTime(m_hour, m_minute, second);
}

// Getters
// -------
int Time::getHour() const
{
    return m_hour;
}

int Time::getMinute() const
{
    return m_minute;
}

int Time::getSecond() const
{
    return m_second;
}

// Formatted-Getters
// -----------------
std::string Time::to24HourString() const
{
    return fmt::format("{:02d}:{:02d}:{:02d}",
                       getHour(), getMinute(), getSecond());
}

std::string Time::to12HourString() const
{
    // Seperate tertiary operators to make the code cleaner
    int hour = (getHour() % 12 == 0) ? 12 : getHour() % 12;
    std::string AM_PM = getHour() < 12 ? "AM" : "PM";

    return fmt::format("{}:{:02d}:{:02d} {}",
                       hour, getMinute(), getSecond(), AM_PM);
}