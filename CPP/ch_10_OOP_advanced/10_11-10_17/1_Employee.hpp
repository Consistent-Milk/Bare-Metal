#pragma once
#include "0_Preprocessors.hpp"

class Employee
{
private:
    std::string m_name;

public:
    // Setters
    void setName(std::string_view name);

    // Getters
    std::string getName() const;

    // Virtual Functions

    // Pure Virutal Function
    virtual double earnings() const = 0;
    // Virtual Function
    virtual std::string toString() const;

    // Constructors
    explicit Employee(std::string_view name);
    // Virtual Destructor
    virtual ~Employee() = default;
};