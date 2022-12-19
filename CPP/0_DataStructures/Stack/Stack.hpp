#pragma once
#include "Node.hpp"

template <class T>
class Stack
{
private:
    Node<T> *stackTop; // Pointer to the stack top
    int size;          // Stack size

public:
    // Default constructor
    Stack()
    {
        stackTop = nullptr;
        size = 0;
    }

    // Default destructor
    ~Stack() {}

    // Check and return if stack is empty
    bool isEmpty()
    {
        bool checkEmpty = (stackTop == nullptr);
        return checkEmpty;
    }

    // Look at the data on top of the stack
    void peek()
    {
        if (stackTop == nullptr)
        {
            std::cout << "Stack is currently empty"
                      << "\n";
        }
        else
        {
            std::cout << stackTop->data << "\n";
        }
    }

    // Reassings the stackTop pointer to a nullptr
    // Losing all reference to the stored data in the stack
    // Shouldn't we deallocate the memory or call
    // the destructor beforehand?
    void clear()
    {
        stackTop = nullptr;
        size = 0;
    }

    // Add new data item on top and push the current
    // data item below
    void push(T item)
    {
        // Allocate memory for a new
        // Node and assign it a pointer to its address
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = stackTop;
        stackTop = newNode;
        size++; // Increase stack size
    }

    // Remove the top element from the stack
    void pop()
    {
        Node<T> *temp;
        if (isEmpty())
        {
            std::cout << "Stack is currently empty.";
        }
        else
        {
            temp = stackTop;           // Assign stackTop a temp pointer
            stackTop = stackTop->next; // Move stackTop pointer to point to the data below it
            delete temp;               // Delete previous stackTop stored as temp
            size--;                    // Decrease stack size
        }
    }

    // Traverse and display stack elements
    void traverseStack()
    {
        Node<T> *traverser = stackTop;
        std::cout << fmt::format("Top --> ");
        while (traverser != nullptr)
        {
            std::cout << fmt::format("{} ", traverser->data);
            traverser = traverser->next;
        }
        std::cout << "\n";
        std::cout << fmt::format("Size of the stack is: {}\n", size);
    }
};