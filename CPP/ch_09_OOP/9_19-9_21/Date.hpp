#pragma once
#include <string>

class Date
{
public:
    // Public static constant variable for class
    static const int monthsPerYear{12};
    // Constructor
    Date(int year, int month, int day);
    // Formatted getter
    std::string toString() const;
    // Destructor
    ~Date();

private:
    int m_year;
    int m_month;
    int m_day;
    bool checkDay(int day) const;
};