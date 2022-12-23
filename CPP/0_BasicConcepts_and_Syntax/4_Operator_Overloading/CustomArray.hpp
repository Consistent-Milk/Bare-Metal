/**
 * @file CustomArray Class Definition
 */

#pragma once
#include "Preprocessors.hpp"

// Marking CustomArray class with the final
// specifier implies that other classes won't be able
// to derive from it, i.e., this class cannot be used as
// a base class.
class CustomArray final
{
    // Overloading input stream operator
    friend std::istream &operator>>(std::istream &in, CustomArray &a);

    // Enabling copy assignment operator to implement copy and swap
    friend void swap(CustomArray &a, CustomArray &b) noexcept;

private:
    size_t m_size{0};             // Pointer based array size
    std::unique_ptr<int[]> m_ptr; // Smart pointer to integer array

public:
    // Constructor Overloading
    // -----------------------

    // First Constructor
    /**
     * @brief Construct a CustomArray instance of 'size' elements
     */
    explicit CustomArray(size_t size);

    /**
     * @brief Construct a CustomArray with a braced-initializer list of ints
     */
    explicit CustomArray(std::initializer_list<int> list);

    /**
     * @brief Construct a CustomArray by copying from another object instance of CustomArray
     */
    CustomArray(const CustomArray &original);

    /**
     * @brief Move Constructor
     */
    CustomArray(CustomArray &&original) noexcept;

    // -----------------------

    // Destructor
    // -----------------------

    /**
     * @brief Destructs the object instance of CustomArray when it goes out of scope and frees memory
     */
    ~CustomArray();

    // -----------------------

    // Getter Member Functions
    // -----------------------

    /**
     * @brief returns the size of the array
     */
    size_t size() const noexcept
    {
        return m_size;
    }

    /**
     * @brief Create and return string representation of an object instance
     */
    std::string toString() const;

    // -----------------------

    // Operator Overloads
    // ------------------

    /**
     * @brief = copy assignment operator overload
     */
    CustomArray &operator=(const CustomArray &right);

    /**
     * @brief = copy assignment operator overload
     */
    CustomArray &operator=(CustomArray &&right) noexcept;

    /**
     * @brief == Logical equality operator overload
     */
    bool operator==(const CustomArray &right) const noexcept;

    /**
     * @brief [] subscript operator overload for non-const objects, returns modifiable lvalue
     */
    int &operator[](size_t index);

    /**
     * @brief [] subscript operator overload for const objects, returns unmodifiable lvalue
     */
    const int &operator[](size_t index) const;

    /**
     * @brief convert CustomArray to bool value: true if non-empty; else false
     */
    explicit operator bool() const noexcept
    {
        return size() != 0;
    }

    /**
     * @brief Object++ preincrement overload, increment every element of the array by 1 and return modified object instance
     */
    CustomArray &operator++();

    /**
     * @brief postincrement every element, and return copy of original Object
     */
    CustomArray operator++(int);

    /**
     * @brief add 'value' to every element and return updated Object instance
     */
    CustomArray &operator+=(int value);
};

// << output stream overloaded operator is not a friend--does not access private data
std::ostream &operator<<(std::ostream &out, const CustomArray &a);