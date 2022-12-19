#include "LinkedList.hpp"
#include "Utility.hpp"

using namespace ds;

int main()
{
    ds::LinkedList l;
    int choice = 0;
    int x = 0;
    std::string s;
    do
    {
        std::cout << "\n1. Insert";
        std::cout << "\n2. Delete";
        std::cout << "\n3. Search";
        std::cout << "\n4. Print";
        std::cout << "\n0. Exit";
        std::cout << "\n\nEnter you choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "\nQuitting the program...\n";
            break;
        case 1:
            std::cout << "\nEnter the element to be inserted : ";
            std::cin >> s;

            if (ds::isDigit(s))
            {
                x = std::stoi(s);
                l.push_back(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 2:
            std::cout << "\nEnter the element to be removed : ";
            std::cin >> s;
            if (ds::isDigit(s))
            {
                x = std::stoi(s);
                l.delete_node(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 3:
            std::cout << "\nEnter the element to be searched : ";
            std::cin >> s;
            if (ds::isDigit(s))
            {
                x = std::stoi(s);
                std::shared_ptr<ds::Node> found =
                    l.search(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 4:
            l.display();
            std::cout << "\n";
            break;
        default:
            std::cout << "Invalid Input\n"
                      << std::endl;
            break;
        }
    } while (choice != 0);
    return 0;
}