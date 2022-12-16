#pragma once
#include <string>

class Time
{
public:
    // Constructor with default values so that class can be
    // instantiated without any arguments
    explicit Time(int hour = 0, int minute = 0, int second = 0);

    // Setters with built-in validators
    void setTime(int hour, int minute, int second);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

    // Getters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    // Formatted Getters
    std::string to24HourString() const;
    std::string to12HourString() const;

private:
    int m_hour{0};
    int m_minute{0};
    int m_second{0};
};