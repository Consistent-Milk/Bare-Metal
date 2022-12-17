// STL
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>
// TPL
#include <fmt/format.h>
// CH
#include "Date.hpp"

// Definition for constructor
Date::Date(int year, int month, int day)
    : m_year{year}, m_month{month}, m_day{day}
{
    bool badMonthCheck = (m_month < 1) || (m_month > monthsPerYear);
    if (badMonthCheck)
    {
        throw std::invalid_argument{"month must be a value from 1-12"};
    }

    if (!checkDay(day))
    {
        throw std::invalid_argument{"Invalid day for curent month and year"};
    }

    std::cout << fmt::format("Date object constructor: {}\n", toString());
}

// Definition for formatted getter
std::string Date::toString() const
{
    return fmt::format("{}-{:02d}-{:02d}", m_year, m_month, m_day);
}

// Definition for destructor
Date::~Date()
{
    std::cout << fmt::format("Date object destructor: {}\n", toString());
}

// Definition for utility function for validating days
bool Date::checkDay(int day) const
{
    // 0 in 0th index will be ignored
    static const std::array daysPerMonth{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // This check fails when given 29 for m_month = 2
    // thus the logic moves on to the next block
    // to verify whether the year is a leap year
    bool dayMonthCheck = day >= 1 && day <= daysPerMonth.at(m_month);
    if (dayMonthCheck)
    {
        return true;
    }

    // Checks whether the year is a leap year if provided day is
    // 29 and month is 2
    bool leapCheck = (m_year % 400 == 0) || (m_year % 4 == 0 && m_year % 100 != 0);
    bool dayMonthLeapCheck = (m_month == 2 && day == 29) && leapCheck;
    if (leapCheck)
    {
        return true;
    }

    return false;
}