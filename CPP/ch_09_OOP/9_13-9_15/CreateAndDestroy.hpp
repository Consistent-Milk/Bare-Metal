#pragma once
#include <string>
#include <string_view>

class CreateAndDestroy
{
public:
    // Constructor
    CreateAndDestroy(int ID, std::string_view message);
    // Destructor
    ~CreateAndDestroy();

private:
    int m_ID;
    std::string m_message;
};