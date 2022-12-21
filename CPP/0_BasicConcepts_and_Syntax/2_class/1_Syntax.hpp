#include <string>

/**
 * @brief Basic Class Syntax, it is a good practice
 * to separate the definition of a classes methods in
 * a header (.h or .hpp) file and implement the logic of the methods
 * in a separate (.cpp) file. This allows for different implementations
 * of the same class and has other designing and maintainence benefits.
 * @param m_data_1 - int
 * @param m_data_2 - std::string
 * @param m_data_3 - float
 * @param m_data_4 - double
 */
class Basic
{
    // Attributes/Data Members of a C++ class are private
    // by default (if we don't explicitly
    // specify that using the  private identifier)
    // that means anything outside of the class can't
    // access these Data Members.
    // One common convention is to attach m_ before the data member name
    // to specify that it is a Data Member of the class
    // Similar to a struct we can combine different data types
    // to store in a class
private:
    int m_data_1;
    std::string m_data_2;
    float m_data_3;
    double m_data_4;

public:
    /*
    We can also define public data members for a class,
    these can be accessed using the dot(.) operator.
    */
    int p_data_1;
    float p_data_2;

    /*
    Setter Methods
    --------------
    These are used to set the values of a classes
    private data members.
    It should be noted that the data members can
    be directly initialized by using the
    special class constructor method. Usually,
    we will want setter methods for all of our
    private data members.

    In special cases, we might want to
    initialize the value of a data member using
    the class constructor but have no way to modify the
    data member later on. In that case, a setter method
    can be omitted for a specific data member.
    In this case, we will initialize m_data_1 through the
    custom class constructor and omit a setter method for it.
    */

    // Setter method for m_data_2
    void setData_2(std::string m_data_2);

    // Setter method for m_data_3
    void setData_3(float data);

    // Setter method for m_data_4
    void setData_4(double data);

    /*
    Getter Methods
    --------------
    These methods are used to get the value of a data member
    from a class. The main use for these methods is that a
    get method can present the data in a different form, keeping
    the actual data representation hidden from the user.

    For example, we will implement logic for getting the private
    data member m_data_4 using getDataHidden_4, which will return
    a std::string instead of the actual data type of m_data_4, which
    is double.

    Also note that the const keyword that follows, this lets the compiler
    and also other programmers know that calling this function will not
    modify the data that it is getting. The compiler will also throw errors
    if the logic implemented for a member function followed by const somehow
    tries to modify the associated data.
    */

    // Getter method for m_data_1
    int getData_1() const;

    // Getter method for m_data_2
    std::string getData_2() const;

    // Getter method for m_data_3
    float getData_3() const;

    // Getter method for m_data_4
    std::string getDataHidden_4() const;

    // Member Function
};