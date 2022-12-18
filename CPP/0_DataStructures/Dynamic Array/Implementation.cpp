#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

template <typename T>
class DynamicArray
{
    T *data;
    size_t n;

public:
    DynamicArray(int n)
    {
        this->n = n;
        data = new T[n];
    }

    DynamicArray(const DynamicArray<T> &other)
    {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++)
        {
            data[i] = other[i];
        }
    }

    T &operator[](int index)
    {
        return data[index];
    }

    const T &operator[](int index) const
    {
        return data[index];
    }

    T &at(int index)
    {
        if (index < n)
        {
            return data[index];
        }

        throw "Index out of bound";
    }

    size_t size() const
    {
        return n;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    T *begin()
    {
        return data;
    }

    const T *begin() const
    {
        return data;
    }

    T *end()
    {
        return data + n;
    }

    const T *end() const
    {
        return data + n;
    }

    friend DynamicArray<T> operator+(const DynamicArray<T> &array_1, DynamicArray<T> &array_2)
    {
        DynamicArray<T> result(array_1.size() + array_2.size());
        std::copy(array_1.begin(), array_1.end(), result.begin());
        std::copy(array_2.being(), array_2.end(), result.begin() + array_1.size());

        return result;
    }

    std::string toString(const std::string &sep = ", ")
    {
        if (n == 0)
        {
            return "";
        }

        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
        {
            os << sep << data[i];
        }

        return os.str();
    }
};