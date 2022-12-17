#include <fmt/format.h>
#include <iostream>
#include "fmt/format.h" // In C++20, this will be #include <format>

// Count class definition
class Count
{
    friend void modifyX(Count &c, int value); // friend declaration
public:
    int getX() const { return m_x; }

private:
    int m_x{0};
};

// function modifyX can modify private data of Count
// because modifyX is declared as a friend of Count (line 8)
void modifyX(Count &c, int value)
{
    c.m_x = value; // allowed because modifyX is a friend of Count
}

int main()
{
    Count counter{}; // create Count object

    std::cout << fmt::format("Initial counter.m_x: {}\n", counter.getX());
    modifyX(counter, 8); // change x's value using a friend function
    std::cout << fmt::format("counter.m_x after modifyX: {}\n",
                             counter.getX());
}