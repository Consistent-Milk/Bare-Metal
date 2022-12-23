/**
 * @brief CustomArray Class member and friend function definitions
 */

#include "CustomArray.hpp"

// Constructors
// ------------

/**
 * @brief Contruct from Size
 */
CustomArray::CustomArray(size_t size)
    : m_size{size},
      m_ptr{std::make_unique<int[]>(size)}
{
    std::cout << "CustomArray(size_t) Constructor\n";
}

/**
 * @brief List Constructor
 */
CustomArray::CustomArray(std::initializer_list<int> list)
    : m_size{list.size()},
      m_ptr{std::make_unique<int[]>(list.size())}
{
    // copy list argument's elements into m_ptr's underlying int array
    // m_ptr.get() returns the int array's starting memory location
    std::copy(std::begin(list), std::end(list), m_ptr.get());
}

/**
 * @brief Copy constructor
 */
CustomArray::CustomArray(const CustomArray &original)
    : m_size{original.size()},
      m_ptr{std::make_unique<int[]>(original.size())}
{
    std::cout << "CustomArray Copy Constructor\n";

    const std::span<const int> source{
        original.m_ptr.get(), original.size()};
    std::copy(std::begin(source), std::end(source), m_ptr.get());
}

/**
 * @brief Move constructor
 */
CustomArray::CustomArray(CustomArray &&original) noexcept
    : m_size{std::exchange(original.m_size, 0)},
      m_ptr{std::move(original.m_ptr)}
{
    std::cout << "CustomArray move constructor\n";
}

/**
 * @brief Copy assingment operator overload
 */
CustomArray &CustomArray::operator=(const CustomArray &right)
{
    std::cout << "CustomArray Copy Assignment Operator\n";
    CustomArray temp{right}; // Invoke copy constructor
    swap(*this, temp);       // Exchange contents of this object and passed rvalue object

    return *this;
}

CustomArray &CustomArray::operator=(CustomArray &&right) noexcept
{
    std::cout << "CustomArray move assignment operator\n";

    if (this != &right)
    {
        m_size = std::exchange(right.m_size, 0);
        m_ptr = std::move(right.m_ptr);
    }

    return *this;
}

CustomArray::~CustomArray()
{
    std::cout << "CustomArray destructor called\n";
}

std::string CustomArray::toString() const
{
    const std::span<const int> items{m_ptr.get(), m_size};
    std::ostringstream output;
    output << "{";

    for (size_t count{0}; const auto &item : items)
    {
        ++count;
        output << item << (count < m_size ? ", " : "");
    }

    output << "}";

    return output.str();
}

bool CustomArray::operator==(const CustomArray &right) const noexcept
{
    const std::span<const int> lhs{m_ptr.get(), size()};
    const std::span<const int> rhs{right.m_ptr.get(), right.size()};
    return std::equal(std::begin(lhs), std::end(lhs), std::begin(rhs), std::end(rhs));
}

int &CustomArray::operator[](size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range{"Index out of range"};
    }

    return m_ptr[index];
}

// overloaded subscript operator for const CustomArrays
// const reference return creates a non-modifiable lvalue
const int &CustomArray::operator[](size_t index) const
{
    // check for subscript out-of-range error
    if (index >= m_size)
    {
        throw std::out_of_range{"Index out of range"};
    }

    return m_ptr[index]; // returns copy of this element
}

// preincrement every element, then return updated CustomArray
CustomArray &CustomArray::operator++()
{
    // use a span and for_each to increment every element
    const std::span<int> items{m_ptr.get(), m_size};
    std::for_each(std::begin(items), std::end(items),
                  [](auto &item)
                  { ++item; });
    return *this;
}

// postincrement every element, and return copy of original CustomArray
CustomArray CustomArray::operator++(int)
{
    CustomArray temp(*this);
    ++(*this);   // call preincrement operator++ to do the incrementing
    return temp; // return the temporary copy made before incrementing
}

// add value to every element, then return updated CustomArray
CustomArray &CustomArray::operator+=(int value)
{
    // use a span and for_each to increment every element
    const std::span<int> items{m_ptr.get(), m_size};
    std::for_each(std::begin(items), std::end(items),
                  [value](auto &item)
                  { item += value; });
    return *this;
}

// overloaded input operator for class CustomArray;
// inputs values for entire CustomArray
std::istream &operator>>(std::istream &in, CustomArray &a)
{
    std::span<int> items{a.m_ptr.get(), a.m_size};

    for (auto &item : items)
    {
        in >> item;
    }

    return in; // enables cin >> x >> y;
}

// overloaded output operator for class CustomArray
std::ostream &operator<<(std::ostream &out, const CustomArray &a)
{
    out << a.toString();
    return out; // enables std::cout << x << y;
}

// swap function used to implement copy-and-swap copy assignment operator
void swap(CustomArray &a, CustomArray &b) noexcept
{
    std::swap(a.m_size, b.m_size); // swap using std::swap
    a.m_ptr.swap(b.m_ptr);         // swap using unique_ptr swap member function
}
