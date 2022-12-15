#include <string>
#include <string_view>

class Account
{
public:
    explicit Account(std::string_view name)
        : m_name{name} {}

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