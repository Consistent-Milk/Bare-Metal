#include "Stack.hpp"

int main(void)
{
    int choice{0};
    Stack<int> stack;

    int x{0};

    do
    {
        std::cout << "\n0. Exit or Ctrl+C";
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Print";
        std::cout << "\n4. Peek";
        std::cout << "\n5. Empty Stack";
        std::cout << "\nEnter Your Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            std::cout << "\nInsert : ";
            std::cin >> x;
            stack.push(x);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.traverseStack();
            break;
        case 4:
            stack.peek();
            break;
        case 5:
            stack.clear();
            break;
        default:
            std::cout << "Invalid option!\n";
            break;
        }
    } while (choice != 0);

    return 0;
}