#include "LinkedList.hpp"

using namespace ds;

bool LinkedList::isEmpty()
{
    if (end == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedList::push_back(int new_element)
{
    if (isEmpty())
    {
        start->nextNode() = std::make_shared<Node>(new_element);
        end = start->nextNode();
    }
    else
    {
        end->nextNode() = std::make_shared<Node>(new_element);
        end = end->nextNode();
    }
}

void LinkedList::push_front(int new_element)
{
    if (isEmpty())
    {
        start->nextNode() = std::make_shared<Node>(new_element);
        end = start->nextNode();
    }
    else
    {
        std::shared_ptr<Node> temp = std::make_shared<Node>(new_element);
        temp->nextNode() = start->nextNode();
        start->nextNode() = temp;
    }
}

void LinkedList::delete_node(int old_element)
{
    if (isEmpty())
    {
        std::cout << "List is Empty";
        return;
    }

    std::shared_ptr<Node> temp = start;
    std::shared_ptr<Node> tempRemove = nullptr;

    bool traversalCondition = temp != end && temp->nextNode()->value() != old_element;

    while (traversalCondition)
    {
        temp = temp->nextNode();
    }

    if (temp == end)
    {
        std::cout << "Element not found\n";
        return;
    }

    tempRemove = temp->nextNode();
    temp->nextNode() = temp->nextNode()->nextNode();
    tempRemove.reset();

    if (temp->nextNode() == nullptr)
    {
        end = temp;
    }

    if (start == end)
    {
        end = nullptr;
    }
}

void LinkedList::display()
{
    if (isEmpty())
    {
        std::cout << "List is Empty!";
    }

    std::shared_ptr<Node> temp = start;

    while (temp->nextNode() != nullptr)
    {
        std::cout << temp->nextNode()->value() << "\t";
        temp = temp->nextNode();
    }
}

std::shared_ptr<ds::Node> LinkedList::search(int find_element)
{
    if (isEmpty())
    {
        std::cout << "List is Empty!";
        return nullptr;
    }

    std::shared_ptr<ds::Node> temp = start;

    bool traversalCondition = temp != end && temp->nextNode()->value() != find_element;

    while (traversalCondition)
    {
        temp = temp->nextNode();
    }

    if (temp == end)
    {
        std::cout << "Element not found\n";
        return nullptr;
    }

    std::cout << "Element was found\n";

    return temp->nextNode();
}