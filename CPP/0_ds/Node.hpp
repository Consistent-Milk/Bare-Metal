#pragma once
#include "Preprocessors.hpp"

namespace ds
{
    template <typename T>
    class Node
    {
    private:
        T nodeValue;                   // Value stored in the current code
        std::shared_ptr<Node<T>> next; // Pointer to the next node in the link

    public:
        T value()
        {
            return nodeValue;
        }

        std::shared_ptr<Node> &nextNode()
        {
            return next;
        }

        Node(T value = NULL) : nodeValue(value), next(nullptr) {}
    };
}
