// STL
#include <iostream>
#include <array>
#include <random>
// TPL
#include <fmt/format.h>

int main()
{
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution randomDie{1, 6};

    // Ignore element zero
    constexpr size_t arraySize{7};

    std::array<int, arraySize> frequency{0};

    for (int roll{1}; roll <= 60'000'000; ++roll)
    {
        ++frequency.at(randomDie(engine));
    }

    std::cout << fmt::format("{}{:>13}\n", "Face", "Frequency");

    // output each array element's value
    for (size_t face{1}; face < frequency.size(); ++face)
    {
        std::cout << fmt::format("{:>4}{:>13}\n", face, frequency.at(face));
    }
}