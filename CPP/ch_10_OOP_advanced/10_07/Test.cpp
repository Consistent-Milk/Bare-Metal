// Do not include "SalariedEmployee.hpp" again here as it is already
// included in "SalariedCommissionEmployee.hpp"
// Otherwise redifinition errors will occur during compilation
// A workaround is to always add #pragma once in all header files
#include "SalariedCommissionEmployee.hpp"

int main()
{
    // create base-class object
    SalariedEmployee salaried{"Sue Jones", 500.0};

    // create derived-class object
    SalariedCommissionEmployee salariedCommission{
        "Bob Lewis", 300.0, 5000.0, .04};

    // output objects salaried and salariedCommission
    std::cout << fmt::format("{}:\n{}\n{}\n",
                             "DISPLAY BASE-CLASS AND DERIVED-CLASS OBJECTS",
                             salaried.toString(),            // base-class toString
                             salariedCommission.toString()); // derived-class toString

    // natural: aim base-class pointer at base-class object
    SalariedEmployee *salariedPtr{&salaried};
    std::cout << fmt::format("{}\n{}:\n{}\n",
                             "CALLING TOSTRING WITH BASE-CLASS POINTER TO",
                             "BASE-CLASS OBJECT INVOKES BASE-CLASS FUNCTIONALITY",
                             salariedPtr->toString()); // base-class version

    // natural: aim derived-class pointer at derived-class object
    SalariedCommissionEmployee *salariedCommissionPtr{&salariedCommission};

    std::cout << fmt::format("{}\n{}:\n{}\n",
                             "CALLING TOSTRING WITH DERIVED-CLASS POINTER TO",
                             "DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS FUNCTIONALITY",
                             salariedCommissionPtr->toString()); // derived-class version

    // aim base-class pointer at derived-class object
    salariedPtr = &salariedCommission;
    std::cout << fmt::format("{}\n{}:\n{}\n",
                             "CALLING TOSTRING WITH BASE-CLASS POINTER TO DERIVED-CLASS",
                             "OBJECT INVOKES BASE-CLASS FUNCTIONALITY",
                             salariedPtr->toString()); // baseclass version
}