#include <string>
#include <string_view>

// Implementing account class in a header file
class Account
{
public:
    void setName(std::string_view name)
    {
        m_name = name;
    }

    const std::string &getName() const
    {
        return m_name;
    }

private:
    std::string m_name;
};