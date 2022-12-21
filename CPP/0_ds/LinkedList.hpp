#pragma once
#include "Node.hpp"

using namespace ds;
namespace ds
{
    template <typename T>
    class LinkedList
    {
    private:
        std::shared_ptr<Node<T>> startNode;
        std::shared_ptr<Node<T>> endNode;

    public:
        LinkedList()
        {
            startNode = std::make_shared<Node<T>>();
            endNode = nullptr;
        }

        /**
         * @brief Utility member function to check if LinkedList is empty
         */
        bool isEmpty()
        {
            if (endNode == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        /**
         * @brief Member function to append a new node with a given value to the list
         */
        void append(T new_node_value)
        {
            if (isEmpty())
            {
                startNode->nextNode() = std::make_shared<Node<T>>(new_node_value);
                endNode = startNode->nextNode();
            }
            else
            {
                endNode->nextNode() = std::make_shared<Node<T>>(new_node_value);
                endNode = endNode->nextNode();
            }
        }

        void display()
        {
            if (isEmpty())
            {
                std::cout << "List is Empty!";
                return;
            }

            std::shared_ptr<Node<T>> temp = startNode;

            while (temp->nextNode() != nullptr)
            {
                std::cout << temp->value() << "\t";
                temp = temp->nextNode();
            }
        }
    };
}