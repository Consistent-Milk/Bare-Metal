// STL
#include <iostream>
// TPL
#include <fmt/format.h>
// CH
#include "CreateAndDestroy.hpp"

CreateAndDestroy::CreateAndDestroy(int ID, std::string_view message)
    : m_ID{ID}, m_message{message}
{
    std::cout << fmt::format("Object {}   constructor runs   {}", m_ID, m_message);
}

CreateAndDestroy::~CreateAndDestroy()
{
    bool conditional = m_ID == 1 || m_ID == 6;
    std::cout << fmt::format("{}Object {}  destructor runs   {}\n", (conditional ? "\n" : ""), m_ID, m_message);
}