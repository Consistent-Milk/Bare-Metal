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
        std::copy(array_2.begin(), array_2.end(), result.begin() + array_1.size());

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

struct student
{
public:
    std::string name;
    int standard;
};

std::ostream &operator<<(std::ostream &os, const student &s)
{
    return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
}

int main()
{
    int nStudents;
    std::cout << "Enter number of students in class 1 : ";
    std::cin >> nStudents;

    DynamicArray<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++)
    {
        std::cout << "Enter name and class of student " << i + 1 << ": ";
        std::string name;
        int standard;
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    auto class2 = class1; // Deep copy

    std::cout << "Second class after initialized using first array : " << class2.toString() << std::endl;

    auto class3 = class1 + class2;
    // Combines both classes and creates a bigger one

    std::cout << "Combined class : ";
    std::cout << class3.toString() << std::endl;

    return 0;
}