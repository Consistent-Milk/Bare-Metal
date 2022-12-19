#pragma once
#include "Node.hpp"

namespace ds
{
    class LinkedList
    {
    private:
        std::shared_ptr<ds::Node> start;
        std::shared_ptr<ds::Node> end;

    public:
        LinkedList()
        {
            start = std::make_shared<ds::Node>();
            end = nullptr;
        }

        bool isEmpty();

        void push_back(int new_element);
        void push_front(int new_element);
        void delete_node(int old_element);
        void display();
        std::shared_ptr<ds::Node> search(int find_element);
    };
}