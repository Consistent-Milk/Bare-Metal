// STL
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
// TPL
#include <fmt/format.h>
// CH
#include "Time/Time.hpp"

// displays a Time in 24-hour and 12-hour formats
void displayTime(std::string_view message, const Time &time, std::fstream &file)
{
    file << fmt::format("{}\n24-hour time: {}\n12-hour time: {}\n\n",
                        message, time.to24HourString(), time.to12HourString());
}

int main()
{
    std::fstream file;
    const Time t1{};           // all arguments defaulted
    const Time t2{2};          // hour specified; minute & second defaulted
    const Time t3{21, 34};     // hour & minute specified; second defaulted
    const Time t4{12, 25, 42}; // hour, minute & second specified

    file.open("Test.txt", std::ios::out);

    if (file.is_open())
    {
        std::cout << "\n\nfstream open\n\n";

        file << "Constructed with:\n\n";
        displayTime("t1: all arguments defaulted", t1, file);
        displayTime("t2: hour specified; minute and second defaulted", t2, file);
        displayTime("t3: hour and minute specified; second defaulted", t3, file);
        displayTime("t4: hour, minute and second specified", t4, file);

        file << "\nattempt to initialize t5 with invalid values\n";
        try
        {
            const Time t5{27, 74, 99}; // all bad values specified
        }
        catch (const std::invalid_argument &e)
        {
            file << fmt::format("t5 not created: {}\n", e.what());
        }
    }

    file.close();
    std::cout << "\n\nftream closed\n\n";
}